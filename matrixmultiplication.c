#include<stdio.h>
int main()
{ 
        int i,j,k,row1,col1,row2,col2,p;
        printf("Enter the number of matrixA rows:");
        scanf("%d",&row1);
        printf("Enter the number of matrixA columns:");
        scanf("%d",&col1);
	printf("Enter the number of matrixB rows:");
        scanf("%d",&row2);
        printf("Enter the number of matrixB columns:");
        scanf("%d",&col2);
        if(col1!=row2)
	{
		printf("Multiplication not possible column if number of elements of first matrix column and second matrix row not equal\n");
		return 0;
	}
	int a[row1][col1],b[row2][col2],c[row1][col2];
	printf("Enter matrix A elements:\n");
	for(i=0;i<row1;i++)
	{
		printf("\n");
		for(j=0;j<col1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter matrix B elements:\n");
	for(i=0;i<row2;i++)
	{
		printf("\n");
                for(j=0;j<col2;j++)
               	{ 
                       	scanf("%d",&b[i][j]);
               	}
       	}
       	for(i=0;i<row1;i++)
       	{ 
               	for(j=0;j<col2;j++)
               	{ 
			c[i][j]=0;
                       	for(k=0;k<col1;k++)
			{
				c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
			}
		}
        }
	printf("Multiplied Array:");
        printf("Matrix A*Matrix B:\n");
        for(i=0;i<row1;i++)
        {
		printf("\n");
               for(j=0;j<col2;j++)
                {
                        printf("%d\t",c[i][j]);
                }
        }
        printf("\n");
        return 0;
}






