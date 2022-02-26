#ifndef BOOKLIST_H
#define BOOKLIST_H
#include <iostream>
#include<cstring>
#include "Book.h"
using namespace std;

class BookList
{
private:
    Book *books ;
    int capacity;
    int booksCount;
public:
    BookList();
    BookList(const BookList& other);
    BookList(int capacity);
    bool addBook(Book b);
    friend ostream &operator<<(ostream &output,  BookList &booklist );
    Book operator[](int i);
    Book searchBook(string name);
    Book searchBook(int id);
    void deleteBook(int id);
    Book getTheHighestRatedBook();
    Book getBooksForUser(User u);
    virtual ~BookList();

};

#endif // BOOKLIST_H
