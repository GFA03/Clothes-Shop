//
// Created by gfa on 4/20/23.
//

#ifndef CLOTHES_SHOP_MENU_H
#define CLOTHES_SHOP_MENU_H

#include "shop/product.h"
#include "shop/shirt.h"
#include "shop/pants.h"
#include "shop/jacket.h"
#include "shop/pyjama.h"
#include "persons/person.h"
#include "persons/customer.h"
#include "persons/employee.h"
#include <algorithm>


class Menu{
    std::vector<Product*> productsList;
    std::vector<Person*> personsList;
public:
    void run();

    void loadData();

    void adminMenu();
    void employeeMenu(int id);
    void customerMenu(int id);
    void editEmployeeMenu(int id);
    void editCustomerMenu(int id);

    std::vector<Product*> generateShoppingCart();
};

#endif //CLOTHES_SHOP_MENU_H
