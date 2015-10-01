/*此巨集用來比較x、y，若x < y，傳回 -1；若x == y，傳回0；若 x > y，傳回1*/
#define COMPARE(x, y) ((x < y) ? -1 : (x == y) ? 0 : 1)

/*內插搜尋函數*/
int interpolation_search(int list[], int left, int right, int key)
{
  int middle;
  float x;
  while(left <= right){
    if (list[right] - list[left] == 0) x = 0;
    else x = (float)(key - list[left]) / (list[right] - list[left]);   
    middle = left + (int)x * (right - left);
    if (middle < left || middle > right) return -1;
    switch (COMPARE(list[middle], key)){
      case -1:
        left = middle + 1;
        break;
      case 0:
        return middle;
      case 1:
        right = middle - 1;
    }
  }
  return -1;
}


/*主程式*/
main()
{
  int list[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
  printf("鍵值符合之記錄的索引為：%d", interpolation_search(list, 0, 9, 15));
  getchar();  
}



