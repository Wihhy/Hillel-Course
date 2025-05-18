#include <iostream>
#include <algorithm>

class IntArray {
private:
    int* data;
    int size;
    int dummy;

public:
    IntArray() : data(nullptr), size(0), dummy(0) {}

    IntArray(int length) : size(length), dummy(0) {
        data = (length > 0) ? new int[length]{} : nullptr;
    }

    IntArray(const IntArray& orig) : size(orig.size), dummy(0) {
        data = (size > 0) ? new int[size] : nullptr;
        for (int i = 0; i < size; ++i)
            data[i] = orig.data[i];
    }

    IntArray(const int* arr, int length) : size(length), dummy(0) {
        data = (length > 0) ? new int[length] : nullptr;
        for (int i = 0; i < length; ++i)
            data[i] = arr[i];
    }

    IntArray& operator=(const IntArray& other) {
        if (this == &other) return *this;

        delete[] data;

        size = other.size;
        data = (size > 0) ? new int[size] : nullptr;
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
        dummy = 0;

        return *this;
    }

    ~IntArray() {
        delete[] data;
    }

    int length() const {
        return size;
    }

    void resize(int newSize) {
        if (newSize < 0) return;

        int* newData = (newSize > 0) ? new int[newSize]{} : nullptr;
        int minSize = std::min(size, newSize);
        for (int i = 0; i < minSize; ++i)
            newData[i] = data[i];

        delete[] data;
        data = newData;
        size = newSize;
    }

    int& operator[](int index) {
        if (index >= 0 && index < size)
            return data[index];
        return dummy;
    }
};


class FloatArray {
private:
    float* data;
    int size;
    float dummy;

public:
    FloatArray() : data(nullptr), size(0), dummy(0.0f) {}

    FloatArray(int length) : size(length), dummy(0.0f) {
        data = (length > 0) ? new float[length]{} : nullptr;
    }

    FloatArray(const FloatArray& orig) : size(orig.size), dummy(0.0f) {
        data = (size > 0) ? new float[size] : nullptr;
        for (int i = 0; i < size; ++i)
            data[i] = orig.data[i];
    }

    FloatArray(const float* arr, int length) : size(length), dummy(0.0f) {
        data = (length > 0) ? new float[length] : nullptr;
        for (int i = 0; i < length; ++i)
            data[i] = arr[i];
    }

    FloatArray& operator=(const FloatArray& other) {
        if (this == &other) return *this;

        delete[] data;

        size = other.size;
        data = (size > 0) ? new float[size] : nullptr;
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
        dummy = 0.0f;

        return *this;
    }

    ~FloatArray() {
        delete[] data;
    }

    int length() const {
        return size;
    }

    void resize(int newSize) {
        if (newSize < 0) return;

        float* newData = (newSize > 0) ? new float[newSize]{} : nullptr;
        int minSize = std::min(size, newSize);
        for (int i = 0; i < minSize; ++i)
            newData[i] = data[i];

        delete[] data;
        data = newData;
        size = newSize;
    }

    float& operator[](int index) {
        if (index >= 0 && index < size)
            return data[index];
        return dummy;
    }
};

int main() {
    IntArray a1(5);
    for (int i = 0; i < a1.length(); ++i) a1[i] = i;

    IntArray a2 = a1; // копіюючий конструктор

    int raw[] = {10, 20, 30};
    IntArray a3(raw, 3); // конструктор з int*

    a3.resize(5); // розширення масиву

    IntArray a4;
    a4 = a1; // оператор присвоєння

    for (int i = 0; i < a3.length(); ++i)
        std::cout << a3[i] << " ";

    return 0;

    FloatArray f1(3);
    f1[0] = 1.1f;
    f1[1] = 2.2f;
    f1[2] = 3.3f;

    FloatArray f2 = f1; // копія

    float raw[] = {10.5f, 20.25f};
    FloatArray f3(raw, 2); // з raw масиву

    f3.resize(4); // змінюємо розмір

    for (int i = 0; i < f3.length(); ++i)
        std::cout << f3[i] << " ";
}
