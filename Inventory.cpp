/* 
 * File:   Inventory.cpp
 * Author: ritoban
 * 
 * Created on December 12, 2020, 3:39 PM
 */

#include "Inventory.h"
#include "Display.h"
#include "MergeSort.h"

Inventory::Inventory() : items(HashTable<std::string>(10)){
}

Inventory::Inventory(const Inventory& orig) : items(orig.items) { }

Inventory::~Inventory() { }


void Inventory::AddItem(std::string item) {
    items.Insert(item);
}

bool Inventory::HasItem(const std::string& item) {
    return items.Contains(item);
}


void Inventory::Show() {
    auto elements = items.GetElements();

    std::string* start = &elements[0];
    mergeSort(start, elements.size());

    Display::BeginColor(Yellow.AsFG());
    Display::PrintBold("Inventory: ");
    Display::NewLine();

    for (int i = 0; i < elements.size(); i++) {
        Display::PrintBold(i + 1);
        Display::PrintBold(". ");
        Display::EndFormat();

        std::cout << elements.at(i) << std::endl;
        Display::NewLine();

    }
}
