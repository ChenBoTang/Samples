concatenate(list_pointer A, list_pointer B)
{
  list_pointer ptr = A;
  while(ptr->next != NULL) 
    ptr = ptr->next;
  ptr->next = B->next;
  free(B);  						/*釋放串列B的首節點*/
}
