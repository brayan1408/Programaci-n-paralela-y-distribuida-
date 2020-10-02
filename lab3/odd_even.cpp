#include<mpi.h>
#include<iostream>
#include<vector>

typedef int elmt;
typedef std::vector<elmt> v_emlt;

void odd_even_sort(){

}

void bubble_sort(v_emlt &v){
	size_t size = v.size();
	for(size_t i = 0; i < n; ++i)
		for(size_t j = 1; j < n-i; ++j)
			if(v[i] < v[i-1])
				std::swap(v[i],v[i-1]);
}

main(int argc, char** argv){
	MPI_Init(NULL,NULL);

	int size,rank;

	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);


}
