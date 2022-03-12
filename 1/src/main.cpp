#include <iostream>
#include <cstdlib>
#include <ctime>

class TArray {
private:
    int len;
    int* data;

public:
    TArray() {
        this->len = 0;
        this->data = NULL;
        std::cout << "defaults constructor\n";
    }
    TArray(int len) {
        this->len = len;
        this->data = new int[this->len];
        for (int i = 0; i < this->len; ++i) {
            this->data[i] = 0;
        }
        std::cout << "len constructor\n";
    }
    TArray(int len, int* arr) {
        this->len = len;
        this->data = new int[this->len];
        for (int i = 0; i < this->len; ++i) {
            this->data[i] = arr[i];
        }
        std::cout << "array constructor\n";
    }

    TArray(const TArray& rv) {
        this->len = rv.len;
        this->data = new int[this->len];
        for (int i = 0; i < this->len; ++i) {
            this->data[i] = rv.data[i];
        }
        std::cout << "copy constructor\n";
    }
    TArray& operator =(const TArray& rv) {
        this->len = rv.len;
        if (this->data != NULL) {
            delete[] this->data;
        }
        this->data = new int[this->len];
        for (int i = 0; i < this->len; ++i) {
            this->data[i] = rv.data[i];
        }
        std::cout << "operator =\n";
        return *this;
    }
    ~TArray() {
        if (this->data != NULL) {
            delete[] this->data;
        }
        std::cout << "destructor\n";
    }

    int max() const {
        if (this->len == 0) {
            throw std::runtime_error("there is no max in empty array");
        }
        int result = this->data[0];
        for (int i = 1; i < this->len; ++i) {
            result = std::max(result, this->data[i]);
        }
        std::cout << "method max\n";
        return result;
    }
};

void generate_array(int len, int* arr) {
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % 100;
    }
}

int main() {
    srand(time(NULL));
    const int max_len = 10;
    int array[max_len];
    generate_array(max_len, array);
    TArray a = {max_len, array};
    generate_array(max_len, array);
    TArray b(max_len, array);
    generate_array(max_len, array);
    TArray c(max_len, array);
    std::cout << a.max() + b.max() + c.max() << std::endl;
    return 0;
}
