main()
{
     int A[2][3] = {{11, 12, 13}, {21, 22, 23}};
     int B[3][2];
     matrix_transpose(2, 3, A, B);
     matrix_traverse(3, 2, B);
     getchar(); 
}

/*安砞Amxn皚硂ㄧ计璶―A锣竚痻皚B玥Bnxm痻皚*/
matrix_transpose(int m, int n, int A[m][n], int B[n][m])
{
  int i, j;
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      B[j][i] = A[i][j]; 
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




