/*�w�q���ƧǤ���ư}�C�������ӼƬ�8*/
#define N 8

bubble_sort(int list[], int n)
{
  int i, j, flag, temp;
  for (i = n - 1; i >= 1; i--){		/*�۾F��ƨ�������L�{�@��n-1�Ӧ^�X*/
    flag = 0;						/*flag�ΨӰO�����L�o�ͥ洫�A�S�����ܡA��ܱƧǧ���*/
    for (j = 0; j <= i - 1; j++){	/*�����j��ΨӶi��C�@�^�X�������*/
      if (list[j] > list[j + 1]){	/*�Y���䪺��Ƥj��k�䪺��ơA�N�洫�Aflag�]�w��1*/
        temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
        flag = 1;
      }
    }
    if (flag = 0)						/*�Yflag����0�A��ܤ����j��S���o�ͥ洫�A�w�g�Ƨǧ���*/
      break;							/*�Ƨǧ����N�i�H�j�����}�~���j��*/
  }
}

main()
{
  int i; 
  int list[N] = {8, 7, 6, 5, 4, 3, 2, 1};
  bubble_sort(list, N);
  printf("�Ƨǵ��G���G");
  for(i = 0; i < N; i++)
    printf("%d ", list[i]);
  getchar();  
}



