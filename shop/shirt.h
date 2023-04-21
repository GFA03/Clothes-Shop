//
// Created by gfa on 4/19/23.
//

#ifndef CLOTHES_SHOP_SHIRT_H
#define CLOTHES_SHOP_SHIRT_H

#include "product.h"


class Shirt : virtual public Product{
    static int shirtCount;
    const int shirtId;
protected:
    std::string sleeveLength; // long or short
    std::string pattern;
public:
    Shirt(std::string gender = "Unisex", std::string color = "Unknown", std::string size = "U", std::string material = "Unknown", float price = 0.0, std::string fit = "Unknown", std::string sleeveLength = "Unknown", std::string pattern = "Unknown");
    Shirt(const Shirt& obj);
    Shirt& operator=(const Shirt& obj);
    void read(std::istream& in);
    void print(std::ostream& out) const;
    friend std::istream& operator>>(std::istream& in, Shirt& obj);
    friend std::ostream& operator<<(std::ostream& out, const Shirt& obj);
    virtual ~Shirt();
};

inline int Shirt::shirtCount = 100;

#endif //CLOTHES_SHOP_SHIRT_H
