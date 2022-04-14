
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#ifndef TEMA2_FINAL_DATA_H
#define TEMA2_FINAL_DATA_H


class Data{
private:
    int zi;
    char *luna;
    int an;

public:
    Data(int zi_=1, char *luna_="ianuarie", int an_=1998);
    Data(const Data &D);
    ~Data();

    void set_date(int zi_, char *luna_, int an_) ;
    void set_zi(int zi_) ;
    void set_luna(const char *luna_) ;
    void set_an(int an_) ;
    int get_zi() const;
    char get_luna() const;
    int get_an() const ;

    Data &operator=(const Data &D);
    bool operator!=(const Data &D);

    int numar_luna(const char* luna) const ;
    bool operator<=(const Data &D) ;
    bool an_bisect(int an) const ;
    int operator-(const Data &D) ;
    friend std::ostream &operator<<(std::ostream &os, const Data &D) ;
    Data  ultima_zi_a_lunii() ;
};

#endif