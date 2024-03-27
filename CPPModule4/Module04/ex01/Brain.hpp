#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <string>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain(void);
    ~Brain(void);
    Brain(const Brain &ref);
    Brain& operator=(const Brain &ref);

    void setIdea(int i, std::string content);
    void setAllIdea(std::string content);
    std::string GetIdea(int i);
};

#endif