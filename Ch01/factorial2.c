main()
{
  int largest = factorial(5);								/* 設定最大數的初始值為0 */
  
  printf("最大數為%d", largest);
  getchar();
}

int factorial(int n)
{ 
  if (n == 0) return 1;
  else return (n * factorial(n - 1));
}

