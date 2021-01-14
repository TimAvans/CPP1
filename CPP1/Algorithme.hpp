#pragma once
#include "iostream"
#include <map>
#include <random>
#include <memory>
#include "Database.hpp"


class Algorithme {
public:
	Algorithme(int language_id);
	std::map<char, int> Get_Alfabet_Counted();

    std::string Run_Algorithme(const std::string& start_sentence);
private:
	std::string alfabet_string = "abcdefghijklmnopqrstuvwxyz";
	//Build a string with the values in alfabet map
	std::string Build_String(const std::string& start_sentence);

	//Set the start random values in alfabet map
	void Set_Alfabet_Random(bool reset = false);

	std::map<int, std::string> written_numbers;

	//Reset the values in the alfabet map
	void Set_Alfabet_Nul();

	std::unique_ptr<Database> db = std::make_unique<Database>("../numerals.db");

	int language_id;
	std::map<char, int> alfabet;
	std::map<char, int> prev_alfabet;

};