#include "Form.hpp"

int main()
{
    Bureaucrat Bae("bae", 5);
    Bureaucrat JustFan("Fan", 120);

    Form album1("previous album", 140, 140);
    Form album2("new album", 10, 10);

    std::cout << "\n\n";
    album1.beSigned(Bae);
    album1.signForm(Bae);
    std::cout << "\n\n";
    album2.beSigned(Bae);
    album2.signForm(Bae);
    std::cout << "\n\n";
    album1.beSigned(JustFan);
    album1.signForm(JustFan);
    std::cout << "\n\n";
    album2.beSigned(JustFan);
    album2.signForm(JustFan);

    std::cout << "\n\n";
    Form *NewAlbum = new Form("Dice");
    std::cout << NewAlbum;
}