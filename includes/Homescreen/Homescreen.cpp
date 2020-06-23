#include <iostream>
#include "Homescreen.h"
#include "./../db/db.h"

using namespace std;

void CMD_WIND::MainMenu()
{
    int ch, ch1;

    do
    {
        cout << "********************************************************************************************************************************************************************************************************" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "**********************************************" << endl;
        cout << "*            1) View Convict Details         *" << endl;
        cout << "*            2) Edit Convict Details         *" << endl;
        cout << "*            3) Change Password              *" << endl;
        cout << "*            4) Exit                         *" << endl;
        cout << "**********************************************" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "********************************************************************************************************************************************************************************************************" << endl;
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {

            db::DisplayPrisonerData();
            break;
        }
        case 2:
        {
            cout << "***********************************************"<< endl;
            cout << "*          1) Add Prisoner Details            *"<< endl;
            cout << "*          2) Delete Prisoner Details         *"<< endl;
            cout << "*          3) Go Back                         *"<< endl;
            cout << "***********************************************"<< endl;
            do
            {
                cout << "Enter Choice" << endl;
                cin >> ch1;
                switch (ch1)
                {
                case 1:
                {
                    db::AddPrisonerData();
                    break;
                }
                case 2:
                {
                    db::DeletePrisonerData();
                    break;
                }
                case 3:
                {
                    //CMD_WIND::MainMenu();
                    break;
                }
                }
            } while (ch1 != 3);
            break;
        }

        case 3:
        {
            db::SecuritySettings();
            break;
        }

        case 4:
        {
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 4);
}