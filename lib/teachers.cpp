#include <iostream>
#include "users.cpp"
#include <fstream>
using namespace std;

class Teacher : public Users
{
public:
    Teacher(string n, string u, string p)
    {
        name = n;
        username = u;
        password = p;

        fstream fin("TeacherInfo.txt", ios::app);
        fin << name << " " << username << " " << password << endl;
    }
    // bool checkAllCloHasBeenTested(Courses)
    // {
    // }

    bool login(string username, string password)
    {
        fstream fin("TeacherInfo.txt");
        string word;
        string username1, password1;
        while (fin >> word)
        {
            fin >> username1;
            fin >> password1;

            if (username1 == username && password1 == password)
            {
                return true;
            }
        }
        return false;
    }
};
