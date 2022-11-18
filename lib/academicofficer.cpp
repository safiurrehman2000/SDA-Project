#include <iostream>
#include "users.cpp"
using namespace std;

class AcademicOfficer : public Users
{
public:
    AcademicOfficer(string n, string u, string p)
    {
        name = n;
        username = u;
        password = p;

        fstream fin("AOInfo.txt", ios::app);
        fin << name << " " << username << " " << password << endl;
    }

    bool login(string username, string password)
    {
        fstream fin("AOInfo.txt");
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