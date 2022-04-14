#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>

std::string generare_nume()
{
    std::string nume;
    char *list_nume[16]={"Adam","Adelin","Adrian","Adriana","Alex","Alexandru","Alexie","Alin","Amalia","Amos","Ana","Anca","Ancuta","Andreas","Andreea","Andrei"};
    nume= list_nume[rand()%16];
    return nume;
}
class Data{
private:
    int zi;
    char *luna;
    int an;

public:
    Data(int zi_=1, char *luna_="ianuarie", int an_=1990){
        this->zi=zi_;
        this->luna= static_cast<char *>(malloc(strlen(luna_) + 1));
        strcpy(this->luna, luna_);
        this->an=an_;
    }
    Data(const Data &D){
        this->zi=D.zi;
        this->luna= static_cast<char *>(malloc(strlen(D.luna) + 1));
        strcpy(this->luna, D.luna);
        this->an=D.an;
    }
    ~Data(){
    }
    void set_date(int zi_, char *luna_, int an_) {
        this->zi=zi_;
        strcpy(this->luna, luna_);
        this->an=an_;
    }

    void set_zi(int zi_) {
        zi = zi_;
    }

    void set_luna(const char *luna_) {
        strcpy(luna, luna_);
    }

    void set_an(int an_) {
        an = an_;
    }

    int get_zi() const {
        return zi;
    }
    char get_luna() const {
        return *luna;
    }
    int get_an() const {
        return an;
    }

    Data &operator=(const Data &D) {
        this->zi=D.zi;
        strcpy(this->luna, D.luna);
        this->an=D.an;
        return *this;
    }

    bool operator!=(const Data &D) {
        bool ok = 1;
        if (this->zi != D.zi)
            ok = 0;
        if (this->an != D.an)
            ok = 0;
        if (strcmp(this->luna, D.luna) != 0)
            ok = 0;
        return !ok;
    }

