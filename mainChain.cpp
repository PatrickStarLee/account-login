#include <iostream>
#include <string>
#include <cstdlib>
#include "chainHashTable.h"

using namespace std;

int main(){
    Hash hashObj;
    string userName, password;
    int option;// 1 is login and 2 is sign up

    cout<<"   Welcome to Facebook."<<endl;
    cout<<"\t Login (1)"<<endl;
    cout<<"\tSign Up (2)"<<endl;
    cout<<"Enter here: ";
    cin>>option;

    hashObj.addAccount("Sammy765", "alien39!");
    hashObj.addAccount("MasterMark", "ninja@6");
    hashObj.addAccount("Munchies27", "chips64!");
    hashObj.addAccount("Bob", "TheBuilder");
    hashObj.addAccount("Paula", "Beauty243");

    while(true){
        if(option == 1){
        cout<<"Username: ";
        cin>>userName;
        cout<<"Password: ";
        cin>>password;
        bool loginCred = hashObj.login(userName, password);

            if(loginCred == false){
                cout << userName << "'s account was not found."<<endl;
            }else{
                cout<<"\nWelcome "<<userName<<"!\n"<<endl;
                
                hashObj.printTable();

                char choice;
                cout<<"\nDelete account? (y/n) ";
                cin>>choice;
                if(choice == 'y'){
                    hashObj.removeAccount(userName);
                    cout<<"\n";
                    hashObj.printTable();
                }
                break;
            }

        }else if(option == 2){
            cout<<"Type your username: ";
            cin>>userName;
            cout<<"Type your password: ";
            cin>>password;
            hashObj.addAccount(userName, password);
            cout<<"Account was created."<<endl;
            hashObj.printTable();
            break;

        }else{
            cout<<"Try again"<<endl;
        }

        cout<<"\t Login (1)"<<endl;
        cout<<"\tSign Up (2)"<<endl;
        cout<<"Enter here: ";
        cin>>option;
    }
    
}