#include <iostream>
#include <string.h>

using namespace std;
class BST;
class Node
{
    string word;
    string meaning;
    Node *lchild;
    Node *rchild;

public:
    Node()
    {
        word = "";
        meaning = "";
        lchild = NULL;
        rchild = NULL;
    }
    Node(string word, string meaning)
    {
        lchild = NULL;
        rchild = NULL;
        this->word = word;
        this->meaning = meaning;
    }
    friend class BST;
};

class BST
{
    Node *root;

public:
    BST()
    {
        root = NULL;
    }
    void insert(string word, string meaning);
    int search(Node *&loc, Node *&par, string word);
    void display(Node *p);
    void displayDescending(Node *p);
    Node *getRoot();
    void deleteController(string word);
    void deleteCase3(string word, Node *&loc, Node *&parent);
    void deleteCase12(string word, Node *&loc, Node *&parent);
};
Node *BST::getRoot()
{
    return root;
}

void BST::insert(string word, string meaning)
{

    Node *t = NULL;
    Node *parent = NULL;
    Node *loc = NULL;
    search(loc, parent, word);
    t = new Node(word, meaning);
    if (root == NULL)
    {
        root = t;
        return;
    }
    else
    {
        if (loc != NULL)
        {

            cout << "The word already exists in the given dictionary..."
                 << "\n";
            return;
        }
        else if (parent->word > word)
        {
            parent->lchild = t;
        }
        else if (parent->word < word)
        {
            parent->rchild = t;
        }
    }
}

int BST::search(Node *&loc, Node *&parent, string word)
{
    Node *ptr = NULL;
    int count = 0;
    loc = NULL;
    parent = NULL;
    ptr = root;
    while (ptr != NULL)
    {
        if (ptr->word == word)
        {
            loc = ptr;
            return count;
        }
        else if (ptr->word > word)
        {
            parent = ptr;
            ptr = ptr->lchild;
            count++;
        }
        else if (ptr->word < word)
        {
            parent = ptr;
            ptr = ptr->rchild;
            count++;
        }
    }
}
void BST::display(Node *p)
{
    if (p)
    {
        display(p->lchild);
        cout << p->word << " ";
        display(p->rchild);
    }
}
void BST::displayDescending(Node *p)
{
    if (p)
    {
        displayDescending(p->rchild);
        cout << p->word << " ";
        displayDescending(p->lchild);
    }
}
void BST::deleteCase12(string word, Node *&loc, Node *&parent)
{

    if (loc->lchild == NULL && loc->rchild == NULL)
    {
        // leaf node
        if (parent->lchild == loc)
        {
            parent->lchild = NULL;
            delete loc;
        }
        else if (parent->rchild == loc)
        {
            parent->rchild = NULL;
            delete loc;
        }
    }

    else
    {
        if (parent->lchild == loc)
        {
            if (loc->lchild)
            {
                parent->lchild = loc->lchild;
                delete loc;
            }
            else if (loc->rchild)
            {
                parent->lchild = loc->rchild;
                delete loc;
            }
        }
        else if (parent->rchild == loc)
        {
            if (loc->lchild)
            {
                parent->rchild = loc->lchild;
                delete loc;
            }
            else if (loc->rchild)
            {
                parent->rchild = loc->rchild;
                delete loc;
            }
        }
    }
}

void BST::deleteCase3(string x, Node *&loc, Node *&parent)
{
    Node *temp = loc->rchild;
    while (temp->lchild)
    {
        temp = temp->lchild;
    }
    string word = temp->word;
    string meaning = temp->meaning;
    Node *loc1 = NULL;
    Node *parent1 = NULL;
    search(loc1, parent1, temp->word);
    deleteCase12(temp->word, loc1, parent1);
    loc->word = word;
    loc->meaning = meaning;
}

void BST::deleteController(string x)
{
    Node *loc = NULL;
    Node *parent = NULL;
    search(loc, parent, x);
    if (loc->lchild && loc->rchild)
    {
        deleteCase3(x, loc, parent);
    }
    else
    {
        deleteCase12(x, loc, parent);
    }
}

int main()
{

    BST B;
    B.insert("8", "Wind");
    Node *p = B.getRoot();
    B.insert("4", "abc");
    B.insert("3", "xyz");
    B.insert("1", "sam");
    B.insert("7", "june");
    B.insert("9", "july");

    cout << "\n";
    B.display(p);
    cout << "\n";
    B.displayDescending(p);

    return 0;
}
