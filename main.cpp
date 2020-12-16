/* 
 * File:   main.cpp
 * Author: ritoban
 *
 * Created on December 12, 2020, 11:16 AM
 */

#include "Display.h"
#include "Color.h"
#include "World.h"
#include "Inventory.h"
#include <string>

void PrintHelp();

int main(int argc, char** argv) {
    Display::BeginColor(Red.AsFG());
    Display::PrintBold("Welcome to The Game!");
    Display::NewLine();
    Display::EndFormat();

    Room* entraceHall = new Room("Entrace Hall", "You enter a large cave, dimly lit by a small opening at the top.");
    Room* greatHall = new Room("Great Hall", "A large, cavernous room, with the ceiling painted to look like the sky, the clouds almost appearing to move as though you were outside.");
    Room* courtyard = new Room("Courtyard", "A vast and open lawn, with the Great Hall on one side, barracks and dormotories and apartments and all manner of other workplaces on the other");

    Character* shopkeeper = new Character("Shopkeeper");

    Inventory inventory;

    DialogueTree tree("Welcome to my shop! I have the best wares from all around, never find anything better!");

    tree.AddOption(
        "Buy 10 gold coins",
        DialogueTree("Ho-ho-ho! Here you are, 10 gold coins!", [&]() {
            inventory.AddItem("10 gold coins");
        })
    );

    tree.AddOption(
        "Buy a sword",
        DialogueTree("Very well. Don't go cutting your own toes off!", [&]() {
            inventory.AddItem("1 Sword");
        })
    );

    tree.AddOption(
        "Buy 1 weeks ration",
        DialogueTree("Off for an adventure, are we? Exciting!", 
        [&]() {
            inventory.AddItem("7 Days Rations");
        })

    );


    shopkeeper->SetDialogue(tree);

    entraceHall->AddCharacter(shopkeeper);

    World world;
    world.AddRoom(entraceHall);
    world.AddRoom(greatHall);
    world.AddRoom(courtyard);

    world.AddPathway(entraceHall, greatHall);

    world.AddPathway(greatHall, entraceHall);
    world.AddPathway(greatHall, courtyard);

    world.AddPathway(courtyard, greatHall);

    Room* current = greatHall;

    while (true) {
        current->Display();
        world.DisplayPathways(current);

        if (current->HasCharacters()) {
            Display::PrintBold("Characters: ");
            Display::NewLine();
            current->DisplayCharacters();
        }

        Display::PrintBold("> ");


        std::string input;
        std::getline(std::cin, input);

        if (input.rfind("help", 0) == 0) {
            PrintHelp();
        } else if (input.rfind("go ", 0) == 0) {
            auto idx = std::stoul(input.substr(3)) - 1;
            current = world.GetPathway(current, idx);
        } else if (input.rfind("talk ", 0) == 0) {
            auto idx = std::stoul(input.substr(5)) - 1;
            auto character = current->GetCharacter(idx);
            character->Speak();
        } else if (input == "see inventory") {
            std::cout << inventory.HasItem("10 gold coins") << std::endl;
            inventory.Show();
        } else if (input.rfind("exit", 0) == 0) {
            break;
        } else {
            Display::Print("Sorry, I didn't understand that. If you're not sure what commands I understand, please type `help`.");
            Display::NewLine();
            Display::NewLine();
        }
    }


    return 0;
}

void PrintHelp() {
    Display::BeginColor(Blue.AsFG());
    Display::PrintBold("Help: ");

    Display::Print("\t `go <pathway number>` -- use a pathway to go to a room");
    Display::NewLine();

    Display::Print("\t `talk <character number>` -- initiate a conversation with a character");

    Display::Print("\t `see invetory` -- see the contents of your inventory");

    Display::Print("\t `exit` -- exit the game");
    Display::NewLine();

    Display::Print("\t `help` -- show this help screen");
    Display::NewLine();

    Display::NewLine();
    Display::NewLine();
}

