#include<iostream>
#include"./../database/database.h"
// #include"./../db/db.h"
#include"Homescreen.h"

using namespace std;


void CMD_WIND::MainMenu(){
        int ch; 
        cout<<"1) View Convict Details"<<endl;
        cout<<"2) Edit Convict Details"<<endl;
        cout<<"3) Visitor Data"<<endl;
        cout<<"4) Prisoner Parole Details"<<endl;
        cout<<"5) Security Settings"<<endl;
        cout<<"6) Exit"<<endl;
        do {
        cout<<"Enter choice: "<<endl;
        cin>>ch;
        switch(ch) {
            case 1: {   
                
                db::DisplayPrisonerData();
                break;
            }
            case 2: {
                cout<<"1) Add Prisoner Details"<<endl;
                cout<<"2) Delete Prisoner Details"<<endl;
                cout<<"3) Go Back"<<endl;
                do{
                    cout<<"Enter Choice"<<endl;
                    cin>>ch;
                    switch(ch){
                        case 1:{
                            db::AddPrisonerData();
                        }
                        case 2:{
                            db::DeletePrisonerData();
                        }
                        default:{
                            CMD_WIND::MainMenu();
                        }
                    }
                }while(ch!=3);
            }
            
            case 3: {
                db::DisplayVisitorData();
                break;
            }
            case 4: {
                db::DisplayParoleDetails();
                break;
            }
            case 5: {
                db::SecuritySettings();
                break;
            }
            
            case 6: {
                cout<<"Exit"<<endl;
                break;
            }
            default: {
                cout<<"Invalid Choice"<<endl;
            }
      }
   }while(ch!=6); 
}