#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	std::string tmp;
	for (int i = 1; i < argc; i++)
	{
		tmp = argv[i];
		for (size_t i = 0; i < tmp.size(); i++)
			tmp[i] = toupper(tmp[i]);
		std::cout << tmp;
		if (i != argc - 1)
			std::cout << ' ';
	}
	std::cout << "\n";
	return (0);
}
