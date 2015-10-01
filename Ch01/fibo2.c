main()
{
  int i;    
  for (i = 0; i < 10; i++)
    printf("%d\n", fibo(i));
  getchar();  
}

int fibo(int n)
{
  if (n == 0) return 0;
  else if (n == 1) return 1; 
  else return fibo(n - 1) + fibo(n - 2);
}
