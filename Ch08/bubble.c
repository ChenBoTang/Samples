/*定義欲排序之資料陣列的元素個數為8*/
#define N 8

bubble_sort(int list[], int n)
{
  int i, j, flag, temp;
  for (i = n - 1; i >= 1; i--){		/*相鄰資料兩兩比較的過程共有n-1個回合*/
    flag = 0;						/*flag用來記錄有無發生交換，沒有的話，表示排序完畢*/
    for (j = 0; j <= i - 1; j++){	/*內部迴圈用來進行每一回合的兩兩比較*/
      if (list[j] > list[j + 1]){	/*若左邊的資料大於右邊的資料，就交換，flag設定為1*/
        temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
        flag = 1;
      }
    }
    if (flag = 0)						/*若flag仍為0，表示內部迴圈沒有發生交換，已經排序完畢*/
      break;							/*排序完畢就可以強制離開外部迴圈*/
  }
}

main()
{
  int i; 
  int list[N] = {8, 7, 6, 5, 4, 3, 2, 1};
  bubble_sort(list, N);
  printf("排序結果為：");
  for(i = 0; i < N; i++)
    printf("%d ", list[i]);
  getchar();  
}



