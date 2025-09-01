#include "sales_system.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <limits> // 用于清除输入缓冲区

using namespace std;

// ==================== 销售人员管理 ====================
void SalesManagementSystem::addSalesPerson() {
    string id, name, gender, birth;
    cout << "请输入员工号: ";
    cin >> id;
    cout << "请输入姓名: ";
    cin >> name;
    cout << "请输入性别: ";
    cin >> gender;
    cout << "请输入出生年月，如(2005-10): ";
    cin >> birth;

    // 检查员工号是否已存在
    for (const auto& sp : salesPeople) {
        if (sp.employeeId == id) {
            cout << "错误: 员工号已存在!" << endl;
            return;
        }
    }

    salesPeople.emplace_back(id, name, gender, birth);
    cout << "销售人员添加成功!" << endl;
}

void SalesManagementSystem::deleteSalesPerson() {
    string id;
    cout << "请输入要删除的员工号: ";
    cin >> id;

    auto it = find_if(salesPeople.begin(), salesPeople.end(),
        [&id](const SalesPerson& sp) { return sp.employeeId == id; });
	//it是一个迭代器，指向salesPeople中第一个满足条件的元素
	
    //salesPeople.end()是一个迭代器，指向salesPeople的末尾无效位置
    if (it != salesPeople.end()) 
    {
        salesPeople.erase(it);
        cout << "销售人员删除成功!" << endl;
    }
    else 
    {
        cout << "未找到该员工!" << endl;
    }
}

void SalesManagementSystem::modifySalesPerson() 
{
    string id;
    cout << "请输入要修改的员工号: ";
    cin >> id;

    auto it = find_if(salesPeople.begin(), salesPeople.end(),
        [&id](const SalesPerson& sp) { return sp.employeeId == id; });

    if (it != salesPeople.end()) 
    {
        cout << "当前信息: " << endl;
        cout << "姓名: " << it->name << endl;
        cout << "性别: " << it->gender << endl;
        cout << "出生年月: " << it->birthDate << endl;

        cout << "请输入新的姓名(直接回车保持原值): ";
        cin.ignore();//作用是 丢弃输入缓冲区中的一个字符（默认是换行符 '\n'）
        string newName;
        getline(cin, newName);//和 cin >> 不同，getline会消耗换行符
        if (!newName.empty()) 
            it->name = newName;

        cout << "请输入新的性别(直接回车保持原值): ";
        string newGender;
        getline(cin, newGender);
        if (!newGender.empty()) 
            it->gender = newGender;

        cout << "请输入新的出生年月(直接回车保持原值): ";
        string newBD;
        getline(cin, newBD);
        if (!newBD.empty()) 
            it->birthDate = newBD;

        cout << "销售人员信息修改成功!" << endl;
    }
    else {
        cout << "未找到该员工!" << endl;
    }
}

void SalesManagementSystem::querySalesPerson() {
    string id;
    cout << "请输入要查询的员工号: ";
    cin >> id;

    auto it = find_if(salesPeople.begin(), salesPeople.end(),
        [&id](const SalesPerson& sp) { return sp.employeeId == id; });

    if (it != salesPeople.end()) {
        cout << "===== 销售人员信息 =====" << endl;
        cout << "员工号: " << it->employeeId << endl;
        cout << "姓名: " << it->name << endl;
        cout << "性别: " << it->gender << endl;
        cout << "出生年月: " << it->birthDate << endl;
    }
    else {
        cout << "未找到该员工!" << endl;
    }
}

// ==================== 产品管理 ====================

void SalesManagementSystem::addProduct() {
    string id, name, type;
    double price;
    cout << "请输入产品号: ";
    cin >> id;
    cout << "请输入产品名称: ";
    cin >> name;
    cout << "请输入产品类型: ";
    cin >> type;
    cout << "请输入产品价格: ";
    cin >> price;

    // 检查产品号是否已存在
    for (const auto& p : products) {
        if (p.productId == id) {
            cout << "错误: 产品号已存在!" << endl;
            return;
        }
    }

    //emplace_back直接在容器中构造对象，避免不必要的拷贝
    products.emplace_back(id, name, type, price);
    cout << "产品添加成功!" << endl;
}

