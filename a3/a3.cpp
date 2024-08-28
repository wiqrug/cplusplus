#include <iostream>
#include <vector>
#include <cstring> // Added to include strcpy and strcmp

using namespace std;

template <typename T>
class Queue {
private:
    vector<T> values;

public:
    void enqueue(T item);
    void dequeue();
    int size() const;  // `const` because it doesn't modify the object
    T at(int index) const;  // Method to access elements by index
};

template<typename T>
void Queue<T>::enqueue(T item) {
    values.push_back(item);
}

template<typename T>
void Queue<T>::dequeue() {
    if (!values.empty()) {
        values.erase(values.begin());
    }
}

template<typename T>
int Queue<T>::size() const {  // Marked `const` because it doesn't modify the object
    return values.size();
}

template<typename T>
T Queue<T>::at(int index) const {
    return values.at(index);
}

template <typename T>
bool isEqual(const Queue<T>& q1, const Queue<T>& q2) {  // Passing by const reference
    if (q1.size() != q2.size()) {
        return false;  // Queues of different sizes are not equal
    }

    for (int i = 0; i < q1.size(); i++) {
        if (q1.at(i) != q2.at(i)) {
            return false;  // If any elements differ, the queues are not equal
        }
    }

    return true;  // All elements are equal
}

class MyClass {
private:
    int number;
    char name[50];  // C-String with a maximum size of 50 characters

public:
    MyClass(int num, const char* str) {
        number = num;
        strcpy(name, str);  // Copy the C-String into the attribute
    }

    // Method to display the data
    void display() const {
        cout << "Number: " << number << ", Name: " << name << endl;
    }

    // Comparison method for objects
    bool operator==(const MyClass& other) const {
        return (number == other.number && strcmp(name, other.name) == 0);
    }
};

int main() {
    // Create a queue with MyClass objects
    Queue<MyClass> queue1;
    Queue<MyClass> queue2;

    // Add objects to the queue
    queue1.enqueue(MyClass(1, "Alice"));
    queue1.enqueue(MyClass(2, "Bob"));

    queue2.enqueue(MyClass(1, "Alice"));
    queue2.enqueue(MyClass(2, "Bob"));

    // Check if the two queues are equal
    if (isEqual(queue1, queue2)) {
        cout << "The queues are equal." << endl;
    } else {
        cout << "The queues are not equal." << endl;
    }

    // Display the elements of the first queue
    for (int i = 0; i < queue1.size(); i++) {
        queue1.at(i).display();
    }

    return 0;
}
