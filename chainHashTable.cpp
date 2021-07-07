#include <iostream>
#include <string>
#include <cstdlib>
#include "chainHashTable.h"
using namespace std;

Hash::Hash(){//default constructor creates empty account in each array entry
    for(int i = 0; i<tableSize; i++){
        hashTable[i] = new account;
        hashTable[i]->user = "n/a";
        hashTable[i]->pass = "n/a";
        hashTable[i]->next = NULL;
    }
}

int Hash::hashFunc(string key){//converts key into index
    int hash = 0;
    int index;
    for(int i = 0; i<key.length(); i++){
        hash += (int) key[i];
    }

    index = hash % tableSize;
    return index;
    
}

bool Hash::login(string user, string pass){
    int index = hashFunc(user);
    account* ptr = hashTable[index];

    if(ptr->user == "n/a"){
        return false;
    }else if(ptr->user == user && ptr->pass == pass){
        return true;
    }else{
        while(ptr->next!=NULL){
            ptr = ptr->next;
            if(ptr->user == user && ptr->pass == pass){
                return true;
            }
        }
    }
    return false;
}

void Hash::addAccount(string user, string pass){
    int index = hashFunc(user);

    if(hashTable[index]->user == "n/a"){
        hashTable[index]->user = user;
        hashTable[index]->pass = pass;

    }else{

        account* ptr = hashTable[index];
        account* newUser = new account;
        newUser->user = user;
        newUser->pass = pass;
        newUser->next = NULL;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = newUser;//once ptr->next points to NULL, add newUser to the end of linked list
    }
}

void Hash::removeAccount(string user){
    //Case 0 - index is empty (no accounts)
    //Case 1 - only 1 account in index and item has matching name
    //Case 2 - match located in 1st account in the index but there are more accounts in index
    //Case 3 - index contains account but 1st account isn't a match
    //  *Case 3.1 - no match
    //  *Case 3.2 - match found

    int index = hashFunc(user);

    account* delPtr;
    account* p1;//pointer 1
    account* p2;//pointer 2

    if(hashTable[index]->user == "n/a"){//Case 0
        cout << user << "'s account was not found."<<endl;

    }else if(hashTable[index]->user == user && hashTable[index]->next == NULL){//Case 1
        hashTable[index]->user = "n/a";
        hashTable[index]->pass = "n/a";
        cout << user << "'s account was successfully deleted.\n";

    }else if(hashTable[index]->user == user){//Case 2
        delPtr = hashTable[index];
        hashTable[index] = hashTable[index]->next;//points to the next account in index;
        delete delPtr;

        cout << user << "'s account was successfully deleted.\n";

    }else{//Case 3
        p1 = hashTable[index]->next; //points to next account in link list
        p2 = hashTable[index]; 

        while(p1 != NULL && p1->user != user){
            p2 = p1;
            p1 = p1->next;
        }

        if(p1 == NULL){//Case 3.1
            cout << user << "'s account was not found."<<endl;

        }else{//Case 3.2
            delPtr = p1;
            p1 = p1->next;
            p2->next = p1;
            delete delPtr;
            cout << user << "'s account was successfully deleted.\n";

        }
    }
}

void Hash::printItemsInIndex(int index){
    account* ptr = hashTable[index];
    while(ptr->next != NULL){
        ptr = ptr->next;
        cout << "------------\n";
        cout << ptr->user << endl;
        cout << ptr->pass << endl;
        cout << "------------\n";
    }
}

void Hash::printTable(){
    int number;
    for(int i = 0; i<tableSize; i++){
        cout << "----------------------------\n";
        cout << "index = " << i << endl;
        cout << hashTable[i]->user << ", " << hashTable[i]->pass << endl;
        printItemsInIndex(i);
        cout << "----------------------------\n";
    }

}

