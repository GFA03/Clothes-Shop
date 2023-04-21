//
// Created by gfa on 4/20/23.
//

#ifndef CLOTHES_SHOP_PANTS_H
#define CLOTHES_SHOP_PANTS_H

#include "product.h"

class Pants : virtual public Product{
    static int pantsCount;
    const int pantsId;
protected:
    std::string length; // long or short
    std::string style; // dress pants, jeans, sweat pants
public:
    Pants(std::string gender = "Unisex", std::string color = "Unknown", std::string size = "U", std::string material = "Unknown", float price = 0.0, std::string fit = "Unknown", std::string length = "Unknown", std::string style = "Unknown");
    Pants(const Pants& obj);
    Pants& operator=(const Pants& obj);
    void read(std::istream& in);
    void print(std::ostream& out) const;
    friend std::istream& operator>>(std::istream& in, Pants& obj);
    friend std::ostream& operator<<(std::ostream& out, const Pants& obj);
    virtual ~Pants();
};

inline int Pants::pantsCount = 1000;

#endif //CLOTHES_SHOP_PANTS_H
