main()
{
  int largest = factorial(5);								/* �]�w�̤j�ƪ���l�Ȭ�0 */
  
  printf("�̤j�Ƭ�%d", largest);
  getchar();
}

int factorial(int n)
{ 
  if (n == 0) return 1;
  else return (n * factorial(n - 1));
}

