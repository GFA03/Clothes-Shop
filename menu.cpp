//
// Created by gfa on 4/20/23.
//

#include "menu.h"

void Menu::loadData(){
    Person* a;
    Person* b;
    Person* c;
    Person* d;
    Person* e;
    a = new Employee("John Bengosu", 20, "Asistent");
    b = new Employee("Mircea Batranu", 21, "Asistent Sef");
    c = new Employee("Laurentiu Cosmin", 30, "Manager");
    d = new Customer("Mihai Bivol", 20, 200);
    e = new Customer("Razvan Dascal", 26, 12);
    this->personsList.push_back(a);
    this->personsList.push_back(b);
    this->personsList.push_back(c);
    this->personsList.push_back(d);
    this->personsList.push_back(e);
    Product* s1;
    Product* s2;
    Product* p1;
    Product* p2;
    Product* j1;
    Product* j2;
    Product* py1;
    Product* py2;
    s1 = new Shirt("Male", "Blue", "M", "Cotton", 100, "Slim fit", "Long", "Stripes");
    s2 = new Shirt("Female", "Red", "S", "Cotton", 120, "Regular fit", "Short", "Checks");
    p1 = new Pants("Female", "Black", "L", "Cotton", 70, "Skinny", "Long", "Jeans");
    p2 = new Pants("Male", "White", "XL", "Cotton", 170, "Regular fit", "Long", "Sweatpants");
    j1 = new Jacket("Male", "Black", "M", "Leather", 700, "Regular fit", "Blazer", "Zipper");
    j2 = new Jacket("Female", "Black", "X", "Leather", 1200, "Regular fit", "Coat", "Zipper");
    py1 = new Pyjama("Male", "White", "L", "Cotton", 100, "Regular fit", "Long", "Stripes", "Long", "Pyjama", "Winter");
    py2 = new Pyjama("Female", "Black", "S", "Cotton", 200, "Regular fit", "Short", "Stripes", "Short", "Pyjama", "Summer");
    this->productsList.push_back(s1);
    this->productsList.push_back(s2);
    this->productsList.push_back(p1);
    this->productsList.push_back(p2);
    this->productsList.push_back(j1);
    this->productsList.push_back(j2);
    this->productsList.push_back(py1);
    this->productsList.push_back(py2);
}

void Menu::run(){
    int command;
    bool running = true;
    system("clear");
    while(running){
        std::cout << "0 - Exit\n";
        std::cout << "1 - Admin menu\n";
        std::cout << "2 - Employee menu\n";
        std::cout << "3 - Customer menu\n";
        std::cout << "Command: ";
        std::cin >> command;
        switch(command){
            case 0:{
                system("clear");
                running = false;
                std::cout << "Bye! See you later!";
                break;
            }
            case 1:{
                system("clear");
                this->adminMenu();
                break;
            }
            case 2:{
                system("clear");
                bool found = false;
                Employee* temp;
                for(int i = 0; i < this->personsList.size(); ++i){
                    temp = dynamic_cast<Employee*>(this->personsList[i]);
                    if(temp != nullptr){
                        std::cout << temp->getName() << '(' << temp->getEmployeeId() << ')' << " -> " << i << '\n';
                        found = true;
                    }
                }
                if(found) {
                    int id;
                    std::cout << "Id: ";
                    std::cin >> id;
                    this->employeeMenu(id);
                }else{std::cout << "No employees found!\n";}
                break;
            }
            case 3:{
                system("clear");
//                this->customerMenu(id);
                break;
            }
            default:{
                system("clear");
                std::cout << "Invalid command";
                break;
            }
        }
    }
}

