/*�w�q���|�̦h�i�H�s��MAX_SIZE�Ӥ���*/
#define MAX_SIZE 100

/*�ŧistack�O���|��Ƶ��c*/
typedef struct stk{
  char data[MAX_SIZE];			/*�s����|������*/
  int top;			        	/*�O�����|������*/
}stack;

/*�ŧi�@�Ӱ��|S�s��B��l�M���A��*/
stack S;

/*�o�Ө�Ʒ|�N�ѼƱ��J���|*/
push(char c)
{
    if (S.top < MAX_SIZE - 1) S.data[++S.top] = c;
}

/*�o�Ө�Ʒ|�q���|�u�X�@�Ӥ����æs��b�Ѽƫ��w����}*/ 
pop(char *c)
{
    if (S.top > -1) *c = S.data[S.top--];
}

/*�o�Ө�Ʒ|�ˬd�ѼƬO�_���B��l�A�O���ܡA�Ǧ^1�A�_���ܡA�Ǧ^0*/ 
int is_operator(char c)
{
   if ((c == '+')||(c == '-')||(c == '*')||(c == '/')) return 1;
   else return 0; 
}

/*�o�Ө�Ʒ|�ˬd�ѼƬO�_���B�⤸�A�O���ܡA�Ǧ^1�A�_���ܡA�Ǧ^0*/ 
int is_operand(char c)
{
  if (c >= 'a' && c <= 'z') return 1;
  else return 0;
}  

/*�o�Ө�Ʒ|�ھڰѼƫ��w���B��l�Ǧ^���u������*/ 
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

/*�o�Ө�Ʒ|�N���Ǫ�ܪk�ഫ����Ǫ�ܪk*/ 
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

/*�D�{��*/
main()
{
    char infix[MAX_SIZE] = "a*(b+c)-d";  /*�ŧi���Ǫ�ܪk�� "a*(b+c)-d"*/ 
    char postfix[MAX_SIZE];              /*�ŧi�ΨӦs���Ǫ�ܪk���ܼ�*/                   
    infix_to_postfix(infix, postfix);    /*�I�s��ƱN���Ǫ�ܪk�ഫ����Ǫ�ܪk*/ 
    printf("%s�ഫ����Ǫ�ܪk�|�o��%s", infix, postfix);               /*�L�X��Ǫ�ܪk�����G*/ 
    getchar();
}
