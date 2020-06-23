#include <iostream>
#include <string>
#include "db.h"
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <conio.h>
#include <fstream>
#include "./../filehandling/filehandling.h"
#include "./../login/login.h"
#include "./../rainbow/rainbow.h"

using namespace std;

void db::AddPrisonerData()
{
   db p2;
   convict_data p1;
   fflush(stdin);
   cout << "Enter name" << endl;
   getline(cin, p1.name);
   cout << "Enter Blood Group" << endl;
   cin >> p1.BloodGroup;
   fflush(stdin);
   cout << "Enter crime committed" << endl;
   getline(cin, p1.crime);
   fflush(stdin);
   cout << "Enter Medical History" << endl;
   getline(cin, p1.medical);
   fflush(stdin);
   cout << "Enter dob" << endl;
   cin >> p1.dob;
   fflush(stdin);
   cout << "Enter Address" << endl;
   getline(cin, p1.adrs);
   fflush(stdin);
   cout << "Enter sex" << endl;
   cin >> p1.sex;
   fflush(stdin);
   cout << "Enter Sentence Duration" << endl;
   getline(cin, p1.duration);
   fflush(stdin);
   cout << "Enter Convict's Age" << endl;
   getline(cin, p1.age);
   fflush(stdin);

   p2.data.push_back(p1);

   //Creating a file in write mode

   fstream Database;
   Database.open("Data.txt", ios::out | ios::app);
   for (vector<convict_data>::iterator i = p2.data.begin(); i != p2.data.end(); ++i)
   {
      int a = (20 - i->name.length());
      int b = (15 - i->BloodGroup.length());
      int c = (21 - i->crime.length());
      int d = (25 - i->medical.length());
      int e = (17 - i->dob.length());
      int f = (37 - i->adrs.length());
      int g = (12 - i->sex.length());
      int h = (12 - i->duration.length());
      int j = (11 - i->age.length());
      Database << "|" << i->name << string(a, ' ') << "|" << i->BloodGroup << string(b, ' ') << "|" << i->crime << string(c, ' ') << "|" << i->medical << string(d, ' ') << "|" << i->dob << string(e, ' ') << "|" << i->adrs << string(f, ' ') << "|" << i->sex << string(g, ' ') << "|" << i->duration << string(h, ' ') << "|" << i->age << string(j, ' ') << "|" << endl;
   }
   Database.close();
}

void db::DisplayPrisonerData()
{
   string line;
   ifstream infile;
   infile.open("Data.txt");
   while (getline(infile, line))
   {
      cout << line << endl;
   }
   infile.close();
}

void db::DeletePrisonerData()
{
   string Name;
   cout << "Enter the name to be Deleted" << endl;
   cin >> Name;
   string line;
   fstream offile;
   fstream newfile;
   offile.open("Data.txt", ios::out | ios::in);
   newfile.open("temp.txt", ios::out | ios::app);
   while (getline(offile, line))
   {
      size_t found = line.find(Name);
      if (found != string::npos)
      {
         line.erase(line.begin(), line.end());
      }
      else
      {
         newfile << line << "\n";
      }
   }
   offile.close();
   newfile.close();
   remove("C:\\cygwin64\\home\\MasterChief\\jail-management-system\\Data.txt");
   char oldname[] = "temp.txt";
   char newname[] = "Data.txt";
   rename(oldname, newname);
}

void db::SecuritySettings()
{
   fstream ob1;
   string line;
   password = "";
   ob1.open("Password.txt", ios::in | ios::out);
   getline(ob1, line);
   string OldPassword, NewPassword, ConfirmNewPassword;
   cout << "Enter Current password" << endl;
   ;
   Login::PassKeyEncoder();
   OldPassword = password;
   if (OldPassword == line)
   {
      ob1.close();
      getchar();
      cout << "Enter New Password" << endl;
      password = "";
      Login::PassKeyEncoder();
      NewPassword = password;
      cout << "confirm New Password" << endl;
      password = "";
      Login::PassKeyEncoder();
      ConfirmNewPassword = password;
      if (NewPassword == ConfirmNewPassword)
      {
         ob1.open("Password.txt", ios::in | ios::out | ios::trunc);
         ob1 << NewPassword;
         cout << "\n " << rainbow::safe("Password Changed Successfully") << endl;
         ob1.close();
      }
      else
      {
         cout << "\n " << rainbow::warn("Passwords Do Not Match!") << endl;
      }
   }
   else
   {
      cout << "\n " << rainbow::warn("Passwords Do Not Match!") << endl;
   }
}
