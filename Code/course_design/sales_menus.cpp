#include "sales_system.h"
#include <iostream>

using namespace std;

// ��ʾ���˵�
void SalesManagementSystem::showMainMenu() {
    cout << "____________________________" << endl;
    cout << "\n==== ������Ϣ����ϵͳ ====" << endl;
    cout << "|  " << "--1. ������Ա����" << endl;
    cout << "|  " << "--2. ��Ʒ����" << endl;
    cout << "|  " << "--3. ���ۼ�¼����" << endl;
    cout << "|  " << "--4. ͳ�Ʊ���" << endl;
    cout << "|  " << "--0. �˳�ϵͳ" << endl;
    cout << "|  " << "--��ѡ��";
}

// ��ʾ������Ա����˵�
void SalesManagementSystem::showSalesPersonMenu() {
    cout << "____________________________" << endl;
    cout << "\n==== ������Ա���� ====" << endl;
    cout << "|  " << "--1. ���������Ա" << endl;
    cout << "|  " << "--2. ɾ��������Ա" << endl;
    cout << "|  " << "--3. �޸�������Ա��Ϣ" << endl;
    cout << "|  " << "--4. ��ѯ������Ա��Ϣ" << endl;
    cout << "|  " << "--0. �������˵�" << endl;
    cout << "|  " << "--��ѡ��: ";
}

// ��ʾ��Ʒ����˵�
void SalesManagementSystem::showProductMenu() {
    cout << "____________________________" << endl;
    cout << "\n==== ��Ʒ���� ====" << endl;
    cout << "|  " << "--1. ��Ӳ�Ʒ" << endl;
    cout << "|  " << "--2. ɾ����Ʒ" << endl;
    cout << "|  " << "--3. �޸Ĳ�Ʒ��Ϣ" << endl;
    cout << "|  " << "--4. ��ѯ��Ʒ��Ϣ" << endl;
    cout << "|  " << "--0. �������˵�" << endl;
    cout << "|  " << "--��ѡ��: ";
}

// ��ʾ���ۼ�¼����˵�
void SalesManagementSystem::showSalesRecordMenu() {
    cout << "\n==== ���ۼ�¼���� ====" << endl;
    cout << "|  " << "--1. ������ۼ�¼" << endl;
    cout << "|  " << "--2. �鿴���ۼ�¼" << endl;
    cout << "|  " << "--3. �޸����ۼ�¼" << endl;
    cout << "|  " << "--4. ɾ�����ۼ�¼" << endl;
    cout << "|  " << "--0. �������˵�" << endl;
    cout << "|  " << "--��ѡ��: ";
}

// ��ʾͳ�Ʊ���˵�
void SalesManagementSystem::showReportMenu() {
    cout << "\n==== ͳ�Ʊ��� ====" << endl;
    cout << "|  " << "--1. ��Ʒ�¶�����ͳ��" << endl;
    cout << "|  " << "--2. Ա���¶�����ͳ��" << endl;
    cout << "|  " << "--3. Ա����������ͳ��" << endl;
    cout << "|  " << "--0. �������˵�" << endl;
    cout << "|  " << "--��ѡ��: ";
}