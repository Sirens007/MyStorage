#include "sales_system.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <limits> // ����������뻺����

using namespace std;

// ==================== ������Ա���� ====================
void SalesManagementSystem::addSalesPerson() {
    string id, name, gender, birth;
    cout << "������Ա����: ";
    cin >> id;
    cout << "����������: ";
    cin >> name;
    cout << "�������Ա�: ";
    cin >> gender;
    cout << "������������£���(2005-10): ";
    cin >> birth;

    // ���Ա�����Ƿ��Ѵ���
    for (const auto& sp : salesPeople) {
        if (sp.employeeId == id) {
            cout << "����: Ա�����Ѵ���!" << endl;
            return;
        }
    }

    salesPeople.emplace_back(id, name, gender, birth);
    cout << "������Ա��ӳɹ�!" << endl;
}

void SalesManagementSystem::deleteSalesPerson() {
    string id;
    cout << "������Ҫɾ����Ա����: ";
    cin >> id;

    auto it = find_if(salesPeople.begin(), salesPeople.end(),
        [&id](const SalesPerson& sp) { return sp.employeeId == id; });
	//it��һ����������ָ��salesPeople�е�һ������������Ԫ��
	
    //salesPeople.end()��һ����������ָ��salesPeople��ĩβ��Чλ��
    if (it != salesPeople.end()) 
    {
        salesPeople.erase(it);
        cout << "������Աɾ���ɹ�!" << endl;
    }
    else 
    {
        cout << "δ�ҵ���Ա��!" << endl;
    }
}

void SalesManagementSystem::modifySalesPerson() 
{
    string id;
    cout << "������Ҫ�޸ĵ�Ա����: ";
    cin >> id;

    auto it = find_if(salesPeople.begin(), salesPeople.end(),
        [&id](const SalesPerson& sp) { return sp.employeeId == id; });

    if (it != salesPeople.end()) 
    {
        cout << "��ǰ��Ϣ: " << endl;
        cout << "����: " << it->name << endl;
        cout << "�Ա�: " << it->gender << endl;
        cout << "��������: " << it->birthDate << endl;

        cout << "�������µ�����(ֱ�ӻس�����ԭֵ): ";
        cin.ignore();//������ �������뻺�����е�һ���ַ���Ĭ���ǻ��з� '\n'��
        string newName;
        getline(cin, newName);//�� cin >> ��ͬ��getline�����Ļ��з�
        if (!newName.empty()) 
            it->name = newName;

        cout << "�������µ��Ա�(ֱ�ӻس�����ԭֵ): ";
        string newGender;
        getline(cin, newGender);
        if (!newGender.empty()) 
            it->gender = newGender;

        cout << "�������µĳ�������(ֱ�ӻس�����ԭֵ): ";
        string newBD;
        getline(cin, newBD);
        if (!newBD.empty()) 
            it->birthDate = newBD;

        cout << "������Ա��Ϣ�޸ĳɹ�!" << endl;
    }
    else {
        cout << "δ�ҵ���Ա��!" << endl;
    }
}

void SalesManagementSystem::querySalesPerson() {
    string id;
    cout << "������Ҫ��ѯ��Ա����: ";
    cin >> id;

    auto it = find_if(salesPeople.begin(), salesPeople.end(),
        [&id](const SalesPerson& sp) { return sp.employeeId == id; });

    if (it != salesPeople.end()) {
        cout << "===== ������Ա��Ϣ =====" << endl;
        cout << "Ա����: " << it->employeeId << endl;
        cout << "����: " << it->name << endl;
        cout << "�Ա�: " << it->gender << endl;
        cout << "��������: " << it->birthDate << endl;
    }
    else {
        cout << "δ�ҵ���Ա��!" << endl;
    }
}

// ==================== ��Ʒ���� ====================

void SalesManagementSystem::addProduct() {
    string id, name, type;
    double price;
    cout << "�������Ʒ��: ";
    cin >> id;
    cout << "�������Ʒ����: ";
    cin >> name;
    cout << "�������Ʒ����: ";
    cin >> type;
    cout << "�������Ʒ�۸�: ";
    cin >> price;

    // ����Ʒ���Ƿ��Ѵ���
    for (const auto& p : products) {
        if (p.productId == id) {
            cout << "����: ��Ʒ���Ѵ���!" << endl;
            return;
        }
    }

    //emplace_backֱ���������й�����󣬱��ⲻ��Ҫ�Ŀ���
    products.emplace_back(id, name, type, price);
    cout << "��Ʒ��ӳɹ�!" << endl;
}

void SalesManagementSystem::deleteProduct() {
    string id;
    cout << "������Ҫɾ���Ĳ�Ʒ��: ";
    cin >> id;

    auto it = find_if(products.begin(), products.end(),
        [&id](const Product& p) { return p.productId == id; });

    if (it != products.end()) {
        // ����Ƿ��й��������ۼ�¼
        bool hasRecords = any_of(salesRecords.begin(), salesRecords.end(),
            [&id](const SalesRecord& sr) { return sr.productId == id; });

        if (hasRecords) {
            cout << "����: �ò�Ʒ�������ۼ�¼���޷�ɾ��!" << endl;
            return;
        }

        products.erase(it);
        cout << "��Ʒɾ���ɹ�!" << endl;
    }
    else {
        cout << "δ�ҵ��ò�Ʒ!" << endl;
    }
}

