#ifndef SALES_SYSTEM_H
#define SALES_SYSTEM_H

#include <vector>
#include <string>
#include <map>

// ������Ա��
class SalesPerson {
public:
    std::string employeeId;
    std::string name;
    std::string gender;
    std::string birthDate;

    // ���캯��
    SalesPerson(std::string id, std::string n, std::string g, std::string bd);
};

// ��Ʒ��
class Product {
public:
    std::string productId;
    std::string name;
    std::string type;
    double price;

    // ���캯��
    Product(std::string id, std::string n, std::string t, double p);
};

// ���ۼ�¼��
class SalesRecord {
public:
    std::string productId;
    int quantity;
    std::string salesDate;
    std::string employeeId;

    // ���캯��
    SalesRecord(std::string pid, int q, std::string sd, std::string eid);
};

// ���۹���ϵͳ��
class SalesManagementSystem {
private:
    std::vector<SalesPerson> salesPeople;
    std::vector<Product> products;
    std::vector<SalesRecord> salesRecords;

public:
    // ������Ա����
    void addSalesPerson();
    void deleteSalesPerson();
    void modifySalesPerson();
    void querySalesPerson();

    // ��Ʒ����
    void addProduct();
    void deleteProduct();
    void modifyProduct();
    void queryProduct();

    // ���ۼ�¼����
    void addSalesRecord();
    void viewSalesRecordsByEmployeeAndDate();
    void modifySalesRecord();
    void deleteSalesRecord();

    // ͳ�Ʊ���
    void productSalesReportByMonth();
    void employeeSalesReportByMonth();
    void employeeMonthlySalesReport();

    // �˵���ʾ
    void showMainMenu();
    void showSalesPersonMenu();
    void showProductMenu();
    void showSalesRecordMenu();
    void showReportMenu();

    // �����к���
    void run();
};

#endif#pragma once
