delete(int value)
{
  if(head->rlink == head)
    printf("��C�O�Ū��L�k���R��\n");
  else{
    current = head->rlink;   
    while((current != head) && (current->data != value))
      current = current->rlink;
    if(current != head){
      current->llink->rlink = current->rlink;
      current->rlink->llink = current->llink;
      free(current);
    }           
    else printf("%d ���s�b�L�k���R��\n", value);
  } 
}
