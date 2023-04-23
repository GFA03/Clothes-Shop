//
// Created by gfa on 4/17/23.
//

#include "person.h"

Person::Person(std::string name, int age):personId(personCount++){
    this->name = name;
    this->age = age;
}

Person::Person(const Person& other):personId(personCount++){
    this->name = other.name;
    this->age = other.age;
}

Person& Person::operator=(const Person& other){
    if(this != &other){
        this->name = other.name;
        this->age = other.age;
    }
    return *this;
}

void Person::read(std::istream& in){
    std::cout << "Insert name: ";
    in.get();
    std::getline(in, this->name);
    std::cout << "Insert age: ";
    in >> this->age;
}

void Person::print(std::ostream& out) const{
    out << "Id: " << this->personId << '\n';
    out << "Name: " << this->name << std::endl;
    out << "Age: " << this->age << std::endl;
}


std::istream& operator>>(std::istream& in, Person& obj){
    obj.read(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Person& obj){
    obj.print(out);
    return out;
}

Person::~Person(){
    this->age = 0;
}

std::string Person::getName() const{return this->name;}

void Person::setName(std::string name){this->name = name;}
void Person::setAge(int age){this->age = age;}
