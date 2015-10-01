/*定義堆疊最多可以存放MAX_SIZE個資料*/
#define MAX_SIZE 5
		
/*宣告stack是堆疊資料結構*/
typedef struct stk{
  char data[MAX_SIZE];			/*存放堆疊的項目*/
  int top;			            /*記錄堆疊的頂端*/
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
  if (isFull(S)) printf("堆疊已滿！");
  else S->data[++S->top] = value;
}

pop(stack *S)
{
  if (isEmpty(S)) printf("堆疊已空！");
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
