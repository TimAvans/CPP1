#include "IO_Handler.hpp"

IO_Handler::IO_Handler()
{
}

IO_Handler::~IO_Handler()
{
}

std::string IO_Handler::Read_Input() noexcept
{
	std::string input{};

	std::getline(std::cin, input);
	
	return input;
}

int IO_Handler::Read_Language_Id() noexcept
{
	std::string input{};

	std::getline(std::cin, input);

	try
	{
		if (isdigit(input[0]))
		{
			if (stoi(input) < 1 || stoi(input) > 2)
			{
				throw input + " is given. Make sure it is the digit 1 or 2";
			}
			else 
			{
				return stoi(input);
			}
		}
		else 
		{
			throw input + " is given. This is neither 1 or 2";
		}
	}
	catch (const std::string& error)
	{
		std::cerr << error << std::endl;
		std::cout << "Dutch will be set as language due to invalid input" << std::endl;
	}

	return 1;
}

void IO_Handler::Write_Welcome_Message(int language_id) noexcept
{
	(language_id == 1) ? Write_Message("Welkom bij Tim's AUTOPANGRAM Services\nSchrijf uw gewilde zin hieronder: ") : Write_Message("Welcome to Tim's AUTOPANGRAM Services\nWrite your sentence down below: ");
}

void IO_Handler::Write_Done_Message(int language_id) noexcept
{

}

void IO_Handler::Write_Started_Message(int language_id, std::string input) noexcept
{
	
	(language_id == 1) ? Write_Message("Het proces is gestart met de zin: " + input) : Write_Message("The process started with the sentence: " + input);
}

void IO_Handler::Write_Counted_Alfabet(std::map<char, int> alfabet) noexcept
{
	for (auto a : alfabet)
	{
		std::cout << a.first;
		std::cout << " : ";
		std::cout << a.second << std::endl;
	}
}

void IO_Handler::Write_Message(std::string message) noexcept
{
	std::cout << message << std::endl;
}
