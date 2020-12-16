/* 
 * File:   World.cpp
 * Author: ritoban
 * 
 * Created on December 12, 2020, 11:30 AM
 */

#include "World.h"
#include "Color.h"
#include "Display.h"
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

void World::AddPathway(Room* room1, Room* room2) {
    if (roomGraph.find(room1) != roomGraph.end()) {
        roomGraph.at(room1).push_back(room2);
    } else {
        roomGraph.insert(std::make_pair(room1, std::list<Room*>()));
        roomGraph.at(room1).push_back(room2);
    }
}

void World::DisplayPathways(Room* room) {
    int i = 1;
    for (auto pathway = roomGraph.at(room).cbegin(); 
            pathway != roomGraph.at(room).cend();
            pathway++) 
    {
        Display::Print("\t");
        Display::BeginColor(Green.AsFG());
        Display::PrintBold(i);
        Display::PrintBold(". ");
        Display::EndFormat();

        Display::Print((*pathway)->GetName());
        Display::NewLine();

        i++;
    }
}


Room* World::GetPathway(Room* source, std::size_t index) {
    std::size_t i = 0;
    for (auto pathway = roomGraph.at(source).cbegin(); 
            pathway != roomGraph.at(source).cend();
            pathway++) 
    {
        if (i == index) {
            return *pathway;
        }
        i++;
    }
    return nullptr;
}
