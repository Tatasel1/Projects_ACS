#include <iostream>
#include <string>
#include <cstring>

class Student {
private:
    std::string name;  // Student's name
    float* grades;     // Dynamic array of grades
    int numGrades;     // Number of grades

public:
    // Constructor
    Student(const std::string& studentName, int numberOfGrades)
        : name(studentName), numGrades(numberOfGrades)
    {
        grades = new float[numGrades]; // Allocate memory for grades
        for (int i = 0; i < numGrades; ++i)
            grades[i] = 0.0f; // Initialize all grades to 0
    }

    // Destructor
    ~Student() {
        delete[] grades; // Free allocated memory
    }


    // Function to set a grade
    void setGrade(int index, float grade) {

        if (index >= 0 && index < numGrades)
            grades[index] = grade;
        else
            std::cerr << "Invalid grade index\n";
    }

    ///adaugat constructor pentru deep copy astfel incat a fio posibila modificarea notei doar pentru student2
  Student(const Student& student) {
        name = student.name;
        numGrades = student.numGrades;

        grades = new float[numGrades];
        for (int i = 0; i < numGrades; ++i)
            grades[i] = student.grades[i];
    }


    // Function to display student info
    void display() const {
        std::cout << "Name: " << name << "\nGrades: ";
        for (int i = 0; i < numGrades; ++i)
            std::cout << grades[i] << " ";
        std::cout << "\n \n";
    }
};

// Example usage
int main() {
    Student student1("Mihai Pop", 4);
    student1.setGrade(0, 8);
    student1.setGrade(1, 9);
    student1.setGrade(2, 6);
    student1.setGrade(3, 7);

    Student student2=student1;

    student2.setGrade(0, 9);


    student1.display();
    student2.display();

    return 0;
}

///in versiunea facuta de LLM (am folosit ChatGpt) acesta nu adauga un deep copy constructor, astfel incat in momentul in care apelam student2=student1 si incercam sa modific nota studentului 2, se schimba nota si pt primul student,
///deoarece vectorul grades este de tip pointer.Shallow Copy-ul imi modifica ambele note deoarece student2 a fost copiat la aceeasi adresa din memorie ca student1,iar faptul ca il modific pe unul il va modifica si pe al doilea, astfel daca doresc
///sa modific doar nota pentru student2 va fi nevoie de un deep copy
