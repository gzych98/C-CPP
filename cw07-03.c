#include <stdio.h>
#include <math.h>

typedef struct punkt
{
	int x;
    int y;    
}punkt ;

int main()
{
	punkt A[1001];
	int i = 0;
	for (i; i <= 1000; i++)
	{
		A[i].x = i;
		A[i].y = i;	
    
	}	
	int x1,y1,x2,y2;
	printf("Podaj wspolrzedne pierwszego punktu [ oddzielone spacja ] : ");
	scanf("%d%d",&x1,&y1);
	printf("\nA =( %d , %d )\n",A[x1].x,A[y1].y);
	
	printf("\nPodaj wspolrzedne drugiego punktu [ oddzielone spacja ] : ");
	scanf("%d%d",&x2,&y2);
	printf("\nB = ( %d , %d )\n",A[x2].x,A[y2].y);
	
	float odleglosc;
	
	odleglosc = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	
	printf("\n\n|AB| = %f\n",odleglosc);
	
	
 
}
