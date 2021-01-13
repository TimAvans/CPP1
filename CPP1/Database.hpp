#pragma once
#include "sqlite3.h"
#include "stdio.h"
#include <iostream>
#include <vector>
class Database {
public:
	Database(const char* directory);

	std::string Select_Number(int number, int language_id);

	void Close_Database();
private:
	//Variables
	const char* directory;
	sqlite3* DB;
	int open;

	//Opens database in readonly if db does not exist it will not be created
	void Open_DB();

	//Retrieves the contents of the database
	static int callback(void* no_use, int argc, char** argv, char** col_name);
};