insert(int value)
{
  list_pointer ptr;
  ptr = (list_pointer)malloc(sizeof(list_node));		/*�t�m�O����Ŷ����s�`�I*/
  ptr->data = value;												/*�]�w�s�`�I��data���*/
  previous = head;													/*�O�e�@�Ӹ`�I���V���`�I*/
  current = head->next;											/*�O�ثe�`�I���V���`�I���U�@�Ӹ`�I*/
  while((current != NULL) && (current->data > ptr->data)){	/*��X�s�`�I�n���J����m*/
    previous = current;
    current = current->next;
  }
  ptr->next = current;											/*�O�s�`�I���쵲���V�ثe�`�I*/
  previous->next = ptr;										/*�O�e�@�Ӹ`�I���쵲����V�s�`�I*/
}
