#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    friend class LinkedList;
    friend class Stack;
};
class LinkedList
{
private:
    Node *start;
    Node *end;

public:
    LinkedList()
    {
        start = end = NULL;
    }
    void insertAtStart(int val);
    void insertAtEnd(int val);
    void insertAfterPos(int val, int pos);
    void insertBeforePos(int val, int pos);
    int deleteFromEnd();
    int deleteFromStart();
    void reverseLinkedList();
    void display();
    void sort();
    int getSize();
    LinkedList concatinate(LinkedList l);
    LinkedList merging(LinkedList l);
    friend class Stack;
};
int LinkedList::getSize()
{
    Node *p;
    p = start;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

void LinkedList::display()
{
    Node *p;
    p = start;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}
void LinkedList::insertAtStart(int val)
{
    Node *t;
    if (start == NULL)
    {
        t = new Node;
        t->data = val;
        start = end = t;
    }
    else
    {
        t = new Node;
        t->data = val;
        t->next = start;
        start = t;
    }
}
void LinkedList::insertAtEnd(int val)
{
    Node *t;
    if (start == NULL)
    {
        t = new Node;
        t->data = val;
        start = end = t;
    }
    else
    {
        t = new Node;
        t->data = val;
        end->next = t;
        end = t;
    }
}
void LinkedList::insertAfterPos(int val, int pos)
{
    Node *t, *p;
    p = start;
    if (start == NULL)
    {
        t = new Node;
        t->data = val;
        start = end = t;
    }
    else
    {
        for (int i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {
            t = new Node;
            t->data = val;
            t->next = p->next;
            p->next = t;
            if (p == end)
            {
                end = t;
            }
        }
    }
}
void LinkedList::insertBeforePos(int val, int pos)
{
    Node *t, *p;
    p = start;
    if (start == NULL)
    {
        t = new Node;
        t->data = val;
        start = end = t;
    }
    else
    {
        for (int i = 0; i < pos - 2 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {
            t = new Node;
            t->data = val;
            t->next = p->next;
            p->next = t;
        }
    }
}

int LinkedList::deleteFromEnd()
{
    Node *t;
    if (start == end == NULL)
    {
        cout << "The Linked List is already empty." << endl;
        return 0;
    }
    else
    {
        while (t->next->next)
        {
            t = t->next;
        }
        Node *p = end;
        delete end;
        end = t;
        return p->data;
    }
}

int LinkedList::deleteFromStart()
{
    Node *t;
    if (start == end == NULL)
    {
        cout << "The Linked List is already empty." << endl;
        return 0;
    }
    else
    {
        t = start;
        start = start->next;
        int x = t->data;
        if (end == t)
        {
            delete end;
        }
        delete t;
        return x;
    }
}

void LinkedList::reverseLinkedList()
{
    Node *p, *q, *r;
    p = start;
    q = r = NULL;
    if (start == NULL)
    {
        cout << "The Linked List is empty. " << endl;
    }
    else
    {
        while (p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        end = start;
        start = q;
    }
}
void LinkedList::sort()
{
    Node *current, *index;
    if (start == NULL)
    {
        cout << "The linked List is Empty." << endl;
        return;
    }
    else
    {
        current = start;
        while (current != NULL)
        {
            index = current->next;
            while (index != NULL)
            {
                if (current->data > index->data)
                {
                    int temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

LinkedList LinkedList::concatinate(LinkedList l)
{
    LinkedList l3;
    Node *p = this->start;
    while (p)
    {
        l3.insertAtEnd(p->data);
        p = p->next;
    }
    Node *q = l.start;
    while (q)
    {
        l3.insertAtEnd(q->data);
        q = q->next;
    }
    return l3;
}

LinkedList LinkedList::merging(LinkedList l)
{
    LinkedList l3;
    Node *p, *q;
    p = this->start;
    q = l.start;
    while (p && q)
    {
        if (p->data < q->data)
        {
            l3.insertAtEnd(p->data);
            p = p->next;
        }
        else if (q->data < p->data)
        {
            l3.insertAtEnd(q->data);
            q = q->next;
        }
        else
        {
            l3.insertAtEnd(p->data);
            l3.insertAtEnd(q->data);
            p = p->next;
            q = q->next;
        }
    }
    while (p)
    {
        l3.insertAtEnd(p->data);
        p = p->next;
    }
    while (q)
    {
        l3.insertAtEnd(q->data);
        q = q->next;
    }
    return l3;
}

class Stack
{
private:
    Node *top;
    LinkedList l;

public:
    Stack()
    {
        top = NULL;
    }
    void push(int x);
    int pop();
    bool isEmpty();
    int topElement();
    void display();
};
void Stack::push(int x)
{
    l.insertAtStart(x);
    top = l.start;
    cout << top->data << "\n";
}

int Stack::pop()
{
    cout << l.start->data << "\n";
    int ans = l.deleteFromStart();
    top = l.start;
    return ans;
}

int Stack::topElement()
{
    if (top == NULL)
    {
        cout << "The stack is already empty."
             << "\n";
    }
    else
    {
        return top->data;
    }
}
bool Stack::isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    return false;
}
void Stack::display()
{
    l.display();
}
int main()
{
    /*LinkedList l1, l2;
    l1.insertAtEnd(50);
    l1.insertAtEnd(60);
    l1.insertAtEnd(100);
    l1.insertAtEnd(80);
    l1.insertAtEnd(90);

    l2.insertAtEnd(40);
    l2.insertAtEnd(60);
    l2.insertAtEnd(120);
    l2.insertAtEnd(160);
    l2.insertAtEnd(70);

    l1.sort();
    l1.display();
    l2.sort();
    l2.display();
    LinkedList l3 = l1.merging(l2);
    l3.display();*/

    Stack st;
    st.push(2);
    st.push(4);
    st.push(3);
    st.push(1);
    st.display();
    cout << st.topElement() << endl;
    int x = st.pop();
    st.display();

    return 0;
}