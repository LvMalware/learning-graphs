#include <iostream>
#include "graph.hpp"

using namespace std;

int
main(int argc, char *argv[])
{
    AdjacencyList al(5);
    al.insertConnection(0, 4);
    al.insertConnection(1, 2);
    al.insertConnection(1, 3);
    al.insertConnection(2, 4);
    al.insertConnection(3, 4);

    for (int n = 0; n < 5; n++)
    {
        int j = (n + 1) % 5;
        cout << "Node " << n << " is " << (al.hasConnection(n, j) ? "" : "NOT ")
             << "connected to node " << j << endl;
    }

    return 0;
}