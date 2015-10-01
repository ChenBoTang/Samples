int count()
{
  int length = 0;
  current = head->next;					/*跳過首節點*/
  while(current != NULL){			/*當目前節點尚未抵達串列的尾端時*/
    length++;
    current = current->next; 
  }
  return length;  
}
