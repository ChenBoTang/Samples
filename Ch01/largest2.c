main()
{
  int i;
  int list[5] = {25,30,18,7,10};                /* �N5�ӥ���Ʀs��b�}�C */
  int largest = 0;								/* �]�w�̤j�ƪ���l�Ȭ�0 */
  for(i = 0; i < 5; i++)						/* �ϥ�for�j���X�̤j�� */
    if (list[i] > largest) largest = list[i];
  printf("�̤j�Ƭ�%d", largest);
  getchar();
}
