#define R 10    /*�w�q��Ƭ�10*/
#define N 8     /*�w�q���ƧǪ���ƭӼƬ�8*/


radix_sort(int list[])
{
  int i, j, max = 0, digits = 0, exp = 1, lsd, num = 0;
  int temp[R][N], count[N];
   
  for(i = 0; i < N; i++)                       /*��X�̤j���*/
    if (list[i] > max) max = list[i];
   
  while (max > 0){                             /*��X�̤j���*/
    digits++;   
    max /= 10;     
  }  

  for(i = 0; i < R; i++)                       /*�N�C���x�l����ƭӼƪ�]��0*/
    count[i] = 0;
  
  while(digits > 0){                           /*�w��ӡB�Q�B��...����ư����t�Ƨ�*/
    for(i = 0; i < N; i++){                    /*�ھګ��w����ƱN��Ƥ��t���x�l*/
      lsd = (list[i] / exp) % 10;  
      temp[lsd][count[lsd]++] = list[i];
    }  
    for(i = 0; i < R; i++)                     /*�ھڤ��t���x�l�����ǱN��ƭ��s�ƦC*/
      if (count[i] > 0){
        for(j = 0; j < count[i]; j++)
          list[num++] = temp[i][j];
        count[i] = 0;
      }
    num = 0;                                
    exp *= 10;
    digits--;     
  }   
}

main()
{
  int i; 
  int list[N] = {356, 123, 353, 228, 153, 152, 238, 236};
  radix_sort(list);
  printf("�Ƨǵ��G���G");
  for(i = 0; i < N; i++)
    printf("%d ", list[i]);
  getchar();  
}



