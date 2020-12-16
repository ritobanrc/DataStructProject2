/* 
 * File:   Character.cpp
 * Author: ritoban
 * 
 * Created on December 12, 2020, 3:39 PM
 */

#include "Character.h"
#include "Display.h"

Character::Character(std::string name) : name(name), tree(DialogueTree("")) {
}

Character::Character(const Character& orig) { }

Character::~Character() { }

void Character::Speak () {
    Display::PrintBold("Talking to ");
    Display::PrintBold(name);
    Display::PrintBold(":");
    Display::NewLine();

    tree.Show();
}

void Character::SetDialogue(DialogueTree tree) {
    this->tree = tree;
}


const std::string& Character::GetName() const {
    return name;
}


