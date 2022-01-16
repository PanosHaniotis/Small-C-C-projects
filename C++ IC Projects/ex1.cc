//AM: 57636

#include <iostream>
using namespace std;


unsigned short count_ones(unsigned int a);

int main()
{
	cout << count_ones(5) <<endl;
	cout << count_ones(4) <<endl;
	cout << count_ones(7) <<endl;
	
}


unsigned short count_ones(unsigned int a)
{
	int sum = 0;
	while (a>0) 
	{	
		if(a & 1) 
		{
			sum++;
		}
		a= a>>1;
	}
	return sum;
}
