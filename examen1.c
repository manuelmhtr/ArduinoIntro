// Por: Manuel Honorio de la Torre Ramírez
// 20 - May - 2014
#include <stdio.h>

float sum(float *);
float mult(float *);
float subst(float, float, float);

float vector[] = {0.0, 0.0, 0.0};

int main(void)
{
	float *ptr = &vector[0];
	
	int i;
	for(i = 1; i <= 3; i++){
		printf("Introduzca el valor %d: ", i);
		scanf("%f", &vector[i-1]);
	}
	printf("\nResultados\n", i);
	printf("Suma: %f\n", sum(ptr));
	printf("Resta: %f\n", subst(vector[0], vector[1], vector[2]));
	printf("Multiplicación: %f\n\n", mult(ptr));
}

float sum(float *ptr){
	double result = 0.0;
	char i;
	for(i = 0; i < 3; i++) result += *(ptr + i);
	return result;	
}

float mult(float *ptr){
	double result = 1.0;
	char i;
	for(i = 0; i < 3; i++) result *= *(ptr + i);
	return result;	
}

float subst(float a, float b, float c){
	return a - b - c;	
}
