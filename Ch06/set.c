/*宣告陣列存放元素，而且節點0~8是存放在索引為0~8的位置*/
int parent[9];

/*這個函數會將兩個互斥集合聯合成一個集合*/
set_union(int i, int j)
{
  parent[i] = j;
}

/*這個函數會在互斥集合中搜尋參數指定的元素位於哪個集合並傳回該集合的樹根*/ 
int find(int i)
{
  while(parent[i] > 0)
    i = parent[i];
  return i;           
}

main()
{
  int i;
  for(i = 0; i < 9; i++) 
    parent[i] = -1;
  set_union(0, 2);
  set_union(1, 2);
  set_union(3, 4);
  set_union(5, 8);
  set_union(6, 8);
  set_union(7, 8);
  set_union(4, 2);
  printf("節點0所在之集合的樹根為節點%d\n", find(0));
  printf("節點3所在之集合的樹根為節點%d\n", find(3));
  printf("節點7所在之集合的樹根為節點%d\n", find(7));
  getchar();      
}
