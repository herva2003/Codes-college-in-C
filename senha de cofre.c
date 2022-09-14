#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 20
#define TAM 5

int barra[MAX] = {5,9,1,7,5,5,9,0,7,1}, senha[TAM] = {3, 1, 3, 2, 3}, senha_obt[TAM] = {0,0,0,0,0};
int zero = 0, one = 0, five = 0, seven = 0, nine = 0;

void codificador(int i)
{
     switch(barra[i])
  {
      case 0:
          zero++;
          senha_obt[0] = zero;
          break;
      case 1:
          one++;
          senha_obt[1] = one;
          break;
      case 5:
          five++;
          senha_obt[2] = five;
          break;
      case 7:
          seven++;
          senha_obt[3] = seven;
          break;
      case 9:
          nine++;
          senha_obt[4] = nine;
          break;
  }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int i = 0, ate, t = 0, r = 0, aux, j, flag = 0, k = 0;

    printf("\n\t\t\t\t\t\t-->REGRAS<--");
    printf("\n\t\t\t- Apenas três tentativas são permitidas para tentar abrir o cofre.");
    printf("\n\t\t\t- Você pode realizar quatro rolamentos na barra para acertar a senha.");
    printf("\n\n\t\t\t\t\t----------------------------------\n");

    while(r < 3)
    {
        printf("\t\t\t\t\t| Tentativa %d\n", r+1);
        for(t = 0; t < 4; t++)
        {
            printf("\t\t\t\t\t| Deslizamento %d\n\t\t\t\t\t| Você escolheu a posição: ", t+1);
            scanf("%d",&ate);
            j = 0;
            aux = 2;
            if(ate < i)
            {
                j = 1;
                for(i = i - aux; i >= ate; i--)
                {
                    codificador(i);
                    printf("%d",i);
                }
            }
            else
            {
                for(i = i; i <= ate; i++)
                {
                    codificador(i);
                    printf("%d",i);
                }
            }
            printf("\t\t\t\t\t| Sua combinação: %d %d %d %d %d\n", senha_obt[0], senha_obt[1], senha_obt[2], senha_obt[3], senha_obt[4]);
            printf("\t\t\t\t\t| sua posição atual: %d\n", ate);
            printf("\t\t\t\t\t----------------------------------\n");
            flag = 0;
            for(k = 0; k < 5; k++)
            {
                if(senha_obt[k] == senha[k])
                {
                  flag++;
                }
            }
            if(flag > 4)
            {
                printf("\n\t\t\t\t\t----------------------------------\n");
                printf("\t\t\t\t\t| Senha obtida: %d %d %d %d %d\n", senha_obt[0], senha_obt[1], senha_obt[2], senha_obt[3], senha_obt[4]);
                printf("\n\t\t\t\t\t    -->Você abriu o cofre!!<--\n");
                break;
            }
            if(j == 1)
            {
                aux = 0;
                i+=2;
            }

        }
        if(flag > 4)
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
           senha_obt[0] = zero = 0;
           senha_obt[1] = one = 0;
           senha_obt[2] = five = 0;
           senha_obt[3] = seven = 0;
           senha_obt[4] = nine = 0;
           i = 0;
           r++;
        }
    }
    printf("\n\n\n");
    system("pause");
    return 0;
}