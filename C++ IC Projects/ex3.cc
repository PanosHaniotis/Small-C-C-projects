//AM: 57636

#include <iostream>
using namespace std;


template<int N, int M>
void compute_row_sum (short a[N][M], short row_sum[N])
{
	int sum = 0;
	for (int i = 0; i<N; i++)
	{
		sum = 0;
		for (int j = 0; j<M; j++)
		{
			sum += a[i][j];
		}
		row_sum[i] = sum;
		cout << row_sum[i]<<endl;
	}
	cout<<endl;
}




int main()
{
	short y [3] = {0,0,0};
	
	short x [3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	
	compute_row_sum<3,3>(x,y);
	
	short z [2][3] = {{7,4,3},{4,3,1}};
	
	compute_row_sum<2,3>(z,y);
	
	short w [6][3] = {{1,2,3},{4,5,6},{7,8,9},{1,2,3},{4,5,6},{7,8,9}};
	
	compute_row_sum<6,3>(w,y);
	
	short u [4][3] = {{1,2,3},{4,5,6},{7,8,9},{1,4,2}};
	
	compute_row_sum<4,3>(u,y);
	
	return 0;	
}
