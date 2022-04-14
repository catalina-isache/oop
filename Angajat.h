//
// Created by isach on 14/04/2022.
//
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include "Data.h"
#ifndef TEMA2_FINAL_ANGAJAT_H
#define TEMA2_FINAL_ANGAJAT_H


class Angajat{
protected:
    static Data data_curenta;
    static Data data_final_an;
    std:: string nume;
    std:: string prenume;
    float salariu;
    Data data_angajare;

public:
    Angajat(std::string nume_, std::string prenume_, float salariu_, Data data_angajare_ );
    Angajat(const Angajat &A);
    virtual ~Angajat();
    void set_angajat(std::string nume_, std::string prenume_, float salariu_, Data data_angajare_ ) ;

    void set_nume(std::string nume_);

    void set_prenume(std::string prenume_) ;
    void set_salariu(float salariu_);
    void set_data_angajare(Data data_angajare_);

    std::string get_nume() const ;
    std::string get_prenume() const ;
    float get_salariu() const ;
    Data get_data_angajare() const;

    Angajat &operator=(const Angajat &A) ;
    friend std::ostream &operator<<(std::ostream &os,const Angajat &A) ;

    float prima_de_primit();
    virtual float spor();

    static void schimba_data_final_an();

    static void schimba_data_curenta(int zi, char* luna, int an);

};


#endif //TEMA2_FINAL_ANGAJAT_H
