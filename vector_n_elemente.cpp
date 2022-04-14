//
// Created by isach on 14/04/2022.
//

#include "vector_n_elemente.h"

vector_n_elemente::vector_n_elemente(int nr_elemente){
    Angajat **vector = static_cast<Angajat **>(malloc(sizeof(Angajat *) * nr_elemente));
    n=nr_elemente;
}
vector_n_elemente::~vector_n_elemente(){
    for(int i=0;i<n;i++)
        delete vector[i];
    delete vector;
};
vector_n_elemente::vector_n_elemente(const vector_n_elemente&A){
    this->n=A.n;
    for(int i=0;i<n;i++)
        this->vector[i]=A.vector[i];

}
void vector_n_elemente::initializare(){
    Data data_ang(1,"februarie", 2000);
    Data data2(11, "aprilie", 2022);
    for (int i=0;i<n;i++){
        if(i%2) {
            vector[i] = new Permanent(i, "ion", "ion", (i * i+1) * 100, data_ang);
            Permanent *pPermanent = dynamic_cast<Permanent*>(vector[i]);
            std::cout<<*pPermanent<<'\n';
            data_ang.set_zi(data_ang.get_zi() <= 25 ? data_ang.get_zi() + 1 : 1);
            data_ang.set_an(data_ang.get_an() <= 2021 ? data_ang.get_an() + 1 : 1990);

        }
        else{
            vector[i]= new Part_Time(8%(i+1)+1, data2,"ion", "ion", (i * i+1) * 100,data_ang);
            Part_Time *pPartTime = dynamic_cast<Part_Time*>(vector[i]);
            std::cout<<*pPartTime<<'\n';
            data_ang.set_zi(data_ang.get_zi() <= 25 ? data_ang.get_zi() + 1 : 1);
            data_ang.set_an(data_ang.get_an() <= 2021 ? data_ang.get_an() + 1 : 1990);
        }

    }
}
void vector_n_elemente::afisare(){
    for(int i=0;i<n;i++)
        std::cout <<"Prima de primit "<<i+1<<": "<< vector[i]->prima_de_primit() << '\n';
}
void vector_n_elemente::afisare_element(int i){
    try{
        if(i>=n) throw MyOutOfBoundsException();;
        std::cout << *vector[i];
    }
    catch (const MyOutOfBoundsException &e) {
        std::cout << e.what() << '\n';
    }
}
