//
// Created by isach on 14/04/2022.
//

#include "Angajat.h"

    Angajat::Angajat(std::string nume_, std::string prenume_, float salariu_, Data data_angajare_ ){
        this->nume=nume_;
        this->prenume=prenume_;
        this->salariu=salariu_;
        this->data_angajare=data_angajare_;
    }
Angajat::Angajat(const Angajat &A){
        this->nume=A.nume;
        this->prenume=A.prenume;
        this->salariu=A.salariu;
        this->data_angajare=A.data_angajare;
    }
    Angajat::~Angajat(){
    }
    void Angajat::set_angajat(std::string nume_, std::string prenume_, float salariu_, Data data_angajare_ ) {
        this->nume=nume_;
        this->prenume=prenume_;
        this->salariu=salariu_;
        this->data_angajare=data_angajare_;
    }

    void Angajat:: set_nume(std::string nume_) {
        nume = nume_;
    }

    void Angajat::set_prenume(std::string prenume_) {
        nume = prenume_;
    }
    void Angajat::set_salariu(float salariu_) {
        salariu = salariu_;
    }
    void Angajat:: set_data_angajare(Data data_angajare_){
        data_angajare= data_angajare_;
    }

    std::string Angajat::get_nume() const {
        return nume;
    }
    std::string Angajat:: get_prenume() const {
        return prenume;
    }
    float Angajat:: get_salariu() const {
        return salariu;
    }
    Data Angajat::get_data_angajare() const{
        return data_angajare;
    }

    Angajat &Angajat::operator=(const Angajat &A) {
        this->nume=A.nume;
        this->prenume=A.prenume;
        this->salariu=A.salariu;
        this->data_angajare=A.data_angajare;
        return *this;
    }
    std::ostream &operator<<(std::ostream &os,const Angajat &A) {
        os<<"Nume si prenume: "<<A.nume<<" "<<A.prenume<<'\n'<<"Salariu: "<<A.salariu<<'\n'<<"Data angajare: "<<A.data_angajare;
        return os;
    }

    float Angajat::prima_de_primit(){
        float sp=spor();
        return salariu*sp;
    }
    float Angajat:: spor(){};

    void Angajat::schimba_data_final_an(){
        data_final_an.set_an(data_final_an.get_an()+1);
    }

    void Angajat::schimba_data_curenta(int zi, char* luna, int an){
        data_curenta.set_zi(zi);
        data_curenta.set_luna(luna);
        data_curenta.set_an(an);
    }