void SalesManagementSystem::deleteProduct() {
    string id;
    cout << "请输入要删除的产品号: ";
    cin >> id;

    auto it = find_if(products.begin(), products.end(),
        [&id](const Product& p) { return p.productId == id; });

    if (it != products.end()) {
        // 检查是否有关联的销售记录
        bool hasRecords = any_of(salesRecords.begin(), salesRecords.end(),
            [&id](const SalesRecord& sr) { return sr.productId == id; });

        if (hasRecords) {
            cout << "警告: 该产品存在销售记录，无法删除!" << endl;
            return;
        }

        products.erase(it);
        cout << "产品删除成功!" << endl;
    }
    else {
        cout << "未找到该产品!" << endl;
    }
}

void SalesManagementSystem::modifyProduct() {
    string id;
    cout << "请输入要修改的产品号: ";
    cin >> id;

    auto it = find_if(products.begin(), products.end(),
        [&id](const Product& p) { return p.productId == id; });

    if (it != products.end()) {
        cout << "当前信息: " << endl;
        cout << "名称: " << it->name << endl;
        cout << "类型: " << it->type << endl;
        cout << "价格: " << it->price << endl;

        cout << "请输入新的名称(直接回车保持原值): ";
        cin.ignore();
        string newName;
        getline(cin, newName);
        if (!newName.empty()) it->name = newName;

        cout << "请输入新的类型(直接回车保持原值): ";
        string newType;
        getline(cin, newType);
        if (!newType.empty()) it->type = newType;

        cout << "请输入新的价格(直接回车保持原值): ";
        string newPriceStr;
        getline(cin, newPriceStr);
        if (!newPriceStr.empty()) {
            try {
                double newPrice = stod(newPriceStr);
                it->price = newPrice;
            }
            catch (...) {
                cout << "无效的价格输入，保持原值" << endl;
            }
        }

        cout << "产品信息修改成功!" << endl;
    }
    else {
        cout << "未找到该产品!" << endl;
    }
}
void SalesManagementSystem::queryProduct() {
    string id;
    cout << "请输入要查询的产品号: ";
    cin >> id;

    auto it = find_if(products.begin(), products.end(),
        [&id](const Product& p) { return p.productId == id; });

    if (it != products.end()) {
        cout << "===== 产品信息 =====" << endl;
        cout << "产品号: " << it->productId << endl;
        cout << "名称: " << it->name << endl;
        cout << "类型: " << it->type << endl;
        cout << "价格: " << fixed << setprecision(2) << it->price << endl;
    }
    else {
        cout << "未找到该产品!" << endl;
    }
}

// ==================== 销售记录管理 ====================

void SalesManagementSystem::addSalesRecord() 
{
    string pid, eid, date;
    int quantity;

    cout << "请输入产品号: ";
    cin >> pid;
    cout << "请输入销售数量: ";
    cin >> quantity;
    cout << "请输入销售日期，如(2005-10-31): ";
    cin >> date;
    cout << "请输入员工号: ";
    cin >> eid;

    // 验证产品是否存在
    bool productExists = any_of(products.begin(), products.end(),
        [&pid](const Product& p) { return p.productId == pid; });
    if (!productExists) 
    {
        cout << "错误: 产品不存在!" << endl;
        return;
    }

    // 验证员工是否存在
    bool employeeExists = any_of(salesPeople.begin(), salesPeople.end(),
        [&eid](const SalesPerson& sp) { return sp.employeeId == eid; });
    if (!employeeExists) 
    {
        cout << "错误: 员工不存在!" << endl;
        return;
    }

    // 日期验证
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') 
		//10是日期格式的长度，4和7是指'-'的位置
    {
        cout << "错误: 日期格式应为YYYY-MM-DD!" << endl;
        return;
    }

    salesRecords.emplace_back(pid, quantity, date, eid);
    cout << "销售记录添加成功!" << endl;
}

void SalesManagementSystem::viewSalesRecordsByEmployeeAndDate() {
    string eid, date;
    cout << "请输入员工号: ";
    cin >> eid;
    cout << "请输入销售日期(YYYY-MM-DD): ";
    cin >> date;

    vector<SalesRecord> matchedRecords;
    for (const auto& record : salesRecords) {
        if (record.employeeId == eid && record.salesDate == date) {
            matchedRecords.push_back(record);
        }
    }

    if (matchedRecords.empty()) {
        cout << "未找到匹配的销售记录!" << endl;
        return;
    }

    cout << "===== 销售记录 =====" << endl;
    cout << "员工号: " << eid << "  日期: " << date << endl;
    cout << "--------------------------------------------------" << endl;
    cout << setw(10) << "序号" << setw(15) << "产品号"
        << setw(10) << "数量" << setw(15) << "金额" << endl;

    for (size_t i = 0; i < matchedRecords.size(); ++i) {
        const auto& record = matchedRecords[i];
        auto productIt = find_if(products.begin(), products.end(),
            [&record](const Product& p) { return p.productId == record.productId; });

        double amount = 0.0;
        if (productIt != products.end()) {
            amount = record.quantity * productIt->price;
        }

        cout << setw(10) << i + 1 << setw(15) << record.productId
            << setw(10) << record.quantity
            << setw(15) << fixed << setprecision(2) << amount << endl;
    }
}

