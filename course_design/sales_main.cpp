#include "sales_system.h"
#include <iostream>

using namespace std;

// 主运行函数
void SalesManagementSystem::run() {
    int choice;
    do {
        showMainMenu();
        cin >> choice;

        switch (choice) {
        case 1: // 销售人员管理
        {
            int subChoice;
            do {
                showSalesPersonMenu();
                cin >> subChoice;
                switch (subChoice) {
                case 1: addSalesPerson(); break;
                case 2: deleteSalesPerson(); break;
                case 3: modifySalesPerson(); break;
                case 4: querySalesPerson(); break;
                case 0: break;
                default: cout << "无效的选择!" << endl;
                }
            } while (subChoice != 0);
        }
        break;
        case 2: // 产品管理
        {
            int subChoice;
            do {
                showProductMenu();
                cin >> subChoice;
                switch (subChoice) {
                case 1: addProduct(); break;
                case 2: deleteProduct(); break;
                case 3: modifyProduct(); break;
                case 4: queryProduct(); break;
                case 0: break;
                default: cout << "无效的选择!" << endl;
                }
            } while (subChoice != 0);
        }
        break;
        case 3: // 销售记录管理
        {
            int subChoice;
            do {
                showSalesRecordMenu();
                cin >> subChoice;
                switch (subChoice) {
                case 1: addSalesRecord(); break;
                case 2: viewSalesRecordsByEmployeeAndDate(); break;
                case 3: modifySalesRecord(); break;
                case 4: deleteSalesRecord(); break;
                case 0: break;
                default: cout << "无效的选择!" << endl;
                }
            } while (subChoice != 0);
        }
        break;
        case 4: // 统计报表
        {
            int subChoice;
            do {
                showReportMenu();
                cin >> subChoice;
                switch (subChoice) {
                case 1: productSalesReportByMonth(); break;
                case 2: employeeSalesReportByMonth(); break;
                case 3: employeeMonthlySalesReport(); break;
                case 0: break;
                default: cout << "无效的选择!" << endl;
                }
            } while (subChoice != 0);
        }
        break;
        case 0:
            cout << "感谢使用销售信息管理系统，再见!" << endl;
            break;
        default:
            cout << "无效的选择!" << endl;
        }
    } while (choice != 0);
}

int main() {
    SalesManagementSystem system;
    system.run();
    return 0;
}