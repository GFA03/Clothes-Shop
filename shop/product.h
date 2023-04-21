//
// Created by gfa on 4/17/23.
//

#ifndef CLOTHES_SHOP_PRODUCT_H
#define CLOTHES_SHOP_PRODUCT_H

#include <string>
#include <iostream>
#include <random>
#include "../IOInterface.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

class Product: IOInterface{
    static int productCount;
    const int productId;

    std::string gender;
    std::string color;
    std::string size;
    std::string material;
    float price;
    std::string fit; // Slim fit or Regular fit

    std::string barCode;
public:
    explicit Product(std::string gender = "Unisex", std::string color = "Unknown", std::string size = "U", std::string material = "Unknown", float price = 0.0, std::string fit = "Unknown");
    Product(const Product& obj);
    Product& operator=(const Product& obj);
    void read(std::istream& in) override;
    void print(std::ostream& out) const override;
    friend std::istream& operator>>(std::istream& in, Product& obj);
    friend std::ostream& operator<<(std::ostream& out, const Product& obj);
    virtual ~Product();

    std::string getBarCode() const;
    float getPrice() const;
};

inline int Product::productCount = 10;

#endif //CLOTHES_SHOP_PRODUCT_H
