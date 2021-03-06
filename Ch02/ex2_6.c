main()
{
     int A[2][3] = {{11, 12, 13}, {21, 22, 23}};
     int B[2][3] = {{10, 20, 30}, {40, 50, 60}};
     int C[2][3];
     matrix_add(2, 3, A, B, C);
     matrix_traverse(2, 3, C);
     getchar(); 
}

/*假設A,B,C均為mxn陣列，這個函數要求出C=A+B*/
matrix_add(int m, int n, int A[m][n], int B[m][n], int C[m][n])
{
  int i, j;
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      C[i][j] = A[i][j] + B[i][j];  
}

/*假設A為mxn陣列，這個函數要印出二維陣列內所有元素的值*/
matrix_traverse(int m, int n, int A[m][n])
{
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         printf("%d ", A[i][j]);
       printf("\n");
     }
}




