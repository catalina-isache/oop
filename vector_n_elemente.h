
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include "Data.h"
#include "Angajat.h"
#include "Part_Tima.h"
#include "Permanent.h"
#ifndef TEMA2_FINAL_VECTOR_N_ELEMENTE_H
#define TEMA2_FINAL_VECTOR_N_ELEMENTE_H


class MyOutOfBoundsException : public std::exception {
public:
    MyOutOfBoundsException() = default;
    const char* what() const noexcept override  {
        return "Element inexistent";
    }
};

class vector_n_elemente{
private:
    Angajat **vector;
    int n;
public:
    vector_n_elemente(int nr_elemente);
    ~vector_n_elemente();
    vector_n_elemente(const vector_n_elemente&A);
    void initializare();
    void afisare();
    void afisare_element(int i);

};



#endif //TEMA2_FINAL_VECTOR_N_ELEMENTE_H
