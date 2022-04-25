#include <iostream>
#include <cstring>

class TString;
class TArray;
TArray process(TString input);

class TString {
private:
    char* data;

public:
    TString(const char* new_data) {
        this->data = new char[strlen(new_data) + 1];
        strcpy(this->data, new_data);
    }

    friend TArray process(TString input);
};

class TArray {
private:
    int len;
    int* data;

public:
    TArray(int new_len) {
        this->len = new_len;
        this->data = new int[this->len];
    }

    void resize(int new_len) {
        int* new_data = new int[new_len];
        memcpy(new_data, this->data, new_len * sizeof(int));
        delete[] this->data;
        this->len = new_len;
        this->data = new_data;
    }

    friend TArray process(TString input);

    friend std::ostream& operator <<(std::ostream& out, const TArray& rv);
};

TArray process(TString input) {
    TArray result = strlen(input.data);
    int count = 0;
    for (unsigned i = 0; i < strlen(input.data); ++i) {
        if (input.data[i] == '*') {
            result.data[count] = i;
            count++;
        }
    }
    result.resize(count);
    return result;
}

std::ostream& operator <<(std::ostream& out, const TArray& rv) {
    for (int i = 0; i < rv.len; ++i) {
        out << rv.data[i] << " ";
    }
    out << "\n";
    return out;
}

int main() {
    TString a = "hello*world*I*am*super*star";
    std::cout << process(a);
    return 0;
}
