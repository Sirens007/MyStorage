#include "sales_system.h"

// SalesPerson 类实现
SalesPerson::SalesPerson(std::string id, std::string n, std::string g, std::string bd)
    : employeeId(id)
    , name(n)
    , gender(g)
    , birthDate(bd) 
{}

// Product 类实现
Product::Product(std::string id, std::string n, std::string t, double p)
    : productId(id)
    , name(n)
    , type(t)
    , price(p) 
{}

// SalesRecord 类实现
SalesRecord::SalesRecord(std::string pid, int q, std::string sd, std::string eid)
    : productId(pid)
    , quantity(q)
    , salesDate(sd)
    , employeeId(eid) 
{}