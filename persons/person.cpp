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

std::istream& Person::read(std::istream& in){
    std::cout << "Insert name: ";
    std::getline(in, this->name);
    std::cout << "Insert age: ";
    in >> this->age;
    return in;
}

std::ostream& Person::print(std::ostream& out) const{
    out << "Name: " << this->name << std::endl;
    out << "Age: " << this->age << std::endl;
    return out;
}


std::istream& operator>>(std::istream& in, Person& obj){
    return obj.read(in);
}

std::ostream& operator<<(std::ostream& out, const Person& obj){
    return obj.print(out);
}

Person::~Person(){
    this->age = 0;
}