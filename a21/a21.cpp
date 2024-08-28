#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

template<typename T>
class BinaryArrayManager {
private:
    T* arr;
    int size;

public:
    BinaryArrayManager();
    BinaryArrayManager(const T* values, int size);
    ~BinaryArrayManager();

    void saveToBinaryFile(const string& filename);
    void addFromBinary(const string& filename);

    // Optional: method to print the array for debugging
    void print() const;
};

template<typename T>
BinaryArrayManager<T>::BinaryArrayManager() : arr(nullptr), size(0) {}

template<typename T>
BinaryArrayManager<T>::BinaryArrayManager(const T* values, int size) : size(size) {
    arr = new T[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = values[i];
    }
}

template<typename T>
BinaryArrayManager<T>::~BinaryArrayManager() {
    delete[] arr;
}

template<typename T>
void BinaryArrayManager<T>::saveToBinaryFile(const string& filename) {
    ofstream ofs;
    ofs.exceptions(ofstream::failbit | ofstream::badbit);

    try {
        ofs.open(filename, ios::binary);
        ofs.write((char*)arr, size * sizeof(T));  // C-style cast to char*
        ofs.close();
    } catch (const ofstream::failure& e) {
        cerr << "Error writing to file: " << e.what() << endl;
        throw;
    }
}

template<typename T>
void BinaryArrayManager<T>::addFromBinary(const std::string& filename) {
    ifstream ifs;
    ifs.exceptions(ifstream::failbit |ifstream::badbit);

    try {
        ifs.open(filename, ios::binary);

        // Determine file size
        ifs.seekg(0, ios::end);
        streamsize fileSize = ifs.tellg();
        ifs.seekg(0, ios::beg);

        // Calculate the number of elements
        int newSize = fileSize / sizeof(T);

        // Allocate memory for the array
        T* newArr = new T[newSize];

        // Read the data from the file
        ifs.read((char*)newArr, fileSize);  // C-style cast to char*
        ifs.close();

        // Clean up the old array and update with the new array
        delete[] arr;
        arr = newArr;
        size = newSize;
    } catch (const ifstream::failure& e) {
        cerr << "Error reading from file: " << e.what() << endl;
        throw;
    }
}

template<typename T>
void BinaryArrayManager<T>::print() const {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int foo[5] = {0, 1, 2, 3, 4};
    BinaryArrayManager<int> manager(foo, 5);

    try {
        manager.saveToBinaryFile("array_data.dat");

        BinaryArrayManager<int> newManager;
        newManager.addFromBinary("array_data.dat");

        newManager.print();  // Should print: 0 1 2 3 4

    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }

    return 0;
}
