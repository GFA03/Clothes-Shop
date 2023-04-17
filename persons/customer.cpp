//
// Created by gfa on 4/17/23.
//

#include "customer.h"

Customer::Customer(std::string name, int age, int discountPoints, std::vector<std::string> purchaseHistory):customerId(customerCount++), Person(name, age){
    this->discountPoints = discountPoints;
    this-> purchaseHistory = purchaseHistory;
}

Customer::Customer(const Customer& other):customerId(customerCount++), Person(other){
    this->discountPoints = other.discountPoints;
    this-> purchaseHistory = other.purchaseHistory;
}

Customer& Customer::operator=(const Customer& other){
    if(this != &other){
        Person::operator=(other);
        this->discountPoints = other.discountPoints;
        this-> purchaseHistory = other.purchaseHistory;
    }
    return *this;
}

std::istream& Customer::read(std::istream& in){
    this->Person::read(in);
    std::cout << "Insert discount points: ";
    in >> this->discountPoints;
    return in;
}

std::ostream& Customer::print(std::ostream& out) const{
    this->Person::print(out);
    out << "Discount points: " << this->discountPoints << std::endl;
    if(!this->purchaseHistory.empty())
    {
        out << "Purchase history:";
        for(const auto & i : this->purchaseHistory)
            out << " " << i;
        out << std::endl;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Customer& obj)
{
    return obj.read(in);
}

std::ostream& operator<<(std::ostream& out, const Customer& obj)
{
    return obj.print(out);
}

Customer::~Customer(){
    this->purchaseHistory.clear();
}
