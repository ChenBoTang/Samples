main()
{
  char str[] = "yxyxxxyyxxx";
  char pat[] = "yyx";
  
  printf("%d", StrMatch(str, pat));
  getchar();
}

int StrMatch(char str[], char pat[])
{
  int i, j;
  int start = 0;                /*���Vstr�r�ꪺ���_�I*/
  int end = strlen(str) - 1;    /*���Vstr�r�ꪺ�̫�@�Ӧr��*/
  int endp = strlen(pat) - 1;   /*���Vpat�r�ꪺ�̫�@�Ӧr��*/
  int endmatch = endp;          /*���Vstr�r�ꤺ�ΨӻPpat�r�ꪺ�̫�@�Ӧr������諸�r��*/
  
  for(i = 0; endmatch <= end; endmatch++, start++){
    if(str[endmatch] == pat[endp])
      for(j = 0, i = start; j < endp && str[i] == pat[j]; i++, j++) ;
    if(j == endp) return start; /*��ܦ��\*/
  }
  return -1;                    /*��ܥ���*/
}


