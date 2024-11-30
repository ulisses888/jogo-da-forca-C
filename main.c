#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int palavra();

int main(){
srand(time(0));

palavra();

return 0;
}






int palavra(){
    int numeroPalavra = rand() % 100;
    printf("%d",numeroPalavra);
    return 0;

}