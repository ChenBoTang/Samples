main()
{
     int A[5] = {10, 20, 30, 40, 50};
     array_delete(A, 5, 2);
     array_traverse(A, 5);
     getchar();
}

/*���]�}�CA��n�Ӥ����A�o�Ө�ƭn�L�X�}�C���Ҧ���������*/
array_traverse(int A[], int n)
{
     int i;
     for(i = 0; i < n; i++)
       printf("%d\n", A[i]);
}

/*���]�}�CA��n�Ӥ����A�o�Ө�ƭn�R���}�C�����ެ�i����*/
array_delete(int A[], int n, int i)
{
  int j;
  if (i < 0 || i >= n) return;			/*�Y����i�W�L�}�C���X�k�d��A�h��^*/
  for(j = i; j < n - 1; j++)			/*�N���᪺���������e���@�Ӧ�m*/
    A[j] = A[j + 1];
  A[n - 1] = 0;  
}




