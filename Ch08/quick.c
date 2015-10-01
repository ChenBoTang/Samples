/*定義欲排序的資料個數為8*/
#define N 8

quick_sort(int list[], int left, int right)
{
  int i, j, pivot, temp;
  /*此if條件式用來確保陣列的第一個索引必須小於最後一個索引才會進行快速排序*/
  if (left < right){
    i = left;
    j = right + 1;
    pivot = list[left];						/*pivot為基準值*/
    /*此迴圈用來重覆從陣列的左、右邊尋找比pivot大、比pivot小的資料，然後交換*/
    do{
      /*此迴圈用來尋找比pivot大的資料，找到後令i指向該資料*/
      do
        i++;
      while (list[i] < pivot);
      /*此迴圈用來尋找比pivot小的資料，找到後令j指向該資料*/
      do
        j--;
      while (list[j] > pivot);
      if (i < j){							/*若i小於j，將i與j所指向的資料交換*/
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }while (i < j);
    temp = list[left];					/*若j大於i，將list[left]與索引j所指向的資料交換*/
    list[left] = list[j];
    list[j] = temp;
    quick_sort(list, left, j - 1);	/*遞迴呼叫將以pivot為中心的左邊資料進行快速排序*/
    quick_sort(list, j + 1, right);	/*遞迴呼叫將以pivot為中心的右邊資料進行快速排序*/
  }
}

main()
{
  int i; 
  int list[N] = {8, 7, 6, 5, 4, 3, 2, 1};
  quick_sort(list, 0, N - 1);
  printf("排序結果為：");
  for(i = 0; i < N; i++)
    printf("%d ", list[i]);
  getchar();  
}



