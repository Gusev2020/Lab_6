// laba5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "locale.h"
#include <queue>
 
using namespace std;
int *dist; // указатель на вектор
int **matr;//указатель для массива указателей


void BFS(int s , int n)
{
	queue <int> Q;
	Q.push(s);
	dist[s] = 0;
	printf("\Порядок обхода:");
	while(!Q.empty())
	{
		s = Q.front();
		Q.pop();
		printf("%d", s);
		for(int i = 0;i < n; i++)
		{
			if((matr[s][i] == 1) && dist[i] == -1)
			{
				Q.push(i);
				dist[i] = dist[s] + 1;
			}
		}
	}
	printf("\nРасстояние: ");
	for(int i = 0; i < n; i++)
	{
		if(dist[i] != -1)
		{
			printf("%d", dist[i]);
		}
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
  system("chcp 1251");
  system("cls");

  int n,i,j,x, Nach;
  
   printf("Введите размер матрицы:");
   scanf("%d", &n);
   printf("введите размер вектора vis:");
   scanf("%d",&x);
  dist = (int*)malloc(n * sizeof(int));
  
  matr = (int**)malloc(n * sizeof(int*));
  
  //выделение памяти под массив указателей
  for(i=0; i<n; i++){
    matr[i] = (int*)malloc(n * sizeof(int));
  }
    //выделение памяти для массива значений
  for( i = 0; i < n; i++)
  {
	for( j = 0; j < n; j++)
	{
		if(i == j) 
		{
			matr[i][j] = 0;
		}  

		if (i < j)
		{
			matr[i][j] = rand()%2;
			matr[j][i] = matr[i][j];
		}
	}
  }
  for(i = 0; i < x; i++)
  {
	dist[i] = -1;
  }


  printf( "Result: ");
  for(i = 0; i < n; i++)
  {
	 printf("\n");
		for (j = 0; j < n; j++)
		  printf("%d\t",matr[i][j]);
    
  }
  printf( " \n   ");
  printf( " \n   ");
  for(int i = 0; i < x; i++)
  {
	printf("%d\t", dist[i]);
  }
  printf( " \n   ");

  printf("Введите вершину начала обхода:\n");
  scanf("%d", &Nach);
  BFS(Nach, n);


  
    getch();
}

