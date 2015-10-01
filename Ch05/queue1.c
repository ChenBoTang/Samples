/*�w�q��C�̦h�i�H�s��MAX_SIZE�Ӥ���*/
#define MAX_SIZE 6

/*�ŧiqueue�O��C��Ƶ��c*/
typedef struct que{
  int data[MAX_SIZE];			/*�s���C������*/
  int front;			      			/*�O����C���e��*/
  int rear; 			      			/*�O����C�����*/
}queue;

queue Q;									/*�ŧi�@�Ӧ�CQ*/


enqueue(queue *Q, char value)
{
  /*�ˬdrear�����ɰw��V���i�@�Ӧ�m�O�_�|�I��front�A�O���ܡA��ܦ�C�w��*/
  if ((Q->rear + 1) % MAX_SIZE == Q->front)
    printf("��C�w���I");
  else{
    Q->rear = (Q->rear + 1) % MAX_SIZE;		/*�Nrear�����ɰw��V���i�@�Ӧ�m*/
    Q->data[Q->rear] = value;							/*�N�s������J��C���*/
  }
}

dequeue(queue *Q)
{
  /*�ˬdfront�O�_����rear�A�O���ܡA��ܦ�C�w��*/
  if (Q->front == Q->rear)
    printf("��C�w�šI");
  else{
    Q->front = (Q->front + 1) % MAX_SIZE;	/*�Nfront�����ɰw��V���i�@�Ӧ�m*/
    printf("%c ", Q->data[Q->front]);					/*�L�X��C�e�ݪ�����*/
  }
}

main()
{
  Q.front = 0;								/*�N�ܼ�front����l�ȳ]�w�� 0*/
  Q.rear = 0; 								/*�N�ܼ�rear����l�ȳ]�w�� 0*/    
  enqueue(&Q, 'A');
  enqueue(&Q, 'B');
  enqueue(&Q, 'C');
  enqueue(&Q, 'D');
  dequeue(&Q);
  dequeue(&Q);
  enqueue(&Q, 'E');
  enqueue(&Q, 'F');
  enqueue(&Q, 'G');
  getchar();      
}