void Menu::adminMenu() {
    int command;
    bool running = true;
    system("clear");
    while(running){
        std::cout << "0 - Exit\n";
        std::cout << "1 - Add Employee\n";
        std::cout << "2 - Add Customer\n";
        std::cout << "3 - Edit Employee\n";
        std::cout << "4 - Edit Customer\n";
        std::cout << "5 - Print all Employees\n";
        std::cout << "6 - Print all Customers\n";
        std::cout << "Command: ";
        std::cin >> command;
        switch(command){
            case 0:{
                system("clear");
                running = false;
                break;
            }
            case 1:{
                system("clear");
                Person* person;
                person = new Employee();
                std::cin >> *(dynamic_cast<Employee*>(person));
                personsList.push_back(person);
                break;
            }
            case 2:{
                system("clear");
                Person* person;
                person = new Customer();
                std::cin >> *(dynamic_cast<Customer*>(person));
                personsList.push_back(person);
                break;
            }
            case 3:{
                system("clear");
                Employee* temp;
                for(int i = 0; i < this->personsList.size(); ++i){
                    temp = dynamic_cast<Employee*>(this->personsList[i]);
                    if(temp != nullptr)
                    {
                        std::cout << temp->getName() << '(' << temp->getEmployeeId() << ')' << " -> " << i << '\n';
                    }
                }
                int id;
                std::cout << "Id: ";
                std::cin >> id;
                if(id >= 0 && id < this->personsList.size() && dynamic_cast<Employee*>(this->personsList[id]) != nullptr)
                    this->editEmployeeMenu(id);
                else{std::cout << "Invalid id";}
                break;
            }
            case 4:{
                system("clear");
                Customer* temp;
                for(int i = 0; i < this->personsList.size(); ++i){
                    temp = dynamic_cast<Customer*>(this->personsList[i]);
                    if(temp != nullptr)
                    {
                        std::cout << temp->getName() << '(' << temp->getCustomerId() << ')' << " -> " << i << '\n';
                    }
                }
                int id;
                std::cout << "Id: ";
                std::cin >> id;
                if(id >= 0 && id < this->personsList.size() && dynamic_cast<Customer*>(this->personsList[id]) != nullptr)
                    this->editCustomerMenu(id);
                else{std::cout << "Invalid id";}
                break;
            }
            case 5:{
                system("clear");
                bool found = false;
                if(!this->personsList.empty()){
                    Employee* temp;
                    for(auto & i : this->personsList){
                        temp = dynamic_cast<Employee*>(i);
                        if(temp != nullptr)
                        {
                            std::cout << *(temp) << '\n';
                            found = true;
                        }
                    }
                }
                if(!found){
                    std::cout << "No employees yet!";
                }
                break;
            }
            case 6:{
                system("clear");
                bool found = false;
                if(!this->personsList.empty()){
                    Customer* temp;
                    for(auto & i : this->personsList){
                        temp = dynamic_cast<Customer*>(i);
                        if(temp != nullptr)
                        {
                            std::cout << *(temp) << '\n';
                            found = true;
                        }
                    }
                }
                if(!found){
                    std::cout << "No customers yet!";
                }
                break;
            }
            default:{
                system("clear");
                std::cout << "Invalid command";
                break;
            }
        }
    }
}

void Menu::editEmployeeMenu(int id) {
    int command;
    bool running = true;
    system("clear");
    while(running){
        std::cout << *(this->personsList[id]) << '\n';
        std::cout << "0 - Exit\n";
        std::cout << "1 - Edit name\n";
        std::cout << "2 - Edit age\n";
        std::cout << "3 - Edit job title\n";
        std::cout << "9 - Delete\n";
        std::cout << "Command: ";
        std::cin >> command;
        switch(command){
            case 0:{
                system("clear");
                running = false;
                break;
            }
            case 1:{
                system("clear");
                std::string name;
                std::cout << "Insert new name: ";
                std::cin.get();
                std::getline(std::cin, name);
                this->personsList[id]->setName(name);
                break;
            }
            case 2:{
                system("clear");
                int age;
                std::cout << "Insert new age: ";
                std::cin >> age;
                this->personsList[id]->setAge(age);
                break;
            }
            case 3:{
                system("clear");
                std::string jobTitle;
                std::cout << "Insert new job title: ";
                std::getline(std::cin, jobTitle);
                dynamic_cast<Employee*>(this->personsList[id])->setJobTitle(jobTitle);
                break;
            }
            case 9:{
                system("clear");
                this->personsList.erase(this->personsList.begin()+id);
                running = false;
                break;
            }
            default:{
                system("clear");
                std::cout << "Invalid command";
                break;
            }
        }
    }
}

void Menu::editCustomerMenu(int id) {
    int command;
    bool running = true;
    system("clear");
    while(running){
        std::cout << *(this->personsList[id]) << '\n';
        std::cout << "0 - Exit\n";
        std::cout << "1 - Edit name\n";
        std::cout << "2 - Edit age\n";
        std::cout << "3 - Edit discount points\n";
        std::cout << "9 - Delete\n";
        std::cout << "Command: ";
        std::cin >> command;
        switch(command){
            case 0:{
                system("clear");
                running = false;
                break;
            }
            case 1:{
                system("clear");
                std::string name;
                std::cout << "Insert new name: ";
                std::cin.get();
                std::getline(std::cin, name);
                this->personsList[id]->setName(name);
                break;
            }
            case 2:{
                system("clear");
                int age;
                std::cout << "Insert new age: ";
                std::cin >> age;
                this->personsList[id]->setAge(age);
                break;
            }
            case 3:{
                system("clear");
                int discountPoints;
                std::cout << "Insert new discount points: ";
                std::cin >> discountPoints;
                dynamic_cast<Customer*>(this->personsList[id])->setDiscountPoints(discountPoints);
                break;
            }
            case 9:{
                system("clear");
                this->personsList.erase(this->personsList.begin()+id);
                running = false;
                break;
            }
            default:{
                system("clear");
                std::cout << "Invalid command";
                break;
            }
        }
    }
}

