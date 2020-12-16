/* 
 * File:   Room.cpp
 * Author: ritoban
 * 
 * Created on December 12, 2020, 11:29 AM
 */

#include "Room.h"
#include "Display.h"
#include <iostream>

Room::Room(std::string name, std::string description) : name(name), description(description) {
}

Room::Room(const Room& orig) {
}

Room::~Room() {
}

void Room::Display() const {
    Display::NewLine();
    Display::PrintBold("Name: ");
    std::cout << name << std::endl;

    Display::PrintBold("Description: ");
    std::cout << description << std::endl << std::endl;
    Display::PrintBold("Pathways: ");
    Display::NewLine();
}

const std::string& Room::GetName() const {
    return this->name;
}


Character* Room::GetCharacter(std::size_t i) const {
    return characters[i];
}

void Room::AddCharacter(Character* c) {
    this->characters.push_back(c);
}



void Room::DisplayCharacters() const {
    int i = 1;
    for (auto character = characters.cbegin();
            character != characters.cend();
            character++) 
    {
        Display::Print("\t");
        Display::BeginColor(Red.AsFG());
        Display::PrintBold(i);
        Display::PrintBold(". ");
        Display::EndFormat();

        Display::Print((*character)->GetName());
        Display::NewLine();

        i++;
    }
}


bool Room::HasCharacters() const {
    return !characters.empty();
}
