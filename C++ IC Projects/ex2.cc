//AM: 57636

#include <iostream>
using namespace std;


unsigned int checksum(unsigned int number);

int main()
{

	cout << checksum(1631)<<endl;
	cout << checksum(524)<<endl;
	cout << checksum(52416)<<endl;
}


unsigned int checksum(unsigned int number)
{
	int sum = 0;
	int digit = 0;
	bool flag = 0;
	int temp = 0;
	
	while (number >0)
	{
		digit = number %10;
		number /= 10;
		if(flag) 
		{
			digit*=2;
			if(digit >=10) 
			{
				temp = (digit%10) + (digit/10);
				digit = temp;
			}
		}
		sum += digit;
		flag= !flag;
	}
	return sum;

}