void Menu::employeeMenu(int id) {
    auto* current = dynamic_cast<Employee*>(this->personsList[id]);
    int command;
    bool running = true;
    system("clear");
    while (running) {
        std::cout << *current << '\n';
        std::cout << "0 - Exit\n";
        std::cout << "1 - Add Product\n";
        std::cout << "2 - Remove Product\n";
        std::cout << "3 - Print all Products\n";
        std::cout << "4 - Work\n";
        std::cout << "Command: ";
        std::cin >> command;
        switch (command) {
            case 0: {
                system("clear");
                running = false;
                break;
            }
            case 1: {
                system("clear");
                std::cout << "11 - Add Shirt\n";
                std::cout << "12 - Add Pants\n";
                std::cout << "13 - Add Jacket\n";
                std::cout << "14 - Add Pyjama\n";
                int command2;
                std::cout << "Command: ";
                std::cin >> command2;
                system("clear");
                switch(command2){
                    case 11:{
                        Product* temp = new Shirt();
                        std::cin >> *(dynamic_cast<Shirt*>(temp));
                        this->productsList.push_back(temp);
                        std::cout << "Shirt successfully added!\n";
                        break;
                    }
                    case 12:{
                        Product* temp = new Pants();
                        std::cin >> *(dynamic_cast<Pants*>(temp));
                        this->productsList.push_back(temp);
                        std::cout << "Pants successfully added!\n";
                        break;
                    }
                    case 13:{
                        Product* temp = new Jacket();
                        std::cin >> *(dynamic_cast<Jacket*>(temp));
                        this->productsList.push_back(temp);
                        std::cout << "Jacket successfully added!\n";
                        break;
                    }
                    case 14:{
                        Product* temp = new Pyjama();
                        std::cin >> *(dynamic_cast<Pyjama*>(temp));
                        this->productsList.push_back(temp);
                        std::cout << "Pyjama successfully added!\n";
                        break;
                    }
                    default:{
                        std::cout << "Invalid command!\n";
                        break;
                    }
                }
                break;
            }
            case 2: {
                system("clear");
                if(!this->productsList.empty()){
                    std::cout << "Id(starting from 0): ";
                    int idProduct;
                    std::cin >> idProduct;
                    if(idProduct > 0 && idProduct < this->productsList.size()){
                        system("clear");
                        this->productsList.erase(this->productsList.begin()+idProduct);
                    }
                    else{
                        std::cout << "No product found at that ID!\n";
                    }
                }else{std::cout << "No products found!\n";}
                break;
            }
            case 3: {
                system("clear");
                if(!this->productsList.empty())
                {
                    for(auto& i: this->productsList){
                        std::cout << *i << '\n';
                    }
                }else{
                    std::cout << "No products found!";
                }
                break;
            }
            case 4: {
                system("clear");
                std::vector<Product*> temp;
                std::string barCode = "";
                if(!this->productsList.empty()){
                    bool continueWork = true;
                    while(continueWork){
                        temp = generateShoppingCart();
                        for(int i = 0; i < temp.size(); ++i){
                            std::cout << temp[i]->getBarCode() << '\n';
                            while(barCode != temp[i]->getBarCode()) {
                                std::cout << "Insert bar code: ";
                                std::cin >> barCode;
                            }
                        }
                        system("clear");
                        std::cout << "You did an " << ANSI_COLOR_RED << "EXCELLENT JOB!" << ANSI_COLOR_RESET << "\n" << "Would you like to continue?\n";
                        std::cout << "Stop work -> 0\n";
                        std::cout << "Continue work -> 1\n";
                        std::cout << "Command: ";
                        std::cin >> continueWork;
                    }
                }else{
                    std::cout << "No products found => No work to do! :)\n";
                }
                break;
            }
            default: {
                system("clear");
                std::cout << "Invalid command";
                break;
            }
        }
    }
}

std::vector<Product*> Menu::generateShoppingCart() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(1, this->productsList.size());
    int numOfElements = dist(mt);
    std::vector<Product*> temp;
    std::sample(
        this->productsList.begin(),
        this->productsList.end(),
        std::back_inserter(temp),
        numOfElements,
        std::mt19937{std::random_device{}()}
    );
    return temp;
}

int main(){
    Menu menu;
    menu.loadData();
    menu.run();
//    Product* p = new Pyjama();
//    std::cout << typeid(dynamic_cast<Pyjama*>(p)).name()+2;
}