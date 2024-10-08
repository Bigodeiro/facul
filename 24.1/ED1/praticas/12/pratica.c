#include <stdio.h>
#include "arvore.h"

int main() {
    No* no;
    int a, b;
    Item item;
    criar(&no);

    while (scanf("%d", &item.preco) && item.preco > 0) {
        scanf("%s %s", item.cultura, item.fazenda);
        inserir(&no, item);
    }

    scanf("%d %d", &a, &b);

    printf("InOrder:\n");
    imprimeIn(no, a, b);

    printf("\nPreOrder:\n");
    imprimePos(no, a, b);
    
    printf("\nPosOrder:\n");
    imprimePre(no, a, b);
    
    destruir(&no);

    return 0;
}
