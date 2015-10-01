#include <stdio.h>

#define b 13                 /*�w�q�����O��13�Ӧ�C�Ҳզ�*/ 
#define EMPTY -32768         /*�w�q������Ŧ쬰EMPTY*/

/*�ŧilist_node�O��V�쵲��C���`�I*/
typedef struct node{
  int key;				    /*�`�I��������*/
  struct node *next;		/*�`�I���쵲���*/
}list_node;

/*�ŧilist_pointer�O���V�`�I������*/
typedef list_node *list_pointer;

/*�ŧi�����ht�O��b�Ӧ�C�Ҳզ�*/
list_pointer ht[b];                                                

/*�o�Ө�Ʒ|�N������l��*/
initialize()
{
  int i;
  for(i = 0; i < b; i++){
    ht[i] = (list_pointer)malloc(sizeof(list_node));              
    ht[i]->key = EMPTY;
    ht[i]->next = NULL;
  }  
}

/*�o�Ө�Ʒ|�N��ȳz�L�������ഫ����}*/
int hash(int key)
{
  return key % b;  
}

/*�o�Ө�Ʒ|�N�ھڦ�}�N��Ȧs��b��������C*/ 
insert(int key)
{
  int address;
  list_pointer ptr, tmp;         
  ptr = (list_pointer)malloc(sizeof(list_node));  /*�t�m�O����Ŷ����s�`�I*/
  ptr->key = key;                                 /*�N��Ȧs��b�s�`�I*/ 
  ptr->next = NULL;                               /*�O�s�`�I���VNULL*/ 
  address = hash(key);                            /*�N��ȳz�L�������ഫ����}*/  
  tmp = ht[address];                              /*�ھڦ�}�Otmp���V�Ӧ�C���}�Y*/ 
  while(tmp->next != NULL)                        /*�Otmp���V�Ӧ�C������*/
    tmp = tmp->next;                             
  tmp->next = ptr;                                /*�Otmp���V�s�`�I*/
}

/*�o�Ө�Ʒ|�L�X������Ҧ����*/ 
show()
{
  int i;
  list_pointer tmp;
  for(i = 0; i < b; i++){
    printf("ht[%d]:\t", i);
    tmp = ht[i];
    do{
      if(tmp->key != EMPTY) printf("%d\t", tmp->key);
      if(tmp->next == NULL) break;
      tmp = tmp->next;
    }while(1);  
    printf("\n");  
  }    
}


/*�D�{��*/
main()
{
  initialize();
  insert(13);
  insert(14);
  insert(26);
  insert(60);
  insert(39);
  insert(40);
  insert(86);
  insert(15);
  insert(25);
  show();
  getchar();  
}



