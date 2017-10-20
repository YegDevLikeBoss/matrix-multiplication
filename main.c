#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define limit 3200

char inp[limit];
int inp2[limit];

int arrio();
int separator(int mm);
int glbio(char cha, int men);

int main(int argc, char *argv[])
{
    int minr=101, r, neg, m=0, n=0, i, j, k, temp, x, imin, jmin, z=-1, kk, tmmp;

    srand(time(NULL)); /*Randomization*/

    for (kk=0;kk<limit;kk++)
    {
        inp2[kk]=101;
    }

    if (argc>1)
        printf("We're sorry, but command line arguments aren't supported. :-|\n\n");

    printf("You have array size of (m x n)\n");

    while(m<4)
    {
        m=glbio('m', 3);
        if (m<4)
            printf("Don't cheat. Enter valid value. :-[\n");
    }
    while(n<5)
    {
        n=glbio('n', 4);
        if (n<5)
            printf("Don't cheat. Enter valid value. :-[\n");
    }
    printf("\nSuccessfully created matrix size of (%dx%d). ;-)\n", m, n);

    int ar[m][n], far[m-1][n-1];

    printf("Your matrix:\n");
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            r = rand() %100;
            neg = rand() %2;
            if(neg==0)
                ar[i][j]=r;
            else
                ar[i][j]=r*-1;
        }

    }

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", ar[i][j]);
        }
        printf("\n");

    }
    printf("\n");
    printf("Successfully changed first string of matrix with last one, and mirrored them. ;-)\n");
    for (j=0;j<n;j++)
    {
        temp=ar[0][j];
        ar[0][j]=ar[m-1][n-j-1];
        ar[m-1][n-j-1]=temp;
    }

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {

            if(neg==0)
                x=ar[i][j];
            else
                x=ar[i][j];
            if (x<minr)
                {minr=x; imin=i; jmin=j;}
        }

    }

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Smallest element of matrix has value of %d\n\n", minr);

    for (i=0;i<imin;i++)
    {
        for (j=0;j<jmin;j++)
        {
            far[i][j]=ar[i][j];
        }
        for (j=jmin;j<n;j++)
        {
            far[i][j]=ar[i][j+1];
        }
    }
    for (i=imin;i<m;i++)
    {
        for (j=0;j<jmin;j++)
        {
            far[i][j]=ar[i+1][j];
        }
        for (j=jmin;j<n;j++)
        {
            far[i][j]=ar[i+1][j+1];
        }
    }

    printf("Successfully deleted line and column in cross of smallest element. ;-)\n");
    for (i=0;i<m-1;i++)
    {
        for (j=0;j<n-1;j++)
        {
            printf("%d ", far[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    while(z<=0)
    {
        printf("First enter second dimension 'x' (x>0) of your matrix.\n");
        z=glbio('x', 0);
        if (z<0)
            printf("Don't cheat. Enter valid value. :-[\n");
    }

    /*while (cnt==0)
    {
        cntRes=selfaio(n-1, z);
        if (cntRes!=0)
            {cnt=1;
            printf("Success");}
    }
    printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA%d %ddd", n, z);*/
    int bar[n-1][z]; /*Second matrix*/

    for (i=0;i<n-1;i++)
    {
        for (j=0;j<z;j++)
        {
            r = rand() %100;
            neg = rand() %2;
            if(neg==0)
                bar[i][j]=r;
            else
                bar[i][j]=r*-1;
        }

    }
    printf("\n\nSecond array\n\n");
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<z;j++)
        {
            printf("%d ", bar[i][j]);
        }
        printf("\n");
    }

    int car[m][z]; /*Third matrix declaration*/

    for (i=0;i<m-1;i++) /*Multiplication algorithm*/
    {
        for (j=0;j<z;j++)
        {
            tmmp=0;
            for (k=0;k<n-1;k++)
            {
                tmmp+=far[i][k]*bar[k][j];
            }
            car[i][j]=tmmp;
        }
    }
    printf("\n\nThird array\n\n");
    for (i=0;i<m-1;i++)
    {
        for (j=0;j<z;j++)
        {
            printf("%d ", car[i][j]);
        }
        printf("\n");
    }
    return 1;
}
/*Functions*/
int arrio()
{
    int i=0, k=0, iMem=0;
    while(k==0)
    {
        inp[i] = getchar();
        if (inp[i]=='\n')
        {
            inp[i]='\0';
            k=1;
        }
        i++;
    }
    iMem=i;
    return iMem;
}
int separator(int mm)
{
    int i=0, temp, modi, result=0;
    float mltp=0.0;

        if (inp[0]>='0'&&inp[0]<='9')
        {
            for (i=mm-2;i>=0;i--)
            {
                modi=inp[i];
                if (modi>='0'&&modi<='9')
                {
                    modi-='0';
                    temp=/*round(*/pow(10.0,mltp-0.0)/*)*/;
                    modi*=temp;
                    mltp=mltp+1.0;
                    result+=modi;
                }
                else
                {
                    return 0;
                }
            }
            return result;

        }
        else return 0;

}
int glbio(char cha, int men)
{
    int tryer, test;
    printf("Enter %c, (%c>%d): ", cha, cha, men);
    test=arrio();
    tryer=separator(test);
    return tryer;
}
