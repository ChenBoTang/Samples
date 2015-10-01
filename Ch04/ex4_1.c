/*�w�q���|�̦h�i�H�s��MAX_SIZE�Ӹ��*/
#define MAX_SIZE 5
		
/*�ŧistack�O���|��Ƶ��c*/
typedef struct stk{
  char data[MAX_SIZE];			/*�s����|������*/
  int top;			            /*�O�����|������*/
}stack;

int isFull(stack *S)
{
  if (S->top == (MAX_SIZE - 1)) return 1;
  else return 0;
}

int isEmpty(stack *S)
{
  if (S->top == -1) return 1;
  else return 0;
}

push(stack *S, char value)
{
  if (isFull(S)) printf("���|�w���I");
  else S->data[++S->top] = value;
}

pop(stack *S)
{
  if (isEmpty(S)) printf("���|�w�šI");
  else printf("%c ", S->data[S->top--]);
}

main()
{
  stack S;
  S.top = -1;
  push(&S, 'A');
  push(&S, 'B');
  push(&S, 'C');
  push(&S, 'D');
  push(&S, 'E');
  push(&S, 'F');
  pop(&S);
  pop(&S);
  pop(&S);
  pop(&S);
  pop(&S);
  pop(&S);    
  getchar();
}
