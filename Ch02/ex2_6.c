main()
{
     int A[2][3] = {{11, 12, 13}, {21, 22, 23}};
     int B[2][3] = {{10, 20, 30}, {40, 50, 60}};
     int C[2][3];
     matrix_add(2, 3, A, B, C);
     matrix_traverse(2, 3, C);
     getchar(); 
}

/*���]A,B,C����mxn�}�C�A�o�Ө�ƭn�D�XC=A+B*/
matrix_add(int m, int n, int A[m][n], int B[m][n], int C[m][n])
{
  int i, j;
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      C[i][j] = A[i][j] + B[i][j];  
}

/*���]A��mxn�}�C�A�o�Ө�ƭn�L�X�G���}�C���Ҧ���������*/
matrix_traverse(int m, int n, int A[m][n])
{
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         printf("%d ", A[i][j]);
       printf("\n");
     }
}




