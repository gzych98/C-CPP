#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int suma(int *tab,int n);
float arytmetyczna(int *tab,int n);
float geometryczna(int *tab,int n);
void quicksort(int *tablica,int lewy,int prawy);

int main()
{

	int (*f)(int*,int);
	f = &suma;
	
	float (*g)(int*,int);
	g = &arytmetyczna;
	
	float (*h)(int*,int);
	h = &geometryczna;
	
	fstream dane;
	dane.open("dane.txt",ios::in);
	if (dane.good()==false)
	{
		cout<<"Blad otwarcia pliku"<<endl;
		system("pause");
	}
	string z_pliku;
	int liczby[100];
	int licznik = 0;
	while(getline(dane,z_pliku,' '))
	{	
		liczby[licznik] = atoi(z_pliku.c_str());
		cout<<liczby[licznik]<<' ';
		licznik++;
	}
	cout<<endl;
	cout<<"Suma = "<<f(liczby,licznik)<<endl;
	cout<<"Arytmetyczna = "<<g(liczby,licznik)<<endl;
	cout<<"Geometryczna = "<<h(liczby,licznik)<<endl;
	quicksort(liczby,0,licznik);
	for(int i = 1 ; i <= licznik ; i++)
	{
		cout<<liczby[i]<<' ';
	}
	float n = licznik/2.0;
	if(n==(licznik/2))
	{
		int m = n;
		float srednia = (liczby[m]+liczby[m+1])/2.0;
		cout<<endl<<"Mediana = "<<srednia<<endl;
	}
	else 
	{
		int m = n;
		cout<<endl<<"Mediana = "<<liczby[m+1]<<endl;
	}

}

int suma(int *tab,int n)
{
	int k = 0;
	for(int i = 0; i < n; i++)
	{
		k += tab[i];
	}
	return k;
}
float arytmetyczna(int *tab,int n)
{
	float suma = 0;
	int i = 0;
	for (i; i < n; i++)
	{
		suma += tab[i];
	}
	
	return suma/(n);
}

float geometryczna(int *tab,int n)
{
	float pierwiastek, iloraz;
	iloraz = 1;
	for(int i = 0 ; i < n ; i++)
	{
		iloraz*=tab[i];
	}
	
	pierwiastek = pow(iloraz,1./(n));
	return pierwiastek;
}

void quicksort(int *tablica,int lewy,int prawy)
{
	int v = tablica[(lewy+prawy)/2];
	int i,j,x;
	i = lewy;
	j = prawy;
	do
	{
		while(tablica[i]<v)i++;
		while(tablica[j]>v)j--;
		if(i<=j)
		{
			x = tablica[i];
			tablica[i]=tablica[j];
			tablica[j]=x;
			i++;
			j--;
		}
	}while(i<=j);
	if (j>lewy) quicksort(tablica,lewy,j);
	if (i<prawy) quicksort(tablica,i,prawy);
}
