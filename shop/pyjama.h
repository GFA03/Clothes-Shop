//
// Created by gfa on 4/20/23.
//

#ifndef CLOTHES_SHOP_PYJAMA_H
#define CLOTHES_SHOP_PYJAMA_H

#include "shirt.h"
#include "pants.h"

class Pyjama : public Shirt, public Pants{
    static int pyjamaCount;
    const int pyjamaId;

    std::string season; // For what season is the pyjama (winter, summer)
public:
    Pyjama(std::string gender = "Unisex", std::string color = "Unknown", std::string size = "U", std::string material = "Unknown", float price = 0.0, std::string fit = "Unknown", std::string sleeveLength = "Unknown", std::string pattern = "Unknown", std::string length = "Unknown",std::string style = "Unknown", std::string season = "Unknown");
    Pyjama(const Pyjama& obj);
    Pyjama& operator=(const Pyjama& obj);
    void read(std::istream& in) override;
    void print(std::ostream& out) const override;
    friend std::istream& operator>>(std::istream& in, Pyjama& obj);
    friend std::ostream& operator<<(std::ostream& out, const Pyjama& obj);
    ~Pyjama();
};

inline int Pyjama::pyjamaCount = 100000;

#endif //CLOTHES_SHOP_PYJAMA_H
