#include "BookList.h"
#include <iostream>
#include<cstring>

using namespace std;
BookList::BookList()
{
    booksCount=0;

}
BookList::BookList(const BookList& blist)
{
    capacity=blist.capacity;
    booksCount=blist.booksCount;
    books=blist.books;

}

BookList::~BookList()
{

    if(capacity>0)
    {
        delete [] books;
    }
}

BookList::BookList(int c)
{
    booksCount=0;
    capacity=c;
    books=new Book [capacity];

}
Book BookList:: operator[](int i)
{
    if( i > capacity )
    {
        cout << "Index out of bounds" <<endl;

        return books[0];
    }

    return books[i];
}

ostream &operator<<(ostream &output,  BookList &booklist )
{
    for(int i=0; i<booklist.booksCount; i++)
    {

        output<<booklist.books[i];
        if(booklist.books[i].getAuthor().getName()!="")
        {
            cout<<booklist.books[i].getAuthor()<<endl;
        }

    }
    return output;
}

bool BookList:: addBook(Book b)
{
    if(booksCount<capacity)
    {
        if(b.getAuthor().getName()!="")
        {
            books[booksCount].setAuthor(b.getAuthor());
            books[booksCount]=b;
        }
        else
        {
            books[booksCount]=b;
        }

        booksCount++;
        return true;
    }
    else
    {
        cout<<"you can't add book the list is full  "<<endl;
        return false;
    }

}

Book BookList::searchBook(string name)
{
    for(int i=0; i<booksCount; i++)
    {
        string temp=books[i].getTitle();

        if(name==temp)
        {
            cout<<"Book found"<<endl;
            cout<<books[i];
            return books[i];
        }

    }
    cout<<"book not found"<<endl;

}
Book BookList:: searchBook(int id)
{
    for(int i=0; i<booksCount; i++)
    {
        int temp=books[i].getId();

        if(id==temp)
        {
            cout<<"Book found"<<endl;
            cout<<books[i];
            return books[i];
        }

    }
    cout<<"book not found"<<endl;
}

void BookList::deleteBook(int id)
{
    int z;
    for(z=0; z<booksCount; z++)
    {
        int temp=books[z].getId();

        if(id==temp)
        {
            break;
        }

    }
    if(z<booksCount)
    {
        booksCount=booksCount-1;
        for (int j=z; j<booksCount; j++)
        {
            books[j] = books[j+1];
        }

        for(int y=0; y<booksCount; y++)
        {
            cout<<books[y]<<endl;
            cout<<"----------------------------"<<endl;
        }
    }

}


Book BookList:: getTheHighestRatedBook()
{
    int index=0;
    double maxim=books[0].getAverageRating();
    for (int e=1; e<booksCount; e++)
    {
        if((books[e].getAverageRating())>maxim)
        {
            maxim=books[e].getAverageRating();
            index=e;
        }

    }

    cout<<"Book with highest rate is:  ----------"<<endl;
    cout<<books[index];
    return books[index];

}
Book BookList::getBooksForUser(User u)
{
    for(int x=0; x<booksCount; x++)
    {
        User temp=books[x].getAuthor();
        if(temp==u)
        {
            cout<<"bookfound"<<"-----------"<<endl;
            cout<< books[x];
            return books[x];
        }

    }

}

