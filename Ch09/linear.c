#define b 13          /*�w�q������j�p��13*/
#define EMPTY -32768  /*�w�q������Ŧ쬰EMPTY*/


/*�ϥνu�ʱ����k�N���key��J�����ht*/ 
int linear_probe(int ht[], int key)
{
  int address;
  address = key % b;              /*�N����ഫ����}*/
  while(ht[address] != EMPTY)     /*��o�͸I����*/ 
    address = (address + 1) % b;  /*���U�@�Ӧ�}����*/
  ht[address] = key;   
}

int linear_search(int ht[], int key)
{
  int address;
  address = key % b;              /*�N����ഫ����}*/
  while(ht[address] != key){       /*��������Ȯ�*/  
    address = (address + 1) % b;  /*���U�@�Ӧ�}����*/
    if (ht[address] == EMPTY || address == key % b) /*�Y���Ŧ�Ϊ�^��B*/
    return -1;                                      /*��ܷj�M����*/ 
  }
  return address;  
}

/*�D�{��*/
main()
{
  int ht[b];                  /*�ŧiht[]�������*/
  int i;
  for(i = 0; i < b; i++)      /*�N������l�Ƭ�EMPTY*/
    ht[i] = EMPTY;
  linear_probe(ht, 13);       /*�N��ȩ�J�����*/
  linear_probe(ht, 14);
  linear_probe(ht, 26);
  linear_probe(ht, 39);
  linear_probe(ht, 45);
  linear_probe(ht, 32);
  for(i = 0; i < b; i++)     /*�L�X��������e*/  
    printf("%d\n", ht[i]);
  getchar();  
}



