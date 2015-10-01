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
  int start = 0;                /*指向str字串的比對起點*/
  int end = strlen(str) - 1;    /*指向str字串的最後一個字元*/
  int endp = strlen(pat) - 1;   /*指向pat字串的最後一個字元*/
  int endmatch = endp;          /*指向str字串內用來與pat字串的最後一個字元做比對的字元*/
  
  for(i = 0; endmatch <= end; endmatch++, start++){
    if(str[endmatch] == pat[endp])
      for(j = 0, i = start; j < endp && str[i] == pat[j]; i++, j++) ;
    if(j == endp) return start; /*表示成功*/
  }
  return -1;                    /*表示失敗*/
}


