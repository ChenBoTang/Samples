/*�`�Ƿj�M*/ 
int sequential_search(int list[], int n, int key)
{
  int i;
  for (i = 0; i < n; i++)
    if (list[i] == key)			/*���}�C�����O���O�_������j�M�����*/
      return i;				/*�Y�����ȲŦX���O���A�N�Ǧ^�����*/
  return -1;				/*�Y�䤣����ȲŦX���O���A�N�Ǧ^ -1*/
}

/*�D�{��*/
main()
{
  int list[] = {54, 2, 40, 22, 17, 22, 60, 35};
  printf("��ȲŦX���O�������ެ��G%d", sequential_search(list, 8, 22));
  getchar();  
}



