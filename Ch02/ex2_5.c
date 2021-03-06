main()
{
     int A[2][3] = {{11, 12, 13}, {21, 22, 23}};
     int B[3][2];
     matrix_transpose(2, 3, A, B);
     matrix_traverse(3, 2, B);
     getchar(); 
}

/*假設A為mxn陣列，這個函數要求出A的轉置矩陣B，則B為nxm矩陣*/
matrix_transpose(int m, int n, int A[m][n], int B[n][m])
{
  int i, j;
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      B[j][i] = A[i][j]; 
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




