#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int age;
    string name;
public:
    Person() : age(0), name("Unnamed") {
        cout << "Person default constructor called" << endl;
    }
    Person(int age, string name) : age(age), name(name) {
        cout << "Person parameterized constructor called" << endl;
    }

    Person(const Person& other) : age(other.age), name(other.name) {
        cout << "Person copy constructor called" << endl;
    }

    virtual ~Person() {
        cout << "Person destructor called" << endl;
    }

    virtual void showRole() {
        cout << "I'm just a person" << endl;
    }

    void showDetails() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {  // Public inheritance
protected:
    int am;  // Academic ID
public:

    Student() : Person(), am(0) {
        cout << "Student default constructor called" << endl;
    }

    Student(int age, string name, int am) : Person(age, name), am(am) {
        cout << "Student parameterized constructor called" << endl;
    }

    Student(const Student& other) : Person(other), am(other.am) {
        cout << "Student copy constructor called" << endl;
    }

    ~Student() {
        cout << "Student destructor called" << endl;
    }

    void showRole() override {
        cout << "Now I'm also a student" << endl;
    }

    void showStudentDetails() const {
        showDetails();
        cout << "Academic ID: " << am << endl;
    }
};

class Teacher : public Person {  // Public inheritance
private:
    string subject;
public:
    Teacher() : Person(), subject("Unknown") {
        cout << "Teacher default constructor called" << endl;
    }

    Teacher(int age, string name, string subject) : Person(age, name), subject(subject) {
        cout << "Teacher parameterized constructor called" << endl;
    }

    Teacher(const Teacher& other) : Person(other), subject(other.subject) {
        cout << "Teacher copy constructor called" << endl;
    }

    ~Teacher() {
        cout << "Teacher destructor called" << endl;
    }

    void showRole() override {
        cout << "Now I'm also a teacher" << endl;
    }

    void showTeacherDetails() const {
        showDetails();
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    Person person;
    Student student;
    Teacher teacher;

    Person person1(30, "Alice");
    Student student1(20, "Bob", 12345);
    Teacher teacher1(40, "Charlie", "Mathematics");

    // Demonstrating copy constructors
    Person person2 = person1;
    Student student2 = student1;
    Teacher teacher2 = teacher1;

    // Showing roles
    person.showRole();    // Output: I'm just a person
    student.showRole();   // Output: Now I'm also a student
    teacher.showRole();   // Output: Now I'm also a teacher

    // Showing details
    person1.showDetails();     // Output: Name: Alice, Age: 30
    student1.showStudentDetails(); // Output: Name: Bob, Age: 20, Academic ID: 12345
    teacher1.showTeacherDetails(); // Output: Name: Charlie, Age: 40, Subject: Mathematics

    // Demonstrating polymorphism
    Person* p1 = &student1;
    p1->showRole();  // Output: Now I'm also a student

    Person* p2 = &teacher1;
    p2->showRole();  // Output: Now I'm also a teacher

    return 0;
}

