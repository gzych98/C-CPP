#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <sstream>
#include <cstring>

using namespace std;



int main()
{
	fstream dane;
	dane.open("dane.txt",ios::in);
	if (dane.good()==false)
	{
		cout<<"Blad otwarcia pliku"<<endl;
		system("pause");
	}
	string z_pliku;
	float liczby[100];
	stringstream ss[100];
	int licznik = 0;
	while(getline(dane,z_pliku,' '))		//na koñcu ka¿dej liniii macierzy powinna pojwiæ siê spacja ¿eby program dobrze wczyta³ dane
	{	
		liczby[licznik] = atof(z_pliku.c_str());
		cout<<liczby[licznik]<<' ';
		licznik++;
	}
	cout<<endl<<"--------------------------------------"<<endl;
	char odp[10];
	char str1[10] = "tak";
	int k = sqrt(licznik);
	cout<<"Wczytales macierz o rozmiarze "<<k<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"Chcesz ja zmiejszyc ? ";
	cin>>odp;
	cout<<"--------------------------------------"<<endl;
	if (stricmp( str1, odp ) == 0 )
	{
		cout<<"Podaj nowy rozmiar : ";
		cin>>k; 
		cout<<"--------------------------------------"<<endl;
		if(k>(sqrt(licznik)))
		{
			cout<<"Za duzy rozmiar !!"<<endl;
			cout<<"--------------------------------------"<<endl;
			system("pause");
			exit(0);
		}
		else if(k==1)
			{
				cout<<"Macierz z jednej liczby? Co ja mam tu liczyc ? "<<endl;
				cout<<"----------------------------------------------"<<endl;
				system("pause");
				exit(0);
			}
			else if(k<1)
			{
				cout<<"Nie mozesz podac liczby mniejszej od 1"<<endl;
				cout<<"--------------------------------------"<<endl;
				system("pause");
				exit(0);
			}
	}
	float **macierz = new float*[k];
	int x = 0;
	for(int i = 0; i < k; i++)
	{
		macierz[i] = new float [k];
		for(int j = 0; j < k; j++)
		{
			macierz[i][j] = liczby[x];
			cout<<macierz[i][j]<<' ';
			x++;
		}
		cout<<endl;
	}
	cout<<"--------------------------------------"<<endl;
	float suma = 0;
	for(int i = 0; i < k; i++)
	{
		suma += macierz[i][i];
	}
	cout<<"Suma elementow na diagonali = "<<suma<<endl;
	cout<<"--------------------------------------"<<endl;
	float iloczyn = 0;
	cout<<"Podaj liczbe skalarna : ";
	float skalarna;
	cin>>skalarna;
	cout<<"--------------------------------------"<<endl;
	cout<<"Iloczyn macierzy przez liczbe skalarna"<<endl;
	cout<<"--------------------------------------"<<endl;
	for(int i = 0; i < k ; i++)
	{
		for(int j = 0; j < k; j++)
		{
			macierz[i][j] *= skalarna ;
			cout<<macierz[i][j]<<' ';
			x++;
		}
		cout<<endl;
	}
	int y = 0;
	for(int i = 0; i < k; i++)
	{
		macierz[i] = new float [k];
		for(int j = 0; j < k; j++)
		{
			macierz[i][j] = liczby[y];
			y++;
		}
	}
	cout<<"--------------------------------------"<<endl;
	cout<<"Iloczyn macierzy przez sama siebie"<<endl;
	cout<<"--------------------------------------"<<endl;
	int pomnozona[k][k];
	for(int i = 0; i < k ; i++)
	{ 
		for(int j = 0; j < k; j++)
		{
			int suma = 0;
			for(int m = 0; m < k ; m++)
			{
				suma += ((macierz[i][m])*(macierz[m][j]));
			}
			cout<<suma<<' ';			
		}
		cout<<endl;
	}
	cout<<"--------------------------------------"<<endl;
	
	

delete [] macierz;
	
	
	
	
system("pause");	
}
