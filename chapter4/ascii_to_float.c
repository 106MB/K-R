#include "stdio.h"
#include "ctype.h"
#include "string.h"
#define LIMIT 100

double atof_local(char s[]);

int main(){
	
	char ascii[LIMIT + 1];
	printf("*Enter floating point numbers*\n");

	while(fgets(ascii, LIMIT, stdin) != NULL)
	{
		// Remove Newline
		ascii[strlen(ascii) - 1] = ascii[strlen(ascii)];
		
		// Convert string to double
		double output_val = atof_local(ascii);
		printf("%lf\n", output_val);
		
	}	
}

double atof_local(char s[])
{
double val, power;
int i, sign;

	// Skip whitespace
	for (i = 0; isspace(s[i]); i++)
	{
		// Do nothing	
	}
	// Set sign, skip sign character 
   sign = (s[i] == '-') ? -1 : 1;
   if (s[i] == '+' || s[i] == '-')
   {
  		i++; 
   }
   // Get each digit until '.', skip dot character
   for (val = 0.0; isdigit(s[i]); i++)
   {
  		val = val * 10.0 + (s[i] - '0'); 
   }  
   if (s[i] == '.') 
   {
       i++;  
   }

   // Contiuing getting digits passed dot, start tracking power
   for (power = 1.0; isdigit(s[i]); i++)
   {
	   val = val * 10.0 + (s[i] - '0'); 
	   power *= 10.0;
	   
   }
  return sign * (val / power); 

 
   

	   
}
