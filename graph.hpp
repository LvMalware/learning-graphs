#include <algorithm>
#include <cstdlib>
#include <queue>
#include <stack>
#include <list>

using std::list;

#ifndef  _GRAPH_H
#define  _GRAPH_H

class AdjacencyMatrix
{

private:
    
    int **matrix;
    int   ncount;

public:

    AdjacencyMatrix(const int nnod)
    {
        /*
         * nnod - the nodes count on the graph
         */
        ncount = nnod;
        int *mat = (int *) calloc(nnod * nnod, sizeof(int));
        matrix = (int **) calloc(nnod, sizeof(int*));
        for (int i = 0; i < nnod; i++)
        {
            matrix[i] = &mat[i * nnod];
        }
    }
    
    ~AdjacencyMatrix()
    {
        delete [] matrix;
    }
    
    bool
    hasConnection(int a, int b)
    {
        /*
         * a - first node index
         * b - second node index
         * return verify if the first node  is connected to the second node
         */
        return matrix[a][b];
    }

    bool
    insertConnection(int a, int b)
    {
        /*
         * a - first node index
         * b - second node index
         * insert a connection from the first node to the second node
         */
        
        return (a == b) ? 0 : matrix[a][b] = 1;
    }

    bool
    insertUndirectedConnection(int a, int b)
    {
        /*
         * a - first node index
         * b - second node index
         * insert a undirected connection from the first node to the second node
         */
        return insertConnection(a, b) && insertConnection(b, a);
    }

    bool
    removeConnection(int a, int b)
    {
        /*
         * a - first node index
         * b - second node index
         * remove the connection from the first node to the second node
         */
        return (matrix[a][b]) ? 0 : 0 == (matrix[a][b] = 0);
    }

    bool
    removeUndirectedConnection(int a, int b)
    {
        /*
         * a - first node index
         * b - second node index
         * remove the undirected connection from the first node to the second node
         */
        return removeConnection(a, b) && removeConnection(b, a);
    }

    int
    getCount()
    {
        /*
         * return the number of nodes
         */
        return ncount;
    }

};

class AdjacencyList
{

private:
    
    list<int> *graph;
    int ncount;

public:

    AdjacencyList(int nnod)
    {
        graph = new list<int>[ncount = nnod];
    }

    ~AdjacencyList()
    {
        delete[] graph;
    }

    bool
    hasConnection(int a, int b)
    {
        /*
         * a - first node index
         * b - second node index
         * return verify if the first node  is connected to the second node
         */
        return std::find(graph[a].begin(), graph[a].end(), b) != graph[a].end();
    }

    bool
    insertConnection(int a, int b)
    {
        /*
         * a - first node index
         * b - second node index
         * insert a connection from the first node to the second node
         */
        if (hasConnection(a, b))
        {
            return false;
        }
        graph[a].push_back(b);
        return true;
    }

    bool
    insertUndirectedConnection(int a, int b)
    {
        /*
         * a - first node index
         * b - second node index
         * insert a undirected connection from the first node to the second node
         */
        return insertConnection(a, b) && insertConnection(b, a);
    }

    bool
    removeConnection(int a, int b)
    {
        /*
         * a - first node index
         * b - second node index
         * remove the connection from the first node to the second node
         */
        list<int>::iterator i = std::find(graph[a].begin(), graph[a].end(), b);
        if (i != graph[a].end())
        {
            graph[a].erase(i);
            return true;
        }
        return false;
    }

    bool
    removeUndirectedConnection(int a, int b)
    {
        /*
         * a - first node index
         * b - second node index
         * remove the undirected connection from the first node to the second node
         */
        return removeConnection(a, b) && removeConnection(b, a);
    }

    int
    getCount()
    {
        /*
         * return the number of nodes
         */
        return ncount;
    }

};



#endif /*_GRAPH_H*/