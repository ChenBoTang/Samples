#include <stdio.h>

/*�������ΨӤ��x�By�A�Yx < y�A�Ǧ^ -1�F�Yx == y�A�Ǧ^0�F�Y x > y�A�Ǧ^1*/
#define COMPARE(x, y) (((x) < (y)) ? -1: ((x) == (y)) ? 0: 1)

/*�ŧipoly_node�O�h�������D�s��*/
typedef struct pnode{
  int coef;						/*�D�s�����Y��*/
  int exp;						/*�D�s����򻦸*/
  struct pnode *next;			/*�D�s��������*/
}poly_node;

/*�ŧipoly_ptr�O���V�h����������*/
typedef poly_node *poly_ptr;

/*�o�Ө�Ʒ|�b�h�����[�J�@�ӫD�s��*/
poly_ptr attach(poly_ptr tail, int coef, int exp)
{
  poly_ptr ptr;
  ptr = (poly_ptr)malloc(sizeof(poly_node));
  ptr->coef = coef;
  ptr->exp = exp;
  ptr->next = NULL;
  tail->next = ptr;
  tail = ptr;
  return(tail);      
}

poly_ptr PolyAdd(poly_ptr A, poly_ptr B)
{
  poly_ptr C, tail;
  C = (poly_ptr)malloc(sizeof(poly_node));
  tail = C;

  A = A->next;
  B = B->next;
  while((A != NULL) && (B != NULL)){
    switch(COMPARE(A->exp, B->exp)){
      /*��A��򻦸�p��B��򻦸�ɡA�NB���D�s���[�J�h����*/
      case -1:
        tail = attach(tail, B->coef, B->exp);
	    B = B->next;
	    break;
      /*��A��򻦸����B��򻦸�ɡA�N��̬ۥ[�᪺�D�s���[�J�h����*/
      case 0:
        if((A->coef + B->coef) != 0)
	    tail = attach(tail, A->coef + B->coef, A->exp);
	    A = A->next;
	    B = B->next;
	    break;
       /*��A��򻦸�j��B��򻦸�ɡA�NA���D�s���[�J�h����*/
      case 1:
        tail = attach(tail, A->coef, A->exp);
	    A = A->next;
    }
  }	 
  while(A){		/*�NA�ѤU���D�s���[�J�h����*/
    tail = attach(tail, A->coef, A->exp);
	A = A->next;
  }
  while(B){	   /*�NB�ѤU���D�s���[�J�h����*/
    tail = attach(tail, B->coef, B->exp);
	B = B->next;
  }
  return (C);
}

main()
{
  poly_ptr A, B, C, tail;
  
  /*�NA(X) ��l��*/
  A = (poly_ptr)malloc(sizeof(poly_node));
  tail = attach(A, 3, 5);
  tail = attach(tail, 8, 4); 
  tail = attach(tail, -6, 2);
  tail = attach(tail, 5, 0);
  
  /*�NB(X) ��l��*/
  B = (poly_ptr)malloc(sizeof(poly_node));
  tail = attach(B, 2, 6);
  tail = attach(tail, 4, 2); 
  tail = attach(tail, 1, 0);
  
  /*�I�s��ƭp��C(X) = A(X) + B(X)*/ 
  C = PolyAdd(A, B);
 
  /*�L�XC(X)�����G*/
  tail = C->next;
  while(tail != NULL){
    printf("�D�s�����Y�ơG %d\t򻦸�G %d\n", tail->coef, tail->exp);
    tail = tail->next;
  }
  getchar();
}
