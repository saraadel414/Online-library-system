#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "User.h"
using namespace std;
class Book
{
public:
    Book();
    Book(const Book& other);
    Book(string title, string isbn, string category);

    void setTitle(string title);
    string getTitle();
    void setISBN(string isbn);
    string getISBN();
    void setId(int id);
    int getId();
    double getAverageRating();
    void setCategory(string category);
    string getCategory();
    void setAuthor(User user);
    User getAuthor();
    void rateBook(int rating);
    bool operator==(const Book& book);
    friend ostream &operator<<(ostream &output,  Book &book );
    friend istream &operator>>( istream &input, Book &book );

    bool isEmpty() ;
    static int countt;

private:
    string title;
    string isbn;
    int ID;
    string category;
    double averageRating;
    int rate;
    User author;

};

#endif // BOOK_H

