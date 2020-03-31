#include "graf.h"

using namespace std;

graf::graf(int nr_noduri)
{
    size_=nr_noduri;
    mat_ = new int*[size_];
    for (int i = 0; i < size_; ++i)
        mat_ [i] = new int[size_];
    for(int i=0; i<size_; i++)
        for(int j=0; j<size_; j++)
            mat_[i][j]=0;

}

graf::graf(const graf& other)
{
    if (size_ <= 0)
    {
        mat_ = NULL;
    }
    else
    {
        size_=other.size_;
        mat_ = new int*[size_];
        for (int i = 0; i < size_; ++i)
            mat_ [i] = new int[size_];
        for(int i=0; i<size_; i++)
            for(int j=0; j<size_; j++)
                mat_[i][j]=other.mat_[i][j];
    }
}

void graf::BFS(int nod)
{
    int* C;
    int* viz;
    C= new int [size_];
    viz= new int [size_];
    for(int i=0; i<size_; i++)
    {

        C[i]=0;
        viz[i]=0;
    }
    int p = 1;
    int u = 1;
    C[1] = nod;
    viz[nod] = 1;
    cout << nod << ' ';
    while(p <= u)
    {
        int crt = C[p++];
        for(int j = 1; j <= size_; j++)
            if(mat_[crt][j] == 1 && viz[j] == 0)
            {
                C[++u] = j;
                viz[j] = 1;
                cout << j << ' ';
            }
    }
    cout<<'\n';
    delete [] C;
    delete [] viz;
}

void graf::DFS(int nod)
{
    int* S;
    int* viz;
    S= new int [size_];
    viz= new int [size_];
    for(int i=0; i<size_; i++)
    {
        S[i]=0;
        viz[i]=0;
    }
    int vf = 1;
    S[1] = nod;
    viz[nod] = 1;
    cout << nod << ' ';
    while(vf != 0)
    {
        int crt = S[vf];
        int ok = 0, j;
        for(j = 1; j <= size_; j++)
            if(mat_[crt][j] == 1 && viz[j] == 0)
            {
                ok = 1;
                break;
            }
        if(ok)
        {
            S[++vf] = j;
            viz[j] = 1;
            cout << j << ' ';
        }
        else
            vf--;
    }
    cout<<'\n';
    delete [] S;
    delete [] viz;
}

int graf::distanta(int x,int y)
{
    int* C;
    int* viz;
    int* dist;
    C= new int [size_];
    viz= new int [size_];
    dist= new int [size_];
    for(int i=0; i<size_; i++)
    {
        C[i]=0;
        viz[i]=0;
        dist[i]=0;
    }
    int p = 1;
    int u = 1;
    C[1] = x;
    viz[x] = 1;
    while(p <= u)
    {
        int crt = C[p++];
        for(int j = 1; j <= size_; j++)
            if(mat_[crt][j] == 1 && viz[j] == 0)
            {
                dist[j]=dist[crt]+1;
                C[++u] = j;
                viz[j] = 1;
            }
    }
    int rez=dist[y];
    delete [] C;
    delete [] viz;
    delete [] dist;
    return rez;
}

int graf::nr_noduri()
{
    return size_-1;
}

int graf::nr_muchii()
{
    int rez=0;
    for (int i = 1; i < size_; i++)
        for (int j = i; j < size_; j++)
            if(mat_[i][j]==1)
                rez++;
    return rez;
}

graf& graf::operator=(const graf& other)
{
    if (size_ <= 0)
    {
        mat_ = NULL;
    }
    else
    {
        size_=other.size_;
        mat_ = new int*[size_];
        for (int i = 0; i < size_; ++i)
            mat_ [i] = new int[size_];
        for(int i=0; i<size_; i++)
            for(int j=0; j<size_; j++)
                mat_[i][j]=other.mat_[i][j];
    }
}

void graf::afis_lista_adiacenta_nod(const int nod)
{
    for(int i = 1; i<size_; i++)
        if(mat_[i][nod]==1)
            cout<<i<<' ';
    cout<<endl;
}

graf graf::operator-(const int nod)
{
    //mat_ [x][y]=mat_ [y][x]=0;
}

graf graf::operator+(const graf &other)
{
    if(size_==other.size_)
    {
        graf result(size_);
        for (int i = 0; i < size_; i++)
            for(int j = 0; j < size_; j++)
                result.mat_[i][j]=mat_[i][j]|other.mat_[i][j];
        return result;
    }
}

void graf::add_muchie(int x, int y)
{
    mat_ [x][y]=mat_ [y][x]=1;
}

std::ostream& operator<<(std::ostream& out, const graf& g)
{
    for (int i = 1; i < g.size_; i++)
        for (int j = i; j < g.size_; j++)
            if(g.mat_[i][j]==1)
                out<<i<<' '<<j<<'\n';
    return out;
}

graf::~graf()
{
    for (int i = 0; i < size_; ++i)
        delete [] mat_[i];
    delete [] mat_;
    size_=0;
}
