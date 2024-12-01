#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int palavra(char *palavraEscolhida);



int main(){
srand(time(0));

char palavraEscolhida[100];
palavra(palavraEscolhida);

printf("%s",palavraEscolhida);

return 0;
}






int palavra(char *palavraEscolhida){
    int numeroPalavra = rand() % 100 + 1;
    int linhaAtual = 0;
    
    FILE *arquivo;
    arquivo = fopen("palavras.txt", "r");
    if (arquivo == NULL){
        printf("Erro ao encontrar o arquivo com as palavras");
        return 1;
    }

    for(linhaAtual;linhaAtual<numeroPalavra;linhaAtual++){
        fgets(palavraEscolhida, 100, arquivo);
    }

            
    fclose(arquivo);
    
    return 0;

}