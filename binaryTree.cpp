#include <iostream>
using namespace std;

template <class T>
class stack;
template <class T>
class node
{
private:
    node *next;
    T data;

public:
    friend class stack<T>;
};
template <class T>
class stack
{
private:
    node<T> *top;

public:
    stack()
    {
        top = NULL;
    }
    void push(T x);
    T pop();
    void display();
    bool isEmpty();
    T topElement();
    int priority(char x);
    bool isOperand(char x);
};
template <class T>
int stack<T>::priority(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
}
template <class T>
bool stack<T>::isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return false;
    }
    return true;
}
template <class T>
T stack<T>::topElement()
{
    if (top == NULL)
    {
        cout << "The stack is currently empty"
             << "\n";
        return ' ';
    }
    return top->data;
}
template <class T>
void stack<T>::push(T x)
{
    node<T> *t;
    t = new node<T>;

    if (top == NULL)
    {
        t->data = x;
        top = t;
        top->next = NULL;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
template <class T>
T stack<T>::pop()
{
    node<T> *p;
    p = top;
    if (top == NULL)
    {
        cout << "The stack is already empty"
             << "\n";
        return NULL;
    }
    else
    {
        top = top->next;
        T x = p->data;
        delete p;
        return x;
    }
}
template <class T>
void stack<T>::display()
{
    node<T> *p = top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}
template <class T>
bool stack<T>::isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    return false;
}

template <class T>
class Queue;

template <class T>
class NodeQ
{
    T data;
    NodeQ *next;

public:
    NodeQ()
    {
        data = 0;
        next = NULL;
    }
    NodeQ(T element)
    {
        data = element;
        next = NULL;
    }
    friend class Queue<T>;
};

template <class T>
class Queue
{
    NodeQ<T> *front;
    NodeQ<T> *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void insert(T element)
    {
        NodeQ<T> *newNodeQ = new NodeQ<T>(element);
        if (front == NULL)
        {
            front = newNodeQ;
            rear = newNodeQ;
        }
        else
        {
            rear->next = newNodeQ;
            rear = newNodeQ;
        }
    }

    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "The queue is empty ." << endl;
            return NULL;
        }
        else
        {
            if (front->next == NULL)
            {
                T x = front->data;
                delete front;
                front = NULL;
                rear = NULL;
                return x;
            }
            else
            {
                NodeQ<T> *temp_address = front->next;
                front->next = NULL;
                T x = front->data;
                delete front;
                front = temp_address;
                return x;
            }
        }
    }

    int size()
    {
        int size = 0;
        NodeQ<T> *ptr = front;
        while (ptr)
        {
            size++;
            ptr = ptr->next;
        }

        return size;
    }

    void display()
    {
        if (front == NULL)
        {
            cout << "The queue is empty ." << endl;
            return;
        }
        NodeQ<T> *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class NodeTree
{
private:
    int data;
    NodeTree *left;
    NodeTree *right;

public:
    NodeTree()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    NodeTree(int x)
    {
        data = x;
    }
    friend class BinaryTree;
    friend NodeTree *copy(NodeTree *p);
};
class BinaryTree
{
private:
    NodeTree *root;

public:
    BinaryTree()
    {
        root = NULL;
    }
    void createTree();
    void displayTree();
    NodeTree *getRoot();
    void inOrder(NodeTree *root);
    void preOrder(NodeTree *root);
    void postOrder(NodeTree *root);
    NodeTree *recursiveCreate();
    void setRoot(NodeTree *p);
    void iPreorder();
    void iInorder();
    void iPostorder();
    void leaf(NodeTree *p);
    void mirrorImage(NodeTree *p);
    void interiorNode(NodeTree *p);
    void levelOrder(NodeTree *p);
    int iHeight(NodeTree *p);
    BinaryTree iCopy(NodeTree *p);
};

void BinaryTree::setRoot(NodeTree *p)
{
    root = p;
}
NodeTree *BinaryTree::getRoot()
{
    return root;
}
void BinaryTree::createTree()
{
    NodeTree *p, *t;
    int x;
    Queue<NodeTree *> q;
    cout << "Enter the root value: "
         << "\n";
    cin >> x;
    root = new NodeTree;
    root->data = x;
    root->left = root->right = NULL;
    q.insert(root);

    while (!q.isEmpty())
    {
        p = q.pop();
        cout << "Enter left child of " << p->data << "\n";
        cin >> x;
        if (x != -1)
        {
            t = new NodeTree;
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            q.insert(t);
        }
        cout << "Enter right child of " << p->data << "\n";
        cin >> x;
        if (x != -1)
        {
            t = new NodeTree;
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            q.insert(t);
        }
    }
}
void BinaryTree::inOrder(NodeTree *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
void BinaryTree::preOrder(NodeTree *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void BinaryTree::postOrder(NodeTree *root)
{
    if (root)
    {

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

NodeTree *BinaryTree::recursiveCreate()
{
    cout << "Enter the value for the current node: " << endl;
    int x;
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }
    else
    {
        NodeTree *p = new NodeTree(x);
        cout << "Enter the left child of current node: " << p->data << endl;
        p->left = recursiveCreate();
        cout << "Enter the right child of the current node: " << p->data << endl;
        p->right = recursiveCreate();
        return p;
    }
}
void BinaryTree::iPreorder()
{
    stack<NodeTree *> st;
    st.push(root);
    while (!st.isEmpty())
    {
        NodeTree *p = st.pop();
        cout << p->data << " ";
        if (p->right)
        {
            st.push(p->right);
        }
        if (p->left)
        {
            st.push(p->left);
        }
    }
}
void BinaryTree::iInorder()
{
    stack<NodeTree *> st;
    NodeTree *p = root;
    while (p || !st.isEmpty())
    {
        while (p)
        {
            st.push(p);
            p = p->left;
        }

        p = st.pop();
        cout << p->data << " ";
        p = p->right;
    }
}

void BinaryTree::iPostorder()
{
    stack<NodeTree *> st1;
    stack<int> st2;
    st1.push(root);
    while (!st1.isEmpty())
    {
        NodeTree *p = st1.pop();
        st2.push(p->data);
        if (p->left)
            st1.push(p->left);
        if (p->right)
            st1.push(p->right);
    }
    st2.display();
}
void BinaryTree::leaf(NodeTree *p)
{
    static int count = 0;
    if (p == NULL)
    {
        return;
    }
    leaf(p->left);
    leaf(p->right);

    if (p->left == NULL && p->right == NULL)
    {
        cout << p->data << endl;
        count++;
    }
}

void BinaryTree::mirrorImage(NodeTree *p)
{
    if (p != NULL)
    {
        mirrorImage(p->left);
        mirrorImage(p->right);
        NodeTree *temp = p->left;
        p->left = p->right;
        p->right = temp;
    }
}

void BinaryTree::interiorNode(NodeTree *p)
{
    static int count = 0;
    if (p == NULL)
    {
        return;
    }
    interiorNode(p->left);
    interiorNode(p->right);

    if (p->left != NULL || p->right != NULL)
    {
        cout << p->data << endl;
        count++;
    }
}

void BinaryTree::levelOrder(NodeTree *p)
{
    Queue<NodeTree *> q;
    q.insert(p);

    while (!q.isEmpty())
    {
        NodeTree *ptr = q.pop();
        cout << ptr->data << " ";
        if (ptr->left)
        {
            q.insert(ptr->left);
        }
        if (ptr->right)
        {
            q.insert(ptr->right);
        }
    }
}

int BinaryTree::iHeight(NodeTree *p)
{
    Queue<NodeTree *> q;
    q.insert(p);
    int size = 0;
    int height = -1;
    while (!q.isEmpty())
    {
        size = q.size();
        height++;

        while (size != 0)
        {
            NodeTree *ptr = q.pop();
            if (ptr->left)
            {
                q.insert(ptr->left);
            }
            if (ptr->right)
            {
                q.insert(ptr->right);
            }
            size--;
        }
    }
    return height;
}

NodeTree *copy(NodeTree *root)
{
    NodeTree *temp;
    if (root != NULL)
    {
        temp = new NodeTree;
        temp->data = root->data;
        temp->left = copy(root->left);
        temp->right = copy(root->right);
        // preorder logic
    }
    else
    {
        return NULL;
    }
    return temp;
}

int main()
{

    BinaryTree B;
    cout << "How do you want to create the binary tree?"
         << "\n";
    cout << "1. Iteratively"
         << "\n";

    cout << "2. Recursively"
         << "\n";
    int choice = 0;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        B.createTree();
        break;
    }
    case 2:
    {
        NodeTree *p = B.recursiveCreate();
        B.setRoot(p);
        break;
    }
    default:
    {
        cout << "Invalid choice entered"
             << "\n";
        break;
    }
    }
    cout << "Menu"
         << "\n";
    cout << "1.Inorder Traversal"
         << "\n";
    cout << "2.Preorder Traversal"
         << "\n";
    cout << "3.Postorder Traversal"
         << "\n";
    cout << "4.Height of a tree"
         << "\n";
    cout << "5. Leaf nodes of a tree"
         << "\n";
    cout << "6. Interior nodes of the tree"
         << "\n";
    cout << "\n";
    int flag = 1;
    while (flag == 1)
    {
        cout << "Enter the choice of operation you want to perform: ";
        int choice1;
        cin >> choice1;
        switch (choice1)
        {
        case 1:
        {
            B.inOrder(B.getRoot());
            break;
        }
        case 2:
        {
            B.preOrder(B.getRoot());
            break;
        }
        case 3:
        {
            B.postOrder(B.getRoot());
            break;
        }
        case 4:
        {
            int height = B.iHeight(B.getRoot());
            cout << height << "\n";
            break;
        }
        case 5:
        {
            B.leaf(B.getRoot());
            break;
        }
        case 6:
        {
            B.interiorNode(B.getRoot());
            break;
        }
        default:
        {
            cout << "Invalid choice entered"
                 << "\n";
            break;
        }
        }
        cout << "\n";
        cout << "Do you want to perform another operation on the binary tree?(1/0)"
             << "\n";
        cin >> flag;
    }

    return 0;
}
