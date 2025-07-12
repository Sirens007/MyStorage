#include "sales_system.h"

// SalesPerson ��ʵ��
SalesPerson::SalesPerson(std::string id, std::string n, std::string g, std::string bd)
    : employeeId(id)
    , name(n)
    , gender(g)
    , birthDate(bd) 
{}

// Product ��ʵ��
Product::Product(std::string id, std::string n, std::string t, double p)
    : productId(id)
    , name(n)
    , type(t)
    , price(p) 
{}

// SalesRecord ��ʵ��
SalesRecord::SalesRecord(std::string pid, int q, std::string sd, std::string eid)
    : productId(pid)
    , quantity(q)
    , salesDate(sd)
    , employeeId(eid) 
{}