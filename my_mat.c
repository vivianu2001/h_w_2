#include <stdio.h>
#include "my_mat.h"
#define n 10
#define INF -1

int arr[n][n];
int floyd[n][n];
int predecessor[n][n];



void path(int i,int j)
{
	if ((i==j)&&predecessor[i][j]==i)
	{
		printf("%d", i);
	}

}

void build_Matrix()
{  
	int num;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j< n; ++j)
		{
			scanf("%d",&num);
			arr[i][j]= num;
		}
	}
	
}


int is_Exist(int i,int j)
{
	floyd_Warshall();
	return (floyd[i][j]!=INF);


}

int shortest_Path(int i,int j)
{
	if(is_Exist(i,j))
	{

		return floyd[i][j];
	}
	else
	{
		return -1;
	}

}

void floyd_Warshall()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j< n; ++j)
		{
			floyd[i][j]=INF;
			predecessor[i][j]=INF;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j< n; ++j)
		{
			if(arr[i][j]!=0)
			{
				floyd[i][j]=arr[i][j];
				predecessor[i][j]=j;
			}
		}

	}

	  for (int i = 0; i < n; ++i)
	 {
	 	floyd[i][i]=0;
	 	predecessor[i][i]=i;
	 }

	for (int k  = 0; k < n; ++k)
	{

		 for (int i = 0; i < n; ++i)
		 {
		 	for (int j = 0; i < j; ++j)
		 	{
		 		if(floyd[i][k]==INF|| floyd[k][j]==INF)
		 		{
		 			continue;
		 		}
		 		if(floyd[i][j]==INF||floyd[i][j]>floyd[i][k]+floyd[k][j])
		 		{
		 			floyd[i][j]= floyd[i][k]+floyd[k][j];
		 			predecessor[i][j]=predecessor[i][k];
		 		}
		 	}
		 }
     }

}
