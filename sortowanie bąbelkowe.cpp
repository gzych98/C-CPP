#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

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

void sortowanie_babelkowe(int *tab,int n)
{
	for(int i = 1; i<n ; i++)
	{
		for(int j = n-1; j>=1; j--)
		{
			if(tab[j]<tab[j-1])
			{
				int bufor;
				bufor = tab[j-1];
				tab[j-1]=tab[j];
				tab[j]=bufor;
			}
		}
	}
}

int main()
{
	int ile;
	cout<<"ile liczb? ";
	cin>>ile;
	
	//dynamiczna alokacja tablicy
	int *tablica = new int[ile];
	int *tablica2 = new int[ile];
	
	//inicjowanie generatora
	srand(time(0));
	
	//wczytywanie liczb do tablicy
		for(int i = 0; i<ile;i++)
	{
		tablica[i]=rand()%100000+1;
		tablica2[i]=tablica[i];
	//	cout<<tablica[i]<<' ';
	}
	clock_t start,stop;
	double czas,czas2;
	
	cout<<"bubblesort"<<endl;
	start = clock();
	sortowanie_babelkowe(tablica,ile);
	stop = clock();
	czas = (double)(stop-start) / CLOCKS_PER_SEC; 
	cout<<"czas = "<<czas<<endl;
	
	cout<<"quicksort"<<endl;
	start = clock();
	quicksort(tablica2,0,ile-1);
	stop = clock();
	czas2 = (double)(stop-start) / CLOCKS_PER_SEC; 
	cout<<"czas2 = "<<czas2<<endl;
	
	
	delete [] tablica2;
	delete [] tablica;
	
	
}
