/*�w�q�ϧΪ����I�ӼƬ�6*/
#define V 6
/*�w�q�ϧΪ���Ƭ�10*/
#define E 10

/*�ŧiedge���c�ΨӦs����*/
typedef struct e{
  int Vi;		/*�䪺�_�I*/
  int Vj;		/*�䪺���I*/
  int cost;	    /*�䪺�v��*/
  int selected;	/*�䪺���A�A0��ܥ��Q�Ҽ{�A1��ܤw�Q����A2��ܤw�Q�ư�*/
}edge;

/*�ŧiedges[]�}�C�ΨӦs��ϧΪ��Ҧ���*/
edge edges[E];

/*�ŧiparent[]�}�C�ΨӦs�񤬥����X�A���I1 ~ 6�N�s��b���ެ�1 ~ 6����m*/ 
int parent[V];

/*�ŧigraph[][]�}�C�A�H�ڦ��]�wedges[]���Ҧ��䪺�_�I,���I,�v���Ϊ��A*/ 
int graph[E][4] = {0, 1, 6, 0,
               0, 4, 19, 0,
               0, 5, 21, 0,
               1, 2, 5, 0,
               1, 3, 16, 0,
               1, 5, 11, 0,
               2, 3, 10, 0,
               3, 4, 8, 0,
               3, 5, 9, 0,
               4, 5, 7, 0};


/*�o�Ө�Ʒ|��@Kruskal's Algorithm*/
kruskal()
{
  int e_index;                 /*�o���ܼƥΨӰO���ثe����*/
  int e_num = 0;               /*�o���ܼƥΨӰO���w�g�������ơA��l�Ȭ�0*/ 
  
  while(e_num < V - 1){
    e_index = select_edge();   /*������Q�Ҽ{�B�v���̤p����*/
    if (cycle(e_index) == 0){  /*�Y�N����[�J�X�i�𤣷|�y���`��*/ 
      add_edge(e_index);       /*�N����[�J�X�i��*/
      e_num++;                 /*�N�w�g�������ƻ��W1*/
    }
    else edges[e_index].selected = 2; /*�_�h�N����ư�*/
  }
  show_spanningtree();          /*��̤ܳp�����X�i��*/ 
}

/*�o�Ө�Ʒ|�q�|���Ҽ{�L���䤤����v���̤p�̡A�M��Ǧ^�����*/
int select_edge()
{
  int i;
  int e_index = 0;
  int mincost = 32767;
  for(i = 0; i < E; i++)
    if ((edges[i].selected == 0) && (edges[i].cost < mincost)){
      e_index = i;
      mincost = edges[i].cost;
    }   
  return e_index;      
}

/*�o�Ө�Ʒ|�b�������X���j�M�Ѽƫ��w�����������Ӷ��X�öǦ^�Ӷ��X�����*/ 
int find(int i)
{
  while(parent[i] > 0)
    i = parent[i];
  return i;           
}

/*�o�Ө�Ʒ|�ˬd�[�J����O�_�y���`���A�O���ܶǦ^1�A�_���ܶǦ^0*/
int cycle(int e_index)
{
  int i = find(edges[e_index].Vi);/*��X�䪺�_�I�Ҧb�����X�����*/ 
  int j = find(edges[e_index].Vj);/*��X�䪺���I�Ҧb�����X�����*/
  if (i == j) return 1;     /*�Y��ڬۦP�A��ܦ��ۦP���X�A�|�y���`���A�G�Ǧ^1*/ 
  return 0;                 /*�_�h�Ǧ^0*/ 
}

/*�o�Ө�Ʒ|�N��[�J���X�üХܬ��w���*/ 
add_edge(int e_index)
{
  int i = find(edges[e_index].Vi);/*��X�䪺�_�I�Ҧb�����X�����*/ 
  int j = find(edges[e_index].Vj);/*��X�䪺���I�Ҧb�����X�����*/
  parent[i] = j;		    /*�Ni�����`�I�]�w��j�A�Y�O�Ĥ@�Ӷ��X�����ĤG�Ӷ��X���l��*/
  edges[e_index].selected = 1;  /*�N����Хܬ��w���*/  
}

/*�o�Ө�Ʒ|��̤ܳp�����X�i������v���`�M*/
show_spanningtree()
{
  int i;
  int totalcost = 0;
  printf("�Q������䬰 ");
  for(i = 0; i < E; i++)
    if(edges[i].selected == 1){
      printf("(%d, %d) ", edges[i].Vi, edges[i].Vj);                   
      totalcost += edges[i].cost;                  
    }
  printf("\n�̤p�����X�i���v���`�M��%d", totalcost);  
}

/*�D�{��*/ 
main()
{
  int i;
  /*�N�ΨӦs�񤬥����X���}�C��l��*/ 
  for(i = 0; i < V; i++)
    parent[i] = -1;
  /*�N�ϧΪ����Jedges[]�}�C�å[�H��l��*/
  for(i = 0; i < E; i++){
    edges[i].Vi = graph[i][0];
    edges[i].Vj = graph[i][1];
    edges[i].cost = graph[i][2];
    edges[i].selected = graph[i][3];
  }  
  kruskal();
  getchar();    
}
