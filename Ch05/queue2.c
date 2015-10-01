#include <stdio.h>

/*�ŧilist_node�O��V�쵲��C���`�I*/
typedef struct node{
  int data;							/*�`�I��������*/
  struct node *next;			/*�`�I���쵲���*/
}list_node;

/*�ŧilist_pointer�O���V�`�I������*/
typedef list_node *list_pointer;

/*�ŧi��ӫ��СA���O���V��C���e�ݤΦ�C�����*/
list_pointer front, rear;

/*�o�Ө�Ʒ|�N������J��C�����*/
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

/*�o�Ө�Ʒ|�q��C���e�ݧR������*/
dequeue()
{
  list_pointer ptr;       
  if (front == NULL) printf("��C�w�šI");
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
