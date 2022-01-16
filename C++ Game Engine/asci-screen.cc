
#define N 25
#define M 100

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class Screen
{
	int row;
	int collum;
	char screen [200][200]; //max screen size
	
	void Initialise()
	{
		
	
		
		for(int i = 0;i<row;i++)
		{
			for(int j = 0;j<collum;j++)
			{
				screen[i][j] = ' ';
			}
			
		}	
	}
		
public:
	Screen(int row, int collum)
	{
		this->row = row;
		this->collum = collum;
		Initialise();
	}
	
	
	void PrintScreen()
	{
		
	
		
		cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
		for(int i = 0;i<row;i++)
		{
			for(int j = 0;j<collum;j++)
			{
			
				cout<<screen[i][j];
			}
			cout<<"\n";
		}
		cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";	
	}
	void DrawFloor(int x,int thic = 1)//row
	{
		for(int i = x; i < x+thic;i++ )
		{	
			for(int j = 0;j<collum;j++)
			{
				
				if(screen[i][j] != 0) 
					screen[i][j] = '@';
			}
		}
	}
	
	void DrawRectangle(int x, int y, int w=10, int h=5,string fillMode = "")//x y starting point , width, height
	{
		
		
		
		
		for(int i = y; i < y+h; i++)
		{
			for(int j = x; j < x+w; j++)
			{
				if(screen[i][j] != 0) 
					screen[i][j] = '@';
				
			}
		}
		
		if(fillMode != "FILL")
		{
			for(int i = y+1; i < y+h-1; i++)
			{
				for(int j = x+1; j < x+w-1; j++)
				{
					if(screen[i][j] != 0) 
						screen[i][j] = ' ';
					
				}
			}
		}
	}
	
	void RemoveRect(int x, int y){
		int i = 0;
		int j = 0;
		int l,r,w,d;
		cout<<"IMHERE";																			//DEBUG
		while (screen[y][x+j] !=' ' ){
			l=abs(j);
			j--;
			cout<<"A";																			//DEBUG
		}
		j=0;
		while (screen[y][x+j] !=' '){
			r=abs(j);
			j++;
			cout<<"B";																			//DEBUG
		}
		j=0;
		while (screen[y+i][x] !=' '){
			w=abs(i);
			i--;
			cout<<"C";	
																								//DEBUG
		}
		i=0;
		while (screen[y+i][x] !=' '){
			d=abs(i);
			i++;
			cout<<"D";																			//DEBUG
		}
		i=0;
		j=0;
		//remove 
		cout<<w<<endl<<d<<endl<<l<<endl<<r<<endl;												//DEBUG
		for(int i = y-w; i <= y+d; i++)
		{
			for(int j = x-l; j <= x+r; j++)
			{
				cout<<i<<"  "<<j<<endl;;														
				if(screen[i][j] != 0) 														
					screen[i][j] = ' ';															
				
			}
		}
		
	}
	
	void PutText(int x, int y,string text = "Sample Text")
	{
		int len = text.length();
		for(int j = x; j < x+len; j++){	 
			
			if (text[j-x] ==' ')
				screen[y][j] = '_';
			else	
				screen[y][j] = text[j-x];
		}
		
	}
	
	
};





int main()
{
	int i = 0;
	int j = 0;
	char p = 1;
	Screen screen1(N,M);
	
	screen1.PutText(3,2);

	screen1.DrawFloor(22,3);
	
	screen1.PrintScreen();
	
	screen1.RemoveRect(3,2);
	
	screen1.PrintScreen();
		
		
	while(p != 'q')
	{
	
	
		
	
		screen1.DrawRectangle(3+15*j,3+6*i); 
		screen1.PrintScreen();
		
		
		cin>>p;
		switch(p)
		{
			case 'q':break; 
			case 'd':{
				screen1.RemoveRect(3+15*j,3+6*i);
				j++;
				break;
			}
			case 'a':{
				screen1.RemoveRect(3+15*j,3+6*i);
				j--;
				break;
			}
			case 'w':{
				screen1.RemoveRect(3+15*j,3+6*i);
				i--;
				break;
			}
			case 's':{
				screen1.RemoveRect(3+15*j,3+6*i);
				i++;
				break;
			}
			default:break;
		}
		
		
		
		
 	}	
	
	
	
	
	
	
	return 0;
}
