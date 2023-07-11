/* @Author  Enes Fidan
 */

#include "../include/university.h"

University::University(const std::string& uni_name, double gpa_score, double gre_score, double toefl_score,double bias, const std::string& country_name)
:m_UniName{uni_name}, m_GPA{gpa_score}, m_GRE{gre_score},m_TOEFL{toefl_score}, m_Bias{bias}, m_CountryName{country_name}
{ }

void University::evaluate_student(const Student& student) const 
{
    double result = m_GPA* student.getGPA() + m_GRE * student.getGRE() + m_TOEFL* student.getTOEFL() + m_Bias;

    if(result >= 0)
    {
        std::cout << student.getName() <<" is admitted to " << m_UniName << "." << std::endl;   
    }
    else
        std::cout << student.getName() <<" is rejected from " << m_UniName <<"." <<std::endl;
    
    student.updateApplicationNum();
}   
