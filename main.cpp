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
    //n= nr de noduri ale grafului
    //m= nr de muchii ale grafului
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
    cout<<g.nr_noduri()<<endl;
    cout<<g.nr_muchii()<<endl;

    graf a(n);
    a.add_muchie(5,2);
    cout<<g;
    cout<<endl;
    cout<<a;
    cout<<endl;
    graf b(n);
    b=a+g;
    cout<<b;
    cout<<endl;
    //g.BFS(v);
    return 0;
}
