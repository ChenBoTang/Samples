#define MAX_SIZE 100			/*�w�q�}���x�}�̦h�]�tMAX_SIZE�ӫD�s��*/
typedef struct{						/*�w�q��ܫD�s�������c*/
  int row;								/*�D�s�����ĴX�C*/
  int col;								/*�D�s�����ĴX��*/
  int value;							/*�D�s������*/
}SparseTerm;

main()
{
  SparseTerm A[MAX_SIZE], B[MAX_SIZE]; 
  attach(&A[0], 4, 5, 6);
  attach(&A[1], 0, 1, 1);
  attach(&A[2], 0, 4, 2);
  attach(&A[3], 1, 3, 3);
  attach(&A[4], 2, 0, 4);
  attach(&A[5], 2, 2, 5);
  attach(&A[6], 3, 4, 6);    
  SparseTranspose(A, B);
  /*�L�X�}���x�}B�����G*/
  int i;
  for(i = 0; i <= B[0].value; i++)
    printf("%d\t%d\t%d\n", B[i].row, B[i].col, B[i].value);
  getchar();
}

/*�o�Ө�Ʒ|�[�J�@�ӫD�s��*/
attach(SparseTerm *term, int row, int col, int value)
{
  term->row = row;
  term->col = col;
  term->value = value;                 
}

/*�o�Ө�Ʒ|�N�}���x�}A��m�A�o��t�@�ӵ}���x�}B*/ 
SparseTranspose(SparseTerm A[], SparseTerm B[])
{
  int i, j, currentB;
  B[0].row = A[0].col;
  B[0].col = A[0].row;
  B[0].value = A[0].value;
  if(B[0].value == 0) return;   /*��ܵ}���x�}�S���D�s��*/
  currentB = 1;
  for(i = 0; i < A[0].col; i++)
    for(j = 0; j <= B[0].value; j++)
      if (A[j].col == i){
        B[currentB].row = A[j].col;
        B[currentB].col = A[j].row;
        B[currentB].value = A[j].value;
        currentB++;
      }    
}
