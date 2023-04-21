//
// Created by gfa on 4/20/23.
//

#ifndef CLOTHES_SHOP_JACKET_H
#define CLOTHES_SHOP_JACKET_H

#include "product.h"

class Jacket : public Product{
    static int jacketCount;
    const int jacketId;

    std::string style; // long or short
    std::string closureType;
public:
    Jacket(std::string gender = "Unknown", std::string color = "Unknown", std::string size = "U", std::string material = "Unknown", float price = 0.0, std::string fit = "Unknown", std::string style = "Unknown", std::string closureType = "Unknown");
    Jacket(const Jacket& obj);
    Jacket& operator=(const Jacket& obj);
    void read(std::istream& in);
    void print(std::ostream& out) const;
    friend std::istream& operator>>(std::istream& in, Jacket& obj);
    friend std::ostream& operator<<(std::ostream& out, const Jacket& obj);
    ~Jacket();
};

inline int Jacket::jacketCount = 10000;

#endif //CLOTHES_SHOP_JACKET_H
