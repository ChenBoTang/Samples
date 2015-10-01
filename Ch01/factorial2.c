main()
{
  int largest = factorial(5);								/* 砞﹚程计﹍0 */
  
  printf("程计%d", largest);
  getchar();
}

int factorial(int n)
{ 
  if (n == 0) return 1;
  else return (n * factorial(n - 1));
}

