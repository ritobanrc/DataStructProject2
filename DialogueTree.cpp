/* 
 * File:   DialogueTree.cpp
 * Author: ritoban
 * 
 * Created on December 12, 2020, 3:39 PM
 */

#include "DialogueTree.h"
#include "Color.h"
#include "Display.h"
#include <utility>

DialogueTree::DialogueTree() : line("") {
}

DialogueTree::DialogueTree(std::string line) : line(line) {
}

DialogueTree::DialogueTree(std::string line, std::function<void()> action) : line(line), action(action) {
}

DialogueTree::DialogueTree(const DialogueTree& orig) : line(orig.line), options(orig.options), action(orig.action) {
}

DialogueTree::~DialogueTree() {
}

void DialogueTree::AddOption(std::string option, DialogueTree response) {
    options.push_back(std::make_pair(option, response));
}


const std::pair<std::string, DialogueTree>& DialogueTree::GetOption(std::size_t index) const {
    return this->options.at(index);
}

void DialogueTree::Show() const {
    // Recursive Base case
    if (this->line == "") {
        return;
    }

    if (this->action) {
        (this->action)();
    }

    int i = 1;
    Display::Print(line);
    Display::NewLine();
    for (auto response = options.cbegin();
            response != options.cend();
            response++) {
        Display::BeginColor(Blue.AsFG());
        Display::PrintBold(i);
        Display::PrintBold(". ");
        Display::Print(response->first);
        Display::NewLine();

        i++;
    }

    Display::NewLine();
    if (!options.empty()) {
        Display::PrintBold("> ");

        int response;


        std::cin >> response;
        const DialogueTree& next = GetOption(response - 1).second;
        next.Show();
    } else {
        Display::Print("Press ENTER to continue...");
        std::cin.ignore();
    }
}

