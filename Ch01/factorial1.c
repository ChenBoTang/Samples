main()
{
  int largest = factorial(5);								/* 設定最大數的初始值為0 */
  
  printf("最大數為%d", largest);
  getchar();
}

int factorial(int n)
{
  int result = 1;
  if (n == 0) return 1;	/* 當n = 0時，f(n) = n! = 0! = 1 */
  while(n > 0){		/* 當n > 0時，f(n) = n! = n * (n - 1) * … * 3 * 2 * 1 */
    result = result * n;
    n = n - 1;
  }
  return result;
}
