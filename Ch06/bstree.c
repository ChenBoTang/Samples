#include <stdio.h>

/*宣告tree_node是二元樹的節點*/
typedef struct node{
  struct node *lchild;	    /*節點的左鏈結欄位*/
  char data;			    /*節點的資料欄位*/
  struct node *rchild;		/*節點的右鏈結欄位*/
}tree_node;

/*宣告tree_pointer是指向節點的指標*/
typedef tree_node *tree_pointer;

/*這個函數會根據參數key指定的鍵值在二元搜尋樹搜尋節點*/
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

/*這個函數會在二元搜尋樹插入節點*/
tree_pointer insert(tree_pointer root, int key)
{
  tree_pointer ptr, current, previous;                  
  if (search(root, key)){
    printf("資料已存在，無法再插入節點！");
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

/*這個函數會顯示二元樹的中序走訪結果*/ 
inorder(tree_pointer root)
{
  if (root){
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
  }
}

/*主程式*/ 
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
