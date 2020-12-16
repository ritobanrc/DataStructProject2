#ifndef CHARACTER_H
#define CHARACTER_H

#include "DialogueTree.h"

class Character {
public:
    Character(std::string name);
    Character(const Character& orig);
    ~Character();

    void Speak();
    const std::string& GetName() const;
    void SetDialogue(DialogueTree);
private:
    std::string name;
    DialogueTree tree;
};

#endif
