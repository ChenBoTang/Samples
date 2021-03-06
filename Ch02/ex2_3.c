main()
{
     int A[5] = {10, 20, 30, 40, 50};
     array_delete(A, 5, 2);
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

/*假設陣列A有n個元素，這個函數要刪除陣列內索引為i的值*/
array_delete(int A[], int n, int i)
{
  int j;
  if (i < 0 || i >= n) return;			/*若索引i超過陣列的合法範圍，則返回*/
  for(j = i; j < n - 1; j++)			/*將之後的元素均往前挪一個位置*/
    A[j] = A[j + 1];
  A[n - 1] = 0;  
}




