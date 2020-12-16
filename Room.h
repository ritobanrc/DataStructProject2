#include <string>
#include <vector>
#include "Character.h"

#ifndef ROOM_H
#define ROOM_H

class Room {
public:
    Room(std::string, std::string);
    Room(const Room& orig);
    ~Room();

    void Display() const;
    const std::string& GetName() const;

    Character* GetCharacter(std::size_t i) const;
    void AddCharacter(Character* c);
    void DisplayCharacters() const;

    bool HasCharacters() const;

private:
    std::string name;
    std::string description;

    std::vector<Character*> characters;
};

#endif
