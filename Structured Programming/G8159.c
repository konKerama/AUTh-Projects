#include <stdio.h>
#include <string.h>
void main ()
{
    int n,i,k;
    char str[20],string[20];
    FILE *numpers,*calls;
    long int arithmos;

    printf ("Dwse arithmo sindromitwn: \n");
    scanf ("%d",&n);

    numpers=fopen ("numpers.txt","w+");

    for (i=0;i<n;i++)
    {
        printf ("Dwse onoma sindromiti: \n");
        scanf ("%s",str);
        fprintf (numpers,"%s \n",str);
    }

    printf ("Dwse arithmo pou elave tin klisi: \n");
    scanf ("%s",str);
    if (strcmp(str,"0")!=0)
    {
        do
        {
            rewind (numpers);
            printf ("Dwse arithmo sindromiti pou kalese: \n");
            scanf ("%ld",&arithmos);

            do
            {
                fscanf (numpers,"%s",string);
                k=strcmp(str,string);
            }while (k=0);

            calls = fopen(str,"ab");
            fprintf (calls,"%ld \n",arithmos);
            fclose (calls);

            printf ("Dwse arithmo pou elave tin klisi: \n");
            scanf ("%s",str);
        }while (strcmp(str,"0")!=0);
    }
    rewind (numpers);

    for (i=1;i<n;i++)
    {
        fscanf (numpers,"%s",str);
        calls = fopen (str,"rb");
        printf ("O arithmos %s elave kliseis apo: \n",str);

        while (!feof(calls))
        {
            fscanf(calls,"%ld",&arithmos);
            printf("%ld",arithmos);
        }
        fclose (calls);
    }
}
