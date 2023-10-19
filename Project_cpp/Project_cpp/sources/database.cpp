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

void BookManagement::show_books()
{
    ConnectionSQL::get_data();
    cout << "\nListe des livres\n\nNom du livre\t\tAuteur\n" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (bk[i].id != 0)
        {
            cout << bk[i].name << "\t\t" << bk[i].author << "\t" << endl;
        }
    }
    system("pause");
}

void BookManagement::search_book()
{
    cout << "\nEntrer le nom du livre: ";
    getline(cin, searchdata);
    cout << "\n\nNom du livre\t\tAuteur\n" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (searchdata == bk[i].name)
        {
            cout << bk[i].name << "\t\t" << bk[i].author << "\t" << endl;
        }
    }
}

void BookManagement::search_author()
{
    cout << "\nEntrer le nom de l'auteur: " << endl;
    getline(cin, searchdata);
    cout << "\n\nNom du livre\t\tAuteur\n" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (searchdata == bk[i].author)
        {
            cout << bk[i].name << "\t\t" << bk[i].author << "\t" << endl;
        }
    }
    system("pause");
}

void BookManagement::add_books()
{
    cout << "\nEntrer le nom du livre: " << endl;
    getline(cin, getname);
    cout << "\nEntrer le nom de l'auteur: " << endl;
    getline(cin, getauthor);
    cout << "\nEntrer le genre du livre: " << endl;
    getline(cin, getgenre);
    pstmt = con->prepareStatement("INSERT INTO book (name, author, genre) VALUES (?,?,?);");
    pstmt->setString(1, getname);
    pstmt->setString(2, getauthor);
    pstmt->setString(3, getgenre);
    res = pstmt->executeQuery();
    system("pause");
}

void BookManagement::modify_book()
{
    cout << "\nEntrer le nom du livre: " << endl;
    getline(cin, searchdata);
    cout << "\nChanger le nom du livre: " << endl;
    getline(cin, getname);
    cout << "\nChanger le nom de l'auteur: " << endl;
    getline(cin, getauthor);
    cout << "\nChanger le genre du livre: " << endl;
    getline(cin, getgenre);
    pstmt = con->prepareStatement("UPDATE book SET name = ?, author = ?, genre = ? WHERE name = ?");
    pstmt->setString(1, getname);
    pstmt->setString(2, getauthor);
    pstmt->setString(3, getgenre);
    pstmt->setString(4, searchdata);
    res = pstmt->executeQuery();
    system("pause");
}

void BookManagement::delete_book()
{
    cout << "\nEntrer le nom du livre: " << endl;
    getline(cin, searchdata);
    pstmt = con->prepareStatement("DELETE FROM book WHERE name = ?");
    pstmt->setString(1, searchdata);
    res = pstmt->executeQuery();
    system("pause");
}

void BookManagement::exit_app()
{
    exit(0);
}

void BookManagement::menu()
{
    cout << "\nLibrary management system\n\n1. Montrer la liste des livres\n2. Rechercher un livre\n3. Rechercher les livres d'un auteur\n4. Ajouter un livre\n5. Modifier un livre\n6. Supprimer un livre\n7. Sortir\n\nQue voulez vous faire : " << endl;
    cin >> j;

    switch (j)
    {
    case 1:
        show_books();
        break;

    case 2:
        search_book();
        break;

    case 3:
        search_author();
        break;

    case 4:
        modify_book();
        break;

    case 5:
        delete_book();
        break;

    case 6:
        add_books();
        break;

    case 7:
        exit_app();
    default:
        printf("Veuillez selectionner une valeur correcte");
        exit(0);
    }

}

int main()
{
    ConnectionSQL Myobj;
    Myobj.conn();
    Myobj.get_data();
    BookManagement Livre;
    /*do 
    {
        Livre.menu();
    } while (j != 7);*/
    Livre.search_book();
}