/*此巨集用來比較x、y，若x < y，傳回 -1；若x == y，傳回0；若 x > y，傳回1*/
#define COMPARE(x, y) ((x < y) ? -1 : (x == y) ? 0 : 1)

/*二元搜尋函數*/
int binary_search(int list[], int left, int right, int key)
{
  int middle;
  /*此if條件式用來確保搜尋範圍的第一個索引必須小於等於最後一個索引才會進行搜尋*/
  if (left <= right){
    /*middle為搜尋範圍中間的索引*/       
    middle = (left + right) / 2;
    /*呼叫巨集比較搜尋範圍中間的記錄和欲搜尋的鍵值*/							
    switch (COMPARE(list[middle], key)){		
      /*若傳回 -1，表示欲搜尋的鍵值較大，則以遞迴呼叫在搜尋範圍的中間到後面進行搜尋*/
      case -1:
        return binary_search(list, middle + 1, right, key);
      /*若傳回0，表示符合欲搜尋的鍵值，則傳回其索引*/
      case 0:
        return middle;
      /*若傳回1，表示欲搜尋的鍵值較小，則以遞迴呼叫在搜尋範圍的前面到中間進行搜尋*/
      case 1:
        return binary_search(list, left, middle - 1, key);
    }
  }
  /*若if條件式檢查到搜尋範圍的第一個索引大於最後一個索引，則傳回 -1，不再進行搜尋*/
  return -1;
}

/*主程式*/
main()
{
  int list[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
  printf("鍵值符合之記錄的索引為：%d", binary_search(list, 0, 9, 15));
  getchar();  
}



