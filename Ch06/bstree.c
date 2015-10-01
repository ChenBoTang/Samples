#include <stdio.h>

/*�ŧitree_node�O�G���𪺸`�I*/
typedef struct node{
  struct node *lchild;	    /*�`�I�����쵲���*/
  char data;			    /*�`�I��������*/
  struct node *rchild;		/*�`�I���k�쵲���*/
}tree_node;

/*�ŧitree_pointer�O���V�`�I������*/
typedef tree_node *tree_pointer;

/*�o�Ө�Ʒ|�ھڰѼ�key���w����Ȧb�G���j�M��j�M�`�I*/
tree_pointer search(tree_pointer root, int key)
{
  tree_pointer current;
  current = root;
  while (current){
    if (key == current->data) return current;
    if (key < current->data)
      current = current->lchild;
    else
      current = current->rchild;
  }
  return NULL;
}

/*�o�Ө�Ʒ|�b�G���j�M�𴡤J�`�I*/
tree_pointer insert(tree_pointer root, int key)
{
  tree_pointer ptr, current, previous;                  
  if (search(root, key)){
    printf("��Ƥw�s�b�A�L�k�A���J�`�I�I");
    return root;                 
  }
  ptr = (tree_pointer)malloc(sizeof(tree_node));
  ptr->data = key;
  ptr->lchild = NULL;
  ptr->rchild = NULL;
  if (!root) root = ptr;
  else{
    current = root;
    while(current){
      previous = current; 
      if (ptr->data < current->data) current = current->lchild;
      else current = current->rchild;      
    }             
    if (ptr->data < previous->data) previous->lchild = ptr;
    else previous->rchild = ptr;
  }
  return root;
}

/*�o�Ө�Ʒ|��ܤG���𪺤��Ǩ��X���G*/ 
inorder(tree_pointer root)
{
  if (root){
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
  }
}

/*�D�{��*/ 
main()
{
  tree_pointer root = NULL;
  root = insert(root, 25);
  root = insert(root, 30);
  root = insert(root, 24);
  root = insert(root, 58);
  root = insert(root, 45);
  root = insert(root, 26);
  root = insert(root, 12);
  root = insert(root, 14);
  inorder(root);
  getchar();    
}
