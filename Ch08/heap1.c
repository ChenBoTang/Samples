#define N 8     					/*�w�q��ƭӼƬ�8*/ 

/*�b�̤j��n�����J�`�I*/ 
insert_to_heap(int list[], int i)
{
  int temp = list[i];              /*�Otemp�������J���`�I*/
  while((i > 0) && (temp > list[(i - 1) / 2])){  /*���O�Ĥ@�Ӹ`�I�B�j�����`�I��*/
    list[i] = list[(i - 1) / 2];   
    i = (i - 1) / 2;
    if (i == 0) break;              
  }
  list[i] = temp;                   
}

/*�غc�̤j��n*/ 
construct_heap(int list[], int n)
{
  int i;
  for(i = 0; i < n; i++)          /*�@�@���J�`�I*/
    insert_to_heap(list, i);                     
}

/*�D�{��*/ 
main()
{
  int i; 
  int list[N] = {15, 42, 29, 66, 73, 15, 10, 19};
  construct_heap(list, N);
  printf("�ϥΰ}�C�s��̤j��n�o��G\n");
  for(i = 0; i < N; i++) printf("%d ", list[i]);
  getchar();
}
