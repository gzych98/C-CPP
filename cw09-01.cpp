#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

void pisz_wzor(int a, int b, int c)
{	
	cout<<endl<<a<<"*x^2 + "<<b<<"*x + "<<c<<" = 0"<<endl;
}

float delta(int a, int b, int c)
{
	return (b*b)-(4*a*c);
}

float pierwiastki(int a , int b, float d)
{
	float x1,x2;
		x1 = ((0-b)+sqrt(d))/2*a;
		x2 = ((0-b)-sqrt(d))/2*a;
		cout<<"x1 = "<<x1<<" x2 = "<<x2<<endl;
}

int main()
{
	int liczby[100];	
	fstream plik;
	plik.open("dane.txt",ios::in);	
	if(plik.good()==false)
	{
		cout<<"Plik nie istnieje !!!";
		exit(0);
	}	
	int licznik = 0;
	string linia;
	while(getline(plik,linia))
	{	
		liczby[licznik] = atoi(linia.c_str());	
		licznik++;		
	}
	
	plik.close();	
	
	cout<<"\tRownania kwadratowe"<<endl; 	

	int k = (sizeof liczby)/(sizeof *liczby);
	
		float d;
		int x,y,z,a,b,c;
		int n = 0;	
		
	licznik = licznik/3;

	for (n; n < licznik; n++)	
	{				
	
		x = 3 * n;
		y = 3 * n + 1;
		z = 3 * n + 2;
		a = liczby[x];
		b = liczby[y];
		c = liczby[z];
		
			pisz_wzor(a,b,c);
			d = delta(a,b,c);
				cout<<"delta = "<<d<<endl;
			if(d<0)
			{
				cout<<"Brak rozwiazan rzeczywistych"<<endl; 
			}
				else if (d == 0)
				{
					float x;
					x = (0-b)/2*a;
					cout<<x;
				}
				else if( d > 0 )
				{
					pierwiastki(a,b,d);
				}
				else cout<<"Program napotkal problem !!!";
	}				
}
