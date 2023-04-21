//
// Created by gfa on 4/20/23.
//

#include "pants.h"

Pants::Pants(std::string gender, std::string color, std::string size, std::string material, float price, std::string fit, std::string length, std::string style):pantsId(pantsCount++),Product(gender, color, size, material, price, fit){
    this->length = length;
    this->style = style;
}

Pants::Pants(const Pants& obj):pantsId(pantsCount++),Product(obj){
    this->length = obj.length;
    this->style = obj.style;
}

Pants& Pants::operator=(const Pants& obj){
    if(this != &obj){
        Product::operator=(obj);
        this->length = obj.length;
        this->style = obj.style;
    }
    return *this;
}

void Pants::read(std::istream& in){
    std::cout << ANSI_COLOR_BLUE"Pants" << ANSI_COLOR_RESET << "\n";
    Product::read(in);
    std::cout << R"(Insert product length(i.e "Long", "Short"): )";
    std::getline(in, this->length);
    std::cout << R"(Insert product style(i.e "Dress", "Jeans", "Sweat" etc): )";
    std::getline(in, this->style);
}

void Pants::print(std::ostream& out) const{
    out << ANSI_COLOR_BLUE"Pants" << ANSI_COLOR_RESET << "\n";
    out << "Id: " << ANSI_COLOR_RED << this->pantsId << ANSI_COLOR_RESET << '\n';
    Product::print(out);
    out << "Length: " << ANSI_COLOR_MAGENTA << this->length << ANSI_COLOR_RESET << "\n";
    out << "Style: " << ANSI_COLOR_MAGENTA << this->style << ANSI_COLOR_RESET << "\n";
}

std::istream& operator>>(std::istream& in, Pants& obj){
    obj.read(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Pants& obj){
    obj.print(out);
    return out;
}

Pants::~Pants(){}
