#include <stdio.h>
#include <windows.h>

typedef struct okrag
{
	int x0;
	int y0;
	int r;
}okrag;

typedef struct punkt
{
	int x;
    int y;    
}punkt;

int main()
{
	punkt A[1001];
	int i = 0;
	for (i; i <= 1000; i++)
	{
		A[i].x = i;
		A[i].y = i;	
    
	}	
	
	okrag pierwszy;
	punkt dowolny;
	printf("Podaj wspolrzedne srodka okregu [ oddzielone spacja ]: ");
	scanf("%d%d",&pierwszy.x0,&pierwszy.y0);	
	printf("Srodek okregu = ( %d , %d )\n",pierwszy.x0,pierwszy.y0);
	

	printf("Podaj promien : ");
	scanf("%d",&pierwszy.r);
	printf("r = %d",pierwszy.r);

	printf("\nPodaj dowolny punkt : ");
	scanf("%d%d",&dowolny.x,&dowolny.y);
	printf("A = ( %d , %d )\n",dowolny.x,dowolny.y);
	
	float wyrazenie;
	wyrazenie = (dowolny.x - pierwszy.x0)*(dowolny.x - pierwszy.x0)+(dowolny.y - pierwszy.y0)*(dowolny.y - pierwszy.y0);
	
	printf("Sprawdzam gdzie lezy punkt");
	int k=1;
	
	for(k;k<=3;k++)
	{		
		printf("\n.");
		Sleep(700);
	}
	printf("\n");
	
	int r2;
	r2 = (pierwszy.r)*(pierwszy.r);
	if(wyrazenie == r2)
		printf("Punkt lezy na okregu");
		else if(wyrazenie < r2)
				printf("Punkt lezy wewnatrz okregu");
				else if(wyrazenie > r2)
					printf("Punkt lezy na zewnatrz okregu");
					else printf("ERROR !!!");
	
}
