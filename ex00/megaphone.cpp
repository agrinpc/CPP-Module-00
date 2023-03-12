#include <iostream>

int	main(int argc, char **argv)
{
	int		i = 0;
	int		j;
	char	*s;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (++i < argc)
	{
		j = -1;
		s = argv[i];
		while (++j < std::strlen(s))
    		s[j] = std::toupper(s[j]);
		std::cout << s;
	}
	std::cout << std::endl;
	return (0);
}