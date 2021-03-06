main()
{
     int A[5] = {10, 20, 30, 40, 50};
     array_insert(A, 5, 2, 8);
     array_traverse(A, 5);
     getchar();
}

/*假設陣列A有n個元素，這個函數要印出陣列內所有元素的值*/
array_traverse(int A[], int n)
{
     int i;
     for(i = 0; i < n; i++)
       printf("%d\n", A[i]);
}

/*假設陣列A有n個元素，這個函數要在陣列內索引為i的位置插入一個值value*/
array_insert(int A[], int n, int i, int value)
{
  int j;
  if (i < 0 || i >= n) return;			/*若索引i超過陣列的合法範圍，則返回*/
  for(j = n - 1; j > i; j--)			/*將原來索引為i及之後的元素均往後挪一個位置*/
    A[j] = A[j - 1];
  A[i] = value;							/*在索引為i的位置插入一個值value*/
}



