#include <stdio.h>
#define TRUE 1          /*若頂點已經拜訪過，就設定為TRUE*/  
#define FALSE 0         /*若頂點尚未拜訪過，就設定為FALSE*/ 
#define MAX_VERTICES 50 /*定義圖形最多有MAX_VERTICES個頂點*/

/*宣告vertex_node是圖形的頂點*/
typedef struct node{
  char vertex;			    /*節點的資料欄位*/
  struct node *next;		/*節點的鏈結欄位*/
}vertex_node;

/*宣告vertex_pointer是指向節點的指標*/
typedef vertex_node *vertex_pointer;

/*宣告用來存放圖形的指標陣列*/ 
vertex_pointer graph[MAX_VERTICES];

/*宣告用來記錄頂點是否已經拜訪過的陣列*/ 
int visited[MAX_VERTICES];

/*宣告圖形的頂點個數為n*/ 
int n = 9;
/*宣告用來表示圖形的相鄰矩陣*/
int admatrix[9][9] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 
                      1, 0, 1, 1, 1, 0, 0, 0, 0,
                      0, 1, 0, 0, 1, 0, 0, 0, 0,
                      0, 1, 0, 0, 1, 1, 0, 0, 0,
                      0, 1, 1, 1, 0, 0, 0, 0, 0,
                      0, 0, 0, 1, 0, 0, 1, 1, 0,
                      0, 0, 0, 0, 0, 1, 0, 1, 0,
                      0, 0, 0, 0, 0, 1, 1, 0, 1,
                      0, 0, 0, 0, 0, 0, 0, 1, 0};

/*定義佇列最多可以存放MAX_SIZE個元素*/
#define MAX_SIZE 50
/*宣告queue是佇列資料結構*/
typedef struct que{
  int data[MAX_SIZE];			/*存放佇列的元素*/
  int front;			      			/*記錄佇列的前端*/
  int rear; 			      			/*記錄佇列的後端*/
}queue;
queue Q;									/*宣告一個佇列Q*/

/*將參數放入佇列，成功的話傳回1，失敗的話傳回0*/ 
int enqueue(int value)
{
  if ((Q.rear + 1) % MAX_SIZE == Q.front) return 0;  /*若佇列已滿，傳回0*/       
  Q.rear = (Q.rear + 1) % MAX_SIZE;		
  Q.data[Q.rear] = value;							
  return 1;
}

/*令參數等於從佇列取出的資料，成功的話傳回1，失敗的話傳回0*/
int dequeue(int *value)
{
  if (Q.front == Q.rear) return 0;     /*若佇列已空，傳回0*/                     
  Q.front = (Q.front + 1) % MAX_SIZE;	
  *value = Q.data[Q.front];					
  return 1;
}

/*這個函數會印出圖形的廣度優先搜尋結果*/
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

/*這個函數會根據圖形的相鄰矩陣建立相鄰串列*/   
create_adlist()
{
  int i, j;
  vertex_pointer ptr, tail;
  
  /*建立headnode並將其設定為尚未尚未拜訪過*/
  for (i = 0; i < n; i++){
    graph[i] = (vertex_pointer)malloc(sizeof(vertex_node)); 
    graph[i]->vertex = i + 'A';
    graph[i]->next = NULL;
    visited[i] = FALSE;
  }    
  
  /*分別針對各個頂點的相鄰頂點建立鏈結串列*/
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (admatrix[i][j] != 0){
        ptr = (vertex_pointer)malloc(sizeof(vertex_node));
        ptr->vertex = j + 'A';
        ptr->next = NULL;
        tail = graph[i];           /*令tail指向headnode*/                       
        while (tail->next != NULL) /*找出該headnode後面的鏈結串列的最後一個節點*/         
          tail = tail->next;
        tail->next = ptr;          /*將新節點插入鏈結串列的尾端*/        
      }   
}

/*這個函數會印出圖形的相鄰串列*/ 
show_adlist()
{
  int i;
  vertex_pointer tmp;
  
  for (i = 0; i < n; i++){
    printf("%c : ", graph[i]->vertex);     /*印出headnode*/ 
    tmp = graph[i]->next;
    while (tmp != NULL){                   /*印出該headnode後面的鏈結串列 (即headnode的相鄰頂點)*/                 
      printf("%c ", tmp->vertex);
      tmp = tmp->next;                  
    }
    printf("\n");
  }     
}


/*主程式*/ 
main()
{
  create_adlist();   
  printf("圖形的相鄰串列：\n");
  show_adlist();
  printf("廣度優先搜尋結果：");
  Q.front = 0;				/*將佇列的前端front初始化為 0*/
  Q.rear = 0; 				/*將佇列的後端rear初始化為 0*/
  bfs(0);                   /*呼叫bfs()函數以A做起始頂點進行廣度優先搜尋*/ 
  getchar();
}
