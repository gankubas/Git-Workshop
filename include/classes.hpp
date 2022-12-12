#include "libs.hpp"

// TODO move Student here

class University
{
    protected:
        std::string name;
        std::vector<Student> students;

    public:
        University(std::string name, std::vector<Student> students);

        std::string getName();
        std::vector<Student> getStudents();

        void addStudent(Student student);
        virtual void printPassingStudents() = 0;  
        virtual void printFailingStudents() = 0;
};

University::University(std::string name, std::vector<Student> students)
{
    this->name = name;
    this->students = students;
}

std::string University::getName()
{
    return this->name;
}

std::vector<Student> University::getStudents()
{
    return this->students;
}

void University::addStudent(Student student)
{
    this->students.push_back(student);
}

class Faculty : public University
{
    private:
        std::vector<std::string> courses = {"PC", "SDA", "POO", "SS", "TSA"};

    public:
        Faculty(std::string name, std::vector<Student> students);

        void addStudent(Student student);
        void printPassingStudents();  
        void printFailingStudents();

        friend std::ostream& operator<<(std::ostream& out, const Faculty& faculty);
};

Faculty::Faculty(std::string name, std::vector<Student> students) : University(name, students) {}

void Faculty::addStudent(Student student)
{
    this->students.push_back(student);
}

void Faculty::printPassingStudents()
{
    std::cout << "Passing students: " << std::endl;
    for (Student student : this->students)
    {
        if (!student.hasFailed())
        {
            std::cout << student << std::endl;
        }
    }
}

void Faculty::printFailingStudents()
{
    std::cout << "Failing students: " << std::endl;
    for (Student student : this->students)
    {
        if (student.hasFailed())
        {
            std::cout << student << std::endl;
        }
    }
}

std::ostream& operator<<(std::ostream& out, const Faculty& faculty)
{
    out << "Name: " << faculty.name << std::endl;
    out << "Students: " << std::endl;

    for(int i = 0; i < faculty.students.size(); i++)
    {
        out << faculty.students.at(i) << "\n\t";

        for(double j : faculty.students.at(i).getGrades())
        {
            out << "Studentul " << faculty.students.at(i).getName() << j < 5 ? " a picat materia " : "a trecut materia " << faculty.students.at(i).getCourse() << "\n";
        }
    }

    return out;
}