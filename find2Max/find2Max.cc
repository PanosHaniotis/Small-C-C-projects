#include <iostream>
#include<stdlib.h>
#include<time.h>


typedef struct{
	int x,y;
}int2;

int2 find2Max(int* ar){
	int max,max2;
	if (ar[0] > ar[1]){
		max = ar[0];
		max2 =ar[1];
		
	} else{
		max = ar[1];
		max2 =ar[0];
	}
	
	for (int i = 0;i<20;i++){
		if(ar[i] > max ){
			max = ar[i];
		}
		if(ar[(i+1)%20] > max2 && ar[(i+1)%20] < max) {
			max2 = ar[i+1];
		}
	}
	return {max,max2};
	
}


int main(){
	srand(time(NULL));
	
	int ar[20];
	for (int i = 0;i<20;i++){
		ar[i] = rand()%50;
		std::cout<<ar[i]<<'\n';
	}
	
	std::cout<<"\n Max "<<find2Max(ar).x <<"  Second Max "<<find2Max(ar).y;
}


