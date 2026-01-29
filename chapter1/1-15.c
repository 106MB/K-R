//write function to convert fahrenheit input to celisus
#include <stdio.h>

void convert(float fahr);
int main(){

	float fahr;
	printf("Enter Fahrenheit Temperature: ");
	scanf("%f", &fahr);
	convert(fahr);

}


void convert(float fahr){
	printf("Celsius: %.1f\n", (5.0/9.0)*(fahr-32));
}
