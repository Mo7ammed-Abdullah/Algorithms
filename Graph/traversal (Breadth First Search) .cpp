#include <bits/stdc++.h>
using namespace std;
#define size 50

int Queue[size + 1];
int adj[size][size];
int n;

int front = 0, rear = 0;


// Queue operation
void enqueue(int item)
{

    if ((front == 1 && rear == size) || front == rear + 1)
    {
        cout << "Queue is full" << endl;
        return;
    }

    if (front == 0)
    {
        front = 1;
        rear = 1;
    }
    else
    {
        rear++;
    }
    Queue[rear] = item;
}

int dequeue()
{
    int item;
    if (front == 0)
    {
        cout << "underflow" << endl;
        return -1;
    }
    item = Queue[front];
    if (front == rear)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        front = front + 1;
    }
    return item;
}


// creating an adjacent matrix undirected graph
void create_graph()
{
    int max_edges, i, j, origin, destin;

    cout << "enter number of vertices: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    max_edges = n * (n - 1) / 2;

    for (i = 0; i < max_edges; i++)
    {
        cout << "Enter edges (enter 0 0 to end):";
        cin >> origin >> destin;

        if (origin == 0 && destin == 0)
        {
            break;
        }

        adj[origin][destin] = 1;
        adj[destin][origin] = 1;                        // comment this if you want a directed graph
    }

    cout << "The adjacency matrix is:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// BFS traversal
void BFS()
{
    int i;
    int exploring;
    int visited[n] = {0};                                 // initialize visited as 0 since no node is yet visited

    cout << "Choose node to begin Traversal: ";
    cin >> i;

    visited[i] = 1;                                       // the first vertex is always considered as visited

    cout << i << " ";
    enqueue(i);                                           // insert first vertex in queue

    while (front != 0 && rear != 0)                       // till queue is empty
    {
        exploring = dequeue();                            // exploring takes out first vertex from queue to find its visited node
        for (int j = 0; j < n; j++)
        {

            if (adj[exploring][j] == 1 && visited[j] == 0)   //eg: if exploring is 0, then we iterate 0th row of matrix  , if 1 is found at 2nd column of that row, we mark visited[2] as 1 . which means 2nd vertex is visited
            {
                cout << j << " ";
                visited[j] = 1;
                enqueue(j);                                 // hence insert 2  in queue to dequeue it and explore its connected vertices.
            }
        }
    }
}

int main()
{

    create_graph();

    BFS();

    return 0;
}
