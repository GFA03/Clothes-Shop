//
// Created by gfa on 4/17/23.
//

#ifndef CLOTHES_SHOP_CUSTOMER_H
#define CLOTHES_SHOP_CUSTOMER_H

#include "person.h"
#include <iostream>
#include <string>
#include <vector>

class Customer: public Person{
    const int customerId;
    static int customerCount;

    int discountPoints;
    std::vector<std::string> purchaseHistory;
public:
    Customer(std::string name = "Unknown", int age = 0, int discountPoints = 0, std::vector<std::string> purchaseHistory = {});
    Customer(const Customer& other);
    Customer& operator=(const Customer& other);
    void read(std::istream& in);
    void print(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& out, const Customer& obj);
    friend std::istream& operator>>(std::istream&, Customer& obj);
    ~Customer();

    int getCustomerId() const;

    void setDiscountPoints(int discountPoints);
};

inline int Customer::customerCount = 100;

#endif //CLOTHES_SHOP_CUSTOMER_H
