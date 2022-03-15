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
    for (TNode* cur = TNode::head; cur != this; cur = cur->next) {
        std::cout << cur->info << std::endl;
    }
    std::cout << this->info << std::endl;
}

int main() {
    TNode a, b, c, d;
    a.SetData("Ann");
    b.SetData("Nick");
    c.SetData("Lena");
    d.SetData("Tom");

    a.AddToList();
    b.AddToList();
    c.AddToList();
    d.AddToList();

    b.PrintAll();
    return 0;
}
