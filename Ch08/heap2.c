#define N 8     					/*�w�q��ƭӼƬ�8*/

/*�վ���w�`�I����m*/ 
adjust_to_heap(int list[], int n, int i)
{
  int temp, large;
  temp = list[i];                   /*�Otemp�����վ��m���`�I*/
  while(2 * i + 1 < n){             /*��list[i]�����l�`�I��*/
    large =  2 * i + 1;             /*�O�j�l�`�I��list[i]�����l�`�I*/    
    if ((large + 1) < n && list[large] < list[large + 1])  /*�Y���k�l�`�I�B�j�󥪤l�`�I*/
      large = large + 1;                                   /*�h�O�j�l�`�I���k�l�`�I*/ 
    if (temp >= list[large]) break; /*�Ytemp�j�󵥩��j�l�`�I�A�h���X*/             
    list[i] = list[large];          /*�N��j�l�`�I���W���@��*/ 
    i = large;                      /*�~�򩹤U�����*/ 
  }
  list[i] = temp;                   
}

/*�غc�̤j��n�Ф覡�G�G�ѤU�ӤW*/ 
construct_heap2(int list[], int n)
{
  int i;
  for(i = n/2 - 1; i >= 0; i--)     /*�@�@�վ�̫�@�Ӧ��l�`�I�����`�I���ڪ���m*/
    adjust_to_heap(list, n, i);                     
}

/*�D�{��*/ 
main()
{
  int i; 
  int list[N] = {15, 42, 29, 66, 73, 15, 10, 19};
  construct_heap2(list, N);
  printf("�ϥΰ}�C�s��̤j��n�o��G\n");
  for(i = 0; i < N; i++) printf("%d ", list[i]);
  getchar();
}