void SalesManagementSystem::modifySalesRecord() 
{
    viewSalesRecordsByEmployeeAndDate();

    if (salesRecords.empty()) 
        return;

    int choice;
    cout << "请输入要修改的记录序号(0取消): ";
    cin >> choice;

    if (choice == 0) 
        return;
    if (choice < 1 || choice > static_cast<int>(salesRecords.size())) 
    {
        cout << "无效的选择!" << endl;
        return;
    }

    SalesRecord& record = salesRecords[choice - 1];
    cout << "当前信息: " << endl;
    cout << "产品号: " << record.productId << endl;
    cout << "数量: " << record.quantity << endl;
    cout << "日期: " << record.salesDate << endl;
    cout << "员工号: " << record.employeeId << endl;

    cout << "请输入新的产品号(直接回车保持原值): ";
    cin.ignore();
    string newPid;
    getline(cin, newPid);
    if (!newPid.empty()) 
    {
        // 验证新产品是否存在
        bool productExists = any_of(products.begin(), products.end(),
            [&newPid](const Product& p) { return p.productId == newPid; });
        if (productExists) 
        {
            record.productId = newPid;
        }
        else 
        {
            cout << "产品不存在，保持原值" << endl;
        }
    }

    cout << "请输入新的数量(直接回车保持原值): ";
    string newQtyStr;
    getline(cin, newQtyStr);
    if (!newQtyStr.empty()) 
    {
        try {
            int newQty = stoi(newQtyStr);
            if (newQty > 0) 
            {
                record.quantity = newQty;
            }
            else 
            {
                cout << "数量必须大于0，保持原值" << endl;
            }
        }
        catch (...) 
        {
            cout << "无效的输入，保持原值" << endl;
        }
    }

    cout << "请输入新的日期(直接回车保持原值): ";
    string newDate;
    getline(cin, newDate);
    if (!newDate.empty()) 
    {
        if (newDate.length() == 10 && newDate[4] == '-' && newDate[7] == '-') 
        {
            record.salesDate = newDate;
        }
        else 
        {
            cout << "日期格式应为YYYY-MM-DD，保持原值" << endl;
        }
    }

    cout << "销售记录修改成功!" << endl;
}

void SalesManagementSystem::deleteSalesRecord() 
{
    viewSalesRecordsByEmployeeAndDate();

    if (salesRecords.empty()) 
        return;

    int choice;
    cout << "请输入要删除的记录序号(0取消): ";
    cin >> choice;

    if (choice == 0) 
        return;
    if (choice < 1 || choice > static_cast<int>(salesRecords.size())) {
        cout << "无效的选择!" << endl;
        return;
    }

    salesRecords.erase(salesRecords.begin() + choice - 1);
    cout << "销售记录删除成功!" << endl;
}

// ==================== 统计报表 ====================

void SalesManagementSystem::productSalesReportByMonth() {
    string month;
    cout << "请输入月份(YYYY-MM): ";
    cin >> month;

    if (month.length() != 7 || month[4] != '-') {
        cout << "错误的月份格式，应为YYYY-MM" << endl;
        return;
    }

    map<string, pair<int, double>> productStats; // productId -> (quantity, totalAmount)

    for (const auto& record : salesRecords) 
    {
        if (record.salesDate.substr(0, 7) == month) 
        {
            auto productIt = find_if(products.begin(), products.end(),
                [&record](const Product& p) { return p.productId == record.productId; });

            if (productIt != products.end()) 
            {
                double amount = record.quantity * productIt->price;
                productStats[record.productId].first += record.quantity;
                productStats[record.productId].second += amount;
            }
        }
    }

    if (productStats.empty()) 
    {
        cout << "该月无销售记录!" << endl;
        return;
    }

    // 转换为vector并排序
    vector<pair<string, pair<int, double>>> sortedProducts(
        productStats.begin(), productStats.end());
    sort(sortedProducts.begin(), sortedProducts.end(),
        [](const auto& a, const auto& b) { return a.second.second > b.second.second; });

    // 打印报表
    cout << "\n===== 产品销售月报表 (" << month << ") =====" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "|                                                |" << endl;
    cout << setw(15) << "产品号" << setw(20) << "产品名称"
        << setw(10) << "数量" << setw(15) << "销售金额" << endl;
    cout << "|                                                |" << endl;
    cout << "-------------------------------------------------" << endl;

    for (const auto& item : sortedProducts) 
    {
        auto productIt = find_if(products.begin(), products.end(),
            [&item](const Product& p) { return p.productId == item.first; });

        if (productIt != products.end()) 
        {
            cout << setw(15) << item.first << setw(20) << productIt->name
                << setw(10) << item.second.first
                << setw(15) << fixed << setprecision(2) << item.second.second << endl;
        }
    }
    cout << "-------------------------------------------------" << endl;
}

