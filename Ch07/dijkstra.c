/*�w�q�[�v�ϧΪ����I�ӼƬ�8*/
#define V 8

/*�w�q �۪��Ȭ�32767*/
#define INFINITE 32767

/*�ŧiadmatrix[][]�}�C�s��[�v�ϧΪ��۾F�x�}*/ 
int admatrix[V][V] = {0, 7, 3, INFINITE, INFINITE, INFINITE, INFINITE, INFINITE,
                      7, 0, INFINITE, 12, INFINITE, INFINITE, INFINITE, INFINITE,
                      3, INFINITE, 0, 9, 17, 10, INFINITE, INFINITE,
                      INFINITE, 12, 9, 0, INFINITE, INFINITE, INFINITE, 14,
                      INFINITE, INFINITE, 17, INFINITE, 0, INFINITE, INFINITE, INFINITE,
                      INFINITE, INFINITE, 10, INFINITE, INFINITE, 0, 1, 11,
                      INFINITE, INFINITE, INFINITE, INFINITE, INFINITE, 1, 0, 15,
                      INFINITE, INFINITE, INFINITE, 14, INFINITE, 11, 15, 0};

int distance[V];  /*�s��_�l���I��䥦�U�I���̵u�Z��*/
int selected[V];  /*�O�����I���̵u���|�O�_�w�g�M�w�A1��ܬO�A0��ܧ_*/ 
int previous[V];  /*�O���U�ӳ��I�̵u���|�����e�@�ӳ��I*/ 

/*�o�Ө�Ʒ|��@Dijkstra�t��k�A�Ѽ�Vs��ܰ_�l���I*/
dijkstra(int Vs)
{
  int i, Vx, Vi;
  for(i = 0; i < V; i++){          /*�N�U�C�}�C��l��*/ 
    distance[i] = admatrix[Vs][i]; 
    selected[i] = 0;
    previous[i] = Vs;
  }
  selected[Vs] = 1;                /*�N�_�l���I�O�����w�g���*/       
          
  for(i = 0; i < V - 1; i++){      /*�O�j�魫��V-1��*/
    Vx = select_shortest();
    selected[Vx] = 1;
    for(Vi = 0; Vi < V; Vi++)
      if (selected[Vi] == 0 && (distance[Vi] > distance[Vx] + admatrix[Vx][Vi])){
        distance[Vi] = distance[Vx] + admatrix[Vx][Vi];
        previous[Vi] = Vx;
      }
  }      
}

/*�o�Ө�Ʒ|�q�|����ܪ����I����ܶZ���̵u�̡A�M��Ǧ^�����*/
int select_shortest()
{
  int i, Vx, shortest = 32767;
  for(i = 0; i < V; i++)
    if (selected[i] == 0 && distance[i] < shortest){
      Vx = i;
      shortest = distance[i];
    }   
  return Vx;      
}

/*�D�{��*/ 
main()
{

  int Vs = 0;   /*Vs���_�l���I*/
  int Vi, i;
  
  dijkstra(Vs);
  
  for(Vi = 0; Vi < V; Vi++){
 	if (Vi == Vs) continue;
	  printf("V%d��V%d���̵u�Z����%d,\t���|��V%d-->",Vs, Vi, distance[Vi], Vi);
      for(i = previous[Vi]; i != Vs ; i = previous[i])
        printf("V%d-->", i);
      printf("V%d\n", Vs);
    }  
  getchar();    
}
