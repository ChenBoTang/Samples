/*�w�q���ƧǤ���ư}�C�������ӼƬ�8*/
#define N 8

insertion_sort(int list[], int n)
{
  int i, j, next;
  for (i = 1; i < n; i++){					        /*�q�ĤG�Ӽ��J�P�}�l�M��e�������J�P��j�p*/
    next = list[i];							        /*next�N���C�����쪺�s���J�P*/
    for (j = i - 1; j >= 0 && next < list[j]; j--)	/*�ĤG�Ӱj��N�����e����B�w�g�ƧǪ����J�P*/
      list[j + 1] = list[j];				        /*�Y�s���J�P����p�A�N�N���e�����J�P���Ჾ*/
    list[j + 1] = next;						        /*�̫�N�ŤU�Ӫ���m�����s���J�P*/
  }
}

main()
{
  int i; 
  int list[N] = {8, 7, 6, 5, 4, 3, 2, 1};
  insertion_sort(list, N);
  printf("�Ƨǵ��G���G");
  for(i = 0; i < N; i++)
    printf("%d ", list[i]);
  getchar();  
}



