insert(int value)
{
  dlist_pointer ptr;         
  ptr = (dlist_pointer)malloc(sizeof(dlist_node));	/*�t�m�O����Ŷ����s�`�I*/
  ptr->data = value;											/*�]�w�s�`�I��data���*/
  current = head->rlink;										/*�O�ثe�`�I���V���`�I���U�@�Ӹ`�I*/
  while((current != head) && (current->data > ptr->data))		/*��X�s�`�I�n���J����m*/
    current = current->rlink;
  ptr->llink = current->llink; 							/*�O�s�`�I�����쵲���V�ثe�`�I�����`�I*/
  ptr->rlink = current;										/*�O�s�`�I���k�쵲���V�ثe�`�I*/
  current->llink->rlink = ptr;								/*�O�ثe�`�I�����`�I���k�쵲����V�s�`�I*/
  current->llink = ptr;										/*�O�ثe�`�I�����쵲����V�s�`�I*/
}
