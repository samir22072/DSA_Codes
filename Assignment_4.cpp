//============================================================================
// Name        : Assignment_4.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class TelephoneDirectory;

class HashEntry
{
private:
    string name;
    long long int key;
    int flag;

public:
    HashEntry()
    {
        this->name = "";
        this->key = 0;
        this->flag = 0;
    }
    HashEntry(string key, long long int telephoneNo)
    {
        this->name = key;
        this->key = telephoneNo;
        this->flag = 0;
    }
    friend class TelephoneDirectory;
};

class TelephoneDirectory
{
private:
    HashEntry *ht;
    bool status;

public:
    TelephoneDirectory()
    {
        ht = new HashEntry[10];
        status = false;
    }
    void insertWithoutReplace(string name, long long int telephoneNo);
    void insertWithReplace(string name, long long int telephoneNo);
    int hashingFunc(long long int key, int initialInd);
    int search(long long int key);
    void update(long long int key, string newName);
    void deleteKey(long long int key);
    void display();
};

void TelephoneDirectory::update(long long int key, string newName)
{
    cout << "Initial Value of the key: "
         << "\n";
    int val = this->search(key);
    if (val == -1)
    {
        cout << "There is no such key in the hash table"
             << "\n";
    }
    else
    {
        ht[val].name = newName;
    }
}

int TelephoneDirectory::hashingFunc(long long int key, int initialInd)
{
    int index = 0;
    long long int sum = 0;
    while (key != 0)
    {
        sum += key % 10;
        key = key / 10;
    }
    index = sum % 10 + initialInd;
    return index;
}

int TelephoneDirectory::search(long long int key)
{
    int hi = this->hashingFunc(key, 0);
    if (ht[hi].key == key)
    {
        return hi;
    }
    int ind = 0;
    ind = (hi + 1) % 10;
    while (ind != hi)
    {
        if (ht[ind].key == key)
        {
            return ind;
        }
        else
        {

            ind = (ind + 1) % 10;
        }
    }

    cout << "Element not found in the Hash Table" << endl;
    return -1;

    // if(ht[hi].key==key ){
    // cout<<ht[hi].key<<" : "<<ht[hi].telephoneNo<<endl;
    // }
    // else{
    // cout<<"Element not found in the Hash Table"<<endl;
    //
    // }
}

void TelephoneDirectory::insertWithoutReplace(string name,
                                              long long int key)
{
    int hi = this->hashingFunc(key, 0);
    if (ht[hi].key == 0)
    {
        ht[hi].name = name;
        ht[hi].key = key;
        ht[hi].flag = 1;
    }
    else
    {
        int ind = 0;
        ind = (hi + 1) % 10;
        while (ind != hi)
        {
            if (ht[ind].key == 0)
            {
                ht[ind].key = key;
                ht[ind].name = name;
                ht[ind].flag = 0;
                break;
            }
            else
            {
                ind = (ind + 1) % 10;
            }
        }
    }
}

void TelephoneDirectory::insertWithReplace(string name,
                                           long long int key)
{
    int hi = this->hashingFunc(key, 0);

    if (ht[hi].key == 0)
    {
        ht[hi].key = key;
        ht[hi].name = name;
        ht[hi].flag = 1;
    }

    else
    {
        long long int tempKey = 0;
        string tempName;

        if (ht[hi].flag == 0)
        {
            tempKey = ht[hi].key;
            tempName = ht[hi].name;

            ht[hi].key = key;
            ht[hi].name = name;
            ht[hi].flag = 1;

            int ind = 0;
            ind = (hi + 1) % 10;
            while (ind != hi)
            {
                if (ht[ind].key == 0)
                {
                    ht[ind].key = tempKey;
                    ht[ind].name = tempName;
                    ht[ind].flag = 0;
                    break;
                }
                else
                {
                    ind = (ind + 1) % 10;
                }
            }
        }
        else if (ht[hi].flag == 1)
        {
            this->insertWithoutReplace(name, key);
        }
    }
}
void TelephoneDirectory::deleteKey(long long int key)
{
    int val = this->search(key);
    if (val != -1)
    {
        for (int i = val; i < 9; i++)
        {
            ht[i].key = ht[(i + 1) % 10].key;
            ht[i].name = ht[(i + 1) % 10].name;
        }
    }
}

void TelephoneDirectory::display()
{
    for (int i = 0; i < 10; i++)
    {
        if (ht[i].key != 0)
            cout << i << " " << ht[i].key << " : " << ht[i].name << endl;
    }
}

int main()
{
    TelephoneDirectory t;
    t.insertWithoutReplace("a", 9819261702);
    t.insertWithoutReplace("A", 9819261602);
    t.insertWithoutReplace("b", 9619642144);
    t.insertWithoutReplace("c", 9821218029);
    t.insertWithoutReplace("d", 9372829601);
    t.insertWithoutReplace("f", 9876565357);
    t.insertWithoutReplace("e", 8765434356);

    t.display();
    cout << "\n";
    t.deleteKey(8765434356);
    cout << "\n";
    t.display();
    return 0;
}
