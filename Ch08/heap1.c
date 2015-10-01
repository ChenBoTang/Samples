#define N 8     					/*定義資料個數為8*/ 

/*在最大堆積中插入節點*/ 
insert_to_heap(int list[], int i)
{
  int temp = list[i];              /*令temp為欲插入的節點*/
  while((i > 0) && (temp > list[(i - 1) / 2])){  /*當不是第一個節點且大於其父節點時*/
    list[i] = list[(i - 1) / 2];   
    i = (i - 1) / 2;
    if (i == 0) break;              
  }
  list[i] = temp;                   
}

/*建構最大堆積*/ 
construct_heap(int list[], int n)
{
  int i;
  for(i = 0; i < n; i++)          /*一一插入節點*/
    insert_to_heap(list, i);                     
}

/*主程式*/ 
main()
{
  int i; 
  int list[N] = {15, 42, 29, 66, 73, 15, 10, 19};
  construct_heap(list, N);
  printf("使用陣列存放最大堆積得到：\n");
  for(i = 0; i < N; i++) printf("%d ", list[i]);
  getchar();
}
