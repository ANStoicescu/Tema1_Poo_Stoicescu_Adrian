#ifndef GRAF_H
#define GRAF_H
#include<iostream>

class graf
{
    int size_;
    int** mat_;
    public:

    graf(int nr_noduri);
    graf(const graf& other);
    void add_muchie(int x, int y);
    virtual ~graf();
    graf& operator=(const graf& other);
    friend std::ostream& operator<<(std::ostream&, const graf&);

};



#endif // GRAF_H
