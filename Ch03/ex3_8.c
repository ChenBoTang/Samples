traverse()
{
  if(head->next == head)								/*�ˬd�O�_���Ŧ�C*/
    printf("��C�O�Ū��L�k�L�X");				/*�O���ܡA�N�L�X���T��*/
  else{															/*�_���ܡA�N�L�X�Ҧ��`�I��data���*/
    current = head->next;								/*�O�ثe�`�I���V���`�I���U�@�Ӹ`�I*/
    while(current != head){							/*��ثe�`�I�|����F��C�����ݮ�*/
      printf("%d ", current->data);				/*�L�X�ثe�`�I��data���*/
      current = current->next; 					/*�O�ثe�`�I���V�U�@�Ӹ`�I*/
    }
  }
}
