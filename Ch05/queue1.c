/*定義佇列最多可以存放MAX_SIZE個元素*/
#define MAX_SIZE 6

/*宣告queue是佇列資料結構*/
typedef struct que{
  int data[MAX_SIZE];			/*存放佇列的元素*/
  int front;			      			/*記錄佇列的前端*/
  int rear; 			      			/*記錄佇列的後端*/
}queue;

queue Q;									/*宣告一個佇列Q*/


enqueue(queue *Q, char value)
{
  /*檢查rear往順時針方向推進一個位置是否會碰到front，是的話，表示佇列已滿*/
  if ((Q->rear + 1) % MAX_SIZE == Q->front)
    printf("佇列已滿！");
  else{
    Q->rear = (Q->rear + 1) % MAX_SIZE;		/*將rear往順時針方向推進一個位置*/
    Q->data[Q->rear] = value;							/*將新元素放入佇列後端*/
  }
}

dequeue(queue *Q)
{
  /*檢查front是否等於rear，是的話，表示佇列已空*/
  if (Q->front == Q->rear)
    printf("佇列已空！");
  else{
    Q->front = (Q->front + 1) % MAX_SIZE;	/*將front往順時針方向推進一個位置*/
    printf("%c ", Q->data[Q->front]);					/*印出佇列前端的元素*/
  }
}

main()
{
  Q.front = 0;								/*將變數front的初始值設定為 0*/
  Q.rear = 0; 								/*將變數rear的初始值設定為 0*/    
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
