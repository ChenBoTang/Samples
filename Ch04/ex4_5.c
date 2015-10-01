#include <stdio.h>
#include <stdlib.h>

/*宣告list_node是單向鏈結串列的節點*/
typedef struct node{
  int data;						/*節點的資料欄位*/
  struct node *next;			/*節點的鏈結欄位*/
}list_node;

/*宣告list_pointer是指向節點的指標*/
typedef list_node *list_pointer;

/*宣告兩個指標，分別指向單向鏈結串列的首節點、目前節點*/
list_pointer head, current;

/*這個函數會將串列初始化，即包含首節點的空串列*/
initialize()
{
  head = (list_pointer)malloc(sizeof(list_node));
  head->next = NULL;            
}

/*這個函數會將新節點推入串列前端*/
push(int value)
{
  list_pointer ptr;
  ptr = (list_pointer)malloc(sizeof(list_node));
  if (ptr == NULL)
    printf("記憶體配置失敗！");
  else{  
    ptr->data = value;
    ptr->next = head->next;
    head->next = ptr;    
  }  
}

/*這個函數會彈出串列前端的節點*/
pop()
{
  current = head->next;   
  if (current == NULL)
    printf("串列已空！");
  else{
    printf("%d ", current->data);
    head->next = current->next;
    free(current);
  }       
}

main()
{
  initialize();
  push(10);
  push(20);
  push(30);
  push(40);
  push(50);
  pop();
  pop();
  pop();
  pop();
  getchar();
}
