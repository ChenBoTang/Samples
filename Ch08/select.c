/*定義欲排序之資料陣列的元素個數為8*/ 
#define N 8

selection_sort(int list[], int n)
{
   int i, j, min, temp;

   for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++)     /*在剩下的資料中找出最小的資料*/
			if(list[j] < list[min])
              min = j;
        temp = list[min];              /*和第X個位置的資料交換*/
        list[min] = list[i];
        list[i] = temp;
   }
}

main()
{
  int i; 
  int list[N] = {8, 7, 6, 5, 4, 3, 2, 1};
  selection_sort(list, N);
  printf("排序結果為：");
  for(i = 0; i < N; i++)
    printf("%d ", list[i]);
  getchar();  
}


