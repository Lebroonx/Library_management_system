//#include <stdlib.h>
//#include <iostream>
//#include "mysql_connection.h"
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/prepared_statement.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>
//using namespace std;
//sql::Driver* driver;
//sql::Connection* con;
//sql::Statement* stmt;
//sql::PreparedStatement* pstmt;
//sql::ResultSet* res;
//
//struct book
//{
//    int id;
//    string name;
//    string author;
//    string genre;
//}bk[100];
//
//class Connection 
//{
//public:
//    virtual void conn() = 0;
//private:
//
//protected:
//};
//
//class ConnectionSQL: public Connection
//{
//public:
//    void conn() override
//    {
//        try
//        {
//            driver = get_driver_instance();
//            con = driver->connect(server, username, password);
//        }
//        catch (sql::SQLException e)
//        {
//            cout << "Could not connect to server" << endl;
//            exit(0);
//        }
//        con->setSchema("testc");
//    }
//
//    void get_data()
//    {
//        pstmt = con->prepareStatement("SELECT * FROM book;");
//        res = pstmt->executeQuery();
//        int i = 0;
//        while (res->next())
//        {
//            bk[i].id = res->getInt("id");
//            bk[i].name = res->getString("name");
//            bk[i].author = res->getString("author");
//            bk[i].genre = res->getString("genre");
//            i++;
//        }
//    }
//
//private:
//    const string server = "localhost";
//    const string username = "root";
//    const string password = "";
//protected:
//};
//
////class ConnectionDB : public Connection
////{
////public:
////    void conn()
////    {
////        try
////        {
////
////        }
////        catch (const std::exception&)
////        {
////
////        }
////    }
////private:
////
////protected:
////};
//
////class Book_management
////{
////public:
////    void data()
////    {
////        pstmt = con->prepareStatement("SELECT * FROM book;");
////    }
////private:
////
////protected:
////};
//
//int main()
//{
//    ConnectionSQL myobj;
//    myobj.conn();
//    myobj.get_data();
//    cout << bk[0].name << bk[0].author << bk[0].genre << endl;
//
//    /*delete pstmt;
//    delete con;
//    system("pause");*/
//    return 0;
//}