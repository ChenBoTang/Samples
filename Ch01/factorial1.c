main()
{
  int largest = factorial(5);								/* �]�w�̤j�ƪ���l�Ȭ�0 */
  
  printf("�̤j�Ƭ�%d", largest);
  getchar();
}

int factorial(int n)
{
  int result = 1;
  if (n == 0) return 1;	/* ��n = 0�ɡAf(n) = n! = 0! = 1 */
  while(n > 0){		/* ��n > 0�ɡAf(n) = n! = n * (n - 1) * �K * 3 * 2 * 1 */
    result = result * n;
    n = n - 1;
  }
  return result;
}
