main()
{
  int i;
  int list[5] = {25,30,18,7,10};                /* 盢5タ俱计皚 */
  int largest = 0;								/* 砞﹚程计﹍0 */
  for(i = 0; i < 5; i++)						/* ㄏノfor癹伴т程计 */
    if (list[i] > largest) largest = list[i];
  printf("程计%d", largest);
  getchar();
}
