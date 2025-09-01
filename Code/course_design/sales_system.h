#ifndef SALES_SYSTEM_H
#define SALES_SYSTEM_H

#include <vector>
#include <string>
#include <map>

// 销售人员类
class SalesPerson {
public:
    std::string employeeId;
    std::string name;
    std::string gender;
    std::string birthDate;

    // 构造函数
    SalesPerson(std::string id, std::string n, std::string g, std::string bd);
};

// 产品类
class Product {
public:
    std::string productId;
    std::string name;
    std::string type;
    double price;

    // 构造函数
    Product(std::string id, std::string n, std::string t, double p);
};

// 销售记录类
class SalesRecord {
public:
    std::string productId;
    int quantity;
    std::string salesDate;
    std::string employeeId;

    // 构造函数
    SalesRecord(std::string pid, int q, std::string sd, std::string eid);
};

// 销售管理系统类
class SalesManagementSystem {
private:
    std::vector<SalesPerson> salesPeople;
    std::vector<Product> products;
    std::vector<SalesRecord> salesRecords;

public:
    // 销售人员管理
    void addSalesPerson();
    void deleteSalesPerson();
    void modifySalesPerson();
    void querySalesPerson();

    // 产品管理
    void addProduct();
    void deleteProduct();
    void modifyProduct();
    void queryProduct();

    // 销售记录管理
    void addSalesRecord();
    void viewSalesRecordsByEmployeeAndDate();
    void modifySalesRecord();
    void deleteSalesRecord();

    // 统计报表
    void productSalesReportByMonth();
    void employeeSalesReportByMonth();
    void employeeMonthlySalesReport();

    // 菜单显示
    void showMainMenu();
    void showSalesPersonMenu();
    void showProductMenu();
    void showSalesRecordMenu();
    void showReportMenu();

    // 主运行函数
    void run();
};

#endif#pragma once
