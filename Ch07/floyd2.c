/*定義加權圖形的頂點個數為4*/ 
#define V 4

/*定義 ∞的值為32767*/
#define INFINITE 32767

/*宣告admatrix[][]陣列存放加權圖形的相鄰矩陣*/ 
int admatrix[V][V] = {0, 2, 9, 12,
                      7, 0, 3, INFINITE,
                      INFINITE, INFINITE, 0, 4,
                      INFINITE, 3, INFINITE, 0};
int A[V][V];                     


/*這個函數會實作Floyd演算法*/
floyd()
{
  int i, j, k;
  for (i = 0; i < V; i++)          /*求出A0*/
    for (j = 0; j < V; j++)
      A[i][j] = admatrix[i][j];
      
  for (k = 0; k < V; k++)          /*求出A1 ~ AV*/
    for (i = 0; i < V; i++)
      for (j = 0; j < V; j++)
        if (A[i][j] > A[i][k] + A[k][j])
          A[i][j] = A[i][k] + A[k][j];    
}


/*主程式*/ 
main()
{
  floyd();
  int i, j;
  for (i = 0; i < V; i++)          /*印出最短距離*/
    for (j = 0; j < V; j++)
      printf("V%d到V%d的最短距離為%d\n", i, j, A[i][j]);
  getchar();    
}
