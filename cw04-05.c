#include <stdio.h>
#include <math.h>
#include <string.h>

main()
{
	char dalej[10];	
	do
	{
		int a, b, c;
		float delta, x1, x2;
		
		printf("Podaj a, b i c [ po spacji ] : ");
		scanf_s("%d%d%d", &a, &b, &c);
		delta = b * b - 4 * a*c;
		x1 = (0 - b - sqrt(delta)) / (2 * a);
		x2 = (0 - b + sqrt(delta)) / (2 * a);
		printf("%dx*x+%dx+%d=0\n", a, b, c);		//wypisanie wzoru funkcji
		if (a != 0)
		{
			printf("delta = %.2f\n", delta);		//wypisani delty
			if (delta < 0)
			{
				printf("Brak rozwiazan rzeczywistych");
			}
			else
			{
				if (delta == 0)
				{
					printf("x0 = %.2f", x1);
				}
				else
				{
					printf("x1 = %.2f\tx2 = %.2f\n", x1, x2);
				}
			}
		}
		else
		{
			printf("To nie jest rownanie kwadratowe");
		}
		printf("\nLiczyc dalej ? (pisz: tak) : "); 
		scanf("%s", &dalej);


	} while (!strcmp(dalej,"tak"));
			
}
