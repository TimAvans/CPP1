#include "Database.hpp"
#include <string>

Database::Database(const char* directory)
{
	this->directory = directory;
	Open_DB();
}

void Database::Open_DB()
{
	try
	{
		open = sqlite3_open_v2(directory, &DB, SQLITE_OPEN_READONLY, nullptr);

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}

}

std::string Database::Select_Number(int number, int language_id = 1)
{
	int exit = 0;
	//SQL
	std::string where_value = " AND value = " + std::to_string(number);
	std::string start = "select num";
	std::string where_language = " from numerals where language_id = " + std::to_string(language_id);
	std::string string_sql = start + where_language + where_value;

	//Retrieved data
	std::vector<std::string> result_str;

	const char* sql = string_sql.c_str();
	char* error{};

	try
	{
		//SELECT num FROM numerals WHERE language_id = 1 ORDER BY value;
		exit = sqlite3_exec(DB, sql, callback, &result_str, &error);
		if (exit != SQLITE_OK)
		{
			std::cerr << error << std::endl;
			sqlite3_free(error);
			throw exit;
		}
	}
	catch (int e)
	{
		std::cerr << sqlite3_errstr(e) << std::endl;
	}

	if (result_str.capacity() == 0)
	{
		result_str.push_back("nul");
	}

	return result_str[0];
}

int Database::callback(void* records, int argc, char** argv, char** col_name)
{
	std::vector<std::string>* result_str = static_cast<std::vector<std::string>*>(records);

	try {
		result_str->push_back(argv[0]);

	}
	catch (...) {
		return 1;
	}
	return 0;
}

void Database::Close_Database() 
{
	sqlite3_close(DB);
}