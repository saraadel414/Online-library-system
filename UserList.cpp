#include "UserList.h"
#include "User.h"
#include <iostream>
#include<cstring>

using namespace std;


UserList::UserList(int cap)
{
    usersCount=0;
    capacity=cap;
    users=new User[cap];

}

void UserList::addUser(User user)
{
    if(usersCount<capacity)
    {
        users[usersCount]= user;
        usersCount++;
    }
    else
    {
        cout<<"can't add user,array is full"<<endl;
    }

}
User UserList::searchUser(string name)
{

    for(int i=0; i<usersCount; i++)
    {
        if (name==users[i].getName())
        {
            cout<<"user found"<<endl;
            cout<< users[i];
            return users[i];
        }
    }
    cout<<"user not found"<<endl;
}
User UserList::searchUser(int id)
{

    for(int i=0; i<usersCount; i++)
    {
        if (id == users[i].getId())
        {
            cout<< users[i];
            return users[i];
        }
    }
    cout<<"user not found"<<endl;

}
void UserList::deleteUser(int id)
{
    int i;
    for(i=0; i<usersCount; i++)
    {
        if (id == users[i].getId())
        {
            break;
        }
    }
    if(i<usersCount)
    {
        usersCount = usersCount - 1;
        for (int j=i; j<usersCount; j++)
        {
            users[j] = users[j+1];
        }
        for(int y=0; y<usersCount; y++)
        {
            cout<<users[y]<<endl;
             cout<<"----------------------------"<<endl;
       }
    }

}



ostream &operator<<( ostream &output, UserList &userList )
{

    for (int i=0; i<userList.usersCount; i++)
    {
        output<<userList.users[i]<<endl;
    }
    return output;
}

UserList::~UserList()
{
    if(capacity>0)
    {
        delete[] users;
    }
}
