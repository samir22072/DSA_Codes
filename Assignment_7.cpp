#include <iostream>
using namespace std;

class graph
{
    int nver;
    int nedge;
    int **matrix;
    int **MST;

public:
    graph()
    {
        nedge = 0;
        nver = 0;
        matrix = NULL;
        MST = NULL;
    }
    graph(int ver, int edge)
    {
        this->nver = ver;
        this->nedge = edge;
        matrix = new int *[nver];
        MST = new int *[nver];
        for (int i = 0; i < nver; i++)
        {
            matrix[i] = new int[nver];
            MST[i] = new int[nver];
            for (int j = 0; j < nver; j++)
            {
                matrix[i][j] = INT_MAX;
                MST[i][j] = INT_MAX;
            }
        }
    }

    void acceptGraph();
    void display();
    void Prims();
};

void graph::Prims()
{
    int near[nver];
    for (int i = 0; i < nver; i++)
    {
        near[i] = INT_MAX;
    }
    int t[2][nver - 1];
    int min = INT_MAX;
    int u = 0, v = 0;
    for (int i = 0; i < nver; i++)
    {
        for (int j = i; j < nver; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = -1;
    for (int i = 0; i < nver; i++)
    {
        if (near[i] != -1)
        {
            if (matrix[i][u] < matrix[i][v])
            {
                near[i] = u;
            }
            else
            {
                near[i] = v;
            }
        }
    }
    for (int i = 1; i < nver - 1; i++)
    {
        int min = INT_MAX;
        int k = 0;
        for (int j = 0; j < nver; j++)
        {
            if (near[j] != -1 && matrix[j][near[j]] < min)
            {
                min = matrix[j][near[j]];
                k = j;
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = -1;

        for (int j = 0; j < nver; j++)
        {
            if (near[j] != -1 && matrix[j][k] < matrix[j][near[j]])
            {
                near[j] = k;
            }
        }
    }
    for (int i = 0; i < nver - 1; i++)
    {
        cout << t[0][i] << " , " << t[1][i] << "\n";
    }
}
void graph::acceptGraph()
{
    cout << "Enter the Adjacency Matrix :" << endl;
    for (int i = 0; i < nedge; i++)
    {
        int s, d, w;
        cout << "Enter source and destination vertex" << endl;
        cin >> s >> d;
        cout << "Enter weight";
        cin >> w;
        matrix[s][d] = w;
        matrix[d][s] = w;
    }
}

void graph::display()
{
    for (int i = 0; i < nver; i++)
    {
        for (int j = 0; j < nver; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter total number of vertices and edges:";
    int vertex;
    cin >> vertex;
    int edges;
    cin >> edges;
    graph g(vertex, edges);
    g.acceptGraph();
    g.display();
    cout << "\n";
    cout << "\n";
    g.Prims();
    return 0;
}