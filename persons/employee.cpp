//
// Created by gfa on 4/17/23.
//

#include "employee.h"

Employee::Employee(std::string name, int age, std::string jobTitle):employeeId(employeeCount), Person(name, age){
    this->jobTitle = jobTitle;
}

Employee::Employee(const Employee &obj):employeeId(employeeCount), Person(obj){
    this->jobTitle = obj.jobTitle;
}

Employee& Employee::operator=(const Employee &obj) {
    if(this != &obj)
    {
        Person::operator=(obj);
        this->jobTitle = obj.jobTitle;
    }
    return *this;
}

std::istream& Employee::read(std::istream &in) {
    Person::read(in);
    std::cout << "Insert job title: ";
    std::getline(in, this->jobTitle);
    return in;
}

std::ostream& Employee::print(std::ostream &out) const{
    Person::print(out);
    out << "Job title: " << this->jobTitle << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Employee& obj){
    return obj.read(in);
}

std::ostream& operator<<(std::ostream& out, const Employee& obj){
    return obj.print(out);
}

Employee::~Employee(){}