#include <stdio.h>
#include <string.h>

float prostokat(float a, float b)
{
	return a*b;
}

float kolo(float r)
{
	float pi, pole;
	pi = 3.141592;
	pole = pi * r * r;

	return pole;
}

float trojkat(float a,float h)
{
	return (a*h)/2;
}


main()
{
	char dalej[10];
	char figura[20];
	
	do
	{
		
		printf("-----------------------------------------\n");
		printf("\tPola figur geometrycznych \n");
		printf("-----------------------------------------\n");
		printf("   [ prostokat ] [ kolo ] [ trojkat ]\n\n");
		printf("Wybierz jedna: ");
		scanf("%s", &figura);
		
		if(!strcmp(figura,"prostokat"))
		{
			float a,b;
			printf("Podaj dlugosci bokow a i b [po spacji] : ");
			scanf("%f%f",&a,&b);
			float k;
			k = prostokat(a,b);
			printf("\na = %0.2f\nb = %0.2f\n\nPole = %.2f\n",a,b,k);
		}
		
		else
		{
			if(!strcmp(figura,"kolo"))
			{
				float r,k;
				printf("Podaj promien : ");
				scanf("%f",&r);
				k = kolo(r);
				printf("\npromien = %.2f\n\nPole = %.2f\n",r,k);
			}
			else
			{
				if(!strcmp(figura,"trojkat"))
				{
					float a,h;
					printf("Podaj dlugosc podstawy i wysokosc [po spacji] : ");
					scanf("%f%f",&a,&h);
					float k;
					k = trojkat(a,h);
					printf("\na = %0.2f\nh = %0.2f\n\nPole = %.2f\n",a,h,k);
				}
				else
				printf("\nNie znam takiej figury\n");
			}
		}		
		
		
	printf("\nChcesz sprobowac ponownie ? : "); 
	scanf("%s", &dalej);
	
	} while (!strcmp(dalej,"tak"));
}
