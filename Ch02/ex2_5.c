main()
{
     int A[2][3] = {{11, 12, 13}, {21, 22, 23}};
     int B[3][2];
     matrix_transpose(2, 3, A, B);
     matrix_traverse(3, 2, B);
     getchar(); 
}

/*���]A��mxn�}�C�A�o�Ө�ƭn�D�XA����m�x�}B�A�hB��nxm�x�}*/
matrix_transpose(int m, int n, int A[m][n], int B[n][m])
{
  int i, j;
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      B[j][i] = A[i][j]; 
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




