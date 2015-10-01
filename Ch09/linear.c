#define b 13          /*定義雜湊表的大小為13*/
#define EMPTY -32768  /*定義雜湊表的空位為EMPTY*/


/*使用線性探測法將鍵值key放入雜湊表ht*/ 
int linear_probe(int ht[], int key)
{
  int address;
  address = key % b;              /*將鍵值轉換為位址*/
  while(ht[address] != EMPTY)     /*當發生碰撞時*/ 
    address = (address + 1) % b;  /*往下一個位址探測*/
  ht[address] = key;   
}

int linear_search(int ht[], int key)
{
  int address;
  address = key % b;              /*將鍵值轉換為位址*/
  while(ht[address] != key){       /*當不等於鍵值時*/  
    address = (address + 1) % b;  /*往下一個位址探測*/
    if (ht[address] == EMPTY || address == key % b) /*若為空位或返回原處*/
    return -1;                                      /*表示搜尋失敗*/ 
  }
  return address;  
}

/*主程式*/
main()
{
  int ht[b];                  /*宣告ht[]為雜湊表*/
  int i;
  for(i = 0; i < b; i++)      /*將雜湊表初始化為EMPTY*/
    ht[i] = EMPTY;
  linear_probe(ht, 13);       /*將鍵值放入雜湊表*/
  linear_probe(ht, 14);
  linear_probe(ht, 26);
  linear_probe(ht, 39);
  linear_probe(ht, 45);
  linear_probe(ht, 32);
  for(i = 0; i < b; i++)     /*印出雜湊表的內容*/  
    printf("%d\n", ht[i]);
  getchar();  
}



