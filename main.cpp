/* 
 * File:   main.cpp
 * Author: ritoban
 *
 * Created on December 12, 2020, 11:16 AM
 */

#include "Display.h"
#include "Color.h"
#include "World.h"

int main(int argc, char** argv) {
    Display::BeginColor(Red.AsFG());
    Display::PrintBold("Welcome to The Game!");
    Display::NewLine();
    Display::EndFormat();

    Room* entraceHall = new Room("You enter a large cave, dimly lit by a small opening at the top.");
    Room* greatHall = new Room("A large, cavernous room, with the ceiling painted to look like the sky, the clouds almost appearing to move as though you were outside.");
    Room* courtyard = new Room("A vast and open lawn, with the Great Hall on one side, barracks and dormotories and apartments and all manner of other workplaces on the other");

    World world;
    world.AddRoom(entraceHall);
    world.AddRoom(greatHall);
    world.AddRoom(courtyard);

    world.AddPathway(entraceHall, greatHall);

    world.AddPathway(greatHall, entraceHall);
    world.AddPathway(greatHall, courtyard);

    world.AddPathway(courtyard, greatHall);

    Room* current;

    while (true) {
    }


    return 0;
}

