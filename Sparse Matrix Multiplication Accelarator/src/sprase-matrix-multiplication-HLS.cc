#include <iostream>
#include <vector>

typedef std::vector<int> vect;
typedef std::vector<std::vector<int> > matrix;

#define ROW 0
#define COLLUM 1
#define VALUE 2


class sparse{
	
	public:
	int r;
	int c;
	int NNZ;
	matrix data;
	
	private:
		
	
	
	
	public://-------methods---------
	
	
	//keno object gia epistrofh sthn pra3h tou pollaplasiasmou
	sparse(int row, int col){
		NNZ = 0;
		r = row;
		c = col;
	}
	
	
	sparse(const matrix& matrix){
 	
		NNZ = 0;
		
	 	r = matrix.size();
		c = matrix[0].size();
		
		
 		
 		int i,j;
 		
 		for (i = 0; i < r; i++){
	        for (j = 0; j < c; j++){
	            if (matrix[i][j] > 0){

					insertToCSR(i, j, matrix[i][j]);
				}
			}
		}					
	}
	
	
	sparse operator*(const sparse& b){
		
		
		
		matrix C;
		C.assign (4,{1,1,1,1});
		//matrix C[ data[NNZ][ROW] ] [ b.data[NNZ][COLLUM] ];
		
//		for (int i=0; i<NNZ-1; i++) {
//		  for (int j=0; j<b.NNZ-1; j++) {
//		   
//		    for (int m=data[i][ROW]; m < data[i+1][ROW]; m++) {
//		      int k=data[m][ROW];
//		      for (int p=b.data[j][COLLUM]; p < b.data[j+1][COLLUM]; p++) {
//		        if (b.data[p][ROW] == k){
//				
//		          C[m][p]  = C[m][p] +  data[m][VALUE]*b.data[p][VALUE];
//		          
//		      	}
//		      }
//		    }
//		  }
//		}

		return sparse(C);
	}

	void convertCSRToCSC(){ 
	    int i, j; 
	    for (i = 0; i < NNZ-1; i++)     
	      
	    // Last i elements are already in place 
	    for (j = 0; j < NNZ-i-1; j++) 
	        if (data[j][COLLUM] > data[j+1][COLLUM]) 
	            data[j].swap(data[j+1]);

    }

		

	
	void insertToCSR(int r, int c, int val){
		
		data.push_back({r,c,val});
	 	NNZ++;
	}
	void printData(){
	    std::cout << "\nDimension of Sparse Matrix: " << NNZ << " x " << 3;
	    std::cout << "\nSparse Matrix: \nRow  Column  Value\n";
	 
	    
		for (int i = 0; i < NNZ; i++) {
 
        	std::cout << data[i][ROW] << " 	" << data[i][COLLUM] << "	" << data[i][VALUE] << "\n";
    	}
	}
	
};





int main(){
	
	matrix a =
	    {
	        {1, 0, 0, 0},
	        {0, 5, 0, 1},
	        {7, 0, 0, 0}
	    };
	
	
	sparse obj_a(a);
	obj_a.printData();
			
	sparse obj_b(4,3);
	obj_b.insertToCSR(1,1,100);
	obj_b.printData();
	
	obj_a.convertCSRToCSC();
	obj_a.printData();
	
	sparse obj_c = obj_a*obj_b;
	
	obj_c.printData();
	

	
	
	
	
	

	
}


