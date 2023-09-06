#include <iostream>
#include <ostream>
#include <string>


class Bureaucrat{
private:
    const std::string   _name;
    int                 _grade;

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