#ifndef INVENTORY_H
#define INVENTORY_H

#include "HashTable.h"
#include <string>

class Inventory {
public:
    Inventory();
    Inventory(const Inventory& orig);
    ~Inventory();

    void AddItem(std::string);
    bool HasItem(const std::string&);

    void Show();

private:
    HashTable<std::string> items;
};

#endif
