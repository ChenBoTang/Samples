/*�������ΨӤ��x�By�A�Yx < y�A�Ǧ^ -1�F�Yx == y�A�Ǧ^0�F�Y x > y�A�Ǧ^1*/
#define COMPARE(x, y) ((x < y) ? -1 : (x == y) ? 0 : 1)

/*�G���j�M���*/
int binary_search(int list[], int left, int right, int key)
{
  int middle;
  /*��if���󦡥ΨӽT�O�j�M�d�򪺲Ĥ@�ӯ��ޥ����p�󵥩�̫�@�ӯ��ޤ~�|�i��j�M*/
  if (left <= right){
    /*middle���j�M�d�򤤶�������*/       
    middle = (left + right) / 2;
    /*�I�s��������j�M�d�򤤶����O���M���j�M�����*/							
    switch (COMPARE(list[middle], key)){		
      /*�Y�Ǧ^ -1�A��ܱ��j�M����ȸ��j�A�h�H���j�I�s�b�j�M�d�򪺤�����᭱�i��j�M*/
      case -1:
        return binary_search(list, middle + 1, right, key);
      /*�Y�Ǧ^0�A��ܲŦX���j�M����ȡA�h�Ǧ^�����*/
      case 0:
        return middle;
      /*�Y�Ǧ^1�A��ܱ��j�M����ȸ��p�A�h�H���j�I�s�b�j�M�d�򪺫e���줤���i��j�M*/
      case 1:
        return binary_search(list, left, middle - 1, key);
    }
  }
  /*�Yif�����ˬd��j�M�d�򪺲Ĥ@�ӯ��ޤj��̫�@�ӯ��ޡA�h�Ǧ^ -1�A���A�i��j�M*/
  return -1;
}

/*�D�{��*/
main()
{
  int list[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
  printf("��ȲŦX���O�������ެ��G%d", binary_search(list, 0, 9, 15));
  getchar();  
}



