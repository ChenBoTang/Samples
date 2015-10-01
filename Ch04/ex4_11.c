/*定義堆疊最多可以存放MAX_SIZE個元素*/
#define MAX_SIZE 100

/*宣告stack是堆疊資料結構*/
typedef struct stk{
  char data[MAX_SIZE];			/*存放堆疊的元素*/
  int top;			        	/*記錄堆疊的頂端*/
}stack;

/*宣告一個堆疊S存放運算子和左括號*/
stack S;

/*這個函數會將參數推入堆疊*/
push(char c)
{
    if (S.top < MAX_SIZE - 1) S.data[++S.top] = c;
}

/*這個函數會從堆疊彈出一個元素並存放在參數指定的位址*/ 
pop(char *c)
{
    if (S.top > -1) *c = S.data[S.top--];
}

/*這個函數會檢查參數是否為運算子，是的話，傳回1，否的話，傳回0*/ 
int is_operator(char c)
{
   if ((c == '+')||(c == '-')||(c == '*')||(c == '/')) return 1;
   else return 0; 
}

/*這個函數會檢查參數是否為運算元，是的話，傳回1，否的話，傳回0*/ 
int is_operand(char c)
{
  if (c >= 'a' && c <= 'z') return 1;
  else return 0;
}  

/*這個函數會根據參數指定的運算子傳回其優先順序*/ 
int get_precedence(char c)
{
    switch(c){
      case '(': return 0;
      case '+': return 1;
      case '-': return 1;
      case '*': return 2;
      case '/': return 2;
      default:  return -1;                                
    }          
}

/*這個函數會將中序表示法轉換為後序表示法*/ 
infix_to_postfix(char *infix, char *postfix)
{
    int i = 0, j = 0;
    char token, item;

    while((token = infix[i++]) != '\0')
    {
	  if (is_operand(token))
		postfix[j++] = token;
	  else if (token == '(')
		push(token);
	  else if (token == ')')
		while (S.top > -1){
		  pop(&item);
		  if (item == '(')	break;
		  postfix[j++] = item;
		}
	  else if (is_operator(token)){
		while (S.top > -1){
          if (get_precedence(token) > get_precedence(S.data[S.top])) break;
          else{
		    pop(&item);
			postfix[j++] = item;
		  }
	    }
		push(token);
	  }
    }
    
    while(S.top > -1)
    {
		pop(&item);
		postfix[j++] = item;
    }
    postfix[j] = '\0';
}

/*主程式*/
main()
{
    char infix[MAX_SIZE] = "a*(b+c)-d";  /*宣告中序表示法為 "a*(b+c)-d"*/ 
    char postfix[MAX_SIZE];              /*宣告用來存放後序表示法的變數*/                   
    infix_to_postfix(infix, postfix);    /*呼叫函數將中序表示法轉換成後序表示法*/ 
    printf("%s轉換為後序表示法會得到%s", infix, postfix);               /*印出後序表示法的結果*/ 
    getchar();
}
