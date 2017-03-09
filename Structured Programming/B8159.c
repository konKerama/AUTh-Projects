void main ()
{
    int min,num_A,num_B,i,j,k,l;
    printf("Dwse elaxisti apostasi \n");
    scanf("%i",&min);
    printf("Dwse arithmo simeiwn tis etairias A \n");
    scanf("%d",&num_A);
    while (num_A>50)
    {
        printf("O arithmos den prepei na einai megaliteros tou 50 \n");
        printf("Dwse arithmo simeiwn tis etairias A \n");
        scanf("%d",&num_A);
    }
    printf("Dwse arithmo simeiwn tis etairias B \n");
    scanf("%d",&num_B);
    while (num_B>50)
    {
        printf("O arithmos den prepei na einai megaliteros tou 50 \n");
        printf("Dwse arithmo simeiwn tis etairias B \n");
        scanf("%d",&num_B);
    }
    int A[num_A][3],B[num_B][3],over[num_A*num_B][2];
    printf("Etairia A \n");
    for (i=1;i<=num_A;i++)
    {
        printf("Dwse kwdiko kai sintetagmenes gia to %do simeio \n",i);
        scanf("%i",&A[i][1]);
        scanf("%i",&A[i][2]);
        scanf("%i",&A[i][3]);
    }
    printf("Etairia B \n");
    for (i=1;i<=num_B;i++)
    {
        printf("Dwse kwdiko kai sintetagmenes gia to %do simeio \n",i);
        scanf("%i",&B[i][1]);
        scanf("%i",&B[i][2]);
        scanf("%i",&B[i][3]);
    }
    k=1;
    for (i=1;i<=num_A;i++)
    {
        for (j=1;j<=num_B;j++)
        {
           if (sqrt((A[i][2]-B[j][2])*(A[i][2]-B[j][2])+(A[i][3]-B[j][3])*(A[i][3]-B[j][3]))<=min)
           {
              over[k][1]=A[i][1];
              over[k][2]=B[j][1];
              k++;
           }
        }
    }
    printf("Oi kwdikoi twn simeiwn pou exoun epikalipsi einai: \n");
    for (i=1;i<=k-1;i++)
    {
        printf("%i %i \n",over[i][1],over[i][2]);
    }
    for (i=1;i<=num_A;i++)
    {
        for (j=1;j<=k-1;j++)
        {
            if (A[i][1]==over[j][1])
            {
                A[i][1]=0;
                A[i][2]=0;
                A[i][3]=0;
                for (l=1;l<=num_B;l++)
                {
                    if (B[l][1]==over[j][2])
                    {
                        B[l][1]=0;
                        B[l][2]=0;
                        B[l][3]=0;
                    }
                }
            }
        }
    }
    for (i=1;i<=num_A;i++)
    {
        if (A[i][1]!=0)
        {
            printf("Ta simeia tis etairias A pou dn exoun epikalipsi einai: \n");
            printf("%i %i %i \n",A[i][1],A[i][2],A[i][3]);
        }
    }
    for (j=1;j<=num_B;j++)
    {
        if (B[j][1]!=0)
        {
            printf("Ta simeia tis etairias B pou dn exoun epikalipsi einai: \n");
            printf("%i %i %i \n",B[j][1],B[j][2],B[j][3]);
        }
    }
}
