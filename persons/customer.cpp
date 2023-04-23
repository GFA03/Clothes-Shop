//
// Created by gfa on 4/17/23.
//

#include "customer.h"

Customer::Customer(std::string name, int age, int discountPoints, std::vector<Product*> purchaseHistory):customerId(customerCount++), Person(name, age){
    this->discountPoints = discountPoints;
    this->purchaseHistory = purchaseHistory;
}

Customer::Customer(const Customer& other):customerId(customerCount++), Person(other){
    this->discountPoints = other.discountPoints;
    this->purchaseHistory = other.purchaseHistory;
}

Customer& Customer::operator=(const Customer& other){
    if(this != &other){
        Person::operator=(other);
        this->discountPoints = other.discountPoints;
        this-> purchaseHistory = other.purchaseHistory;
    }
    return *this;
}

void Customer::read(std::istream& in){
    this->Person::read(in);
    std::cout << "Insert discount points: ";
    in >> this->discountPoints;
}

void Customer::print(std::ostream& out) const{
    out << "Customer id: " << this->customerId << '\n';
    this->Person::print(out);
    out << "Discount points: " << this->discountPoints << std::endl;
    if(!this->purchaseHistory.empty())
    {
        out << "Purchase history:";
        for(const auto& i : this->purchaseHistory)
            out << '\n' << *i << '\n';
        out << std::endl;
    }
}

std::istream& operator>>(std::istream& in, Customer& obj)
{
    obj.read(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Customer& obj)
{
    obj.print(out);
    return out;
}

Customer::~Customer(){
    this->purchaseHistory.clear();
}

int Customer::getCustomerId() const {return this->customerId;}

float Customer::getDiscountPoints() {
    return this->discountPoints;
}

void Customer::setDiscountPoints(int discountPoints) {this->discountPoints = discountPoints;}

void Customer::addProduct(Product* product) {
    this->purchaseHistory.push_back(product);
}
