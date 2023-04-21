//
// Created by gfa on 4/21/23.
//

#ifndef CLOTHES_SHOP_IOINTERFACE_H
#define CLOTHES_SHOP_IOINTERFACE_H

#include <iostream>

class IOInterface{
public:
    virtual void read(std::istream& in) = 0;
    virtual void print(std::ostream& out) const = 0;
};

#endif //CLOTHES_SHOP_IOINTERFACE_H
