/* @Author  Enes Fidan
 */
#include "../include/university.h"

Student::Student(const std::string& name, double gpa_score, double gre_score, double toefl_score)
:m_Name{name}, m_GPA{gpa_score}, m_GRE{gre_score}, m_TOEFL{toefl_score} , m_AppNum{0}
{ 
    std::cout << m_Name << " logged in to the system."<< std::endl;
}

void Student::set_name(const std::string& new_name){
    m_Name = new_name;
}

Student::Student(const Student& another)
:Student{ another.m_Name, another.m_GPA, another.m_GRE, another.m_TOEFL} // copy constructor delegates to another consturctor
{ 
}

double Student::getGPA() const { 
    return this->m_GPA; 
} 

double Student::getGRE() const { 
    return this->m_GRE; 
}
double Student::getTOEFL() const { 
    return this->m_TOEFL; 
}
const std::string& Student::getName() const { 
    return this->m_Name;
}

void Student::updateApplicationNum()const {
    this->m_AppNum += 1;
}

Student::~Student(){
    std::cout << this->m_Name << " logged out of the system with "<< this->m_AppNum << " application(s)." << std::endl;
}

