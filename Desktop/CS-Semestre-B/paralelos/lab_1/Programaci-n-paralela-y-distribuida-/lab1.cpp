#include <iostream>

using namespace std;

int main(){
unsigned t0, t1, tb, t2;

int MAX=0;


printf("\n\n");

    	// Ingresando dado de la Matriz A
	printf( " \n Dimesiones de MAX :  "); 
   	scanf("%d",&MAX);
    	
	int A[MAX][MAX];
	int x[MAX];
	int y[MAX];

	srand(clock()); 

    for (int i = 0; i < MAX ; i++){
		for (int j = 0; j < MAX; j++){
		
			A[i][j]= rand() %10; }   // Funcion que asigna numeros aleatorios a cada elemento de la matriz 
	}

    for (int i=0; i<MAX ; i++){
	x[i]= rand() %10;
}

     for (int i=0; i<MAX ; i++){
	y[i]= (rand() %10)*0;
	
}

/*Initialize A and x, assign y = 0*/

/*First pair of loops*/

t0=clock();
for(int i= 0;i<MAX;i++){
	for(int j= 0;j<MAX;j++)
		{y[i] +=A[i][j]*x[j]; 
t1= clock(); }}


double time = (double(t1-t0)/CLOCKS_PER_SEC);
cout << "Execution Time first bucle: " << time << endl;
/*Assign y = 0*/
/*Second pair of loops*/

tb = clock();
for(int j= 0;j<MAX;j++){
	for(int i= 0;i<MAX;i++){
		y[i] +=A[i][j]*x[j];
t2 = clock(); }}

double time2 = (double(t2-tb)/CLOCKS_PER_SEC);
cout << "Execution Time second bucle: " << time2 << endl;

return 0;
}


