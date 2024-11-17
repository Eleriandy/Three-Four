#include <iostream> 
#include <string>
using namespace std;

// Klasa bazowa dla wszystkich pracowników szkoły
class Employee {
private:
    string name;  // Ukryte dane: imię
    int age;      // Ukryte dane: wiek

public:
    // Konstruktor
    Employee(string name = "Unknown", int age = 0) : name(name), age(age) {}

    // Getter dla imienia
    string getName() const {
        return name;
    }

    // Setter dla imienia
    void setName(const string& name) {
        this->name = name;
    }

    // Getter dla wieku
    int getAge() const {
        return age;
    }

    // Setter dla wieku
    void setAge(int age) {
        this->age = age;
    }

    // Wirtualna metoda do wyświetlania szczegółów (można nadpisać)
    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Wirtualny destruktor
    virtual ~Employee() {}
};

// Klasa pochodna dla Dyrektora
class Director : public Employee {
private:
    string department;  // Ukryte dane: dział

public:
    // Konstruktor
    Director(string name, int age, string department)
        : Employee(name, age), department(department) {}

    // Getter dla działu
    string getDepartment() const {
        return department;
    }

    // Setter dla działu
    void setDepartment(const string& department) {
        this->department = department;
    }

    // Nadpisanie metody displayDetails
    void displayDetails() override {
        cout << "Director - Name: " << getName() << ", Age: " << getAge()
            << ", Department: " << department << endl;
    }
};

// Klasa pochodna dla Nauczyciela
class Teacher : public Employee {
private:
    string subject;  // Ukryte dane: przedmiot

public:
    // Konstruktor
    Teacher(string name, int age, string subject)
        : Employee(name, age), subject(subject) {}

    // Getter dla przedmiotu
    string getSubject() const {
        return subject;
    }

    // Setter dla przedmiotu
    void setSubject(const string& subject) {
        this->subject = subject;
    }

    // Nadpisanie metody displayDetails
    void displayDetails() override {
        cout << "Teacher - Name: " << getName() << ", Age: " << getAge()
            << ", Subject: " << subject << endl;
    }
};

// Klasa pochodna dla Wychowawcy
class Educator : public Employee {
private:
    int classGroup;  // Ukryte dane: grupa klasowa

public:
    // Konstruktor
    Educator(string name, int age, int classGroup)
        : Employee(name, age), classGroup(classGroup) {}

    // Getter dla grupy klasowej
    int getClassGroup() const {
        return classGroup;
    }

    // Setter dla grupy klasowej
    void setClassGroup(int classGroup) {
        this->classGroup = classGroup;
    }

    // Nadpisanie metody displayDetails
    void displayDetails() override {
        cout << "Educator - Name: " << getName() << ", Age: " << getAge()
            << ", Class Group: " << classGroup << endl;
    }
};

// Klasa pochodna dla Sekretarza
class Secretary : public Employee {
private:
    string office;  // Ukryte dane: biuro

public:
    // Konstruktor
    Secretary(string name, int age, string office)
        : Employee(name, age), office(office) {}

    // Getter dla biura
    string getOffice() const {
        return office;
    }

    // Setter dla biura
    void setOffice(const string& office) {
        this->office = office;
    }

    // Nadpisanie metody displayDetails
    void displayDetails() override {
        cout << "Secretary - Name: " << getName() << ", Age: " << getAge()
            << ", Office: " << office << endl;
    }
};

// Program testowy
int main() {
    // Zmienne do danych testowych
    string name, department, subject, office;
    int age, classGroup;

    // Dane wejściowe dla Wychowawcy
    cout << "Enter Educator's Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Class Group: ";
    cin >> classGroup;

    // Tworzenie obiektu Wychowawcy
    Educator educator(name, age, classGroup);

    // Wyświetlanie szczegółów
    cout << "Educator Details:" << endl;
    educator.displayDetails();

    // Zmiana danych za pomocą setterów
    educator.setName("Jan Kowalski");
    educator.setAge(40);
    educator.setClassGroup(2);

    // Wyświetlanie zmodyfikowanych danych
    cout << "\nUpdated Educator Details:" << endl;
    educator.displayDetails();

    return 0;
}
