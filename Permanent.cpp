

#include "Permanent.h"


Permanent::Permanent(int nr_minori_intretinere_, std::string nume_, std::string prenume_, float salariu_,
          Data data_angajare_)
        : Angajat(nume_, prenume_, salariu_, data_angajare_) {
    this->nr_minori_intretinere=nr_minori_intretinere_;
}

Permanent::Permanent(const Permanent &P)
        : Angajat(P) {
    this->nr_minori_intretinere= P.nr_minori_intretinere;

}

void Permanent:: operator=(const Permanent &P) {
    (Angajat &) (*this) = P;
    this->nr_minori_intretinere= P.nr_minori_intretinere;
}
std::ostream &operator<<(std::ostream &os,const Permanent &A) {
    os<<(Angajat &)(A)<<"Numar minori in intretinere: "<<A.nr_minori_intretinere<<'\n';
    return os;
}
Permanent::~Permanent(){};

void Permanent:: set_nr_minori_intretinere(int nr_minori_intretinere_) {
    nr_minori_intretinere = nr_minori_intretinere_;
}

int Permanent::get_nr_minori_intretinere() const{
    return nr_minori_intretinere;
}

float Permanent::spor() {
    float spor_;
    char *t=static_cast<char *>(malloc(strlen("decembrie") + 1));
    if((data_final_an-data_angajare)/365>=12){
        double var=12*nr_minori_intretinere;
        var/=100;
        spor_=1+var;
    }

    else spor_=1;
    return spor_;
}

