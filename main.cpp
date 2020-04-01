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

    cout<<g.distanta(1,4)<<endl;
    //graf a(n+1);
    g.afis_lista_adiacenta_nod(nod);
    cout<<endl;
    graf a(n);
    a.add_muchie(5,2);
    a.add_muchie(1,4);
    cout<<g;
    cout<<endl;
    cout<<a;
    cout<<endl;
    graf b(n);
    b=a+g;
    cout<<b;
    cout<<endl;
    b=b-3;
    cout<<b;
    cout<<endl;
    cout<<g.conex()<<endl;
    cout<<a.conex()<<endl;
    cout<<g.arbore()<<endl;
    graf arb(n);
    arb.add_muchie(1,2);
    arb.add_muchie(1,3);
    arb.add_muchie(2,4);
    arb.add_muchie(4,5);
    cout<<arb.arbore()<<endl;
    cout<<b.nr_noduri()<<endl;
    cout<<b.nr_muchii()<<endl;
    //g.BFS(v);
    return 0;
}
