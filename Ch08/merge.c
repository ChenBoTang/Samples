/*�w�q���ƧǪ���ƭӼƬ�8*/
#define N 9

merge_sort(int list[], int temp[], int left, int right)
{
  int middle, i, j, k, n;

  if (left < right){
    middle = (left + right) / 2;
    merge_sort(list, temp, left, middle);
    merge_sort(list, temp, middle + 1, right);
    
    i = left;                           /*i���V���䪺�Ĥ@�Ӹ��*/
    j = middle + 1;                     /*j���V�k�䪺�Ĥ@�Ӹ��*/                             
    k = left;                           /*k���Vtemp[]���Ĥ@�Ӹ��*/ 
    n = right - left + 1;               /*n���ثe���b�X�֪���ƭӼ�*/ 
    while (i <= middle && j <= right)   /*�̷Ӥj�p�N���k���䪺��ƦX�֩�Jtemp[]*/      
      if (list[i] <= list[j]) temp[k++] = list[i++];
      else temp[k++] = list[j++];
    while (i <= middle)                 /*�N����ѤU����ƽƻs��temp[]*/
      temp[k++] = list[i++];  
    while (j <= right)                  /*�N�k��ѤU����ƽƻs��temp[]*/
      temp[k++] = list[j++];
    for(i = 0; i < n; i++, right--)     /*�Ntemp[]�ƻs�^list[]*/
      list[right] = temp[right];         
  }
}

main()
{
  int i; 
  int list[N] = {68, 27, 6, 15, 74, 3, 12, 1, 50};
  int temp[N];
  merge_sort(list, temp, 0, N - 1);
  printf("�Ƨǵ��G���G");
  for(i = 0; i < N; i++) printf("%d ", list[i]);
  getchar();
}
