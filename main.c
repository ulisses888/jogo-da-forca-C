#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int palavra(char *palavraEscolhida);
int menu();
int jogar();

int main()
{
    int escolha;
    srand(time(0));
    for (;;)
    {
        menu(escolha);
        if (escolha = 2){
            return 0;
        }
    }

    return 0;
}

int palavra(char *palavraEscolhida)
{

    int numeroPalavra = rand() % 100 + 1;
    int linhaAtual = 0;

    FILE *arquivo;
    arquivo = fopen("palavras.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao encontrar o arquivo com as palavras");
        return 1;
    }

    for (linhaAtual; linhaAtual < numeroPalavra; linhaAtual++)
    {
        fgets(palavraEscolhida, 25, arquivo);
    }

    fclose(arquivo);

    return 0;
}

int menu()
{

    int escolha = 0;
    printf("---------------------\n");
    printf("-- Jogo da Forca!! --\n");
    printf("---------------------\n\n");

    printf("1 - Iniciar Jogo\n");
    printf("2 - Sair do Jogo\n");
    printf("3 - Regras do Jogo\n");

    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        jogar();
        break;
    case 2:
        return 0;
        break;
    case 3:
        printf("\nRegras do Jogo:\n");
        printf("1. Uma palavra secreta é escolhida e suas letras são substituídas por traços (_).\n");
        printf("2. O jogador sugere uma letra por vez.\n");
        printf("3. Se a letra estiver na palavra, ela é revelada. Caso contrário, uma parte da forca é desenhada.\n");
        printf("4. O jogador vence se descobrir a palavra antes que o desenho da forca seja concluído.\n");
        printf("5. Se o desenho for concluído antes da descoberta da palavra, o jogador perde.\n");
        printf("6. Usar somente letras minusculas exemplo: a,b,c,d,e,etc...\n");
        break;
    default:
        printf("Opcao Invalida!");
        return 1;
    }

    return 0;
}

int jogar()
{
    int ganhou = 0;
    char palavraEscolhida[25];
    char chutes[26];
    int numeroChutes = 0;
    char letraChutada;
    int jaChutou = 0;

    palavra(palavraEscolhida);
    

    while (ganhou == 0)
    {
        for (int i = 0; i < strlen(palavraEscolhida) - 1; i++)
        {
            int acerto = 0;
            for (int j = 0; j < numeroChutes; j++)
            {
                if (chutes[j] == palavraEscolhida[i])
                {
                    printf(" %c ", palavraEscolhida[i]);
                    acerto = 1;
                    break;
                }
            }
            if (acerto == 0)
            {
                printf(" _ ");
            }
        }

        printf("\n\n");
        printf("Chute uma letra:\n");
        scanf(" %c", &letraChutada);
        printf("\n");
        for(int l = 0; l < numeroChutes && numeroChutes!= 0; l++){
            if(chutes[l] == letraChutada){
                printf("\nVoce ja chutou essa letra\n\n");
                jaChutou = 1;
                break;
            }
        }

        if(jaChutou != 1){
        chutes[numeroChutes] = letraChutada;
        numeroChutes++;
        }
        jaChutou = 0;

        printf("Letras chutadas:");
        for(int k = 0; k < numeroChutes; k++){
            printf(" %c ", chutes[k]);

        }
        printf("\n");
    }

    return 0;
}