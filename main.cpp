#include "include/classes.hpp"



int main(void)
{
    Faculty acs("ACS", {Student("John Doe", {7.0, 5.0, 9.9}, 1), Student("Jane doe", {4.5, 6.0, 1.0}, 2)});

    acs.printPassingStudents();
    acs.printFailingStudents();
    std::cout << acs;
    
    return 0;
}