

#include <stdio.h>

int main(void)
{
	int number;
	int hundreds, tens, units;
	
	scanf("%d", &number);
	
	hundreds = number / 100;
	tens = (number / 10) % 10; 
	units = number % 10;
	
	printf("%d", hundreds + tens + units);    
	      
           
	return 0;
}

