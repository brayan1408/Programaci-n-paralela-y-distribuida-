#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;


typedef vector<vector<int>> matrix;
typedef vector<int> _list;

//Pagina 22 Libro 
/* First pair of loops */
	
void PrintM (matrix m){
  for(int i = 0; i < m.size(); i ++){
    for(int j = 0; j < m[0].size(); j++){
      cout<<m[i][j]<<"  ";
    }
    cout<<endl;
  }
  cout<<endl;
}
matrix inicializarM(int MAX){
  matrix A = matrix(MAX, _list(MAX,0));
  int num ;
  for(int i = 0; i < MAX; i++){
    for(int j = 0; j < MAX; j++){
    	num=1+rand()%(101-1);
      	A[i][j] = num;
    }
  }
  return A;
}

void Mul_Clasica (matrix A ,  matrix B ){
	int i, j , k; 
	matrix C(A.size(),_list (B[0].size(),0));  //almacenamiento de nuestra respuesta
	for (i = 0; i < A.size(); i++)
	{for (j = 0; j < B[0].size(); j++)
		{for (k = 0; k < A[0].size(); k++)	{
				C[i][j] += A[i][k]*B[k][j];
			}	}	}

	
}	



int main()
{
	//clock_t Time_First, Time_Second;
	unsigned t0, t1 ;

	int tam = 675; 

	matrix A = inicializarM(tam);
	//PrintM(A);
	matrix B = inicializarM(tam);
	//PrintM(B);
	t0=clock();
	//--Time_Second = clock();
	Mul_Clasica(A,B);
	//--Time_Second = clock() - Time_Second;
	t1= clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Execution Time first bucle: " << time << endl;


	//--cout<<"Multiplicacion Clasica : "<<float(Time_Second)/CLOCKS_PER_SEC<<endl;

	return 0;
}
