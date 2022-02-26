#include "User.h"
#include <iostream>
#include<cstring>

using namespace std;

int User::coun=0;


User::User()
{
    coun++;
    setId(coun);
    name="";
    age=0;
    password="";
    email="";

}



User::User(string n, int ag, string em, string pass)
{
    name=n;
    age=ag;
    email=em;
    password=pass;

}


User::User(const User& user)
{
    name=user.name;
    age=user.age;
    email=user.email;
    password=user.password;
    id=user.id;
}

void User::setName(string n)
{
    name=n;
}
string User::getName()const
{
    if (name.empty())
    {
        return name;
    }
}

void User::setAge(int ag)
{
    age=ag;
}

int User::getAge()
{
    return age;
}

void User::setEmail(string em)
{
    email= em;
}
string User::getEmail()
{
    return email;
}

void User::setPassword(string pass)
{
    password= pass;
}
string User::getPassword()
{
    return password;
}

void User::setId(int ID)
{
    id=ID;

}

int User::getId()
{
    return id;

}

bool User::operator==(const User& user)const
{
    if (user.name==name && user.age==age && user.id==id && user.email==email)
    {
        return true;
    }
    else
    {
        return false;
    }


}
istream &operator>>( istream &input, User &user )
{
    cout<<"Let's add a User"<<endl<<"Enter the User information in this order"<<endl<<"Name Age Email Password(space separated)"<<endl;
    input>>user.name>>user.age>>user.email>>user.password;
    return input;

}
ostream &operator<<(ostream &output, const User &user )
{
    output<<"========User "<<user.id<<" info========"<<endl;
    output<<"Name: "<<user.name<<endl<<"Age: "<<user.age<<endl<<"ID: "<<user.id<<endl<<"Email: "<<user.email<<endl;
    output<<"==========================================="<<endl;
    return output;

}

