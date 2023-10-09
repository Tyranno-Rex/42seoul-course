#include "Base.hpp"

void leak(){
    system("leaks");
}

int main(void)
{
    srand(time(NULL));
    const int len = 10;
    Base *generatedClasses[len];

    atexit(leak);
    std::memset(generatedClasses, 0, sizeof(generatedClasses)); 
    for (int i = 0; i < len; i++)
        generatedClasses[i] = generate();
    for (int i = 0; i < len; i++){
        identify(generatedClasses[i]);
        identify(*generatedClasses[i]);
    }
    for (int i = 0; i < len; i++){
        delete generatedClasses[i];
        generatedClasses[i] = NULL;
		identify(generatedClasses[i]);
	}
    return 0;
}
