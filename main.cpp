#include "include/classes.hpp"

class Student
{
    private:
        int id;
        std::string name;
        std::vector<double> grades;
        double average;

    public:
        Student(int id, std::string name, std::vector<double> grades);

        int getId();
        std::string getName();
        std::vector<double> getGrades();
        double getAverage();
        
        void calculateAverage(); // TODO: implement this function
        bool hasFailed();

        friend std::ostream& operator<<(std::ostream& out, const Student& student);
};

Student::Student(int id, std::string name, std::vector<double> grades)
{
    this->id = id;
    this->name = name;
    this->grades = grades;
}

int Student::getId()
{
    return this->id;
}

std::string Student::getName()
{
    return this->name;
}

std::vector<double> Student::getGrades()
{
    return this->grades;
}

double Student::getAverage()
{
    return this->average;
}

bool Student::hasFailed()
{
    return this->average > 5.0;
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
    out << "ID: " << student.id << "\n" << "Name: " << student.name << "\n" << "Grades: [ ";

    for(double i : student.grades)
    {
        out << i << " ";
    }

    out << "]\n" << "Average: " << student.average << "\n";

    return out;
}

int main(void)
{
    Faculty acs("ACS", {Student("John Doe", {7.0, 5.0, 9.9}, 1), Student("Jane doe", {4.5, 6.0, 1.0}, 2)});

    acs.printPassingStudents();
    acs.printFailingStudents();
    std::cout << acs;
    
    return 0;
}