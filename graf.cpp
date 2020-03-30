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

graf::~graf()
{
    for (int i = 0; i < size_; ++i)
        delete [] mat_[i];
    delete [] mat_;
    size_=0;
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

graf graf::operator+(const graf &other) const
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

