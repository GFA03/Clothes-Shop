//
// Created by gfa on 4/19/23.
//

#include "product.h"

std::string generateBarCode(){
    std::random_device rd;
    static const std::string AlphaNumeric = "0123456789A!BC@D?E#F$GHIJ%KLMNO&PQRSTUV*WXYZabcdefghijklmnopqrstuvwxyz";
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0, AlphaNumeric.size());
    std::string random;
    for(int i = 0; i < 10; ++i)
        random.push_back(AlphaNumeric[dist(mt)]);
    return random;
}

Product::Product(std::string gender, std::string color, std::string size, std::string material, float price, std::string fit):productId(productCount++){
    this->gender = gender;
    this->color = color;
    this->size = size;
    this->material = material;
    this->price = price;
    this->fit = fit;
    this->barCode = generateBarCode();
}

Product::Product(const Product& obj):productId(productCount++){
    this->gender = obj.gender;
    this->color = obj.color;
    this->size = obj.size;
    this->material = obj.material;
    this->price = obj.price;
    this->fit = obj.fit;
    this->barCode = obj.barCode;
}

Product& Product::operator=(const Product& obj){
    if(this != &obj){
        this->gender = obj.gender;
        this->color = obj.color;
        this->size = obj.size;
        this->material = obj.material;
        this->price = obj.price;
        this->fit = obj.fit;
        this->barCode = obj.barCode;
    }
    return *this;
}

void Product::read(std::istream& in){
    std::cout << "Insert product gender: ";
    in.get();
    std::getline(in, this->gender);
    std::cout << "Insert product color: ";
    std::getline(in, this->color);
    std::cout << R"(Insert product size(i.e "S", "M", "L", "XL" etc): )";
    in >> this->size;
    std::cout << "Insert product material: ";
    in.get();
    std::getline(in, this->material);
    std::cout << "Insert product price: ";
    in >> this->price;
    std::cout << R"(Insert product fit(i.e: "Slim fit", "Regular fit", "Large fit"): )";
    in.get();
    std::getline(in, this->fit);
}

void Product::print(std::ostream& out) const{
    out << "Product id: " << ANSI_COLOR_MAGENTA << this->productId << ANSI_COLOR_RESET << '\n';
    out << "Gender: " << ANSI_COLOR_MAGENTA << this->gender << ANSI_COLOR_RESET << '\n';
    out << "Color: " << ANSI_COLOR_MAGENTA << this->color << ANSI_COLOR_RESET << '\n';
    out << "Size: " << ANSI_COLOR_MAGENTA << this->size << ANSI_COLOR_RESET << '\n';
    out << "Material: " << ANSI_COLOR_MAGENTA << this->material << ANSI_COLOR_RESET << '\n';
    out << "Price: " << ANSI_COLOR_MAGENTA << this->price << ANSI_COLOR_RESET << '\n';
    out << "Type of fit: " << ANSI_COLOR_MAGENTA << this->fit << ANSI_COLOR_RESET << "\n";
    out << "Barcode: " << ANSI_COLOR_GREEN << this->barCode << ANSI_COLOR_RESET << "\n";
}

std::istream& operator>>(std::istream& in, Product& obj){
    obj.read(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Product& obj){
    obj.print(out);
    return out;
}

Product::~Product(){}

std::string Product::getBarCode() const {
    return this->barCode;
}