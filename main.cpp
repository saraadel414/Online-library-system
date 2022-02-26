#include <iostream>
#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "Book.h"
#include "BookList.h"
using namespace std;

int main()
{
    cout<<"How many users will be added?"<<endl;
    int num;
    cin>>num;
    UserList u2(num);

    cout<<"How many books will be added?"<<endl;
    int num1;
    cin>>num1;
    BookList b2(num1);

    string screen;
    screen = "Select one of the following choices: \n1-Books menu \n2-Users menu \n3-Exit \n";
    string BookScreen;
    BookScreen = "BOOKS MENU\n1-Create a BOOK\n2-Search for a book\n3-Display all books(with book rating)\n4-Get the highest rating book\n5-Get all books of a user\n6-copy current book list to a new list\n7-Back to the main menu\n";
    string Userscreen;
    Userscreen = "USERS MENU \n1-Create a USER \n2-Search for a user \n3-Display all users \n4-Back to the main menu\n";
    string SearchScreen;
    SearchScreen = "SEARCH FOR A USER: \n1-Search by name \n2-Search by id \n3-Return to users menu \n";
    string AuthorScreen;
    AuthorScreen = "1-Assign Author \n2-Rate book \n3-Continue\n";
    string SearchScreenB;
    SearchScreenB = "SEARCH FOR A BOOK: \n1-Search by name \n2-Search by id \n3-Return to books menu \n";
    string DeleteScreen;
    DeleteScreen = "1-Delete User \n2-Return to User menu\n";
    string DeleteScreenB;
    DeleteScreenB = "1-Delete Book \n2-Return to Book menu\n";

    int choice;
    int UserChoice;
    int SearchChoice;
    int BookChoice;
    int AuthorChoice;
    int SearchChoiceB;
    int DeleteChoice;
    int DeleteChoiceB;

    while(cout << screen && cin>> choice || BookChoice ==7 || UserChoice ==4)  ///////MAIN MENU/////
    {
/////////////////////////////////BOOK MENU//////////////////////////////////////
        if(choice ==1 || SearchChoice==3 || DeleteChoiceB==2 || AuthorChoice==3)
        {
            int j;
            while(cout << BookScreen && cin>> BookChoice && BookChoice !=7 )
            {
                /////////////////////Add BOOK////////////////////

                if(BookChoice==1 || j!=num1)
                {
                    for(j=0; j<num1; j++)
                    {
                        Book b1;
                        cin>>b1;

                        while(cout << AuthorScreen && cin>> AuthorChoice && AuthorChoice!=3)
                        {
                            if(AuthorChoice==1)   //////Assign Author///////
                            {
                                cout<<"Enter User ID"<<endl;
                                int id3;
                                cin>>id3;
                                User temp;
                                temp = u2.searchUser(id3);
                                b1.setAuthor(temp);

                            }
                            else if(AuthorChoice==2) //////Rate book///////
                            {
                                cout<<"Enter Book Rate"<<endl;
                                int rate;
                                cin>>rate;
                                b1.rateBook(rate);
                            }

                        }
                        b2.addBook(b1);
                   }


                }
                //////////////////Search Book////////////////////
                else if(BookChoice== 2)
                {
                    while(cout << SearchScreenB && cin>> SearchChoiceB && SearchChoiceB!=3)
                    {
                        if(SearchChoiceB==1) //////Search by name/////
                        {
                            string name;
                            cout<<"Enter Name:"<<endl;
                            cin>>name;
                            b2.searchBook(name);
                        }
                        else if(SearchChoiceB==2)  //////Search by id/////
                        {
                            int id;
                            cout<<"Enter ID:"<<endl;
                            cin>>id;
                            b2.searchBook(id);
                        }
                    }
                }
                //////////////////Display all books////////////////////
                else if(BookChoice==3)
                {
                    cout<<b2;
                    while(cout << DeleteScreenB && cin>> DeleteChoiceB && DeleteChoiceB!=2)
                    {
                        if(DeleteChoiceB ==1)   //////////Delete Book////////////
                        {
                            int id2;
                            cout<<"Enter ID:"<<endl;
                            cin>>id2;
                            b2.deleteBook(id2);
                        }

                    }
                }
                //////////////////Highest rate book////////////////////
                else if(BookChoice ==4)
                {
                    b2.getTheHighestRatedBook();
                }
                //////////////////Get all books of a user////////////////////
                else if(BookChoice ==5 )
                {
                    cout<<"Enter User ID"<<endl;
                    int id3;
                    cin>>id3;
                    User temp;
                    temp = u2.searchUser(id3);
                    b2.getBooksForUser(temp);
                }
                //////////////////Copy book////////////////////
                else if(BookChoice ==6)
                {
                    BookList b=b2;
                    cout<<"Copied current list to a new list and switched to it"<<endl;
                }

            }
        }
/////////////////////////////////USER MENU//////////////////////////////////////
        else if (choice ==2 || SearchChoice==3 || DeleteChoice==2)
        {
            while(cout << Userscreen && cin>> UserChoice && UserChoice !=4)
            {
                /////////////////////Add User////////////////////
                if(UserChoice ==1)
                {
                    for(int i=0; i<num; i++)
                    {
                        User u1;
                        cin>>u1;
                        u2.addUser(u1);
                    }

                }
                //////////////////Search User////////////////////
                else if(UserChoice ==2)
                {
                    while(cout << SearchScreen && cin>> SearchChoice && SearchChoice!=3)
                    {
                        if(SearchChoice==1) //////Search by name/////
                        {
                            string name;
                            cout<<"Enter Name:"<<endl;
                            cin>>name;
                            u2.searchUser(name);
                        }
                        else if(SearchChoice==2)  //////Search by id/////
                        {
                            int id;
                            cout<<"Enter ID:"<<endl;
                            cin>>id;
                            u2.searchUser(id);
                        }

                    }
                }
                //////////////////Display all Users////////////////////
                else if(UserChoice ==3)
                {
                    cout<<u2;
                    while(cout << DeleteScreen && cin>> DeleteChoice && DeleteChoice!=2)
                    {
                        if(DeleteChoice ==1)   //////////Delete User////////////
                        {
                            int id2;
                            cout<<"Enter ID:"<<endl;
                            cin>>id2;
                            u2.deleteUser(id2);
                        }

                    }
                }
            }

        }
/////////////////////////////////Exit MENU//////////////////////////////////////
        else if(choice ==3)
        {
            return 0;
        }
        else
        {
            cout<<"invalid input"<<endl;
        }


    }
    return 0;
}
