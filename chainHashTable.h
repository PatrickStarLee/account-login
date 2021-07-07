#ifndef CHAINHASHTABLE_H
#define CHAINHASHTABLE_H
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Hash{
    private:   
        struct account{//implementing username/password authentication
            string user;
            string pass;
            account* next;
        };

        static const int tableSize = 10;//default hash table size
        account* hashTable[tableSize];

    public:
        Hash();
        int hashFunc(string key);
        void addAccount(string user, string pass);
        void printTable();
        void printItemsInIndex(int index);
        bool login(string user, string pass);
        void removeAccount(string user);

};




#endif