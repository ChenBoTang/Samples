/*�ŧitwo_three_node�O2-3�𪺸`�I*/
typedef struct node{
  struct node *lchild;		/*�`�I�����쵲���*/
  char lkey;			/*�`�I����������*/
  struct node *mchild;	/*�`�I�����쵲���*/
  char rkey;			/*�`�I���k������*/
  struct node *rchild;		/*�`�I���k�쵲���*/
}two_three_node;

/*�ŧitwo_three_pointer�O���V�`�I������*/
typedef two_three_node *two_three_pointer;
