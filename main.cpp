#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct laimikis{string pav;int kiekis;double gylis;double laik;};
int unknowns=0;
int skaityti(laimikis a[]){
    string tempkiek,tempg,pavadinimai,templ;
    int n=0;
    fstream z("laimikiai.csv");
    getline (z,pavadinimai);
    while(z>>ws&&getline(z,a[n].pav,',')){
    getline(z,tempkiek,',');
    if (tempkiek==""){a[n].kiekis=0;}
    else{a[n].kiekis=stoi(tempkiek);}
    getline(z,tempg,',');
    if (tempg==""){a[n].gylis=-1;unknowns++;}
    else {a[n].gylis=stod(tempg);}
    getline(z,templ);
    a[n].laik=stod(templ);
    n++;
    }
    return n;
}
void suvestines (laimikis a[]){
    fstream b("rezultatai.txt");
    int n=0;
    string didzpav="";
    double did=0;
    double visakiek=0;double tempdid=0;
    while (a[n].pav!=""){
        if (a[n].kiekis>tempdid){tempdid=a[n].kiekis;didzpav=a[n].pav;}
        visakiek+=a[n].kiekis;
        n++;
    }
    did=tempdid;
    b<<"bendra mase: "<<visakiek<<endl;
    b<<"didziausias laimikis- "<<didzpav<<" mase: "<<did;
 
}
int main()
{
    laimikis a[100];
    skaityti(a);
    suvestines(a);
    cout<<"is viso "<<skaityti(a)<<endl;
    cout<<"trecio gylis "<<a[2].gylis;
    cout<<"Nezinomas gylis: "<<unknowns;
    return 0;
}



