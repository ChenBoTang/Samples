hanoi(int n, char from, char through, char to)
{
  if (n > 0){
    hanoi(n - 1, from, to, through);
    printf("�N%d����L�q�W�l%c����W�l%c\n", n, from, to);
    hanoi(n - 1, through, from, to);
  }
}

main()
{
    hanoi(3, 'A', 'B', 'C');
    getchar();    
}


