#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
float a[100],b[100];
int main()
{
    float raza,h,l,abaza,alat,frisca,gem,lmic,lmare,cmica,cmare,totalgem=0.0,totalfrisca=0.0;
    char s[10],baza[10];
    int i=0,x;
    while(1)
    {
        i++;
        cin>>s;
        if (strcmp(s,"ADD")==0)
        {
            cin>>baza;
            if(strcmp(baza,"cerc")==0)
            {
                cin>>raza>>h;
                abaza=3.14*raza*raza;
                alat=2*3.14*raza*h;
                frisca=abaza*2+alat;
                gem=2*abaza*h;

            }
            if(strcmp(baza,"dreptunghi")==0)
            {
                cin>>lmic>>lmare>>h;
                abaza=lmic*lmare;
                frisca=2*(abaza+h*lmic+h*lmare);
                gem=2*abaza*h;
            }
            if(strcmp(baza,"patrat")==0)
            {
                cin>>l>>h;
                abaza=l*l;
                frisca=2*abaza+4*l*h;
                gem=2*h*abaza;
            }
            if(strcmp(baza,"triunghi")==0)
            {
                cin>>cmica>>cmare>>h;
                abaza=cmica*cmare/2;
                frisca=2*abaza+h*cmica+h*cmare+h*sqrt(cmica*cmica+cmare*cmare);
                gem=abaza*h*2;
            }
            cout<<"gem: "<<gem<<" frisca: "<<frisca<<'\n';
            a[i]=gem;
            b[i]=frisca;
            totalgem+=gem;
            totalfrisca+=frisca;

        }
        if (strcmp(s,"REMOVE")==0)
        {
            cin>>x;
            totalgem-=a[x];
            totalfrisca-=b[x];
            a[x]=0;
            b[x]=0;
        }
        if (strcmp(s,"TOTAL")==0)
        {
            cout<<"gem total: "<<totalgem<<" frisca totala: "<<totalfrisca<<'\n';
        }
        if (strcmp(s,"STOP")==0)
            break;
    }

}

