#ifndef USER_H
#define USER_H
#include <iostream>
#include<cstring>

using namespace std;
class User
{

    private:
        string name;
        int age;
        int id;
        string password;
        string email;

    public:

        static int coun;

        User();
        User(string name, int age, string email, string password);
        User(const User& user);

        bool operator==(const User& user)const;
        void setName(string name);
        string getName() const;
        void setPassword(string password);
        string getPassword();
        void setEmail(string email);
        string getEmail();
        void setAge(int age);
        int getAge();
        void setId(int id);
        int getId();
        friend ostream &operator<<(ostream &output, const User &user );
        friend istream &operator>>( istream &input, User &user );

};

#endif // USER_H
