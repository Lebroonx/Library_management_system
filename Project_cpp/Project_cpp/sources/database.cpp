#include "../headers/database.h"

void ConnectionSQL::conn()
{
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
}

void ConnectionSQL::get_data()
{
    pstmt = con->prepareStatement("SELECT * FROM book;");
    res = pstmt->executeQuery();
    int i = 0;
    while (res->next())
    {
        bk[i].id = res->getInt("id");
        bk[i].name = res->getString("name");
        bk[i].author = res->getString("author");
        bk[i].genre = res->getString("genre");
        i++;
    }
}

void ConnectionDB::conn()
{
    if (bk[0].id == 0)
    {
        cout << "Erreur" << endl;
    }
}

int main()
{
    ConnectionSQL myobj;
    myobj.conn();
    myobj.get_data();
    ConnectionDB myobj1;
    myobj1.conn();
    cout << bk[0].id << bk[0].author << bk[0].genre;
}