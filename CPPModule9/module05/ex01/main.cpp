#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat Bae("bae", 5);
    Bureaucrat JustFan("Fan", 120);

    Form album1("previous album", 140, 140);
    Form album2("new album", 10, 10);

    std::cout << "\n\n";
    album1.beSigned(Bae);
    Bae.signForm(album1);

    std::cout << "\n\n";
    album2.beSigned(Bae);
    Bae.signForm(album2);
    
    std::cout << "\n\n";
    album1.beSigned(JustFan);
    JustFan.signForm(album1);
    
    std::cout << "\n\n";
    album2.beSigned(JustFan);
    JustFan.signForm(album2);

    std::cout << "\n\n";
    Form *NewAlbum = new Form("Dice");
    std::cout << NewAlbum;
}