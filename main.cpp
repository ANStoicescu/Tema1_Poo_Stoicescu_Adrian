#include <iostream>
#include <fstream>
#include "graf.h"

using namespace std;
ifstream f("date.in");
int n,m,nod;
int *v;
int main()
{
    f>>n>>m>>nod;
    n++;
    graf g(n);
    for(int i = 1; i <= m; i++)
    {
        int x,y;
        f >> x >> y;
        g.add_muchie(x,y);
    }
    g.BFS(nod);
    g.DFS(nod);
    //graf a(n+1);
    graf a(3);
    a=g;
    cout<<g;
    cout<<a;
    //g.BFS(v);
    return 0;
}
