#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include "Data.h"
#include "Angajat.h"
#include "Part_Tima.h"
#include "Permanent.h"
#include "vector_n_elemente.h"

std::string generare_nume()
{
    std::string nume;
    char *list_nume[16]={"Adam","Adelin","Adrian","Adriana","Alex","Alexandru","Alexie","Alin","Amalia","Amos","Ana","Anca","Ancuta","Andreas","Andreea","Andrei"};
    nume= list_nume[rand()%16];
    return nume;
}

Data Angajat:: data_curenta(11, "aprilie", 2022);
Data Angajat:: data_final_an(30, "decembrie", 2020);


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

void meniu(){
    int n;
    std::cout<<"Introduceti numarul comenzii: "<<'\n';
    std::cout<<"1 - Testare generala"<<'\n';
    std::cout<<"2 - Testare tipul Data"<<'\n';
    std::cout<<"3 - Testare vector stl cu smart pointers"<<'\n';
    std::cin>>n;
    if(n==1) testare_generala();
    if(n==2) testare_data();
    if(n==3) vector_stl();
}

int main() {
    //vector_al_meu(); //ruleaza si afiseaza dar da segmentation fault
    meniu();
    return 0;
}
