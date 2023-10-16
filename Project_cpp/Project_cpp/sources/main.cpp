
#include <stdlib.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
using namespace std;

const string server = "localhost";
const string username = "root";
const string password = "";

int main()
{
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::PreparedStatement *pstmt;
    sql::ResultSet *res;

    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to server" << endl;
        exit(0);
    }

    con->setSchema("testc");

    pstmt = con->prepareStatement("SELECT * FROM inventory;");
    res = pstmt->executeQuery();
    while (res->next())
    {
        cout << res->getInt("id") << endl;
        cout << res->getString("name") << endl;
        cout << res->getInt("quantity") << endl;
    }



    /*delete pstmt;
    delete con;
    system("pause");*/
    return 0;
}