#ifndef STUDENT_H
#define STUDENT_H
/* @Author
 * Student Name:  Enes Fidan
 */
#include <iostream>

class Student{
public:
    Student() = default; // default constructor to allow user to create an object with no initial values

    Student(const std::string& , double , double , double);
    
    void set_name(const std:: string&); // sets student name
    
    //Getters

    // a const method that returns student's GPA 
    double getGPA()const;
    // a const method that returns student's GRE
    double getGRE()const;

    // a const method that returns student's TOEFL score
    double getTOEFL()const;

    // a const method that returns student's name as const reference so that it wont be modified somehow 
    const std::string& getName()const;


    //updates application number
    void updateApplicationNum() const;

    // copy constructor for student object
    Student(const Student&);


    ~Student();
private:
    std::string m_Name{}; 
    double m_GPA{};
    double m_GRE{};
    double m_TOEFL{};
    mutable int m_AppNum{};

};








#endif