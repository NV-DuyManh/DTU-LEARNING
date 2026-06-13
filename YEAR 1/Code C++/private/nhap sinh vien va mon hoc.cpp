#include<iostream>
#include<string>

class Student {
    std::string name;
    int age;
    float grade_math, grade_phys, grade_chemistry;

public:
    // Default constructor
    Student() : name(""), age(0), grade_math(0), grade_phys(0), grade_chemistry(0) {}

    // Parameterized constructor
    Student(std::string n, int a, float gm, float gp, float gc) : name(n), age(a), grade_math(gm), grade_phys(gp), grade_chemistry(gc) {}

    // Copy constructor
    Student(const Student& s) : name(s.name), age(s.age), grade_math(s.grade_math), grade_phys(s.grade_phys), grade_chemistry(s.grade_chemistry) {}

    // Destructor
    ~Student() {}

    // Getter and Setter functions
    std::string getName() const { return name; }
    int getAge() const { return age; }
    float getGradeMath() const { return grade_math; }
    float getGradePhys() const { return grade_phys; }
    float getGradeChem() const { return grade_chemistry; }

    void setName(std::string n) { name = n; }
    void setAge(int a) { age = a; }
    void setGradeMath(float gm) { grade_math = gm; }
    void setGradePhys(float gp) { grade_phys = gp; }
    void setGradeChem(float gc) { grade_chemistry = gc; }

    // Input and Output functions
    void Input() {
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter age: ";
        std::cin >> age;
        std::cout << "Enter grade in Math: ";
        std::cin >> grade_math;
        std::cout << "Enter grade in Physics: ";
        std::cin >> grade_phys;
        std::cout << "Enter grade in Chemistry: ";
        std::cin >> grade_chemistry;
    }

    void Output() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Grade in Math: " << grade_math << "\n";
        std::cout << "Grade in Physics: " << grade_phys << "\n";
        std::cout << "Grade in Chemistry: " << grade_chemistry << "\n";
    }

    // Function to calculate Grade Point Average
    float gradePointAverage() const {
        return (grade_math + grade_phys + grade_chemistry) / 3;
    }
};

int main() {
    // Create a Student object by default constructor
    Student s1;
    // Call Input() and Output() function
    s1.Input();
    s1.Output();
    // Print Grade Point Average of Student
    std::cout << "Grade Point Average: " << s1.gradePointAverage() << "\n";

    // Create new Student object copy from above Student by Copy Constructor
    Student s2 = s1;
    // Print information of that Student
    s2.Output();

    return 0;
}

