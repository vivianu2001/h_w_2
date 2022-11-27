# include <stdio.h>
#include "my_mat.h"

 int main()
{	
	int i,j; 
	int arr [10][10];
    char c;
    int boolean=true;
  	while(boolean)
  {
		scanf("%c",&c);

		switch (c)
		{
		case 'A': 
			arr=build_Matrix();

			break;

		case 'B':
			scanf("%d %d", &i,&j);
			is_Exist(i,j);
			break;

		case 'C':
			scanf("%d %d", &i,&j);
			shortest_Path(i,j);
			break;

		case 'D':
			boolean=false;
			break;
		}


	}
	

	return 0;
}