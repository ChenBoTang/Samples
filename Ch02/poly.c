/*�������ΨӤ��x�By�A�Yx < y�A�Ǧ^ -1�F�Yx == y�A�Ǧ^0�F�Y x > y�A�Ǧ^1*/
#define COMPARE(x, y) (((x) < (y)) ? -1: ((x) == (y)) ? 0: 1)
#define MAX_SIZE 100							/*�w�q�h�����̦h�]�tMAX_SIZE�ӫD�s��*/
typedef struct{										/*�w�q��ܫD�s�������c*/
  int coef;												/*�D�s�����Y��*/
  int exp;												/*�D�s����򻦸*/
}NonZeroTerm;

typedef struct{										/*�w�q��ܦh���������c*/
  int count;											/*�D�s�����Ӽ�*/
  NonZeroTerm terms[MAX_SIZE];		/*�D�s��*/
}Polynomial;

main()
{
  Polynomial A, B, C;
  A.count = 0;
  attach(&A, 3, 5);
  attach(&A, 8, 4); 
  attach(&A, -6, 2);
  attach(&A, 5, 0);
  B.count = 0;
  attach(&B, 2, 6);
  attach(&B, 4, 2); 
  attach(&B, 1, 0);
  PolyAdd(&A, &B, &C);
  /*�L�X�h����C(X)�����G*/
  int i;
  printf("�h����C(X)���D�s����%d��\n", C.count);
  for(i = 0; i < C.count; i++)
    printf("��%d�ӫD�s�����Y�ơG%d\t򻦸�G%d\n", i+1, C.terms[i].coef, C.terms[i].exp);
  getchar();
}

/*�o�Ө�Ʒ|�b�h�����[�J�@�ӫD�s��*/
attach(Polynomial *ptr, int coef, int exp)
{
  if (ptr->count >= MAX_SIZE) return;
  ptr->terms[ptr->count].coef = coef;
  ptr->terms[ptr->count].exp = exp;
  ptr->count++;                 
}

/*�o�Ө�Ʒ|�N��Ӧh�����ۥ[�AA(X) + B(X) = C(X)*/ 
PolyAdd(Polynomial *pA, Polynomial *pB, Polynomial *pC)
{
  int currentA = 0, currentB = 0;
  pC->count = 0;                
  while(currentA < pA->count && currentB < pB->count){
    switch(COMPARE(pA->terms[currentA].exp, pB->terms[currentB].exp)){
      case -1:       /*��A��򻦸�p��B��򻦸�ɡA�NB���D�s���[�J�h����*/
        attach(pC, pB->terms[currentB].coef, pB->terms[currentB].exp);
        currentB++;
        break;
      case 0:       /*��A��򻦸����B��򻦸�ɡA�N��̬ۥ[�᪺�D�s���[�J�h����*/
        if((pA->terms[currentA].coef + pB->terms[currentB].coef) != 0)
         attach(pC, pA->terms[currentA].coef + pB->terms[currentB].coef, pA->terms[currentA].exp);
         currentA++;
         currentB++;
         break;
       case 1:      /*��A��򻦸�j��B��򻦸�ɡA�NA���D�s���[�J�h����*/
         attach(pC, pA->terms[currentA].coef, pA->terms[currentA].exp);
         currentA++;
    }
  }  
  while(currentA < pA->count){  /*�NA�ѤU���D�s���[�J�h����*/
    attach(pC, pA->terms[currentA].coef, pA->terms[currentA].exp);
    currentA++;
  }                           
  while(currentB < pB->count){  /*�NB�ѤU���D�s���[�J�h����*/
    attach(pC, pB->terms[currentB].coef, pB->terms[currentB].exp);
    currentB++;
  }                    
}
