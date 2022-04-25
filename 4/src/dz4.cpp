#include <iostream>
#include <cstring>

class TString {
private:
    char* data;

public:
    TString(const char* rv) {
        (*this).data = new char[strlen(rv) + 1];
        strcpy((*this).data, rv);
    }
    ~TString() {
        delete[] (*this).data;
    }
    bool operator ==(const TString& rv) {
        return 0 == strcmp((*this).data, rv.data);
    }
};

int main() {
    TString a = "hello", b = "hello", c = "world";
    std::cout << (a == b) << "\n" <<
                 (a == c) << "\n" <<
                 (b == c) << "\n";
    return 0;
}
