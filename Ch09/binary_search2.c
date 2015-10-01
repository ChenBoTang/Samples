/*�������ΨӤ��x�By�A�Yx < y�A�Ǧ^ -1�F�Yx == y�A�Ǧ^0�F�Y x > y�A�Ǧ^1*/
#define COMPARE(x, y) ((x < y) ? -1 : (x == y) ? 0 : 1)

/*�G���j�M���*/
int binary_search2(int list[], int left, int right, int key)
{
  int middle;
  while(left <= right){
    middle = (left + right) / 2;
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


/*�D�{��*/
main()
{
  int list[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
  printf("��ȲŦX���O�������ެ��G%d", binary_search2(list, 0, 9, 15));
  getchar();  
}



