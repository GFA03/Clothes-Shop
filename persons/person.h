//
// Created by gfa on 4/17/23.
//

#ifndef CLOTHES_SHOP_PERSON_H
#define CLOTHES_SHOP_PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

class IOInterface{
public:
    virtual std::istream& read(std::istream& in) = 0;
    virtual std::ostream& print(std::ostream& out) const = 0;
};

class Person : public IOInterface{
    static int personCount;
    const int personId;
    std::string name;
    int age;
public:
    Person(std::string name = "Unknown", int age = 0);
    Person(const Person& other);
    Person& operator=(const Person& other);
    std::istream& read(std::istream& in);
    std::ostream& print(std::ostream& out) const;
    friend std::istream& operator>>(std::istream& in, Person& obj);
    friend std::ostream& operator<<(std::ostream& out, const Person& obj);
    virtual ~Person();
};

inline int Person::personCount = 10;

#endif //CLOTHES_SHOP_PERSON_H