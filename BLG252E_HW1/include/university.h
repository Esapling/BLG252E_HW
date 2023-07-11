/* @Author
 * Student Name:  Enes Fidan
 */

#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include <iostream>
#include "../include/student.h"


class University{
public:
    University() = default;  // default constructor to allow user to create an object with no initial values

    University(const std::string& , double , double, double ,double , const std::string& = "");
    
    void evaluate_student(const Student&) const;

private:
    const std::string m_UniName{};
    double m_GPA;
    double m_GRE;
    double m_TOEFL;
    double m_Bias;
    const std::string m_CountryName{};
};







#endif

