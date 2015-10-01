main()
{
  int largest = factorial(5);								/* 砞﹚程计﹍0 */
  
  printf("程计%d", largest);
  getchar();
}

int factorial(int n)
{
  int result = 1;
  if (n == 0) return 1;	/* 讽n = 0f(n) = n! = 0! = 1 */
  while(n > 0){		/* 讽n > 0f(n) = n! = n * (n - 1) *  * 3 * 2 * 1 */
    result = result * n;
    n = n - 1;
  }
  return result;
}
