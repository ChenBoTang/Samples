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

/*�o�Ө�Ʒ|�L�X�ϧΪ��`���u���j�M���G*/
dfs(int v)
{
  vertex_pointer tmp;
  
  visited[v] = TRUE;
  printf("%c ", v + 'A');
  for(tmp = graph[v]; tmp; tmp = tmp->next)
    if (visited[tmp->vertex - 'A'] == FALSE)      
      dfs(tmp->vertex - 'A');
}

/*�D�{��*/ 
main()
{
  create_adlist();   
  printf("�ϧΪ��۾F��C�G\n");
  show_adlist();
  printf("�`���u���j�M���G�G");
  dfs(0);
  getchar();
}
