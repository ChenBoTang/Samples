/*�w�q���ƧǪ���ƭӼƬ�8*/
#define N 8

quick_sort(int list[], int left, int right)
{
  int i, j, pivot, temp;
  /*��if���󦡥ΨӽT�O�}�C���Ĥ@�ӯ��ޥ����p��̫�@�ӯ��ޤ~�|�i��ֳt�Ƨ�*/
  if (left < right){
    i = left;
    j = right + 1;
    pivot = list[left];						/*pivot����ǭ�*/
    /*���j��Ψӭ��бq�}�C�����B�k��M���pivot�j�B��pivot�p����ơA�M��洫*/
    do{
      /*���j��ΨӴM���pivot�j����ơA����Oi���V�Ӹ��*/
      do
        i++;
      while (list[i] < pivot);
      /*���j��ΨӴM���pivot�p����ơA����Oj���V�Ӹ��*/
      do
        j--;
      while (list[j] > pivot);
      if (i < j){							/*�Yi�p��j�A�Ni�Pj�ҫ��V����ƥ洫*/
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }while (i < j);
    temp = list[left];					/*�Yj�j��i�A�Nlist[left]�P����j�ҫ��V����ƥ洫*/
    list[left] = list[j];
    list[j] = temp;
    quick_sort(list, left, j - 1);	/*���j�I�s�N�Hpivot�����ߪ������ƶi��ֳt�Ƨ�*/
    quick_sort(list, j + 1, right);	/*���j�I�s�N�Hpivot�����ߪ��k���ƶi��ֳt�Ƨ�*/
  }
}

main()
{
  int i; 
  int list[N] = {8, 7, 6, 5, 4, 3, 2, 1};
  quick_sort(list, 0, N - 1);
  printf("�Ƨǵ��G���G");
  for(i = 0; i < N; i++)
    printf("%d ", list[i]);
  getchar();  
}



