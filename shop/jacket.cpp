//
// Created by gfa on 4/20/23.
//

#include "jacket.h"

Jacket::Jacket(std::string gender, std::string color, std::string size, std::string material, float price, std::string fit, std::string style, std::string closureType):jacketId(jacketCount++),Product(gender, color, size, material, price, fit){
    this->style = style;
    this->closureType = closureType;
}

Jacket::Jacket(const Jacket& obj):jacketId(jacketCount++),Product(obj){
    this->style = obj.style;
    this->closureType = obj.closureType;
}

Jacket& Jacket::operator=(const Jacket& obj){
    if(this != &obj){
        Product::operator=(obj);
        this->style = obj.style;
        this->closureType = obj.closureType;
    }
    return *this;
}

void Jacket::read(std::istream& in){
    std::cout << ANSI_COLOR_BLUE"Jacket" << ANSI_COLOR_RESET << "\n\n";
    Product::read(in);
    std::cout << R"(Insert product style(i.e "Coat", "Blazer", "Windbreaker"): )";
    std::getline(in, this->style);
    std::cout << R"(Insert product closure type(i.e "Button", "Zipper", "Snap"): )";
    std::getline(in, this->closureType);
}

void Jacket::print(std::ostream& out) const{
    out << ANSI_COLOR_BLUE"Jacket" << ANSI_COLOR_RESET << "\n\n";
    out << "Id: " << ANSI_COLOR_RED << this->jacketId << ANSI_COLOR_RESET << '\n';
    Product::print(out);
    out << "Style: " << ANSI_COLOR_MAGENTA << this->style << ANSI_COLOR_RESET << "\n";
    out << "Closure type: " << ANSI_COLOR_MAGENTA << this->closureType << ANSI_COLOR_RESET << "\n";
}

std::istream& operator>>(std::istream& in, Jacket& obj){
    obj.read(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Jacket& obj){
    obj.print(out);
    return out;
}

Jacket::~Jacket(){}
