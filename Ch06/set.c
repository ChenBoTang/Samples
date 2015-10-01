/*�ŧi�}�C�s�񤸯��A�ӥB�`�I0~8�O�s��b���ެ�0~8����m*/
int parent[9];

/*�o�Ө�Ʒ|�N��Ӥ������X�p�X���@�Ӷ��X*/
set_union(int i, int j)
{
  parent[i] = j;
}

/*�o�Ө�Ʒ|�b�������X���j�M�Ѽƫ��w�����������Ӷ��X�öǦ^�Ӷ��X�����*/ 
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
  printf("�`�I0�Ҧb�����X����ڬ��`�I%d\n", find(0));
  printf("�`�I3�Ҧb�����X����ڬ��`�I%d\n", find(3));
  printf("�`�I7�Ҧb�����X����ڬ��`�I%d\n", find(7));
  getchar();      
}
