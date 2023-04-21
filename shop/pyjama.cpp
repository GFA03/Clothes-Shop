//
// Created by gfa on 4/20/23.
//
#include "pyjama.h"

//
// Created by gfa on 4/20/23.
//

#include "pyjama.h"
#include <algorithm>

Pyjama::Pyjama(std::string gender, std::string color, std::string size, std::string material, float price, std::string fit, std::string sleeveLength, std::string pattern, std::string length, std::string style, std::string season):pyjamaId(pyjamaCount++),Product(gender, color, size, material, price, fit), Shirt(gender, color, size, material, price, fit, sleeveLength, pattern), Pants(gender, color, size, material, price, fit, length, style){
    this->season = season;
}

Pyjama::Pyjama(const Pyjama& obj):pyjamaId(pyjamaCount++),Product(obj), Shirt(obj), Pants(obj){
    this->season = obj.season;
}

Pyjama& Pyjama::operator=(const Pyjama& obj){
    if(this != &obj){
        Shirt::operator=(obj);
        Pants::operator=(obj);
        this->season = obj.season;
    }
    return *this;
}

std::string toLowercase(const std::string& word){
    std::string temp;
    for(auto c: word)
        temp.push_back(std::tolower(c));
    return temp;
}

void Pyjama::read(std::istream& in){
    std::cout << ANSI_COLOR_BLUE"Pyjama" << ANSI_COLOR_RESET << "\n";
    Product::read(in);
    std::cout << R"(Insert product pattern(i.e "Stripes", "Checks", "Multiple", "Simple"): )";
    std::getline(in, this->pattern);
    this->style = "Pyjama";
    std::cout << R"(Insert product season(i.e "Summer", "Winter"): )";
    std::getline(in, this->season);
    if(toLowercase(this->season) == "summer"){
        this->sleeveLength = "Short";
        this->length = "Short";
    }else{
        this->sleeveLength = "Long";
        this->length = "Long";
    }
}

void Pyjama::print(std::ostream& out) const{
    out << ANSI_COLOR_BLUE"Pyjama" << ANSI_COLOR_RESET << "\n";
    out << "Id: " << ANSI_COLOR_RED << this->pyjamaId << ANSI_COLOR_RESET << '\n';
    Product::print(out);
    out << "Sleeve length: " << ANSI_COLOR_MAGENTA << this->sleeveLength << ANSI_COLOR_RESET << "\n";
    out << "Pattern: " << ANSI_COLOR_MAGENTA << this->pattern << ANSI_COLOR_RESET << "\n";
    out << "Length: " << ANSI_COLOR_MAGENTA << this->length << ANSI_COLOR_RESET << "\n";
    out << "Style: " << ANSI_COLOR_MAGENTA << this->style << ANSI_COLOR_RESET << "\n";
    out << "Season: " << ANSI_COLOR_MAGENTA << this->season << ANSI_COLOR_RESET << "\n";
}

std::istream& operator>>(std::istream& in, Pyjama& obj){
    obj.read(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Pyjama& obj){
    obj.print(out);
    return out;
}

Pyjama::~Pyjama()= default;
