//
// Created by gfa on 4/17/23.
//

#ifndef CLOTHES_SHOP_EMPLOYEE_H
#define CLOTHES_SHOP_EMPLOYEE_H

#include "person.h"

class Employee : public Person{
    const int employeeId;
    static int employeeCount;
    std::string jobTitle;
public:
    Employee(std::string name = "Unknown", int age = 0, std::string jobTitle = "Unknown");
    Employee(const Employee& obj);
    Employee& operator=(const Employee& obj);
    std::ostream& print(std::ostream& out) const;
    std::istream& read(std::istream& in);
    friend std::istream& operator>>(std::istream& in, Employee& obj);
    friend std::ostream& operator<<(std::ostream& out, const Employee& obj);
    ~Employee();
};

#endif //CLOTHES_SHOP_EMPLOYEE_H
