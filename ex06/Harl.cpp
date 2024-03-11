#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::complain(std::string level)
{
	void		(Harl::*funcs[4])(void);
	std::string	levels[4];

	funcs[0] = &Harl::debug;
	funcs[1] = &Harl::info;
	funcs[2] = &Harl::warning;
	funcs[3] = &Harl::error;
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			for (int j = i; j < 4; j++)
			{
				std::cout << "[ " << levels[j] << " ]" << std::endl;
				(this->*funcs[j])();
				std::cout << std::endl;
			}
			break ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