void SalesManagementSystem::employeeSalesReportByMonth() 
{
    string month;
    cout << "请输入月份(YYYY-MM): ";
    cin >> month;

    if (month.length() != 7 || month[4] != '-') 
    {
        cout << "错误的月份格式，应为YYYY-MM" << endl;
        return;
    }

    map<string, double> employeeStats; // employeeId -> totalAmount

    for (const auto& record : salesRecords) 
    {
        if (record.salesDate.substr(0, 7) == month) 
        {
            auto productIt = find_if(products.begin(), products.end(),
                [&record](const Product& p) { return p.productId == record.productId; });

            if (productIt != products.end()) 
            {
                double amount = record.quantity * productIt->price;
                employeeStats[record.employeeId] += amount;
            }
        }
    }

    if (employeeStats.empty()) {
        cout << "该月无销售记录!" << endl;
        return;
    }

    // 转换为vector并排序
    vector<pair<string, double>> sortedEmployees(
        employeeStats.begin(), employeeStats.end());
    sort(sortedEmployees.begin(), sortedEmployees.end(),
        [](const auto& a, const auto& b) { return a.second > b.second; });

    // 打印报表
    cout << "\n===== 员工销售月报表 (" << month << ") =====" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "|                                            |" << endl;
    cout << setw(10) << "员工号" << setw(15) << "员工姓名"
        << setw(15) << "销售金额" << endl;
    cout << "|                                            |" << endl;
    cout << "---------------------------------------------" << endl;

    for (const auto& item : sortedEmployees) {
        auto employeeIt = find_if(salesPeople.begin(), salesPeople.end(),
            [&item](const SalesPerson& sp) { return sp.employeeId == item.first; });

        if (employeeIt != salesPeople.end()) {
            cout << setw(10) << item.first << setw(15) << employeeIt->name
                << setw(15) << fixed << setprecision(2) << item.second << endl;
        }
    }
    cout << "---------------------------------------------" << endl;
}

void SalesManagementSystem::employeeMonthlySalesReport() {
    string eid;
    cout << "请输入员工号: ";
    cin >> eid;

    // 检查员工是否存在
    auto employeeIt = find_if(salesPeople.begin(), salesPeople.end(),
        [&eid](const SalesPerson& sp) { return sp.employeeId == eid; });

    if (employeeIt == salesPeople.end()) {
        cout << "员工不存在!" << endl;
        return;
    }

    map<string, double> monthlyStats; // month -> totalAmount

    for (const auto& record : salesRecords) {
        if (record.employeeId == eid) {
            string month = record.salesDate.substr(0, 7);
            auto productIt = find_if(products.begin(), products.end(),
                [&record](const Product& p) { return p.productId == record.productId; });

            if (productIt != products.end()) {
                double amount = record.quantity * productIt->price;
                monthlyStats[month] += amount;
            }
        }
    }

    if (monthlyStats.empty()) {
        cout << "该员工无销售记录!" << endl;
        return;
    }

    // 转换为vector并按月份排序
    vector<pair<string, double>> sortedMonths(
        monthlyStats.begin(), monthlyStats.end());
    sort(sortedMonths.begin(), sortedMonths.end());

    // 打印报表
    cout << "\n===== 员工月度销售报表 (" << employeeIt->name << ") =====" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "|                                            |" << endl;
    cout << setw(10) << "月份" << setw(15) << "员工号"
        << setw(15) << "销售金额" << endl;
    cout << "|                                            |" << endl;
    cout << "---------------------------------------------" << endl;

    for (const auto& item : sortedMonths) {
        cout << setw(10) << item.first << setw(15) << eid
            << setw(15) << fixed << setprecision(2) << item.second << endl;
    }
    cout << "---------------------------------------------" << endl;
}