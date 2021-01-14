#pragma once
#include "Database.hpp"


//Deze word niet meer gebruikt, ik maak gebruik van een smartpointer
class Database_RAII {
public:
	Database_RAII();
	~Database_RAII();

	// forbid copying
	Database_RAII(const Database_RAII& other) = delete;
	Database_RAII& operator=(const Database_RAII& other) = delete;

	// allow move
	Database_RAII(Database_RAII&& other) noexcept;
	Database_RAII& operator=(Database_RAII&& other) noexcept;

	Database& Get_Database();

	void Set_Database(Database db);

private:
	Database db{ "../numerals.db" };
};