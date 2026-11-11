#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct laimikis{string pav;int kiekis;double gylis;double laik;};
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
  if (tempg==""){a[n].gylis=-1;}
  else {a[n].gylis=stod(tempg);}
  getline(z,templ);
  a[n].laik=stod(templ);
  n++;
   }
  return n;
}
void isvesti(laimikis a[],double &visamas){
  int n=0;
  while (a[n].pav!=""){
      cout<<left<<setw(20)<<fixed<<setprecision(2)<<a[n].pav<<" "<<a[n].kiekis<<" "<<a[n].gylis<<endl;
      visamas+=a[n].kiekis;
      n++;
   }
}
int main()
{
  laimikis a[100];
  skaityti(a);
  cout<<"is viso "<<skaityti(a)<<endl;
  cout<<"trecio gylis "<<a[2].gylis;
  return 0;
}

