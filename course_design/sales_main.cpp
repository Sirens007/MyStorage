#include "sales_system.h"
#include <iostream>

using namespace std;

// �����к���
void SalesManagementSystem::run() {
    int choice;
    do {
        showMainMenu();
        cin >> choice;

        switch (choice) {
        case 1: // ������Ա����
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
                default: cout << "��Ч��ѡ��!" << endl;
                }
            } while (subChoice != 0);
        }
        break;
        case 2: // ��Ʒ����
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
                default: cout << "��Ч��ѡ��!" << endl;
                }
            } while (subChoice != 0);
        }
        break;
        case 3: // ���ۼ�¼����
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
                default: cout << "��Ч��ѡ��!" << endl;
                }
            } while (subChoice != 0);
        }
        break;
        case 4: // ͳ�Ʊ���
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
                default: cout << "��Ч��ѡ��!" << endl;
                }
            } while (subChoice != 0);
        }
        break;
        case 0:
            cout << "��лʹ��������Ϣ����ϵͳ���ټ�!" << endl;
            break;
        default:
            cout << "��Ч��ѡ��!" << endl;
        }
    } while (choice != 0);
}

int main() {
    SalesManagementSystem system;
    system.run();
    return 0;
}