    int numar_luna(const char* luna) const {
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

    bool operator<=(const Data &D) { //returneaza 1 daca this<=D

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
    bool an_bisect(int an) const {
        if (an % 400 == 0)
            return 1;

        if (an % 100 == 0)
            return 0;
        if (an % 4 == 0)
            return 1;
        return 0;
    }
    int operator-(const Data &D) { //returneaza 1 daca this<D
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

    friend std::ostream &operator<<(std::ostream &os, const Data &D) {
        os<<D.zi<<" "<<D.luna<<" "<<D.an<<'\n';
        return os;
    }

    Data  ultima_zi_a_lunii()  {
        int nrzileluna[13]={0,31,28+an_bisect(this->an),31,30,31,30,31, 31, 31, 31,30,31};
        Data ult_zi(nrzileluna[numar_luna(this->luna)], this->luna, this->an);
        return ult_zi;
    }
};

class Angajat{
protected:
    static Data data_curenta;
    static Data data_final_an;
    std:: string nume;
    std:: string prenume;
    float salariu;
    Data data_angajare;

public:
    Angajat(std::string nume_, std::string prenume_, float salariu_, Data data_angajare_ ){
        this->nume=nume_;
        this->prenume=prenume_;
        this->salariu=salariu_;
        this->data_angajare=data_angajare_;
    }
    Angajat(const Angajat &A){
        this->nume=A.nume;
        this->prenume=A.prenume;
        this->salariu=A.salariu;
        this->data_angajare=A.data_angajare;
    }
    ~Angajat(){
    }
    void set_angajat(std::string nume_, std::string prenume_, float salariu_, Data data_angajare_ ) {
        this->nume=nume_;
        this->prenume=prenume_;
        this->salariu=salariu_;
        this->data_angajare=data_angajare_;
    }

    void set_nume(std::string nume_) {
        nume = nume_;
    }

    void set_prenume(std::string prenume_) {
        nume = prenume_;
    }
    void set_salariu(float salariu_) {
        salariu = salariu_;
    }
    void set_data_angajare(Data data_angajare_){
        data_angajare= data_angajare_;
    }

    std::string get_nume() const {
        return nume;
    }
    std::string get_prenume() const {
        return prenume;
    }
    float get_salariu() const {
        return salariu;
    }
    Data get_data_angajare() const{
        return data_angajare;
    }

    Angajat &operator=(const Angajat &A) {
        this->nume=A.nume;
        this->prenume=A.prenume;
        this->salariu=A.salariu;
        this->data_angajare=A.data_angajare;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &os,const Angajat &A) {
        os<<"Nume si prenume: "<<A.nume<<" "<<A.prenume<<'\n'<<"Salariu: "<<A.salariu<<'\n'<<"Data angajare: "<<A.data_angajare;
        return os;
    }

    float prima_de_primit(){
        float sp=spor();
        return salariu*sp;
    }
    virtual float spor(){};

    static void schimba_data_final_an(){
        data_final_an.set_an(data_final_an.get_an()+1);
    }

    static void schimba_data_curenta(int zi, char* luna, int an){
        data_curenta.set_zi(zi);
        data_curenta.set_luna(luna);
        data_curenta.set_an(an);
    }

};

Data Angajat:: data_curenta(11, "aprilie", 2022);
Data Angajat:: data_final_an(30, "decembrie", 2020);

class Part_Time: public Angajat {
protected:
    int nr_ore_zi;
    Data final_contract;
public:
    Part_Time(int nr_ore_zi_, Data final_contract_, std::string nume_, std::string prenume_, float salariu_,
              Data data_angajare_)
            : Angajat(nume_, prenume_, salariu_, data_angajare_) {
        this->nr_ore_zi = nr_ore_zi_;
        this->final_contract = final_contract_;
    }

    Part_Time(const Part_Time &P)
            : Angajat(P) {
        this->nr_ore_zi = P.nr_ore_zi;
        this->final_contract = P.final_contract;
    }

    void operator=(const Part_Time &P) {
        (Angajat &) (*this) = P;
        this->final_contract = P.final_contract;
        this->nr_ore_zi = P.nr_ore_zi;
    }
    ~Part_Time(){};
    friend std::ostream &operator<<(std::ostream &os, Part_Time &A) {
        os<<(Angajat &)(A)<<"Numar ore pe zi: "<<A.nr_ore_zi<<'\n'<<"Data final contract: "<<A.final_contract<<'\n';
        return os;
    }
    void set_nr_ore_zi(int nr_ore_zi_) {
        nr_ore_zi = nr_ore_zi_;
    }
    void set_data_angajare(Data data_final_contract){
        data_angajare= data_final_contract;
    }
    Data get_final_contract() const{
        return final_contract;
    }
    int get_nr_ore_zi() const{
        return nr_ore_zi;
    }
    float spor(){
        float spor_;
        Data ult_zi;
        ult_zi=data_curenta.ultima_zi_a_lunii();
        if(this->final_contract<=  ult_zi )
            spor_=(float)75/100;
        else spor_=1;
        return spor_;
    }
};

class Permanent: public Angajat {
protected:
    int nr_minori_intretinere;
public:
    Permanent(int nr_minori_intretinere_, std::string nume_, std::string prenume_, float salariu_,
              Data data_angajare_)
            : Angajat(nume_, prenume_, salariu_, data_angajare_) {
        this->nr_minori_intretinere=nr_minori_intretinere_;
    }

    Permanent(const Permanent &P)
            : Angajat(P) {
        this->nr_minori_intretinere= P.nr_minori_intretinere;

    }

    void operator=(const Permanent &P) {
        (Angajat &) (*this) = P;
        this->nr_minori_intretinere= P.nr_minori_intretinere;
    }
    friend std::ostream &operator<<(std::ostream &os,const Permanent &A) {
        os<<(Angajat &)(A)<<"Numar minori in intretinere: "<<A.nr_minori_intretinere<<'\n';
        return os;
    }
    ~Permanent(){};

    void set_nr_minori_intretinere(int nr_minori_intretinere_) {
        nr_minori_intretinere = nr_minori_intretinere_;
    }

    int get_nr_minori_intretinere() const{
        return nr_minori_intretinere;
    }

    float spor() {
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

};

void testare_data(){
    Data d(11,"aprilie", 2022);
    Data maine;
    maine=d;
    maine.set_zi(d.get_zi()+1);
    std::cout<<maine;
    Data poimaine(maine);
    poimaine.set_zi(maine.get_zi()+1);
    std::cout<<poimaine;
    Data raspoimaine=poimaine;
    raspoimaine.set_zi(poimaine.get_zi()+1);
    std::cout<<raspoimaine;
    int dif=raspoimaine-d;
    std::cout<<"Numar zile diferenta: "<<dif;
}

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
    vector_n_elemente(int nr_elemente){
        Angajat **vector = static_cast<Angajat **>(malloc(sizeof(Angajat *) * nr_elemente));
        n=nr_elemente;
    }
    ~vector_n_elemente(){
        for(int i=0;i<n;i++)
            delete vector[i];
    };
    void initializare(){
        Data data_ang(1,"februarie", 2000);
        Data data2(11, "aprilie", 2022);
        for (int i=0;i<n;i++){
            if(i%2) {
                vector[i] = new Permanent(i, generare_nume(), generare_nume(), (i * i+1) * 100, data_ang);
                Permanent *pPermanent = dynamic_cast<Permanent*>(vector[i]);
                std::cout<<*pPermanent<<'\n';
                data_ang.set_zi(data_ang.get_zi() <= 25 ? data_ang.get_zi() + 1 : 1);
                data_ang.set_an(data_ang.get_an() <= 2021 ? data_ang.get_an() + 1 : 1990);

            }
            else{
                vector[i]= new Part_Time(8%(i+1)+1, data2,generare_nume(), generare_nume(), (i * i+1) * 100,data_ang);
                Part_Time *pPartTime = dynamic_cast<Part_Time*>(vector[i]);
                std::cout<<*pPartTime<<'\n';
                data_ang.set_zi(data_ang.get_zi() <= 25 ? data_ang.get_zi() + 1 : 1);
                data_ang.set_an(data_ang.get_an() <= 2021 ? data_ang.get_an() + 1 : 1990);
            }

        }
    }
    void afisare(){
        for(int i=0;i<n;i++)
            std::cout <<"Prima de primit "<<i+1<<": "<< vector[i]->prima_de_primit() << '\n';
    }
    void afisare_element(int i){
        try{
            if(i>=n) throw MyOutOfBoundsException();;
            std::cout << *vector[i];
        }
        catch (const MyOutOfBoundsException &e) {
            std::cout << e.what() << '\n';
        }
    }

};


void vector_stl()
{
    Data data_ang(1,"februarie", 2000);
    Data data_azi(11, "aprilie", 2022);

    std::vector< std::shared_ptr<Angajat> > v;
    std::shared_ptr<Part_Time> pa( new Part_Time(7,data_ang,"ion","ion",7500,data_ang) );
    std::shared_ptr<Permanent> pb( new Permanent(12,"ion", "ana", 2900,data_azi) );
    v.push_back(pa);
    v.push_back(pb);
    std::cout<<"Prima prima: "<<v[0]->prima_de_primit()<<'\n';
    std::cout<<"A doua prima: "<<v[1]->prima_de_primit()<<'\n';
}

void vector_al_meu()
{
    vector_n_elemente v(10);
    v.initializare();
    v.afisare_element(12);
    v.afisare();
}

void testare_generala(){
    Data data_ang(1,"februarie", 2000);
    Data data_azi(11, "aprilie", 2022);
    Data data_indep(1,"ianuarie", 1995);

    Angajat unu("ion","ion",7500,data_ang);
    std::cout<<unu<<'\n';
    Part_Time doi(7,data_ang,"ion","ion",7500,data_ang);
    std::cout<<doi;
    Permanent trei(3,"alex","ioan", 3000, data_indep);
    std::cout<<trei;

    std::cout<<'\n';

    Angajat *v[3];
    v[0]= new Permanent(12,"ion", "ana", 2900,data_azi);
    v[1]= new Part_Time(7,data_ang,"ion","ion",7500,data_ang);
    v[2]= new Permanent(3,"alex","ioan", 3000, data_indep);
    for(int i=0;i<3;i++)
        std::cout<<"Prima de primit "<<i+1<<": "<<v[i]->prima_de_primit()<<'\n';
}

int meniu(){
    int n;
    std::cout<<"Introduceti numarul comenzii: "<<'\n';
    std::cout<<"1 - Testare generala"<<'\n';
    std::cout<<"2 - Testare tipul Data"<<'\n';
    std::cout<<"3 - Testare vector de pointers"<<'\n';
    std::cout<<"4 - Testare vector stl cu smart pointers"<<'\n';
    std::cin>>n;
    if(n==1) testare_generala();
    if(n==2) testare_data();
    if(n==3) vector_al_meu();
    if(n==4) vector_stl();
}
int main() {
    vector_al_meu();
    meniu();
    return 0;
}
