#include<stdio.h>
#include<stdlib.h>

void print_matrix(int mat[][100], int m, int n)
{
	int i = 0, j = 0;

	for(i = 0; i <= m; i++)
	{
		printf("\n");
		for (j = 0; j <= n; j++)
		{
			printf("%2d ", mat[i][j]);
		}
	}	
}

void  rotate_a_raw(int mat[][100], int m, int n, int c)
{
	int i;
	int t1, t2;

	//printf("\n c: %d", c);
	for (i = c; i < (m - c); i++)
	{
		t1 = mat[i][m - c];
		mat[i][m - c] = mat[c][i];
		t2 = mat[m - c][m - i];
		mat[m - c][m - i] = t1;
		t1 = mat[m - i][c];
		mat[m - i][c] = t2;
		mat[c][i] = t1;
	} 
}


void rotate_sqr_matrix(int mat[][100], int m, int n)
{
	int i;

	for (i = 0; i <= (m / 2); i++)
	{
	//	printf("\n i: %d", i);
		rotate_a_raw(mat, m, n, i);
	}
}


int main()
{
	int m, n, i, j;
	int mat[100][100];

	printf("\nEnter the matrix #raws: ");
	scanf("%d", &m);
	printf("\nEnter the matrix #colms: ");
	scanf("%d", &n);

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}

	print_matrix(mat, m - 1, n -1);
	
	rotate_sqr_matrix(mat, m - 1, n - 1);	

	printf("\n");
	print_matrix(mat, m - 1, n - 1);
}
