/*定義欲排序的資料個數*/ 
#define N 9

shell_sort(int list[], int n)
{
   int i, j, d, temp;
   
   for(d = n / 2; d > 0; d /= 2) 
     for(i = d; i < n; i++){
        temp = list[i];
        for(j = i; j >= d; j -= d)     
		  if(temp < list[j - d]) list[j] = list[j - d];
          else break; 
        list[j] = temp;
     }
}

main()
{
  int i; 
  int list[N] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  shell_sort(list, N);
  printf("排序結果為：");
  for(i = 0; i < N; i++)
    printf("%d ", list[i]);
  getchar();  
}


