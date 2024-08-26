#include "automato.h"




int main(int argc, char const *argv[])
{
    Automato automato;

    LeituraReticulado(&automato);

    int x, y;
    x = 2;
    y = 1;

    printf("Pesquisando a celula %d %d\n", x, y);
    if (pesquisaCelula(automato.reticulado, x, y))
    {
        printf("Celula encontrada\n");
    }else
    {
        printf("Celula não encontrada\n");
    }

    // evoluirReticulado(&automato);

    imprimeReticulado(&automato);

    // desalocarReticulado(&automato);

    return 0;
}