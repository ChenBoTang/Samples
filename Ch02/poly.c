/*此巨集用來比較x、y，若x < y，傳回 -1；若x == y，傳回0；若 x > y，傳回1*/
#define COMPARE(x, y) (((x) < (y)) ? -1: ((x) == (y)) ? 0: 1)
#define MAX_SIZE 100							/*定義多項式最多包含MAX_SIZE個非零項*/
typedef struct{										/*定義表示非零項的結構*/
  int coef;												/*非零項的係數*/
  int exp;												/*非零項的羃次*/
}NonZeroTerm;

typedef struct{										/*定義表示多項式的結構*/
  int count;											/*非零項的個數*/
  NonZeroTerm terms[MAX_SIZE];		/*非零項*/
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
  /*印出多項式C(X)的結果*/
  int i;
  printf("多項式C(X)的非零項有%d個\n", C.count);
  for(i = 0; i < C.count; i++)
    printf("第%d個非零項的係數：%d\t羃次：%d\n", i+1, C.terms[i].coef, C.terms[i].exp);
  getchar();
}

/*這個函數會在多項式加入一個非零項*/
attach(Polynomial *ptr, int coef, int exp)
{
  if (ptr->count >= MAX_SIZE) return;
  ptr->terms[ptr->count].coef = coef;
  ptr->terms[ptr->count].exp = exp;
  ptr->count++;                 
}

/*這個函數會將兩個多項式相加，A(X) + B(X) = C(X)*/ 
PolyAdd(Polynomial *pA, Polynomial *pB, Polynomial *pC)
{
  int currentA = 0, currentB = 0;
  pC->count = 0;                
  while(currentA < pA->count && currentB < pB->count){
    switch(COMPARE(pA->terms[currentA].exp, pB->terms[currentB].exp)){
      case -1:       /*當A的羃次小於B的羃次時，將B的非零項加入多項式*/
        attach(pC, pB->terms[currentB].coef, pB->terms[currentB].exp);
        currentB++;
        break;
      case 0:       /*當A的羃次等於B的羃次時，將兩者相加後的非零項加入多項式*/
        if((pA->terms[currentA].coef + pB->terms[currentB].coef) != 0)
         attach(pC, pA->terms[currentA].coef + pB->terms[currentB].coef, pA->terms[currentA].exp);
         currentA++;
         currentB++;
         break;
       case 1:      /*當A的羃次大於B的羃次時，將A的非零項加入多項式*/
         attach(pC, pA->terms[currentA].coef, pA->terms[currentA].exp);
         currentA++;
    }
  }  
  while(currentA < pA->count){  /*將A剩下的非零項加入多項式*/
    attach(pC, pA->terms[currentA].coef, pA->terms[currentA].exp);
    currentA++;
  }                           
  while(currentB < pB->count){  /*將B剩下的非零項加入多項式*/
    attach(pC, pB->terms[currentB].coef, pB->terms[currentB].exp);
    currentB++;
  }                    
}
