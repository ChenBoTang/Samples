/*���]A��m��n�x�}�BB��n��p�x�}�BC��m��p�x�}�A�o�Ө�ƭn�p��C=A��B*/
matrix_multiply(int m, int n, int p, int A[m][n], int B[n][p], int C[m][p])
{
  int i, j, k;
  for(i = 0; i < m; i++)
    for(j = 0; j < p; j++){
      C[i][j] = 0;
      for(k = 0; k < n; k++)
        C[i][j] = C[i][j] + A[i][k] * B[k][j];
    }
}
