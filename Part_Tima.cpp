//
// Created by isach on 14/04/2022.
//

#include "Part_Tima.h"

Part_Time::Part_Time(int nr_ore_zi_, Data final_contract_, std::string nume_, std::string prenume_, float salariu_,
              Data data_angajare_)
            : Angajat(nume_, prenume_, salariu_, data_angajare_) {
        this->nr_ore_zi = nr_ore_zi_;
        this->final_contract = final_contract_;
    }

Part_Time::Part_Time(const Part_Time &P)
            : Angajat(P) {
        this->nr_ore_zi = P.nr_ore_zi;
        this->final_contract = P.final_contract;
    }

    void Part_Time::operator=(const Part_Time &P) {
        (Angajat &) (*this) = P;
        this->final_contract = P.final_contract;
        this->nr_ore_zi = P.nr_ore_zi;
    }
Part_Time::~Part_Time(){};

    std::ostream &operator<<(std::ostream &os, Part_Time &A) {
        os<<(Angajat &)(A)<<"Numar ore pe zi: "<<A.nr_ore_zi<<'\n'<<"Data final contract: "<<A.final_contract<<'\n';
        return os;
    }
    void Part_Time:: set_nr_ore_zi(int nr_ore_zi_) {
        nr_ore_zi = nr_ore_zi_;
    }
    void Part_Time::set_data_angajare(Data data_final_contract){
        data_angajare= data_final_contract;
    }
    Data Part_Time::get_final_contract() const{
        return final_contract;
    }
    int Part_Time::get_nr_ore_zi() const{
        return nr_ore_zi;
    }
    float Part_Time::spor(){
        float spor_;
        Data ult_zi;
        ult_zi=data_curenta.ultima_zi_a_lunii();
        if(this->final_contract<=  ult_zi )
            spor_=(float)75/100;
        else spor_=1;
        return spor_;
    }

