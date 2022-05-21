#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

std::string generare_nume()
{
    std::string nume;
    string list_nume[16]={"Adam","Adelin","Adrian","Adriana","Alex","Alexandru","Alexie","Alin","Amalia","Amos","Ana","Anca","Ancuta","Andreas","Andreea","Andrei"};
    nume= list_nume[rand()%16];
    return nume;
}
template <typename T>
class Data{
private:
    int zi{};
    T luna;
    int an{};

public:
    Data()=default;
    Data(int zi_, T luna_, int an_){
        this->zi=zi_;
        this->luna= luna_;
        this->an=an_;
    }
    Data(const Data<T> &D){
        this->zi=D.zi;
        this->luna=D.luna;
        this->an=D.an;
    }
    ~Data()=default;
    void set_date(int zi_, T luna_, int an_) {
        this->zi=zi_;
        this->luna=luna_;
        this->an=an_;
    }

    void set_zi(int zi_) {
        zi = zi_;
    }

    void set_luna(T luna_) {
        luna=luna_;
    }

    void set_an(int an_) {
        an = an_;
    }

    int get_zi() const {
        return zi;
    }
    T get_luna() const {
        return luna;
    }
    int get_an() const {
        return an;
    }

    Data &operator=(const Data<T> &D) {
        this->zi=D.zi;
        this->luna=D.luna;
        this->an=D.an;
        return *this;
    }

    bool operator!=(const Data<T> &D) {
        bool ok = true;
        if (typeid(D.luna).name()==typeid(this->luna).name())
            ok = (this->luna==D.luna);
        else{
            int a=get_numar_luna(D.luna);
            int b=get_numar_luna(this->luna);
            ok=(a==b);
        }
        if (this->zi != D.zi)
            ok = false;
        if (this->an != D.an)
            ok = false;
        return !ok;
    }

    int numar_luna(int luna_) const {
        return luna_;
    }
    int numar_luna(string luna_) const{
        if(luna_[0]=='i' && luna_[1]=='a')
            return 1;
        if(luna_[0]=='f' )
            return 2;
        if(luna_[0]=='m' && luna_[2]=='r')
            return 3;
        if(luna_[0]=='a' && luna_[1]=='p')
            return 4;
        if(luna_[0]=='m' && luna_[2]=='i')
            return 5;
        if(luna_[0]=='i' && luna_[2]=='n')
            return 6;
        if(luna_[0]=='i' && luna_[2]=='l')
            return 7;
        if(luna_[0]=='a' && luna_[1]=='u')
            return 8;
        if(luna_[0]=='s' )
            return 9;
        if(luna_[0]=='o' )
            return 10;
        if(luna_[0]=='n' )
            return 11;
        if(luna_[0]=='d' )
            return 12;
        return 1;
    }

    bool operator<=(const Data<T> &D) { //returneaza 1 daca this<=D

        if (this->an > D.an)
            return false;
        if (this->an < D.an)
            return true;

        int this_numar_luna=numar_luna(this->luna);
        int D_numar_luna=numar_luna(D.luna);
        if(this_numar_luna > D_numar_luna)
            return false;
        if(this_numar_luna < D_numar_luna)
            return true;

        if (this->zi > D.zi)
            return false;
        if (this->zi < D.zi)
            return true;

        return true;
    }
    bool an_bisect(int an_) const {
        if (an_ % 400 == 0)
            return true;

        if (an_ % 100 == 0)
            return false;
        if (an_ % 4 == 0)
            return true;
        return false;
    }
    int operator-(const Data<T> &D) {
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

    friend std::ostream &operator<<(std::ostream &os, const Data<T> &D) {
        os<<D.zi<<" "<<D.luna<<" "<<D.an<<'\n';
        return os;
    }

    Data<int>  ultima_zi_a_lunii()  {
        int nrzileluna[13]={0,31,28+an_bisect(this->an),31,30,31,30,31, 31, 31, 31,30,31};
        Data<int> ult_zi(nrzileluna[numar_luna(this->luna)], numar_luna(this->luna), this->an);
        return ult_zi;
    }

    Data<int> conversion(){
        Data<int> data_int(get_zi(),numar_luna(get_luna()),get_an());
        return data_int;
    }

};
//folosim template method
class Angajat{
protected:
    std:: string nume;
    std:: string prenume;
    float salariu;
    Data<int> data_angajare;

public:
    Angajat(std::string nume_, std::string prenume_, float salariu_,Data<int> dataAngajare) : data_angajare(dataAngajare) {
        this->nume=nume_;
        this->prenume=prenume_;
        this->salariu=salariu_;

    }
    Angajat(const Angajat &A) : data_angajare(A.data_angajare) {
        this->nume=A.nume;
        this->prenume=A.prenume;
        this->salariu=A.salariu;
    }
    ~Angajat()=default;

    Angajat &operator=(const Angajat &A) {
        this->nume=A.nume;
        this->prenume=A.prenume;
        this->salariu=A.salariu;
        this->data_angajare=A.data_angajare;
        return *this;
    }

    float prima_de_primit(){
        float sp=spor();
        return salariu*sp;
    }
    virtual float spor(){};

