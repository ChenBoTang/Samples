#include <stdio.h>

/*宣告list_node是單向鏈結串列的節點*/
typedef struct node{
  int data;							/*節點的資料欄位*/
  struct node *next;			/*節點的鏈結欄位*/
}list_node;

/*宣告list_pointer是指向節點的指標*/
typedef list_node *list_pointer;

/*宣告兩個指標，分別指向佇列的前端及佇列的後端*/
list_pointer front, rear;

/*這個函數會將元素放入佇列的後端*/
enqueue(int value)
{
  list_pointer ptr;            
  ptr = (list_pointer)malloc(sizeof(list_node));          
  ptr->data = value;
  ptr->next = NULL;
  if (rear == NULL) front = ptr;
  else rear->next = ptr;
  rear = ptr;  
}

/*這個函數會從佇列的前端刪除元素*/
dequeue()
{
  list_pointer ptr;       
  if (front == NULL) printf("佇列已空！");
  else{
    printf("%d ", front->data);
    ptr = front;
    front = front->next;
    free(ptr);   
  }     
}

main()
{
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  enqueue(60);
  enqueue(70);
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  getchar();     
}
