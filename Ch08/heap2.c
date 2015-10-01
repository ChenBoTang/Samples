#define N 8     					/*定義資料個數為8*/

/*調整指定節點的位置*/ 
adjust_to_heap(int list[], int n, int i)
{
  int temp, large;
  temp = list[i];                   /*令temp為欲調整位置的節點*/
  while(2 * i + 1 < n){             /*當list[i]有左子節點時*/
    large =  2 * i + 1;             /*令大子節點為list[i]的左子節點*/    
    if ((large + 1) < n && list[large] < list[large + 1])  /*若有右子節點且大於左子節點*/
      large = large + 1;                                   /*則令大子節點為右子節點*/ 
    if (temp >= list[large]) break; /*若temp大於等於其大子節點，則跳出*/             
    list[i] = list[large];          /*將其大子節點往上移一階*/ 
    i = large;                      /*繼續往下做比較*/ 
  }
  list[i] = temp;                   
}

/*建構最大堆積－方式二：由下而上*/ 
construct_heap2(int list[], int n)
{
  int i;
  for(i = n/2 - 1; i >= 0; i--)     /*一一調整最後一個有子節點的父節點到樹根的位置*/
    adjust_to_heap(list, n, i);                     
}

/*主程式*/ 
main()
{
  int i; 
  int list[N] = {15, 42, 29, 66, 73, 15, 10, 19};
  construct_heap2(list, N);
  printf("使用陣列存放最大堆積得到：\n");
  for(i = 0; i < N; i++) printf("%d ", list[i]);
  getchar();
}
