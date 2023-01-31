#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMANHO 128

struct filaRequisicoes
{
    int id; // identificação do usuário;
    struct file *proximo;
};
typedef struct filaRequisicoes frequest;

struct perfil
{
    int id; // identificação do usuário;
    char *nome;
    char *cidade;
    int idade;
};
typedef struct perfil Perfil;

// lista de usuários
struct user
{
    struct perfil *perfilDoUsuario;          // informações do usuario
    struct user *listaDeAmigos;              // lista de amigos já confirmados
    struct filaRequisicoes *amigosPendentes; // fila de amigos ainda não confirmados
    struct user *proximoUser;                // ponteiro para o próximo usuario da lista
};
typedef struct user User;

User *AlocaUser(User *listaUser)
{
    listaUser = (User *)malloc(sizeof(User));
    listaUser->perfilDoUsuario = (Perfil *)malloc(sizeof(Perfil));
    listaUser->listaDeAmigos = (User *)malloc(sizeof(User));
    listaUser->amigosPendentes = (frequest *)malloc(sizeof(frequest));
    listaUser->proximoUser = (User *)malloc(sizeof(User));
    return listaUser;
}

Perfil *AlocaPerfil()
{
    Perfil *newPerfil = (Perfil *)malloc(sizeof(Perfil *));
    newPerfil->nome = (char *)malloc(sizeof(char) * TAMANHO);   // aloca o nome ao novo perfil
    newPerfil->cidade = (char *)malloc(sizeof(char) * TAMANHO); // aloca a cidade ao novo perfil
    // o id e a idade não foram alocados, por que eles NÃO SÃO PONTEIROS!
}

Perfil *criarUsuario(int id)
{
    Perfil *newPerfil = AlocaPerfil();
    fflush(stdin);
    // getchar();
    printf("Nome:");
    fgets((newPerfil)->nome, TAMANHO, stdin); // adiciona um nome ao usuario
    printf("Cidade:");
    fgets((newPerfil)->cidade, TAMANHO, stdin); // adiciona uma cidade ao usuario
    printf("Idade:");
    scanf("%d", &(newPerfil)->idade); // adiciona uma idade ao usuario
    newPerfil->id = id;               // iguala o id do perfil ao id parametro
    return newPerfil;
}

User *buscaPorId(User *listaUser, int buscaId)
{
    User *listaAux = listaUser; // cria uma lista auxiliar
    while (listaAux != NULL)
    {
        if (listaAux->perfilDoUsuario->id == buscaId)
        {
            User *userPorId = listaUser;
            userPorId->proximoUser = NULL; // impossibilita de retornar proximoUser;
            return userPorId;
        }
        if (listaAux->proximoUser == NULL)
        {
            printf("\n Id nao existente na lista de usuarios");
            return NULL;
        }
        listaAux = listaAux->proximoUser;
    }
}

User *buscaPorNome(User *listaUser, char *nome)
{
    User *listaAux = listaUser;
    int comparador;
    while (comparador == 0)
    {
        User *busca = listaAux;
        busca->proximoUser = NULL;
        return busca;
        if (listaAux->proximoUser == NULL)
        {
            printf("\nNao existe um usuario com esse nome");
            return NULL;
        }
        listaAux = listaAux->proximoUser;
    }
}

int removerPorId(User *listaUser, int id)
{
    if (listaUser == NULL)
    {
        printf("Nao existe usuario com esse id");
        return 0;
    }
    else
    {
        User *listaAux = listaUser;
        User *inicio = listaUser;
        User *anterior = NULL;
        while (listaAux != NULL)
        {
            if (listaAux->perfilDoUsuario->id == id)
            {
                if (anterior == NULL)
                {
                    User *proximoAux = listaAux->proximoUser;
                    free(listaUser);
                    return proximoAux;
                }
                else
                {
                    anterior->proximoUser = listaAux->proximoUser;
                    free(listaUser);
                    return inicio;
                }
            }
            if (listaAux->proximoUser == NULL)
            {
                printf("\nNao foi encontrado nenhum usuario com esse id");
                return 0;
            }
            anterior = listaAux;
            listaAux = listaAux->proximoUser;
        }
    }
}

int removerPorNome(User *listaUser, char *nome)
{
    
}

void solicitarAmizade(User *listaUser, int idPerfilSolicitante, int idPerfilAmigo)
{
}

void aceitarPrimeiraSolicitacaoAmizade(User *listaUser, int idPerfil)
{
}

void aceitarTodasSolicitacaoAmizade(User *listaUser, int idPerfil)
{
}

void rejeitarTodasSolicitacaoAmizade(User *listaUser, int idPerfil)
{
}

void rejeitarPrimeiraSolicitacaoAmizade(User *listaUser, int idPerfil)
{
}

int numAmigos(User *listaUser, int idPerfil)
{
}

int numUsers(User *listaUser)
{
}

int numSolicitacoesAmigos(User *listaUser, int idPerfil)
{
}

User *quemEhOPerfilMaisAmigo(User *listaUser)
{
}

User *recomendarAmizade(int idPerfil, User *listaUser)
{
}

int main()
{
    int menu, id = 0, buscaId = 0;
    char buscaNome[TAMANHO];
    User *listaUser = NULL;
    while (menu != 0)
    {
        printf("Oque deseja fazer?\n");
        printf("1 - criar perfil\n2 - procurar user por id\n3 - procurar user por nome\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            id++;
            criarUsuario(id);
            break;
        case 2:
            printf("insira o id");
            scanf("%d", &buscaId);
            printf("");
        }
    }
    return 0;
}
