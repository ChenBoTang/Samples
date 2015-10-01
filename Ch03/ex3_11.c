delete(int value)
{
  if(head->rlink == head)
    printf("串列是空的無法做刪除\n");
  else{
    current = head->rlink;   
    while((current != head) && (current->data != value))
      current = current->rlink;
    if(current != head){
      current->llink->rlink = current->rlink;
      current->rlink->llink = current->llink;
      free(current);
    }           
    else printf("%d 不存在無法做刪除\n", value);
  } 
}
