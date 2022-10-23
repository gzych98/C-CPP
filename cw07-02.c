#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
		char * x = argv[1];
		float a = atof( x );   
		char * y = argv[3];
		float b = atof( y );  
		char *znak = argv[2];
        

			
				printf("-------------------------------\n");
				printf("\tKALKULATOREK\n");
				printf("-------------------------------\n");
			
		float suma, roznica, iloczyn, iloraz;
		 
			switch(*znak)
			{
				case '+':
					suma=a+b;
		   			printf("Wynik dzialania: %0.2f",suma);
		  			break;
		  		case '-':
					roznica=a-b;
		      		printf("Wynik dzialania: %0.2f",roznica);
		  			break;
		  		case '*':
					iloczyn=a*b;
		     		printf("Wynik dzialania: %0.2f",iloczyn);
		  			break;
		  		case '/':
		  			if(b == 0)
		  			{
		  				printf("Nie mozna dzielic przez 0 !!!");
					}  			
		  			else
		  			{
		  			 	iloraz=a/b;
		     			printf("Wynik dzialania: %0.2f",iloraz);
					}
						
		  			break;
		  		default: printf ("bledny zapis !!!");   
			}
			
		
}
		
		

