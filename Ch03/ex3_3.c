#include <stdio.h>

/*�ŧilist_node�O��V�쵲��C���`�I*/
typedef struct node{
  int data;					/*�`�I��������*/
  struct node *next;		/*�`�I���쵲���*/
}list_node;

/*�ŧilist_pointer�O���V�`�I������*/
typedef list_node *list_pointer;

/*�ŧi�T�ӫ��СA���O���V��V�쵲��C�����`�I�B�ثe�`�I�Ϋe�@�Ӹ`�I*/
list_pointer head, current, previous;

/*�o�Ө�Ʒ|�N��C��l�ơA�Y�]�t���`�I���Ŧ�C*/
initialize()
{
  head = (list_pointer)malloc(sizeof(list_node));
  head->next = NULL; 
}

/*�o�Ө�Ʒ|�̷ӥѤj��p�����ǱN�Ѽ�value���w���ȴ��J��C*/ 
insert(int value)
{
  list_pointer ptr; 
   ptr = (list_pointer)malloc(sizeof(list_node));
  ptr->data = value;
  previous = head;
  current = head->next;
  while((current != NULL) && (current->data > ptr->data)){
    previous = current;
    current = current->next;
  }
  ptr->next = current;
  previous->next = ptr;
}

/*�o�Ө�Ʒ|�L�X��C���Ҧ��`�I��data���*/ 
traverse()
{
  if(head->next == NULL)
    printf("��C�O�Ū��L�k�L�X");
  else{
    current = head->next;
    while(current != NULL){
      printf("%d ", current->data);
      current = current->next; 
    }  
  }
}

/*�D�{��*/
main()
{
  initialize();		/*�N��C��l�Ƭ��]�t���`�I���Ŧ�C*/
  insert(30);		/*���J30*/
  insert(20); 	/*���J20*/
  insert(80); 	/*���J80*/
  insert(50);		/*���J50*/
  traverse();		/*�̷Ӷ��ǦL�X�Ҧ��`�I*/
  getchar();
}
