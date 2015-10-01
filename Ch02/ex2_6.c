main()
{
     int A[2][3] = {{11, 12, 13}, {21, 22, 23}};
     int B[2][3] = {{10, 20, 30}, {40, 50, 60}};
     int C[2][3];
     matrix_add(2, 3, A, B, C);
     matrix_traverse(2, 3, C);
     getchar(); 
}

/*安砞A,B,CАmxn皚硂ㄧ计璶―C=A+B*/
matrix_add(int m, int n, int A[m][n], int B[m][n], int C[m][n])
{
  int i, j;
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      C[i][j] = A[i][j] + B[i][j];  
}

/*安砞Amxn皚硂ㄧ计璶蝴皚ず┮Τじ*/
matrix_traverse(int m, int n, int A[m][n])
{
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         printf("%d ", A[i][j]);
       printf("\n");
     }
}




