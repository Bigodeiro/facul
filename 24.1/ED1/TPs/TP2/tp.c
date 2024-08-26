#include "automato.h"




int main(int argc, char const *argv[])
{
    Automato automato;

    LeituraReticulado(&automato);

    // printf("A matriz %s vazia\n", automato.reticulado == NULL ? "está" : "não está");

    // evoluirReticulado(&automato);

    imprimeReticulado(&automato);

    // desalocarReticulado(&automato);

    return 0;
}