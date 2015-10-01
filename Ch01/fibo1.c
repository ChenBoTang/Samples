main()
{
  int i;    
  for (i = 0; i < 10; i++)
    printf("%d\n", fibo(i));
  getchar();  
}

int fibo(int n)
{
  int fn;
  int fn1;
  int fn2;
  int i;
  if (n == 0) return 0;
  else if (n == 1) return 1;
  else{
    fn2 = 0;
    fn1 = 1;
    for(i = 2; i <= n; i++){
      fn = fn1 + fn2;
      fn2 = fn1;
      fn1 = fn;      
    }  
  }
  return fn;
}
