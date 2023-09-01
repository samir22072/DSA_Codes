//============================================================================
// Name        : Assignment_8.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>

using namespace std;

class NodeVertex
{
private:
    int value;
    NodeVertex *next;

public:
    NodeVertex()
    {
        this->value = 0;
        this->next = nullptr;
    }
    NodeVertex(int value, int weight)
    {
        this->value = value;
        this->next = nullptr;
    }
    friend class Graph;
};

class Node
{
private:
    int val;
    Node *next;

public:
    Node()
    {
        val = 0;
        next = NULL;
    }
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
    friend class Queue;
    friend class Stack;
};

class Stack
{
private:
    Node *head;

public:
    Stack()
    {
        head = nullptr;
    }
    void push(int x);
    int pop();
    bool isEmpty();
};

void Stack::push(int x)
{
    Node *s = new Node(x);
    if (head == nullptr)
    {
        head = s;
        head->next = nullptr;
    }
    else
    {
        s->next = head;
        head = s;
    }
}
int Stack::pop()
{
    int val;
    if (head == nullptr)
    {
        cout << "The stack is empty"
             << "\n";
        return -1;
    }
    else
    {
        Node *p = head;
        head = head->next;
        val = p->val;
        delete p;
        return val;
    }
    return -1;
}
bool Stack::isEmpty()
{
    if (head == nullptr)
    {
        return 1;
    }
    return 0;
}
class Queue
{
private:
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
    }
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    bool existsInQueue(int x);
};
bool Queue::existsInQueue(int x)
{
    Node *p = head;
    while (p)
    {
        if (p->val == x)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}
bool Queue::isEmpty()
{
    if (head == nullptr && tail == nullptr)
    {
        return 1;
    }
    return 0;
}
void Queue::enqueue(int x)
{
    Node *s = new Node(x);
    if (head == nullptr && tail == nullptr)
    {
        s->next = nullptr;
        head = s;
        tail = s;
    }
    else
    {
        s->next = nullptr;
        tail->next = s;
        tail = s;
    }
}
int Queue::dequeue()
{
    int val;
    if (head == nullptr && tail == nullptr)
    {
        cout << "Queue is empty"
             << "\n";
        return -1;
    }
    else if (head == tail && head != nullptr && tail != nullptr)
    {
        Node *p = head;
        head = nullptr;
        tail = nullptr;
        val = p->val;
        delete p;
        return val;
    }
    else
    {
        Node *p = head;
        head = head->next;
        val = p->val;
        delete p;
        return val;
    }
    return -1;
}

class Graph
{
private:
    int noVertices;
    int noEdges;
    NodeVertex **headArr;

public:
    Graph()
    {
        this->noVertices = 0;
        this->noEdges = 0;
        this->headArr = nullptr;
    }
    Graph(int noVertices, int noEdges)
    {
        this->noVertices = noVertices;
        this->noEdges = noEdges;
        this->headArr = new NodeVertex *[noVertices];
        for (int i = 0; i < noVertices; i++)
        {
            headArr[i] = nullptr;
        }
    }
    void createGraph();
    void topologicalSort();
    void display();
};
void Graph::topologicalSort()
{
    int *indegree = new int[noVertices];
    for (int i = 0; i < noVertices; i++)
    {
        indegree[i] = 0;
    }
    for (int i = 0; i < noVertices; i++)
    {
        NodeVertex *p = headArr[i]->next;
        while (p)
        {
            indegree[p->value]++;
            p = p->next;
        }
    }
    for (int i = 0; i < noVertices; i++)
    {
        cout << i << " : " << indegree[i] << "\n";
    }
    cout << "\n";
    Queue q;
    for (int i = 0; i < noVertices; i++)
    {
        if (indegree[i] == 0)
        {
            q.enqueue(i);
            break;
        }
    }
    while (!q.isEmpty())
    {
        int w = q.dequeue();
        cout << w << " ";
        NodeVertex *p = headArr[w]->next;
        while (p && q.existsInQueue(p->value) == false)
        {
            indegree[p->value]--;
            if (indegree[p->value] == 0)
            {
                q.enqueue(p->value);
            }
            p = p->next;
        }
    }
}

void Graph::createGraph()
{

    for (int i = 0; i < noVertices; i++)
    {
        cout << "Enter the value of the given vertex: "
             << "\n";
        NodeVertex *vertex = new NodeVertex;
        cin >> vertex->value;
        this->headArr[i] = vertex;
    }

    for (int i = 0; i < noVertices; i++)
    {
        cout << "Enter the number of vertices adjacent to "
             << this->headArr[i]->value << ": "
             << "\n";
        int x = 0;
        cin >> x;
        NodeVertex *ptr = this->headArr[i];
        while (x-- != 0)
        {
            NodeVertex *adjVertex = new NodeVertex;
            cout << "Enter the value of current adjacent node: "
                 << "\n";
            cin >> adjVertex->value;

            ptr->next = adjVertex;
            ptr = adjVertex;
        }
    }
}
void Graph::display()
{
    for (int i = 0; i < this->noVertices; i++)
    {
        cout << i << ": " << this->headArr[i]->value << " ";
        NodeVertex *ptr = headArr[i]->next;
        while (ptr)
        {
            cout << "(" << ptr->value << ")"
                 << ", ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
}

int main()
{
    int noVertices, noEdges;
    cout << "Enter the number of vertices in the graph : "
         << "\n";
    cin >> noVertices;
    cout << "Enter the number of edges in the graph : "
         << "\n";
    cin >> noEdges;
    Graph g(noVertices, noEdges);
    g.createGraph();
    g.display();
    cout << "\n";
    g.topologicalSort();

    return 0;
}