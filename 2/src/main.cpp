#include <iostream>
#include <string>

class TNode {
private:
    static TNode* head;
    TNode* next;
    TNode* prev;
    std::string info;

public:
    void SetData(std::string str);
    void AddToList();
    void PrintAll();
};

TNode* TNode::head = nullptr;

void TNode::AddToList() {
    this->next = TNode::head;
    this->prev = nullptr;
    if (TNode::head != nullptr) {
        TNode::head->prev = this;
    }
    TNode::head = this;
}

void TNode::SetData(std::string str) {
    this->info = str;
}

void TNode::PrintAll() {
    for (TNode* cur = TNode::head; cur != nullptr; cur = cur->next) {
        std::cout << cur->info << std::endl;
    }
}

int main() {
    std::string input;
    TNode a;
    std::getline(std::cin, input);
    a.SetData(input);
    a.AddToList();
    std::getline(std::cin, input);
    while (input != "") {
        TNode* new_node = new TNode;
        new_node->SetData(input);
        new_node->AddToList();
        std::getline(std::cin, input);
    }
    a.PrintAll();
    return 0;
}
