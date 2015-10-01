main()
{
     int A[2][3] = {{11, 12, 13}, {21, 22, 23}};
     matrix_traverse(2, 3, A);
     getchar(); 
}

/*假設A為mxn陣列，這個函數要印出二維陣列內所有元素的值*/
matrix_traverse(int m, int n, int A[m][n])
{
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         printf("%d ", A[i][j]);
       printf("\n");
     }
}




