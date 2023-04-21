//
// Created by gfa on 4/17/23.
//

#include "employee.h"

Employee::Employee(std::string name, int age, std::string jobTitle):employeeId(employeeCount++), Person(name, age){
    this->jobTitle = jobTitle;
}

Employee::Employee(const Employee &obj):employeeId(employeeCount++), Person(obj){
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

void Employee::read(std::istream &in) {
    Person::read(in);
    std::cout << "Insert job title: ";
    in.get();
    std::getline(in, this->jobTitle);
}

void Employee::print(std::ostream &out) const{
    out << "Employee id: " << this->employeeId << '\n';
    Person::print(out);
    out << "Job title: " << this->jobTitle << '\n';
}

std::istream& operator>>(std::istream& in, Employee& obj){
    obj.read(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Employee& obj){
    obj.print(out);
    return out;
}

Employee::~Employee(){}

int Employee::getEmployeeId() const{return this->employeeId;}

void Employee::setJobTitle(std::string jobTitle){this->jobTitle = jobTitle;}