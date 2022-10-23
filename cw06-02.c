#include <stdio.h>
#include <math.h>

int  tabl[12]={};
int n = 12;

int suma(int n)
{	
	float suma = 0;
	int i = 0;
	for (i; i <= n; i++)
	{
		suma += tabl[i];
	}
	return suma;
}

float arytmetyczna(int n)
{
	float suma = 0;
	int i = 0;
	for (i; i < n; i++)
	{
		suma += tabl[i];
	}
	
	return suma/(n);
}

float geometryczna(int n)
{
	float pierwiastek, iloraz;
	int i = 0;
	iloraz = 1;
	for(i;i<n;i++)
	{
		iloraz*=tabl[i];
	}
	
	pierwiastek = pow(iloraz,1./(n));
	return pierwiastek;
}


int main()
{									
	FILE *plik;
	plik = fopen ("dane.txt","r");		//otwieram plik i dodaje wartosci do tablicy
	printf("Wypisuje wartosci z pliku :\n");
	int i = 0;
	for (i; i < 12; i++)
	{
		fscanf_s(plik, "%d", &tabl[i]);
		printf("%d \t", tabl[i]);

	}
	
	float m,k,p;
	m = suma(n);
	printf("\n\nSuma %26.3f\n", m);
	k = arytmetyczna(n);
	printf("\nSrednia arytmetyczna %10.3f\n", k);
	p = geometryczna(n);
	printf("\nSrednia geometryczna %10.3f\n", p);
}
