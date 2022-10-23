#include <stdio.h>
#include <stdlib.h>

void najmniejsza(int table[], int size)
{
	int i = 0, j, temp;
	for (i; i<size-1; i++)
        {
		for (j=0; j<size-1-i; j++)
		{
			if (table[j] > table[j+1])
			{
				temp = table[j+1];
				table[j+1] = table[j];
				table[j] = temp;
			}
		}
        }
}
void najwieksza(int table[], int size)
{
	int i = 0, j, temp;
	for (i; i<size-1; i++)
        {
		for (j=0; j<size-1-i; j++)
		{
			if (table[j] < table[j+1])
			{
				temp = table[j+1];
				table[j+1] = table[j];
				table[j] = temp;
			}
		}
        }
}

void wypisz(int tab[])
{
	int i = 0;
		for (i; i < 9; i++)
	{
	
		printf("%d \t", tab[i]);

	}
	printf("\n");
	
}


int main()
{
	int  tabl[9]={};									
	FILE *plik;
	plik = fopen ("dane.txt","r");		//otwieram plik i dodaje wartosci do tablicy
	printf("Wypisuje wartosci z pliku :\n");
	int i = 0;
	for (i; i < 9; i++)
	{
		fscanf_s(plik, "%d", &tabl[i]);

	}
	wypisz(tabl);	
	printf("Sortuje i wypisuje od najwiekszej do najmniejszej :\n");
	najwieksza(tabl, 9);
	wypisz(tabl);
	printf("Sortuje i wypisuje od najmniejszej do najwiekszej :\n");
	najmniejsza(tabl, 9);
	wypisz(tabl);	

}
