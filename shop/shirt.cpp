//
// Created by gfa on 4/20/23.
//

#include "shirt.h"

Shirt::Shirt(std::string gender, std::string color, std::string size, std::string material, float price, std::string fit, std::string sleeveLength, std::string pattern):shirtId(shirtCount++),Product(gender, color, size, material, price, fit){
    this->sleeveLength = sleeveLength;
    this->pattern = pattern;
}

Shirt::Shirt(const Shirt& obj):shirtId(shirtCount++),Product(obj){
    this->sleeveLength = obj.sleeveLength;
    this->pattern = obj.pattern;
}

Shirt& Shirt::operator=(const Shirt& obj){
    if(this != &obj){
        Product::operator=(obj);
        this->sleeveLength = obj.sleeveLength;
        this->pattern = obj.pattern;
    }
    return *this;
}

void Shirt::read(std::istream& in){
    std::cout << ANSI_COLOR_BLUE"SHIRT" << ANSI_COLOR_RESET << "\n";
    Product::read(in);
    std::cout << R"(Insert product sleeve length(i.e "Long", "Short"): )";
    std::getline(in, this->sleeveLength);
    std::cout << R"(Insert product pattern(i.e "Stripes", "Checks", "Multiple", "Simple"): )";
    std::getline(in, this->pattern);
}

void Shirt::print(std::ostream& out) const{
    out << ANSI_COLOR_BLUE"SHIRT" << ANSI_COLOR_RESET << "\n";
    out << "Id: " << ANSI_COLOR_RED << this->shirtId << ANSI_COLOR_RESET << '\n';
    Product::print(out);
    out << "Sleeve length: " << ANSI_COLOR_MAGENTA << this->sleeveLength << ANSI_COLOR_RESET << "\n";
    out << "Pattern: " << ANSI_COLOR_MAGENTA << this->pattern << ANSI_COLOR_RESET << "\n";
}

std::istream& operator>>(std::istream& in, Shirt& obj){
    obj.read(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Shirt& obj){
    obj.print(out);
    return out;
}

Shirt::~Shirt(){}