#include <string>

#ifndef ROOM_H
#define ROOM_H

class Room {
public:
    Room(std::string);
    Room(const Room& orig);
    ~Room();
    

private:
    std::string description;
};

#endif
