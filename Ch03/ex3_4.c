delete(int value)
{
  if(head->next == NULL)										/*�ˬd�O�_���Ŧ�C*/
    printf("��C�O�Ū��L�k���R��\n");					/*�O���ܡA�N�L�X���T��*/
  else{																		/*�_���ܡA�N��X���R�����`�I*/
    previous = head;
    current = head->next;   
    while((current != NULL) && (current->data != value)){
      previous = current;
      current = current->next;
    }
    if(current != NULL){											/*�ˬd��쪺�`�I�O�_�s�b*/
      previous->next = current->next;						/*�O���ܡA�N�R���Ӹ`�I*/
      free(current);
    }           
    else printf("%d ���s�b�L�k���R��\n", value);	/*�_���ܡA�N�L�X���T��*/
  } 
}
