#pragma once
#include <iostream>
#include <sstream>
#include <map>
class IO_Handler {
public:
	IO_Handler();
	~IO_Handler();

	std::string Read_Input() noexcept;
	int Read_Language_Id() noexcept;
	void Write_Message(std::string message) noexcept;
	void Write_Welcome_Message(int language_id) noexcept;
	void Write_Done_Message(int language_id) noexcept;
	void Write_Started_Message(int language_id, std::string input) noexcept;
	void Write_Counted_Alfabet(std::map<char, int> alfabet) noexcept;
private:
	std::string welcome_message;
};