#include "Book.h"
#include <iostream>
#include "User.h"
using namespace std;

int Book::countt=0;

Book::Book()
{
    countt++;
    setId(countt);
    rate=0;
    averageRating=0;
    title="";
    isbn="";
    category="";


}

Book::Book(const Book& other)
{
    title=other.title;
    isbn=other.isbn;
    category=other.category;
    averageRating=other.averageRating;
    author=other.author;
    rate=other.rate;
    ID=other.ID;
}
Book::Book(string t, string is, string cat)
{
    title=t;
    isbn=is;
    category=cat;

}

void Book::setTitle(string t)
{
    title=t;
}
string Book::getTitle()
{
    return title;
}

void Book::setISBN(string is)
{
    isbn=is;
}

string Book::getISBN()
{
    return isbn;
}

void Book::setId(int I)
{
    ID=I;
}

int Book::getId()
{
    return ID;
}

void Book::setCategory(string cat)
{
    category=cat;
}

string Book::getCategory()
{
    return category;
}

void Book::setAuthor(User user)
{
    author=user;
}

User Book::getAuthor()
{
    return author;
}

double Book::getAverageRating()
{
    return averageRating;
}

void Book::rateBook(int rating)
{
    averageRating=(rate+rating)/(double)2;
    rate=rating;
}

bool Book::operator==(const Book& book)
{
    if(book.author==author&&book.category==category&&book.title==title&&book.isbn==isbn&&book.ID==ID)
    {
        return true;

    }
    else
    {
        return false;
    }
}

ostream &operator<<(ostream &out,  Book &book )
{
    out<<"======Book "<<book.getId()<<" info======"<<endl;
    out<<"Title: "<<book.getTitle()<<endl<<"ISBN: "<<book.getISBN()<<endl<<"Id: "<<book.getId()<<endl<<"Category: "<<book.getCategory()<<endl<<"Avg Rating: "<<book.averageRating<<endl<<endl;
    if(book.author.getName()!="")
    {
        cout<<book.getAuthor()<<endl;
    }

    return out;
}
istream &operator>>( istream &in, Book &book )
{
    cout<<"Let's add a book"<<endl<<"Enter the book information in this order"<<endl<<"Title ISBN Category(space separated)"<<endl;
    in>>book.title>>book.isbn>>book.category;
    return in;
}


