#include <map>
#include <list>
#include "Room.h"

#ifndef WORLD_H
#define WORLD_H

class World {
public: 
    World();
    World(const World&);
    ~World();

    void AddRoom(Room*);
    void AddPathway(Room*, Room*);

    void DisplayPathways(Room*);
    Room* GetPathway(Room*, std::size_t);

private:
    // This is a directed graphs that represents all of the rooms.
    std::map<Room*, std::list<Room*>> roomGraph;
};

#endif
