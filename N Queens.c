#include<stdio.h>
#include<conio.h>
#define N 4
void printSolution(int board[N][N])
{	
	int i,j;
	static  int k = 1;
    printf("%d-\n",k++);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}
int isSafe(int board[N][N],int row,int col)
{
	int i,j;
	for(i=row,j=col;i>=0 && j>=0;i--,j--)
		if(board[i][j])
		return 0;
	for(i=row,j=col;i<N && j>=0;i++,j--)
		if(board[i][j])
		return 0;
	for(i=0;i<N;i++)
		if(board[row][i])
		return 0;
	return 1;

}
int NQueenUtil(int board[N][N],int col)
{	
	int i;
	if(col==N)
	{
		printSolution(board);
		return 1;
	}
	for(i=0;i<N;i++)
	{
		if(isSafe(board,i,col)==1)
		{
		board[i][col]=1;
		if(NQueenUtil(board,col+1)==1)
		return 1;
		board[i][col]=0;
		}
	}
	return 0;
}
int main()
{
	int board[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
 
    if ( NQueenUtil(board, 0) == 0 )
    {
      printf("Solution does not exist");
      return 0;
    }
 
    printSolution(board);
    return 0;
}
