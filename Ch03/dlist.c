#include <stdio.h>
#include <stdlib.h>

/*宣告dlist_node是環狀雙向鏈結串列的節點*/
typedef struct dnode{
  struct dnode *llink;		/*節點的左鏈結欄位*/
  int data;							/*節點的資料欄位*/
  struct dnode *rlink;			/*節點的右鏈結欄位*/
}dlist_node;

/*宣告dlist_pointer是指向節點的指標*/
typedef dlist_node *dlist_pointer;

/*宣告兩個指標，分別指向環狀雙向鏈結串列的首節點及目前節點*/
dlist_pointer head, current;

/*這個函數會將串列初始化*/
initialize()
{
  head = (dlist_pointer)malloc(sizeof(dlist_node));
  head->llink = head;
  head->rlink = head;            
}

/*這個函數會依照由大到小的順序將參數值插入串列*/ 
insert(int value)
{
  dlist_pointer ptr;         
  ptr = (dlist_pointer)malloc(sizeof(dlist_node));
  ptr->data = value;
  current = head->rlink;
  while((current != head) && (current->data > ptr->data))
    current = current->rlink;
  ptr->llink = current->llink; 
  ptr->rlink = current;
  current->llink->rlink = ptr;
  current->llink = ptr;
}

/*這個函數會在串列內刪除data欄位等於參數值的節點*/ 
delete(int value)
{
  if(head->rlink == head)
    printf("串列是空的無法做刪除\n");
  else{
    current = head->rlink;   
    while((current != head) && (current->data != value))
      current = current->rlink;
    if(current != head){
      current->llink->rlink = current->rlink;
      current->rlink->llink = current->llink;
      free(current);
    }           
    else printf("%d 不存在無法做刪除\n", value);
  } 
}

/*這個函數會印出串列內所有節點的data欄位*/ 
traverse()
{
  if(head->rlink == head)
    printf("串列是空的無法印出");
  else{
    current = head->rlink;
    while(current != head){
      printf("%d ", current->data);
      current = current->rlink;            
    }  
  }
}

main()
{
  initialize();
  insert(10);
  insert(20);
  insert(30);
  insert(25);
  insert(50);
  delete(30);
  insert(80);
  insert(5);
  delete(25);
  insert(60);
  traverse();    
  getchar();
}
