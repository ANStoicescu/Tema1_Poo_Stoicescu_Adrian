#include "graf.h"

using namespace std;

graf::graf(int nr_noduri)// acest constructor se apeleaza atunci cand avem doar numarul de noduri. Initializam o matrice de adiacenta plina de 0
{
    size_=nr_noduri;
    mat_ = new int*[size_];
    for (int i = 0; i < size_; ++i)
        mat_ [i] = new int[size_];
    for(int i=0; i<size_; i++)
        for(int j=0; j<size_; j++)
            mat_[i][j]=0;

}

graf::graf(const graf& other)// acest constructor se apeleaza atunci cand avem un graf pe care vrem sa il initializam si copiem intr-un graf nou
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

void graf::add_muchie(int x, int y)
{
    mat_ [x][y]=mat_ [y][x]=1;
}

// functiile BFS si DFS nu returneaza nimic, ele afiseaza rezultatul direct pe ecran
void graf::BFS(int nod)// parcurgerea in latime
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

void graf::DFS(int nod)// parcurgerea in adancime
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

int graf::distanta(int x,int y)// ca sa calculez distanta am folosit un BFS care retine in vectorul dist toate distantele de la nodul x la celelalte noduri
{//functia returneaza distanta dintre nodul x si nodul y
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

graf& graf::operator=(const graf& other)
{//am supraincarcat operatorul '=' sa copieze matricea si dimensiunea unui graf in alt graf
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
        if(mat_[i][nod]==1)//acolo unde avem 1 in matriccea de adiacenta pe linia lui nod afisam acel i
            cout<<i<<' ';
    cout<<endl;
}

graf graf::operator-(const int nod)
{
    graf result(size_-1);
    for (int i = 0; i < size_; i++)
        for(int j = 0; j < size_; j++)
        {
            if(i==nod)
                break;//daca suntem pe linia sau coloana nodului pe care il eliminam iesim din for
            if(j==nod)
                continue;
            int ii=i,jj=j;
            if(i>nod)
                ii--;//toate nodurile de ordin mai mare decat nodul pe care il eliminam vor primi un ordin mai mic cu 1
            if(j>nod)
                jj--;
            result.mat_[ii][jj]=mat_[i][j];
        }
    return result;
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

bool graf::conex() // este acelasi algoritm ca la cel de distanta doar ca daca de la nodul unu nu putem ajunge la toate nodurile rezulta ca graful nu este conex
{
    int* C;
    int* viz;
    int* dist;
    int x=1;
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
    bool conex=1;
    for(int i=2; i<size_; i++)
    {
        if(dist[i]==0)
            conex=0;
    }
    delete [] C;
    delete [] viz;
    delete [] dist;
    return conex;
}

bool este_ciclu(int u, bool visited[], int parent,int size_,int** mat_)
{
    visited[u] = true;
    for(int i = 1; i<size_; i++)
    {
        if(mat_[u][i])
        {
            if(!visited[i])
            {
                if(este_ciclu(i, visited, u, size_, mat_))// daca am gasit un ciclu nu mai mergem mai departe
                {
                    return true;
                }
            }
            else if(i != parent)        //cand nodul curent e vizitat dar nu parintele
            {
                return true;    //avem un ciclu
            }
        }
    }
    return false;
}

bool graf::arbore()
{
    bool *viz = new bool[size_];

    for(int i = 0; i<size_; i++)
        viz[i] = 0;

    if(este_ciclu(1, viz, -1, size_, mat_))    //verificam daca avem un ciclu
        return false;

    for(int i = 1; i<size_; i++)
    {
        if(!viz[i])    //daca avem un nod care nu a fost vizitat atunci nu e arbore
            return false;
    }
    return true;
}

int graf::nr_noduri()
{
    return size_-1;
}

int graf::nr_muchii()
{// numaram cati de 1 avem in matricea de adiacenta, desupra diagonalei principale deoarece este un graf neorientat
    int rez=0;
    for (int i = 1; i < size_; i++)
        for (int j = i; j < size_; j++)
            if(mat_[i][j]==1)
                rez++;
    return rez;
}

std::ostream& operator<<(std::ostream& out, const graf& g)
{// vom afisa doar muchhile deasupra diagonalei principale deoarece este un graf neorientat
    for (int i = 1; i < g.size_; i++)
        for (int j = i; j < g.size_; j++)
            if(g.mat_[i][j]==1)
                out<<i<<' '<<j<<'\n';
    return out;
}

graf::~graf()//destructor
{
    for (int i = 0; i < size_; ++i)
        delete [] mat_[i];
    delete [] mat_;
    size_=0;
}
