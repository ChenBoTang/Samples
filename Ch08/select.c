/*�w�q���ƧǤ���ư}�C�������ӼƬ�8*/ 
#define N 8

selection_sort(int list[], int n)
{
   int i, j, min, temp;

   for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++)     /*�b�ѤU����Ƥ���X�̤p�����*/
			if(list[j] < list[min])
              min = j;
        temp = list[min];              /*�M��X�Ӧ�m����ƥ洫*/
        list[min] = list[i];
        list[i] = temp;
   }
}

main()
{
  int i; 
  int list[N] = {8, 7, 6, 5, 4, 3, 2, 1};
  selection_sort(list, N);
  printf("�Ƨǵ��G���G");
  for(i = 0; i < N; i++)
    printf("%d ", list[i]);
  getchar();  
}


