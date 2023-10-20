#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
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


// list of books as a database
struct book
{
	int id;
	string name;
	string author;
	string genre;
}bk[100];
string searchdata;
string getname;
string getauthor;
string getgenre;
int j;

// template method to check connection to a database
class Connection
{
public:
	virtual void conn() = 0;
private:
protected:
};

// Connection to MySQL database
class ConnectionSQL : public Connection
{
public:
	// check connection to database
	void conn() override;
	// fetch the database in the list of books
	void get_data();
private:
	// datas to connect to the database
	const string server = "localhost";
	const string username = "root";
	const string password = "";
protected:

};

class ConnectionDB : public Connection
{
public:
	// check if the list of book is filled
	void conn() override;
private:
protected:
};

class BookManagement: ConnectionSQL
{
public:
	void menu();
	void show_books();
	void search_book();
	void search_author();
	void add_books();
	void modify_book();
	void delete_book();
	void exit_app();
private:
protected:

};

#endif // !DATABASE_H