#include "Database_RAII.hpp"

Database_RAII::Database_RAII(){}

Database_RAII::~Database_RAII()
{
	db.Close_Database();
}

Database_RAII::Database_RAII(Database_RAII&& other) noexcept
{
	Set_Database(other.Get_Database());
}

Database_RAII& Database_RAII::operator=(Database_RAII&& other) noexcept
{
	std::swap(Get_Database(), other.Get_Database());
	return *this;
}

Database& Database_RAII::Get_Database()
{
	return db;
}

void Database_RAII::Set_Database(Database db)
{
	this->db = db;
}


