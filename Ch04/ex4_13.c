/*�w�q���|�̦h�i�H�s��MAX_SIZE�Ӥ���*/
#define MAX_SIZE 100

/*�ŧistack�O���|��Ƶ��c*/
typedef struct stk{
  float data[MAX_SIZE];			/*�s����|������*/
  int top;			        	/*�O�����|������*/
}stack;

/*�ŧi�@�Ӱ��|S�s��B�⤸*/
stack S;

/*�o�Ө�Ʒ|�N�ѼƱ��J���|*/
push(float f)
{
    if (S.top < MAX_SIZE - 1) S.data[++S.top] = f;
}

/*�o�Ө�Ʒ|�q���|�u�X�@�Ӥ����æs��b�Ѽƫ��w����}*/ 
pop(float *f)
{
    if (S.top > -1) *f = S.data[S.top--];
}

/*�o�Ө�Ʒ|�ˬd�ѼƬO�_���B�⤸�A�O���ܡA�Ǧ^1�A�_���ܡA�Ǧ^0*/ 
int is_operand(char c)
{
  if (c >= 'a' && c <= 'z') return 1;
  else return 0;
}  

/*���w�B�⤸���ȡA���B�O�Na,b,...k���Ȧs��b�}�Cop[]�ó]�w��5,6,...,15*/
float op[] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

float eval_postfix(char *postfix)
{
    int i = 0;
    char token;
    float op1, op2, result;
    
    while((token = postfix[i++]) != '\0'){
      if(is_operand(token))
		push(op[token - 'a']);
	  else{
		pop(&op2);
		pop(&op1);
        switch(token){
	      case '+':
            result = op1 + op2;
		    break;
	      case '-':
            result = op1 - op2;
		    break;
	      case '*':
            result = op1 * op2;
		    break;
	      case '/':
            result = op1 / op2;
		    break;
        }
		push(result);
	  }
    }
    pop(&result);
    return(result);
}

/*�D�{��*/
main()
{
    char postfix[MAX_SIZE] = "abc+*d-";  /*�ŧi��Ǫ�ܪk�� "abc+*d-"*/ 
    printf("���]a = 5�Bb = 6�Bc = 7�Bd = 8�A�habc+*d-���Ȭ�%f", eval_postfix(postfix));
    getchar();
}