void SalesManagementSystem::modifyProduct() {
    string id;
    cout << "������Ҫ�޸ĵĲ�Ʒ��: ";
    cin >> id;

    auto it = find_if(products.begin(), products.end(),
        [&id](const Product& p) { return p.productId == id; });

    if (it != products.end()) {
        cout << "��ǰ��Ϣ: " << endl;
        cout << "����: " << it->name << endl;
        cout << "����: " << it->type << endl;
        cout << "�۸�: " << it->price << endl;

        cout << "�������µ�����(ֱ�ӻس�����ԭֵ): ";
        cin.ignore();
        string newName;
        getline(cin, newName);
        if (!newName.empty()) it->name = newName;

        cout << "�������µ�����(ֱ�ӻس�����ԭֵ): ";
        string newType;
        getline(cin, newType);
        if (!newType.empty()) it->type = newType;

        cout << "�������µļ۸�(ֱ�ӻس�����ԭֵ): ";
        string newPriceStr;
        getline(cin, newPriceStr);
        if (!newPriceStr.empty()) {
            try {
                double newPrice = stod(newPriceStr);
                it->price = newPrice;
            }
            catch (...) {
                cout << "��Ч�ļ۸����룬����ԭֵ" << endl;
            }
        }

        cout << "��Ʒ��Ϣ�޸ĳɹ�!" << endl;
    }
    else {
        cout << "δ�ҵ��ò�Ʒ!" << endl;
    }
}
void SalesManagementSystem::queryProduct() {
    string id;
    cout << "������Ҫ��ѯ�Ĳ�Ʒ��: ";
    cin >> id;

    auto it = find_if(products.begin(), products.end(),
        [&id](const Product& p) { return p.productId == id; });

    if (it != products.end()) {
        cout << "===== ��Ʒ��Ϣ =====" << endl;
        cout << "��Ʒ��: " << it->productId << endl;
        cout << "����: " << it->name << endl;
        cout << "����: " << it->type << endl;
        cout << "�۸�: " << fixed << setprecision(2) << it->price << endl;
    }
    else {
        cout << "δ�ҵ��ò�Ʒ!" << endl;
    }
}

// ==================== ���ۼ�¼���� ====================

void SalesManagementSystem::addSalesRecord() 
{
    string pid, eid, date;
    int quantity;

    cout << "�������Ʒ��: ";
    cin >> pid;
    cout << "��������������: ";
    cin >> quantity;
    cout << "�������������ڣ���(2005-10-31): ";
    cin >> date;
    cout << "������Ա����: ";
    cin >> eid;

    // ��֤��Ʒ�Ƿ����
    bool productExists = any_of(products.begin(), products.end(),
        [&pid](const Product& p) { return p.productId == pid; });
    if (!productExists) 
    {
        cout << "����: ��Ʒ������!" << endl;
        return;
    }

    // ��֤Ա���Ƿ����
    bool employeeExists = any_of(salesPeople.begin(), salesPeople.end(),
        [&eid](const SalesPerson& sp) { return sp.employeeId == eid; });
    if (!employeeExists) 
    {
        cout << "����: Ա��������!" << endl;
        return;
    }

    // ������֤
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') 
		//10�����ڸ�ʽ�ĳ��ȣ�4��7��ָ'-'��λ��
    {
        cout << "����: ���ڸ�ʽӦΪYYYY-MM-DD!" << endl;
        return;
    }

    salesRecords.emplace_back(pid, quantity, date, eid);
    cout << "���ۼ�¼��ӳɹ�!" << endl;
}

