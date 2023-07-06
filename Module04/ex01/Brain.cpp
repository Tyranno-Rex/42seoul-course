#include "Brain.hpp"

Brain::Brain(void)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "no idea\n";
    std::cout << "I have an idea that I have no idea\n";
}

Brain::~Brain(void)
{
    std::cout << "Brain Dead\n";
}

Brain::Brain(const Brain &ref)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = ref.ideas[i];
    std::cout << "Copy: Brain is Copied\n";
}

Brain& Brain::operator=(const Brain &ref)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = ref.ideas[i];
    std::cout << "Copy(=): Brain is Copied\n";
    return (*this);
}

void Brain::setIdea(int i, std::string content)
{
    this->ideas[i] = content;
    std::cout << "SetIdea: Brain[" << i <<"]'s Idea is set\n";
}

void Brain::setAllIdea(std::string content)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = content;
    std::cout << "SetAllIdea: All Brain's Ideas are set\n";
}

std::string Brain::GetIdea(int i)
{
    return (this->ideas[i]);
}