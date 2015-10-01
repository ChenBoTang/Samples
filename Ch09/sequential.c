/*循序搜尋*/ 
int sequential_search(int list[], int n, int key)
{
  int i;
  for (i = 0; i < n; i++)
    if (list[i] == key)			/*比對陣列內的記錄是否等於欲搜尋的鍵值*/
      return i;				/*若找到鍵值符合的記錄，就傳回其索引*/
  return -1;				/*若找不到鍵值符合的記錄，就傳回 -1*/
}

/*主程式*/
main()
{
  int list[] = {54, 2, 40, 22, 17, 22, 60, 35};
  printf("鍵值符合之記錄的索引為：%d", sequential_search(list, 8, 22));
  getchar();  
}



