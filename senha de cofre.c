#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 20

int barra[MAX] = {5,9,1,7,5,5,9,0,7,1}, senha[5] = {0, 1, 1, 1, 1};
int zero = 0, one = 0, five = 0, seven = 0, nine = 0;

void codificador(int i)
{
    (barra[i] == 0) ? zero++ :
    (barra[i] == 1) ? one++ :
    (barra[i] == 5) ? five++ :
    (barra[i] == 7) ? seven++ :
    (barra[i] == 9) ? nine++ :
    ' ';
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int i = 0, ate, t = 0, r = 0, cont = 0;

    printf("\n\t\t\t\t\t\t-->REGRAS<--");
    printf("\n\t\t\t- Apenas três tentativas são permitidas para tentar abrir o cofre.");
    printf("\n\t\t\t- Você pode realizar quatro rolamentos na barra para acertar a senha.");
    printf("\n\n\t\t\t\t\t----------------------------------\n");

    while(r < 3)
    {
        printf("\t\t\t\t\t| Tentativa: %d\n", r+1);
        for(t = 0; t < 4; t++)
        {
            printf("\t\t\t\t\t| Rolamentos: %d\n", t+1);
            printf("\t\t\t\t\t| Você escolheu a posição: ");
            scanf("%d",&ate);

            if(ate < i)
            {
                for(i = i; i >= ate; i--)
                {
                    codificador(i);
                }
            i++;
            }
            else
            {
                for(i = i; i <= ate; i++)
                {
                    codificador(i);
                }
            }

            printf("\t\t\t\t\t| Sua combinação: %d %d %d %d %d\n", zero, one, five, seven, nine);
            printf("\t\t\t\t\t| sua posição atual: %d\n", ate);
            printf("\t\t\t\t\t----------------------------------\n");

            if(senha[0] == zero && senha[1] == one && senha[2] == five && senha[3] == seven && senha[4] == nine)
            {
                printf("\n\t\t\t\t\t----------------------------------\n");
                printf("\t\t\t\t\t| Senha obtida: %d %d %d %d %d\n\t\t\t\t\t|", zero, one, five, seven, nine);
                printf("\n\t\t\t\t\t|   -->Você abriu o cofre!!<--");
                printf("\n\t\t\t\t\t----------------------------------\n");
                cont = 1;
                break;
            }

        }
        if(cont > 0)
        {
            break;
        }
        else
        {
            if (r < 2)
            {
                printf("\n\t\t\t\t\t----------------------------------\n");
                printf("\t\t\t\t\t| \tA senha está errada!!\n\t\t\t\t\t|\t-->Tente novamente<--\n");
                printf("\t\t\t\t\t----------------------------------\n\n");
                printf("\t\t\t\t\t----------------------------------\n");
            }
        }
        if(r == 2)
        {
            printf("\n\t\t\t\t\t----------------------------------");
            printf("\n\t\t\t\t\t| -->Suas tentativas acabaram!<--|\n");
            printf("\t\t\t\t\t----------------------------------\n");
            break;
        }
        else
        {
           zero = 0;
           one = 0;
           five = 0;
           seven = 0;
           nine = 0;
           i = 0;
           r++;
        }
    }
    printf("\n\n\n");
    system("pause");
    return 0;
}
