#define MAX_SIZE 100			/*定義稀疏矩陣最多包含MAX_SIZE個非零項*/
typedef struct{						/*定義表示非零項的結構*/
  int row;								/*非零項位於第幾列*/
  int col;								/*非零項位於第幾行*/
  int value;							/*非零項的值*/
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
  /*印出稀疏矩陣B的結果*/
  int i;
  for(i = 0; i <= B[0].value; i++)
    printf("%d\t%d\t%d\n", B[i].row, B[i].col, B[i].value);
  getchar();
}

/*這個函數會加入一個非零項*/
attach(SparseTerm *term, int row, int col, int value)
{
  term->row = row;
  term->col = col;
  term->value = value;                 
}

/*這個函數會將稀疏矩陣A轉置，得到另一個稀疏矩陣B*/ 
SparseTranspose(SparseTerm A[], SparseTerm B[])
{
  int i, j, currentB;
  B[0].row = A[0].col;
  B[0].col = A[0].row;
  B[0].value = A[0].value;
  if(B[0].value == 0) return;   /*表示稀疏矩陣沒有非零項*/
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
