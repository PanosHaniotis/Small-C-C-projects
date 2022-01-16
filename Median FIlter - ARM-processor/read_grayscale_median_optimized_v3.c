
/*
Changelog: 
- median filter function no longer changes the values of the frame while being applied. It stores the values in a temporary matrix.
- SRAM buffers


*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define N 372 /* frame dimension for QCIF format */
#define M 496 /* frame dimension for QCIF format */
#define filename "C:\\cherry_496x372.yuv"
#define file_yuv "C:\\cherry_output.yuv"

/* code for armulator*/
#pragma arm section zidata="dram"
int current_y[N][M];
int current_u[N][M];
int current_v[N][M];
int temp_current_y[N][M];


#pragma arm section zidata="sram"

int buffer [6][M];




#pragma arm section

int i,j;




void read()
{
  FILE *frame_c;
  if((frame_c=fopen(filename,"rb"))==NULL)
  {
    printf("current frame doesn't exist\n");
    exit(-1);
  }

  for(i=0;i<N;i++)
  {
    for(j=0;j<M;j++)
    {
      current_y[i][j]=fgetc(frame_c);
    }
  }
  for(i=0;i<N;i++)
  {
    for(j=0;j<M;j++)
    {
      current_u[i][j]=fgetc(frame_c);
    }
  }
  for(i=0;i<N;i++)
  {
    for(j=0;j<M;j++)
    {
      current_v[i][j]=fgetc(frame_c);
    }
  }
  fclose(frame_c);
}







void write()
{
  FILE *frame_yuv;
  frame_yuv=fopen(file_yuv,"wb");

  for(i=0;i<N;i++)
  {
    for(j=0;j<M;j++)
    {
      fputc(current_y[i][j],frame_yuv);
    }
  }

  for(i=0;i<N;i++)
  {
    for(j=0;j<M;j++)
    {
      fputc(current_u[i][j],frame_yuv);
    }
  }


  for(i=0;i<N;i++)
  {
    for(j=0;j<M;j++)
    {
      fputc(current_v[i][j],frame_yuv);
    }
  }
  fclose(frame_yuv);
}





void grayscale()
{
	//y contains grayscale information
	int uv = 127;
	
	for(i=0;i<N;i=i+3)
    {
    	for(j=0;j<M;j++)
    	{
    		current_u[i][j] = uv;
    		current_u[i][j+1] = uv;
    		current_u[i][j+2] = uv;
    	}
	}
	for(i=0;i<N;i++)
    {
    	for(j=0;j<M;j++)
    	{
    		current_v[i][j] = uv;
    		current_v[i][j+1] = uv;
    		current_v[i][j+2] = uv;
    	}
	}
}







int find_median(int a,int b,int c)
{
    if ((a <= b) && (b <= c)) return b; 
    if ((a <= c) && (c <= b)) return c; 
    if ((b <= a) && (a <= c)) return a;  
    if ((b <= c) && (c <= a)) return c;  
    if ((c <= a) && (a <= b)) return a;  
    return b;                            
}







int max(int array[])
{
	int max_val = array[0];
	int k;
	for(k = 1;k < 4;k++)
	{
		
		if( array[k] > max_val) {max_val = array[k];}
	}
	return max_val;
}







void move_to_y()
{
	
  for(i=0;i<N;i++)
  {
    for(j=0;j<M;j=j+3)
    {
      current_y[i][j] = temp_current_y[i][j];
      current_y[i][j+1] = temp_current_y[i][j+1];
      current_y[i][j+2] = temp_current_y[i][j+2];
      
    }
  }
}








void median_filter()
{
	int temp [4] ={0,0,0,0};
	int n;
	int z1;
	int z2;
	int z3;
	int z4;
	
	for(j=1;j<M-1;j++)
	{
		buffer[0][j] = current_y[0][j];
		buffer[1][j] = current_y[1][j];
		buffer[2][j] = current_y[2][j];
	}		
	
	for(i=1;i<N-4;i++)//avoiding edge descrepancy
	{
		n = i%6;
		
		//filling the buffer
		if(n==1)
		{
			for(j=1;j<M-1;j++)
			{
				buffer[3][j] = current_y[i+2][j];
				buffer[4][j] = current_y[i+3][j];
				buffer[5][j] = current_y[i+4][j];
			}			
		}
		
		if(n==4)
		{
			for(j=1;j<M-1;j++)
				{
					buffer[0][j] = current_y[i+2][j];
					buffer[1][j] = current_y[i+3][j];
					buffer[2][j] = current_y[i+4][j];
				}			
		}
		
    	for(j=1;j<M-1;j++)
    	{
    		if(n==0)//avoid buffer[-1] situation
    		{
    			z1 = find_median(buffer[n][j],buffer[n+1][j],buffer[5][j]);
				z2 = find_median(buffer[n][j],buffer[n][j+1],buffer[n][j-1]);
				z3 = find_median(buffer[n][j],buffer[5][j+1],buffer[n+1][j-1]);
				z4 = find_median(buffer[n][j],buffer[5][j-1],buffer[n+1][j+1]);
    		}
    		else
    		{
				z1 = find_median(buffer[n][j],buffer[n+1][j],buffer[n-1][j]);
				z2 = find_median(buffer[n][j],buffer[n][j+1],buffer[n][j-1]);
				z3 = find_median(buffer[n][j],buffer[n-1][j+1],buffer[n+1][j-1]);
				z4 = find_median(buffer[n][j],buffer[n-1][j-1],buffer[n+1][j+1]);
			}
			
			temp [0] = z1;
			temp [1] = z2;
			temp [2] = z3;
			temp [3] = z4;
			
			temp_current_y[i][j] = max(temp);
    	}
    	
	}	
  
}




int main()
{
	read();
	
	grayscale();
	
	median_filter();
	
	move_to_y();//move temporary array to the output array
	
	write();
	
	printf("Program Finished\n");
	exit(0);
  
}
  

