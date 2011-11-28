/****************************************************************************
 * 5642 - LC-Display
 * http://livearchive.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=417&page=show_problem&problem=3643
 *
 * Author: Rafael Sepúlveda
 *
 * El problema consiste en emular la impresion en pantalla de un numero en pantallas digitales como la de las calculadoras. Para esto se guardo la
 * impresión de cada dígito en forma de arreglo para posteriormente imprimirla en 3 tamaños distintos dependiendo del requerimiento de la entrada
 */

#include <stdio.h>

int s,n;

char zero[5][3]={' ','-',' ','|',' ','|',' ',' ',' ','|',' ','|',' ','-',' '};
char one[5][3]={' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' '};
char two[5][3]={' ','-',' ',' ',' ','|',' ','-',' ','|',' ',' ',' ','-',' '};
char three[5][3]={' ','-',' ',' ',' ','|',' ','-',' ',' ',' ','|',' ','-',' '};
char four[5][3]={' ',' ',' ','|',' ','|',' ','-',' ',' ',' ','|',' ',' ',' '};
char five[5][3]={' ','-',' ','|',' ',' ',' ','-',' ',' ',' ','|',' ','-',' '};
char six[5][3]={' ','-',' ','|',' ',' ',' ','-',' ','|',' ','|',' ','-',' '};
char seven[5][3]={' ','-',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' '};
char eight[5][3]={' ','-',' ','|',' ','|',' ','-',' ','|',' ','|',' ','-',' '};
char nine[5][3]={' ','-',' ','|',' ','|',' ','-',' ',' ',' ','|',' ','-',' '};

void LeerNumeros()
{
    scanf("%i %i",&s,&n);

}

int Cardinalidad_n(int a)
{
    int counter=1;
    while (a/10!=0)
    {
        a=a/10;
        counter++;
    }
    return counter;
}

void Dividir_n(int a,int b[])
{
    int i;
    for (i=Cardinalidad_n(a)-1;i>=0;i--)
    {
        b[i]=a%10;
        a=a/10;
    }
}

void LCD(int a[],int b)
{
    int l;
    int h,i,j;
    int repeat=s;

    for (i=0;i<5;i++)
    {
        l=0;

        while (l!=Cardinalidad_n(b))
        {
            for (j=0;j<3;j++)
            {
                if (a[l]==0)
                {
                    printf("%c",zero[i][j]);
                    if (s!=1)
                    {
                        if (j==1)
                        {
                        for (h=0;h<s-1;h++)
                        {
                            printf("%c",zero[i][j]);
                        }
                        }
                    }
                }
                else if (a[l]==1)
                {
                    printf("%c",one[i][j]);

                    if (s!=1)
                    {
                        if (j==1)
                        {
                            for (h=0;h<s-1;h++)
                            {
                                printf("%c",one[i][j]);
                            }
                        }
                    }

                }
                else if (a[l]==2)
                {
                    printf("%c",two[i][j]);

                    if (s!=1)
                    {
                        if (j==1)
                        {
                        for (h=0;h<s-1;h++)
                        {
                            printf("%c",two[i][j]);
                        }
                        }
                    }

                }
                else if (a[l]==3)
                {
                    printf("%c",three[i][j]);

                    if (s!=1)
                    {
                        if (j==1)
                        {
                        for (h=0;h<s-1;h++)
                        {
                            printf("%c",three[i][j]);
                        }
                        }
                    }

                }
                else if (a[l]==4)
                {
                    printf("%c",four[i][j]);

                    if (s!=1)
                    {
                        if (j==1)
                        {
                        for (h=0;h<s-1;h++)
                        {
                            printf("%c",four[i][j]);
                        }
                        }
                    }

                }
                else if (a[l]==5)
                {
                    printf("%c",five[i][j]);

                    if (s!=1)
                    {
                        if (j==1)
                        {
                        for (h=0;h<s-1;h++)
                        {
                            printf("%c",five[i][j]);
                        }
                        }
                    }

                }
                else if (a[l]==6)
                {
                    printf("%c",six[i][j]);

                    if (s!=1)
                    {
                        if (j==1)
                        {
                        for (h=0;h<s-1;h++)
                        {
                            printf("%c",six[i][j]);
                        }
                        }
                    }

                }
                else if (a[l]==7)
                {
                    printf("%c",seven[i][j]);

                    if (s!=1)
                    {
                        if (j==1)
                        {
                        for (h=0;h<s-1;h++)
                        {
                            printf("%c",seven[i][j]);
                        }
                        }
                    }

                }
                else if (a[l]==8)
                {
                    printf("%c",eight[i][j]);

                    if (s!=1)
                    {
                        if (j==1)
                        {
                        for (h=0;h<s-1;h++)
                        {
                            printf("%c",eight[i][j]);
                        }
                        }
                    }

                }
                else if (a[l]==9)
                {
                    printf("%c",nine[i][j]);

                    if (s!=1)
                    {
                        if (j==1)
                        {
                        for (h=0;h<s-1;h++)
                        {
                            printf("%c",nine[i][j]);
                        }
                        }
                    }

                }
                else {}
            }
            if(l!=Cardinalidad_n(b)-1) printf(" ");

            l++;
        }

        printf("\n");

        if (s!=1 && repeat!=1)
        {
            if (i==1 || i==3)
            {
                i--;
                repeat--;
            }

        }
        else repeat=s;

    }
}



int main(int argc, char **argv)
{
    while(1){
    LeerNumeros();
    if(s==0 && n==0) break;
    int arreglo[Cardinalidad_n(n)];

    Dividir_n(n,arreglo);

    LCD(arreglo,n);
    printf("\n");

    }

    return 0;
}
