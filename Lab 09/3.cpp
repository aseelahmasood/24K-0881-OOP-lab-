#include <iostream>
using namespace std;

// Abstract Class
class Course {
protected:
    string courseCode;
    int credits;

public:
    Course(string code, int cr) : courseCode(code), credits(cr) {}

    virtual double calculateGrade() = 0;
    virtual void displayInfo() = 0;

    virtual ~Course() {}
};

// Derived Class for LectureCourse
class LectureCourse : public Course {
private:
    double midtermScore, finalExamScore;

public:
    LectureCourse(string code, int cr, double midterm, double finalExam)
        : Course(code, cr), midtermScore(midterm), finalExamScore(finalExam) {}

    double calculateGrade() override {
        return (midtermScore * 0.4 + finalExamScore * 0.6);
    }

    void displayInfo() override {
        cout << "Lecture Course: " << courseCode << " | Credits: " << credits
             << " | Final Grade: " << calculateGrade() << "\n";
    }
};

// Derived Class for LabCourse
class LabCourse : public Course {
private:
    double labPerformance, projectScore;

public:
    LabCourse(string code, int cr, double performance, double project)
        : Course(code, cr), labPerformance(performance), projectScore(project) {}

    double calculateGrade() override {
        return (labPerformance * 0.5 + projectScore * 0.5);
    }

    void displayInfo() override {
        cout << "Lab Course: " << courseCode << " | Credits: " << credits
             << " | Final Grade: " << calculateGrade() << "\n";
    }
};

int main() {
    Course* c1 = new LectureCourse("CS101", 3, 78, 88);
    Course* c2 = new LabCourse("CS102L", 1, 85, 90);

    c1->displayInfo();
    c2->displayInfo();

    delete c1;
    delete c2;
    return 0;
}
