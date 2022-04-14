//
// Created by isach on 14/04/2022.
//
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include "Data.h"
#include "Angajat.h"
#ifndef TEMA2_FINAL_PART_TIMA_H
#define TEMA2_FINAL_PART_TIMA_H


class Part_Time: public Angajat {
protected:
    int nr_ore_zi;
    Data final_contract;
public:
    Part_Time(int nr_ore_zi_, Data final_contract_, std::string nume_, std::string prenume_, float salariu_,
              Data data_angajare_);

    Part_Time(const Part_Time &P);

    void operator=(const Part_Time &P) ;
    ~Part_Time();

    friend std::ostream &operator<<(std::ostream &os, Part_Time &A) ;
    void set_nr_ore_zi(int nr_ore_zi_) ;
    void set_data_angajare(Data data_final_contract);
    Data get_final_contract() const;
    int get_nr_ore_zi() const;
    float spor();
};



#endif //TEMA2_FINAL_PART_TIMA_H
