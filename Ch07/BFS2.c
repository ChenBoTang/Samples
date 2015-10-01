#include <stdio.h>
#define TRUE 1          /*�Y���I�w�g���X�L�A�N�]�w��TRUE*/  
#define FALSE 0         /*�Y���I�|�����X�L�A�N�]�w��FALSE*/ 
#define MAX_VERTICES 50 /*�w�q�ϧγ̦h��MAX_VERTICES�ӳ��I*/

/*�ŧivertex_node�O�ϧΪ����I*/
typedef struct node{
  char vertex;			    /*�`�I��������*/
  struct node *next;		/*�`�I���쵲���*/
}vertex_node;

/*�ŧivertex_pointer�O���V�`�I������*/
typedef vertex_node *vertex_pointer;

/*�ŧi�ΨӦs��ϧΪ����а}�C*/ 
vertex_pointer graph[MAX_VERTICES];

/*�ŧi�ΨӰO�����I�O�_�w�g���X�L���}�C*/ 
int visited[MAX_VERTICES];

/*�ŧi�ϧΪ����I�ӼƬ�n*/ 
int n = 9;
/*�ŧi�ΨӪ�ܹϧΪ��۾F�x�}*/
int admatrix[9][9] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 
                      1, 0, 1, 1, 1, 0, 0, 0, 0,
                      0, 1, 0, 0, 1, 0, 0, 0, 0,
                      0, 1, 0, 0, 1, 1, 0, 0, 0,
                      0, 1, 1, 1, 0, 0, 0, 0, 0,
                      0, 0, 0, 1, 0, 0, 1, 1, 0,
                      0, 0, 0, 0, 0, 1, 0, 1, 0,
                      0, 0, 0, 0, 0, 1, 1, 0, 1,
                      0, 0, 0, 0, 0, 0, 0, 1, 0};

/*�w�q��C�̦h�i�H�s��MAX_SIZE�Ӥ���*/
#define MAX_SIZE 50
/*�ŧiqueue�O��C��Ƶ��c*/
typedef struct que{
  int data[MAX_SIZE];			/*�s���C������*/
  int front;			      			/*�O����C���e��*/
  int rear; 			      			/*�O����C�����*/
}queue;
queue Q;									/*�ŧi�@�Ӧ�CQ*/

/*�N�ѼƩ�J��C�A���\���ܶǦ^1�A���Ѫ��ܶǦ^0*/ 
int enqueue(int value)
{
  if ((Q.rear + 1) % MAX_SIZE == Q.front) return 0;  /*�Y��C�w���A�Ǧ^0*/       
  Q.rear = (Q.rear + 1) % MAX_SIZE;		
  Q.data[Q.rear] = value;							
  return 1;
}

/*�O�ѼƵ���q��C���X����ơA���\���ܶǦ^1�A���Ѫ��ܶǦ^0*/
int dequeue(int *value)
{
  if (Q.front == Q.rear) return 0;     /*�Y��C�w�šA�Ǧ^0*/                     
  Q.front = (Q.front + 1) % MAX_SIZE;	
  *value = Q.data[Q.front];					
  return 1;
}

/*�o�Ө�Ʒ|�L�X�ϧΪ��s���u���j�M���G*/
bfs(int v)
{
  vertex_pointer tmp;
  
  printf("%c ", v + 'A');
  visited[v] = TRUE; 
  enqueue(v);
  while(dequeue(&v)){
    for(tmp = graph[v]; tmp; tmp = tmp->next)
      if (visited[tmp->vertex - 'A'] == FALSE){
        printf("%c ", tmp->vertex);
        visited[tmp->vertex - 'A'] = TRUE;
        enqueue(tmp->vertex - 'A');
      }
  }
}

/*�o�Ө�Ʒ|�ھڹϧΪ��۾F�x�}�إ߬۾F��C*/   
create_adlist()
{
  int i, j;
  vertex_pointer ptr, tail;
  
  /*�إ�headnode�ñN��]�w���|���|�����X�L*/
  for (i = 0; i < n; i++){
    graph[i] = (vertex_pointer)malloc(sizeof(vertex_node)); 
    graph[i]->vertex = i + 'A';
    graph[i]->next = NULL;
    visited[i] = FALSE;
  }    
  
  /*���O�w��U�ӳ��I���۾F���I�إ��쵲��C*/
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (admatrix[i][j] != 0){
        ptr = (vertex_pointer)malloc(sizeof(vertex_node));
        ptr->vertex = j + 'A';
        ptr->next = NULL;
        tail = graph[i];           /*�Otail���Vheadnode*/                       
        while (tail->next != NULL) /*��X��headnode�᭱���쵲��C���̫�@�Ӹ`�I*/         
          tail = tail->next;
        tail->next = ptr;          /*�N�s�`�I���J�쵲��C������*/        
      }   
}

/*�o�Ө�Ʒ|�L�X�ϧΪ��۾F��C*/ 
show_adlist()
{
  int i;
  vertex_pointer tmp;
  
  for (i = 0; i < n; i++){
    printf("%c : ", graph[i]->vertex);     /*�L�Xheadnode*/ 
    tmp = graph[i]->next;
    while (tmp != NULL){                   /*�L�X��headnode�᭱���쵲��C (�Yheadnode���۾F���I)*/                 
      printf("%c ", tmp->vertex);
      tmp = tmp->next;                  
    }
    printf("\n");
  }     
}


/*�D�{��*/ 
main()
{
  create_adlist();   
  printf("�ϧΪ��۾F��C�G\n");
  show_adlist();
  printf("�s���u���j�M���G�G");
  Q.front = 0;				/*�N��C���e��front��l�Ƭ� 0*/
  Q.rear = 0; 				/*�N��C�����rear��l�Ƭ� 0*/
  bfs(0);                   /*�I�sbfs()��ƥHA���_�l���I�i��s���u���j�M*/ 
  getchar();
}
