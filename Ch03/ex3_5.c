int count()
{
  int length = 0;
  current = head->next;					/*���L���`�I*/
  while(current != NULL){			/*��ثe�`�I�|����F��C�����ݮ�*/
    length++;
    current = current->next; 
  }
  return length;  
}
