
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include "Data.h"
#include "Angajat.h"
#include "Part_Tima.h"
#ifndef TEMA2_FINAL_PERMANENT_H
#define TEMA2_FINAL_PERMANENT_H


class Permanent: public Angajat {
protected:
    int nr_minori_intretinere;
public:
    Permanent(int nr_minori_intretinere_, std::string nume_, std::string prenume_, float salariu_,
              Data data_angajare_);

    Permanent(const Permanent &P);

    void operator=(const Permanent &P) ;
    friend std::ostream &operator<<(std::ostream &os,const Permanent &A) ;
    ~Permanent();

    void set_nr_minori_intretinere(int nr_minori_intretinere_) ;

    int get_nr_minori_intretinere() const;

    float spor();

};


#endif //TEMA2_FINAL_PERMANENT_H
