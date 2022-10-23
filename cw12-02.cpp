#include <iostream>
using namespace std;
 
class Dana {
  protected:
    int bok, kat;
  public:
    Dana(){
       cout<<"Podaj dlugosci " << endl;
    };
 
    void is_valid(int a, int b)
	{
      if(a<0 || b<0 || b>360)
	  {
        cout <<"Nieprawidlowe dane wejsciowe !!!"<<endl;
        bok = 0;
        kat = 0;
      }
    }
 
    void ustaw(int a, int b)
	{
        bok=a;
        kat=b;
        is_valid(a,b);
     }
 
     virtual int get()
	 {
      return 0;
     }
 
};
 
class Dlugosc: public Dana {
  public:
    int get(){ return bok; }
};
 
class Kat: public Dana {
  public:
    int get(){ return kat; }
};
 
int main () {
  int a,b;
  Dlugosc pierwsza;
  cin>>a;
  Kat kt;
  cin>>b;
  Dana * dlBoku = &pierwsza;
  Dana * katt = &kt;
  dlBoku->ustaw (a,b);
  katt->ustaw (a,b);
  cout << "Dlugosc boku: "<<pierwsza.get() << '\n';
  cout << "Kat: "<<kt.get() << '\n';
  return 0;
}
