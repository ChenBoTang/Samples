#include <stdio.h>
#include <stdlib.h>

/*�ŧidlist_node�O�������V�쵲��C���`�I*/
typedef struct dnode{
  struct dnode *llink;		/*�`�I�����쵲���*/
  int data;							/*�`�I��������*/
  struct dnode *rlink;			/*�`�I���k�쵲���*/
}dlist_node;

/*�ŧidlist_pointer�O���V�`�I������*/
typedef dlist_node *dlist_pointer;

/*�ŧi��ӫ��СA���O���V�������V�쵲��C�����`�I�Υثe�`�I*/
dlist_pointer head, current;

/*�o�Ө�Ʒ|�N��C��l��*/
initialize()
{
  head = (dlist_pointer)malloc(sizeof(dlist_node));
  head->llink = head;
  head->rlink = head;            
}

/*�o�Ө�Ʒ|�̷ӥѤj��p�����ǱN�Ѽƭȴ��J��C*/ 
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

/*�o�Ө�Ʒ|�b��C���R��data��쵥��ѼƭȪ��`�I*/ 
delete(int value)
{
  if(head->rlink == head)
    printf("��C�O�Ū��L�k���R��\n");
  else{
    current = head->rlink;   
    while((current != head) && (current->data != value))
      current = current->rlink;
    if(current != head){
      current->llink->rlink = current->rlink;
      current->rlink->llink = current->llink;
      free(current);
    }           
    else printf("%d ���s�b�L�k���R��\n", value);
  } 
}

/*�o�Ө�Ʒ|�L�X��C���Ҧ��`�I��data���*/ 
traverse()
{
  if(head->rlink == head)
    printf("��C�O�Ū��L�k�L�X");
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
