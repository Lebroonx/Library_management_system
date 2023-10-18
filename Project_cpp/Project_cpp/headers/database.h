#ifndef DATABASE_H
#define DATABASE_H

#include <stdlib.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
using namespace std;
sql::Driver* driver;
sql::Connection* con;
sql::Statement* stmt;
sql::PreparedStatement* pstmt;
sql::ResultSet* res;

struct book
{
	int id;
	string name;
	string author;
	string genre;
}bk[100];

class Connection
{
public:
	virtual void conn() = 0;
private:
protected:
};

class ConnectionSQL : public Connection
{
public:
	void conn() override;
	void get_data();
private:
	const string server = "localhost";
	const string username = "root";
	const string password = "";
protected:

};

class ConnectionDB : public Connection
{
public:
	void conn() override;
private:
protected:
};

#endif // !DATABASE_H
