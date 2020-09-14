//Sparse Matrix

#include <stdio.h>
#define size 10
#define spSize size*size

int mat1[size][size], mat2[size][size];
int sp1[spSize][3], sp2[spSize][3], tr1[spSize][3], tr2[spSize][3];

void read(int a[size][size], int r, int c)
{
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d", &a[i][j]);
}

void display(int a[size][size], int r, int c)
{
	for(int i=0;i<r;i++)
	{	
		for(int j=0;j<c;j++)
			printf("%d\t", a[i][j]);
	printf("\n");
	}
}

void sparse(int a[size][size],int sp[spSize][3], int r, int c)
{
	int k=1;
	sp[0][0]=r;
	sp[0][1]=c;

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			if(a[i][j]!=0)
			{
				sp[k][0]=i;
				sp[k][1]=j;
				sp[k][2]=a[i][j];
				k++;
			}
	sp[0][2]=k-1;

	displaySparse(sp, k);
}

void displaySparse(int sp[spSize][3], int k)
{
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<3;j++)
			printf("%d\t",sp[i][j]);
		printf("\n");
	}
}

void transpose(int sp[spSize][3], int trans[spSize][3])
{
	int k=1;
	trans[0][0] = sp[0][1];
	trans[0][1] = sp[0][0];
	trans[0][2] = sp[0][2];

	for(int i=0;i<sp[0][1];i++)
		for(int j=1;j<=sp[0][2];j++)
			if(sp[j][1]==i)
			{
				trans[k][0]=sp[j][1];
				trans[k][1]=sp[j][0];
				trans[k][2]=sp[j][2];
				k++;
			}

	displaySparse(trans, k);
}

void sum(int a1[spSize][3], int a2[spSize][3])
{
	int n1, n2, sum[size][3], i, j, k;
	n1=a1[0][2];
	n2=a2[0][2];
	i=j=k=1;

	sum[0][0]=a1[0][0];
	sum[0][1]=a1[0][1];

	while(i<=n1 && j<=n2)
	{
		if(a1[i][0]<a2[j][0] || a1[i][1]<a2[j][1])         
		{          
			sum[k][0]=a1[i][0];
			sum[k][1]=a1[i][1];
			sum[k][2]=a1[i][2];
			k++;
			i++;      
		}

		else if(a2[j][0]<a1[i][0] || a2[j][1]<a1[i][1])          
		{          
			sum[k][0]=a2[j][0];
			sum[k][1]=a2[j][1]; 
			sum[k][2]=a2[j][2];
			k++;
			j++;  
		}
		      
		else     
		{  
			int s=a1[i][2]+a2[j][2];   
			if(s!=0)
			{
				sum[k][0]=a1[i][0];
				sum[k][1]=a1[i][1];
				sum[k][2]=a1[i][2]+a2[j][2];
				k++;	
			}
			i++;
			j++;
		}
	}
	   
	while(i<=n1)        
	{
		sum[k][0]=a1[i][0];
		sum[k][1]=a1[i][1];
		sum[k][2]=a1[i][2];
		i++;
		k++;
	} 

	while(j<=n2)      
	{   
		sum[k][0]=a2[j][0];
		sum[k][1]=a2[j][1];
		sum[k][2]=a2[j][2];
		j++;
		k++;
	} 
	sum[0][2]=k-1; 

	displaySparse(sum, k);
}

void main()
{
	int r,c;
	printf("Enter the number of rows and columns\n");
	scanf("%d %d", &r, &c);

	printf("\nEnter the elements of Matrix 1:\n");
	read(mat1, r, c);
	printf("\nEnter the elements of Matrix 2:\n");
	read(mat2, r, c);

	printf("\nMatrix 1:\n");
	display(mat1, r, c);	
	printf("\nMatrix 2:\n");
	display(mat2, r, c);

	printf("\nMatrix 1 in tuple form:\n");
	sparse(mat1, sp1, r, c);
	printf("\nMatrix 2 in tuple form:\n");
	sparse(mat2, sp2, r, c);

	printf("\nTranspose of Matrix 1 in tuple form:\n");
	transpose(sp1, tr1);
	printf("\nTranspose of Matrix 2 in tuple form:\n");
	transpose(sp2, tr2);

	printf("\nSum of the matrices in tuple form:\n");
	sum(sp1, sp2);
}




