concatenate(list_pointer A, list_pointer B)
{
  list_pointer ptr = A;
  while(ptr->next != NULL) 
    ptr = ptr->next;
  ptr->next = B->next;
  free(B);  						/*�����CB�����`�I*/
}
