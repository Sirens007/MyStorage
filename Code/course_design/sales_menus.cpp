#include "sales_system.h"
#include <iostream>

using namespace std;

// 显示主菜单
void SalesManagementSystem::showMainMenu() {
    cout << "____________________________" << endl;
    cout << "\n==== 销售信息管理系统 ====" << endl;
    cout << "|  " << "--1. 销售人员管理" << endl;
    cout << "|  " << "--2. 产品管理" << endl;
    cout << "|  " << "--3. 销售记录管理" << endl;
    cout << "|  " << "--4. 统计报表" << endl;
    cout << "|  " << "--0. 退出系统" << endl;
    cout << "|  " << "--请选择：";
}

// 显示销售人员管理菜单
void SalesManagementSystem::showSalesPersonMenu() {
    cout << "____________________________" << endl;
    cout << "\n==== 销售人员管理 ====" << endl;
    cout << "|  " << "--1. 添加销售人员" << endl;
    cout << "|  " << "--2. 删除销售人员" << endl;
    cout << "|  " << "--3. 修改销售人员信息" << endl;
    cout << "|  " << "--4. 查询销售人员信息" << endl;
    cout << "|  " << "--0. 返回主菜单" << endl;
    cout << "|  " << "--请选择: ";
}

// 显示产品管理菜单
void SalesManagementSystem::showProductMenu() {
    cout << "____________________________" << endl;
    cout << "\n==== 产品管理 ====" << endl;
    cout << "|  " << "--1. 添加产品" << endl;
    cout << "|  " << "--2. 删除产品" << endl;
    cout << "|  " << "--3. 修改产品信息" << endl;
    cout << "|  " << "--4. 查询产品信息" << endl;
    cout << "|  " << "--0. 返回主菜单" << endl;
    cout << "|  " << "--请选择: ";
}

// 显示销售记录管理菜单
void SalesManagementSystem::showSalesRecordMenu() {
    cout << "\n==== 销售记录管理 ====" << endl;
    cout << "|  " << "--1. 添加销售记录" << endl;
    cout << "|  " << "--2. 查看销售记录" << endl;
    cout << "|  " << "--3. 修改销售记录" << endl;
    cout << "|  " << "--4. 删除销售记录" << endl;
    cout << "|  " << "--0. 返回主菜单" << endl;
    cout << "|  " << "--请选择: ";
}

// 显示统计报表菜单
void SalesManagementSystem::showReportMenu() {
    cout << "\n==== 统计报表 ====" << endl;
    cout << "|  " << "--1. 产品月度销售统计" << endl;
    cout << "|  " << "--2. 员工月度销售统计" << endl;
    cout << "|  " << "--3. 员工各月销售统计" << endl;
    cout << "|  " << "--0. 返回主菜单" << endl;
    cout << "|  " << "--请选择: ";
}