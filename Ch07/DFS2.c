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

/*這個函數會印出圖形的深度優先搜尋結果*/
dfs(int v)
{
  vertex_pointer tmp;
  
  visited[v] = TRUE;
  printf("%c ", v + 'A');
  for(tmp = graph[v]; tmp; tmp = tmp->next)
    if (visited[tmp->vertex - 'A'] == FALSE)      
      dfs(tmp->vertex - 'A');
}

/*主程式*/ 
main()
{
  create_adlist();   
  printf("圖形的相鄰串列：\n");
  show_adlist();
  printf("深度優先搜尋結果：");
  dfs(0);
  getchar();
}
