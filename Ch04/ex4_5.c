#include <stdio.h>
#include <stdlib.h>

/*�ŧilist_node�O��V�쵲��C���`�I*/
typedef struct node{
  int data;						/*�`�I��������*/
  struct node *next;			/*�`�I���쵲���*/
}list_node;

/*�ŧilist_pointer�O���V�`�I������*/
typedef list_node *list_pointer;

/*�ŧi��ӫ��СA���O���V��V�쵲��C�����`�I�B�ثe�`�I*/
list_pointer head, current;

/*�o�Ө�Ʒ|�N��C��l�ơA�Y�]�t���`�I���Ŧ�C*/
initialize()
{
  head = (list_pointer)malloc(sizeof(list_node));
  head->next = NULL;            
}

/*�o�Ө�Ʒ|�N�s�`�I���J��C�e��*/
push(int value)
{
  list_pointer ptr;
  ptr = (list_pointer)malloc(sizeof(list_node));
  if (ptr == NULL)
    printf("�O����t�m���ѡI");
  else{  
    ptr->data = value;
    ptr->next = head->next;
    head->next = ptr;    
  }  
}

/*�o�Ө�Ʒ|�u�X��C�e�ݪ��`�I*/
pop()
{
  current = head->next;   
  if (current == NULL)
    printf("��C�w�šI");
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
