main()
{
  int list[] = {54, 2, 40, 22, 17, 22, 60, 35};    
  printf("%d", sequential_search(list, 8, 22));
  getchar();      
}

int sequential_search(int list[], int n, int key)
{
  int i;
  for (i = 0; i < n; i++)
    if (list[i] == key)			/* ���}�C������ƬO�_������j�M������ */
      return i;						/* �Y���ŦX���󪺸�ơA�N�Ǧ^����� */
  
  return(-1);							/* �Y�䤣��ŦX���󪺸�ơA�N�Ǧ^ -1 */
}
