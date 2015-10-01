main()
{
     int A[5] = {10, 20, 30, 40, 50};
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




