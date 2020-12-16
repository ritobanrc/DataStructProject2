#ifndef DIALOGUETREE_H
#define DIALOGUETREE_H

#include <utility>
#include <string>
#include <vector>
#include <functional>


class DialogueTree {
public:
    DialogueTree();
    DialogueTree(std::string line);
    DialogueTree(std::string line, std::function<void()> action);
    DialogueTree(const DialogueTree& orig);
    ~DialogueTree();

    void AddOption(std::string option, DialogueTree response);
    const std::pair<std::string, DialogueTree>& GetOption(std::size_t index) const;

    void Show() const;

private:
    std::string line;
    std::vector<std::pair<std::string, DialogueTree>> options;
    std::function<void()> action;
};

#endif
