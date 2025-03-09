#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string personName, int personAge) : name(personName), age(personAge) {}
    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Teacher : virtual public Person {
protected:
    string subject;
public:
    Teacher(string personName, int personAge, string subjectExpertise)
        : Person(personName, personAge), subject(subjectExpertise) {}
    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject Expertise: " << subject << endl;
    }
};

class Researcher : virtual public Person {
protected:
    string researchArea;
public:
    Researcher(string personName, int personAge, string area)
        : Person(personName, personAge), researchArea(area) {}
    void displayDetails() override {
        Person::displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;
public:
    Professor(string personName, int personAge, string subjectExpertise, string area, int numPublications)
        : Person(personName, personAge), Teacher(personName, personAge, subjectExpertise), 
          Researcher(personName, personAge, area), publications(numPublications) {}
    void displayDetails() override {
        Person::displayDetails();
        cout << "Subject Expertise: " << subject << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main() {
    Professor prof("Dr. John Smith", 50, "Computer Science", "Artificial Intelligence", 25);
    prof.displayDetails();
    return 0;
}
