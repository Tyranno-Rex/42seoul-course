#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat{
private:
    const std::string   _name;
    int                 _grade;
    void                setGrade(int grade);

public:
    // 디폴드 생성자, 생성자, 소멸자
    Bureaucrat(void);
    Bureaucrat(std::string name);
    Bureaucrat(int grade);
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat(void);

    // 클래스 내의 함수
    std::string getName() const;
    int         getGrade() const;
    void        signForm(Form &form) const;

    //  increment or decrement the bureaucrat grade
    void increment(void);
    void decrement(void);

    // 오버로딩
    Bureaucrat &operator=(const Bureaucrat &ref);
    
    // 예외처리 exception
    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &oper, Bureaucrat *Bur);

#endif