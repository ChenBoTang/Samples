/*定義欲排序之資料陣列的元素個數為8*/
#define N 8

insertion_sort(int list[], int n)
{
  int i, j, next;
  for (i = 1; i < n; i++){					        /*從第二個撲克牌開始和其前面的撲克牌比大小*/
    next = list[i];							        /*next就像每次拿到的新撲克牌*/
    for (j = i - 1; j >= 0 && next < list[j]; j--)	/*第二個迴圈就像之前拿到且已經排序的撲克牌*/
      list[j + 1] = list[j];				        /*若新撲克牌比較小，就將之前的撲克牌往後移*/
    list[j + 1] = next;						        /*最後將空下來的位置讓給新撲克牌*/
  }
}

main()
{
  int i; 
  int list[N] = {8, 7, 6, 5, 4, 3, 2, 1};
  insertion_sort(list, N);
  printf("排序結果為：");
  for(i = 0; i < N; i++)
    printf("%d ", list[i]);
  getchar();  
}



