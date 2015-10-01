main()
{
     int A[5] = {10, 20, 30, 40, 50};
     array_delete(A, 5, 2);
     array_traverse(A, 5);
     getchar();
}

/*安砞皚AΤnじ硂ㄧ计璶皚ず┮Τじ*/
array_traverse(int A[], int n)
{
     int i;
     for(i = 0; i < n; i++)
       printf("%d\n", A[i]);
}

/*安砞皚AΤnじ硂ㄧ计璶埃皚ずまi*/
array_delete(int A[], int n, int i)
{
  int j;
  if (i < 0 || i >= n) return;			/*璝まi禬筁皚猭絛瞅玥*/
  for(j = i; j < n - 1; j++)			/*盢ぇじА┕玡竚*/
    A[j] = A[j + 1];
  A[n - 1] = 0;  
}




