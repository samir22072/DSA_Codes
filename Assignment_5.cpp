//============================================================================
// Name        : Assignment_5.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define size 10

class HashEntryNode
{
private:
    string word;
    string meaning;
    HashEntryNode *next;

public:
    HashEntryNode()
    {
        word = "";
        meaning = "";
        next = NULL;
    }
    HashEntryNode(string word, string meaning)
    {
        this->word = word;
        this->meaning = meaning;
        this->next = NULL;
    }
    friend class HashTable;
};

class HashTable
{
private:
    HashEntryNode *arr[size];

public:
    HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = NULL;
        }
    }
    int hashingFunction(string word);
    void insert(string word, string meaning);
    void deleteWord(string word);
    void update(string word, string newMeaning);
    void display();
    HashEntryNode *search(string word);
};
int HashTable::hashingFunction(string word)
{
    int ans = 0;
    int len = word.length();
    for (int i = 0; i < len; i++)
    {
        ans += word[i];
    }
    ans %= size;
    return ans;
}

void HashTable::insert(string word, string meaning)
{
    int hi = this->hashingFunction(word);
    if (arr[hi] == NULL)
    {
        HashEntryNode *newNode = new HashEntryNode(word, meaning);
        arr[hi] = newNode;
    }
    else
    {
        HashEntryNode *p = arr[hi];
        while (p->next != NULL)
        {
            p = p->next;
        }
        HashEntryNode *newNode = new HashEntryNode(word, meaning);
        p->next = newNode;
    }
}

HashEntryNode *HashTable::search(string word)
{
    int hi = this->hashingFunction(word);
    HashEntryNode *p = arr[hi];
    if (p != NULL)
    {
        while (p->word != word && p->next)
        {
            p = p->next;
        }
        if (p != NULL && p->word == word)
        {
            cout << p->word << ":" << p->meaning << "\n";
            return p;
        }
        else
        {
            cout << "Nothing found"
                 << "\n";
            return NULL;
        }
    }
    else
    {
        cout << "Nothing found"
             << "\n";
        return NULL;
    }
}

void HashTable::update(string word, string newMeaning)
{
    HashEntryNode *pos = this->search(word);
    if (pos != NULL)
    {
        pos->meaning = newMeaning;
    }
    else
    {
        cout << "No such word occurs in the dictionary"
             << "\n";
    }
}

void HashTable::deleteWord(string word)
{
    cout << "The word to be deleted is: "
         << "\n";
    HashEntryNode *pos = this->search(word);
    cout << "\n";
    cout << "x"
         << "\n";
    if (pos != NULL)
    {
        int hi = this->hashingFunction(word);
        if (pos == arr[hi])
        {
            arr[hi] = pos->next;
            pos->next = NULL;
            delete pos;
        }
        else
        {
            HashEntryNode *x = arr[hi];
            while (x->next != pos)
            {
                x = x->next;
            }
            if (x)
            {
                x->next = pos->next;
                pos->next = NULL;
                delete pos;
            }
        }
    }
    else
    {
        cout << "You cannot delete something that does not exist"
             << "\n";
    }
}
void HashTable::display()
{
    for (int i = 0; i < size; i++)
    {
        HashEntryNode *p = arr[i];

        if (p != NULL)
        {
            cout << i << " ";
            while (p)
            {
                cout << p->word << ":" << p->meaning << " ";
                p = p->next;
            }
            cout << "\n";
        }
    }
}

int main()
{
    HashTable T;
    T.insert("a", "b");
    T.insert("Samir", "Wind");
    T.insert("xyz", "abc");
    T.insert("xzy", "tjj");
    T.insert("yzx", "uio");
    T.insert("qwr", "tyu");
    T.display();

    cout << "\n";

    T.deleteWord("Sq");

    T.display();
    return 0;
}