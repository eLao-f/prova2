#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int dados;
    struct Node *proximo;
}   *primeiro = NULL;
void criar(int lista[], int n)
{
    int i;
    struct Node *t, *ultimo;
    primeiro = (struct Node *) malloc (sizeof (struct Node));
    primeiro->dados = lista[0];
    primeiro->proximo = NULL;
    ultimo = primeiro;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *) malloc (sizeof (struct Node));
        t->dados = lista[i];
        t->proximo = NULL;
        ultimo->proximo = t;
        ultimo = t;
    }
}
int adicionar(struct Node *listaInc)
{
    int soma = 0;
    while (listaInc != NULL)
    {
        soma += listaInc->dados;
        listaInc = listaInc->proximo;
    }
    return soma;
}
int main()
{
    int lista[] = { 2, 9, 21, 1, 17, 6 };
    criar (lista, 6);
    printf ("soma %d\n", adicionar (primeiro));
    return 0;
}