    std::string get_nume() const {
        return nume;
    }
    std::string get_prenume() const {
        return prenume;
    }

};

extern Data<string>  data_curenta(21,"mai",2022);
extern Data<string>  data_final_an(30,"decembrie",2022);

class Part_Time:  public Angajat{
protected:
    int nr_ore_zi;
    Data<int> final_contract;
public:
    Part_Time(int nr_ore_zi_, const Data<int>& final_contract_, std::string nume_, std::string prenume_, float salariu_,
              const Data<int>& data_angajare_)
            : Angajat(nume_, prenume_, salariu_, Data<int>(0, 0, 0)) {
        this->nr_ore_zi = nr_ore_zi_;
        this->final_contract = final_contract_;
    }

    Part_Time(const Part_Time &P)
            : Angajat(P) {
        this->nr_ore_zi = P.nr_ore_zi;
        this->final_contract = P.final_contract;
    }

    ~Part_Time()=default;

    float spor(){
        float spor_;
        Data<int> ult_zi;
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
              const Data<int>& data_angajare_)
            : Angajat(nume_, prenume_, salariu_, data_angajare_) {
        this->nr_minori_intretinere=nr_minori_intretinere_;
    }

    Permanent(const Permanent &P)
            : Angajat(P) {
        this->nr_minori_intretinere= P.nr_minori_intretinere;

    }

    ~Permanent()= default;

    float spor() override {
        float spor_;
        Data<int> data_final=data_final_an.conversion();
        if((data_final-data_angajare)/365>=12){
            double var=12*nr_minori_intretinere;
            var/=100;
            spor_=1+var;
        }
        else spor_=1;
        return spor_;
    }

};

void testare_data(){
    Data<string> d(11,"aprilie", 2022);
    Data<string> maine;
    maine=d;
    maine.set_zi(d.get_zi()+1);
    std::cout<<maine;
    Data<string> poimaine(maine);
    poimaine.set_zi(maine.get_zi()+1);
    std::cout<<poimaine;
    Data<string> raspoimaine=poimaine;
    raspoimaine.set_zi(poimaine.get_zi()+1);
    std::cout<<raspoimaine;
    int dif=raspoimaine-d;
    std::cout<<"Numar zile diferenta: "<<dif;
}

class SingletonPrime_de_primit{
private:
    static SingletonPrime_de_primit* instance;
    vector<pair<pair<string,string>, double> > lista_prime;
    SingletonPrime_de_primit():lista_prime(){
    }

public:
    static SingletonPrime_de_primit* getInstance(){
        if (instance == 0)
            instance = new SingletonPrime_de_primit();
        return instance;
    }
    void adauga_angajat(const shared_ptr<Angajat>& p){
        lista_prime.push_back({{p->get_nume(),p->get_prenume()},p->prima_de_primit()});
    }
    void afisare(){
        for(auto & i : lista_prime){
            cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<'\n';
        }
    }

};
SingletonPrime_de_primit* SingletonPrime_de_primit::instance = 0;
string generare_luna(int x){
    switch(x) {
        case 0:
            return "ianuarie";
            break;
        case 1:
            return "februarie";
            break;
        case 2:
            return "martie";
        case 3:
            return "aprilie";
        case 4:
            return "mai";
        case 5:
            return "iunie";
        case 6:
            return "iulie";
        case 7:
            return "august";
        case 8:
            return "septembrie";
        case 9:
            return "octombrie";
        case 10:
            return "noiembrie";
        case 11:
            return "decembrie";
        default:
            return "decembrie";
    }
}

template <typename T> T maxim(T x, T y)
{
    if(x<=y) return y;
    return x;
}

int main() {
    SingletonPrime_de_primit* s = SingletonPrime_de_primit::getInstance();
    std::vector< std::shared_ptr<Angajat> > v;
    Data<string> data_ang_max_s(1,"ianuarie",1980);
    Data<int> data_ang_max_i(1,1,1980);
    int n=5;
    for(int i=1; i<=n;i++){
        if(i%2){
            Data<string> data_ang(rand()%30,generare_luna(rand()%12), 2010+i);
            Data<string> data_final(rand()%30,generare_luna(rand()%12), 2010+i*2);
            std::shared_ptr<Part_Time> pa( new Part_Time(7,data_ang.conversion(),generare_nume(),generare_nume(),i*1000.5,data_ang.conversion()) );
            v.push_back(pa);
            s->adauga_angajat(pa);
            data_ang_max_s=maxim(data_ang_max_s,data_ang);
        }
        else{
            Data<int> data_ang(rand()%30,rand()%12+1, 2010+i);
            Data<int> data_final(rand()%30,rand()%12+1, 2010+i*2);
            std::shared_ptr<Permanent> pb( new Permanent(rand()%5,generare_nume(), generare_nume(), i*1000,data_ang.conversion()) );
            v.push_back(pb);
            s->adauga_angajat(pb);
            data_ang_max_i=maxim(data_ang_max_i,data_ang);
        }
    }
    s->afisare();
    cout<<"Data cea mai recenta angajare: "<<(data_ang_max_i<=data_ang_max_s.conversion()? data_ang_max_s.conversion():data_ang_max_i);

    return 0;
}
