#include <iostream>
#include <cstring>
using namespace std;

class Student {
    int id, *scores, numScores;
    char name[50];
public:
    Student(int studID, const char* studName, int* studScores, int num) : id(studID), numScores(num) {
        strcpy(name, studName);
        scores=new int[numScores];
        for (int i=0;i<numScores;i++) scores[i] = studScores[i];
    }
    Student(const Student& other) : id(other.id), numScores(other.numScores) {
        strcpy(name, other.name);
        scores = new int[numScores];
        for (int i= 0;i<numScores;i++) scores[i] = other.scores[i];
    }
    ~Student() { delete[] scores; }
    void display() {
        cout << "Student ID: " << id << "\nName: " << name << "\nScores: ";
        for (int i=0;i<numScores; i++) cout << scores[i] << " ";
        cout << "\n";
    }
};

int main() {
    int scores[] = {85, 90, 78};
    Student stud1(1, "Alice", scores, 3), stud2 = stud1;
    cout << "Original Student:\n"; stud1.display();
    cout << "Copied Student:\n"; stud2.display();
    return 0;
}