
#include "Data.h"

Data::Data(int zi_, char *luna_, int an_){
    this->zi=zi_;
    this->luna= static_cast<char *>(malloc(strlen(luna_) + 1));
    strcpy(this->luna, luna_);
    this->an=an_;
}
Data::Data(const Data &D){
    this->zi=D.zi;
    this->luna= static_cast<char *>(malloc(strlen(D.luna) + 1));
    strcpy(this->luna, D.luna);
    this->an=D.an;
}
Data::~Data(){
    delete luna;
}
void Data::set_date(int zi_, char *luna_, int an_) {
    this->zi=zi_;
    strcpy(this->luna, luna_);
    this->an=an_;
}

void Data::set_zi(int zi_) {
    zi = zi_;
}

void Data::set_luna(const char *luna_) {
    strcpy(luna, luna_);
}

void Data::set_an(int an_) {
    an = an_;
}

int Data::get_zi() const {
    return zi;
}
char Data::get_luna() const {
    return *luna;
}
int Data::get_an() const {
    return an;
}

Data  & Data::operator=(const Data &D) {
    this->zi=D.zi;
    strcpy(this->luna, D.luna);
    this->an=D.an;
    return *this;
}

bool Data::operator!=(const Data &D) {
    bool ok = 1;
    if (this->zi != D.zi)
        ok = 0;
    if (this->an != D.an)
        ok = 0;
    if (strcmp(this->luna, D.luna) != 0)
        ok = 0;
    return !ok;
}

int Data:: numar_luna(const char* luna) const {
    if(luna[0]=='i' && luna[1]=='a')
        return 1;
    if(luna[0]=='f' )
        return 2;
    if(luna[0]=='m' && luna[2]=='r')
        return 3;
    if(luna[0]=='a' && luna[1]=='p')
        return 4;
    if(luna[0]=='m' && luna[2]=='i')
        return 5;
    if(luna[0]=='i' && luna[2]=='n')
        return 6;
    if(luna[0]=='i' && luna[2]=='l')
        return 7;
    if(luna[0]=='a' && luna[1]=='u')
        return 8;
    if(luna[0]=='s' )
        return 9;
    if(luna[0]=='o' )
        return 10;
    if(luna[0]=='n' )
        return 11;
    if(luna[0]=='d' )
        return 12;
}

bool Data:: operator<=(const Data &D) { //returneaza 1 daca this<=D

    if (this->an > D.an)
        return 0;
    if (this->an < D.an)
        return 1;

    int this_numar_luna=numar_luna(this->luna);
    int D_numar_luna=numar_luna(D.luna);
    if(this_numar_luna > D_numar_luna)
        return 0;
    if(this_numar_luna < D_numar_luna)
        return 1;

    if (this->zi > D.zi)
        return 0;
    if (this->zi < D.zi)
        return 1;

    return 1;
}
bool Data:: an_bisect(int an) const {
    if (an % 400 == 0)
        return 1;

    if (an % 100 == 0)
        return 0;
    if (an % 4 == 0)
        return 1;
    return 0;
}
int Data::operator-(const Data &D) { //returneaza 1 daca this<D
    //if(*this<=D) return -1;  ///exceptiee
    int nr_zile=0;
    int nrzileluna[13]={0,31,28+an_bisect(this->an),31,30,31,30,31, 31, 31, 31,30,31};
    if(numar_luna(D.luna)== numar_luna(this->luna) && D.an==this->an)
        return this->zi-D.zi;
    nr_zile=this->zi;
    for(int i=1; i< numar_luna(this->luna); i++)
        nr_zile+=nrzileluna[i];

    nrzileluna[2]=28+an_bisect(D.an);
    for(int i=numar_luna(D.luna)+1; i<=12; i++)
        nr_zile+=nrzileluna[i];
    nr_zile+=nrzileluna[numar_luna(D.luna)]-D.zi+1;

    for(int i=D.an+1;i<this->an; i++)
        nr_zile+=365+an_bisect(i);
    return nr_zile;
}

std::ostream & operator<<(std::ostream &os, const Data &D) {
    os<<D.zi<<" "<<D.luna<<" "<<D.an<<'\n';
    return os;
}

Data Data:: ultima_zi_a_lunii()  {
    int nrzileluna[13]={0,31,28+an_bisect(this->an),31,30,31,30,31, 31, 31, 31,30,31};
    Data ult_zi(nrzileluna[numar_luna(this->luna)], this->luna, this->an);
    return ult_zi;
}
