/*�w�q���V�ϧΪ����I�ӼƬ�8*/
#define V 8

/*�ŧiadmatrix[][]�}�C�s�񦳦V�ϧΪ��۾F�x�}*/ 
int admatrix[V][V] = {0, 1, 1, 1, 0, 0, 0, 0,
                      0, 0, 0, 0, 1, 1, 0, 0,
                      0, 0, 0, 0, 0, 1, 0, 0,
                      0, 0, 0, 0, 0, 0, 1, 0,
                      0, 0, 0, 0, 0, 1, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 1,
                      0, 0, 0, 0, 0, 0, 0, 1,
                      0, 0, 0, 0, 0, 0, 0, 0};

int indegree[V];  /*�O���C�ӳ��I���i�J�����*/
int outputed[V];  /*�O���C�ӳ��I�O�_�w�g��X�A1��ܬO�A0��ܧ_*/                   


/*�o�Ө�Ʒ|��@�ݾ�Ƨ�*/
topology_sort()
{
  int i, j, Vx;
  
  for (i = 0; i < V; i++){          /*�N�}�C��l��*/
    indegree[i] = 0;
    outputed[i] = 0;  
  }
      
  for (i = 0; i < V; i++)          /*�p��C�ӳ��I���i�J�����*/
    for (j = 0; j < V; j++)
      if (admatrix[i][j] == 1)
        indegree[j]++;
      
  for (i = 0; i < V; i++){         /*�ݾ�ƧǪ��j�饲������V���~�൲��*/
    Vx = select_vertex();          /*��ܩ|���Q��X�B�S���e��̪����I*/ 
    printf("V%d ", Vx);            /*��X�ӳ��I�üХܬ��w�g��X*/
    outputed[Vx] = 1; 
    for (j = 0; j < V; j++)        /*�N�ӳ��I�ҳs���X�h����R��*/ 
      if (admatrix[Vx][j] == 1){    
        admatrix[Vx][j] = 0;                  
        indegree[j]--;
      }
  }    
}

/*�o�Ө�Ʒ|��ܨS���e��̪����I�A�Y�|���Q��X�B�i�J����׬�0�����I*/
select_vertex()
{
  int i;
  for (i = 0; i < V; i++)
    if (outputed[i] == 0 && indegree[i] == 0)
      return i;                             
}

/*�D�{��*/ 
main()
{
  topology_sort();
  getchar();    
}
