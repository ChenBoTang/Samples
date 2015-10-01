/*�w�q�[�v�ϧΪ����I�ӼƬ�4*/ 
#define V 4

/*�w�q �۪��Ȭ�32767*/
#define INFINITE 32767

/*�ŧiadmatrix[][]�}�C�s��[�v�ϧΪ��۾F�x�}*/ 
int admatrix[V][V] = {0, 2, 9, 12,
                      7, 0, 3, INFINITE,
                      INFINITE, INFINITE, 0, 4,
                      INFINITE, 3, INFINITE, 0};
int A[V][V];                     


/*�o�Ө�Ʒ|��@Floyd�t��k*/
floyd()
{
  int i, j, k;
  for (i = 0; i < V; i++)          /*�D�XA0*/
    for (j = 0; j < V; j++)
      A[i][j] = admatrix[i][j];
      
  for (k = 0; k < V; k++)          /*�D�XA1 ~ AV*/
    for (i = 0; i < V; i++)
      for (j = 0; j < V; j++)
        if (A[i][j] > A[i][k] + A[k][j])
          A[i][j] = A[i][k] + A[k][j];    
}


/*�D�{��*/ 
main()
{
  floyd();
  int i, j;
  for (i = 0; i < V; i++)          /*�L�X�̵u�Z��*/
    for (j = 0; j < V; j++)
      printf("V%d��V%d���̵u�Z����%d\n", i, j, A[i][j]);
  getchar();    
}