void SalesManagementSystem::viewSalesRecordsByEmployeeAndDate() {
    string eid, date;
    cout << "������Ա����: ";
    cin >> eid;
    cout << "��������������(YYYY-MM-DD): ";
    cin >> date;

    vector<SalesRecord> matchedRecords;
    for (const auto& record : salesRecords) {
        if (record.employeeId == eid && record.salesDate == date) {
            matchedRecords.push_back(record);
        }
    }

    if (matchedRecords.empty()) {
        cout << "δ�ҵ�ƥ������ۼ�¼!" << endl;
        return;
    }

    cout << "===== ���ۼ�¼ =====" << endl;
    cout << "Ա����: " << eid << "  ����: " << date << endl;
    cout << "--------------------------------------------------" << endl;
    cout << setw(10) << "���" << setw(15) << "��Ʒ��"
        << setw(10) << "����" << setw(15) << "���" << endl;

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
    cout << "������Ҫ�޸ĵļ�¼���(0ȡ��): ";
    cin >> choice;

    if (choice == 0) 
        return;
    if (choice < 1 || choice > static_cast<int>(salesRecords.size())) 
    {
        cout << "��Ч��ѡ��!" << endl;
        return;
    }

    SalesRecord& record = salesRecords[choice - 1];
    cout << "��ǰ��Ϣ: " << endl;
    cout << "��Ʒ��: " << record.productId << endl;
    cout << "����: " << record.quantity << endl;
    cout << "����: " << record.salesDate << endl;
    cout << "Ա����: " << record.employeeId << endl;

    cout << "�������µĲ�Ʒ��(ֱ�ӻس�����ԭֵ): ";
    cin.ignore();
    string newPid;
    getline(cin, newPid);
    if (!newPid.empty()) 
    {
        // ��֤�²�Ʒ�Ƿ����
        bool productExists = any_of(products.begin(), products.end(),
            [&newPid](const Product& p) { return p.productId == newPid; });
        if (productExists) 
        {
            record.productId = newPid;
        }
        else 
        {
            cout << "��Ʒ�����ڣ�����ԭֵ" << endl;
        }
    }

    cout << "�������µ�����(ֱ�ӻس�����ԭֵ): ";
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
                cout << "�����������0������ԭֵ" << endl;
            }
        }
        catch (...) 
        {
            cout << "��Ч�����룬����ԭֵ" << endl;
        }
    }

    cout << "�������µ�����(ֱ�ӻس�����ԭֵ): ";
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
            cout << "���ڸ�ʽӦΪYYYY-MM-DD������ԭֵ" << endl;
        }
    }

    cout << "���ۼ�¼�޸ĳɹ�!" << endl;
}

void SalesManagementSystem::deleteSalesRecord() 
{
    viewSalesRecordsByEmployeeAndDate();

    if (salesRecords.empty()) 
        return;

    int choice;
    cout << "������Ҫɾ���ļ�¼���(0ȡ��): ";
    cin >> choice;

    if (choice == 0) 
        return;
    if (choice < 1 || choice > static_cast<int>(salesRecords.size())) {
        cout << "��Ч��ѡ��!" << endl;
        return;
    }

    salesRecords.erase(salesRecords.begin() + choice - 1);
    cout << "���ۼ�¼ɾ���ɹ�!" << endl;
}

// ==================== ͳ�Ʊ��� ====================

void SalesManagementSystem::productSalesReportByMonth() {
    string month;
    cout << "�������·�(YYYY-MM): ";
    cin >> month;

    if (month.length() != 7 || month[4] != '-') {
        cout << "������·ݸ�ʽ��ӦΪYYYY-MM" << endl;
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
        cout << "���������ۼ�¼!" << endl;
        return;
    }

    // ת��Ϊvector������
    vector<pair<string, pair<int, double>>> sortedProducts(
        productStats.begin(), productStats.end());
    sort(sortedProducts.begin(), sortedProducts.end(),
        [](const auto& a, const auto& b) { return a.second.second > b.second.second; });

    // ��ӡ����
    cout << "\n===== ��Ʒ�����±��� (" << month << ") =====" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "|                                                |" << endl;
    cout << setw(15) << "��Ʒ��" << setw(20) << "��Ʒ����"
        << setw(10) << "����" << setw(15) << "���۽��" << endl;
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
    cout << "�������·�(YYYY-MM): ";
    cin >> month;

    if (month.length() != 7 || month[4] != '-') 
    {
        cout << "������·ݸ�ʽ��ӦΪYYYY-MM" << endl;
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
        cout << "���������ۼ�¼!" << endl;
        return;
    }

    // ת��Ϊvector������
    vector<pair<string, double>> sortedEmployees(
        employeeStats.begin(), employeeStats.end());
    sort(sortedEmployees.begin(), sortedEmployees.end(),
        [](const auto& a, const auto& b) { return a.second > b.second; });

    // ��ӡ����
    cout << "\n===== Ա�������±��� (" << month << ") =====" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "|                                            |" << endl;
    cout << setw(10) << "Ա����" << setw(15) << "Ա������"
        << setw(15) << "���۽��" << endl;
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
    cout << "������Ա����: ";
    cin >> eid;

    // ���Ա���Ƿ����
    auto employeeIt = find_if(salesPeople.begin(), salesPeople.end(),
        [&eid](const SalesPerson& sp) { return sp.employeeId == eid; });

    if (employeeIt == salesPeople.end()) {
        cout << "Ա��������!" << endl;
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
        cout << "��Ա�������ۼ�¼!" << endl;
        return;
    }

    // ת��Ϊvector�����·�����
    vector<pair<string, double>> sortedMonths(
        monthlyStats.begin(), monthlyStats.end());
    sort(sortedMonths.begin(), sortedMonths.end());

    // ��ӡ����
    cout << "\n===== Ա���¶����۱��� (" << employeeIt->name << ") =====" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "|                                            |" << endl;
    cout << setw(10) << "�·�" << setw(15) << "Ա����"
        << setw(15) << "���۽��" << endl;
    cout << "|                                            |" << endl;
    cout << "---------------------------------------------" << endl;

    for (const auto& item : sortedMonths) {
        cout << setw(10) << item.first << setw(15) << eid
            << setw(15) << fixed << setprecision(2) << item.second << endl;
    }
    cout << "---------------------------------------------" << endl;
}