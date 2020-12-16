/* 
 * File:   World.cpp
 * Author: ritoban
 * 
 * Created on December 12, 2020, 11:30 AM
 */

#include "World.h"
#include <fstream>
#include <iostream>
#include <list>
#include <utility>
#include <vector>

World::World() {
}

World::World(const World& orig) {
    roomGraph = std::map<Room*, std::list<Room*>>(orig.roomGraph);
}

World::~World() {
}

void World::AddRoom(Room* room) {
    this->roomGraph.insert(std::make_pair(room, std::list<Room*>()));
}
