main()
{
     int A[5] = {10, 20, 30, 40, 50};
     array_insert(A, 5, 2, 8);
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

/*���]�}�CA��n�Ӥ����A�o�Ө�ƭn�b�}�C�����ެ�i����m���J�@�ӭ�value*/
array_insert(int A[], int n, int i, int value)
{
  int j;
  if (i < 0 || i >= n) return;			/*�Y����i�W�L�}�C���X�k�d��A�h��^*/
  for(j = n - 1; j > i; j--)			/*�N��ӯ��ެ�i�Τ��᪺���������ᮿ�@�Ӧ�m*/
    A[j] = A[j - 1];
  A[i] = value;							/*�b���ެ�i����m���J�@�ӭ�value*/
}



