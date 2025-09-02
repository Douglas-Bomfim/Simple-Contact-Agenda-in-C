#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tipo_REGISTRO{
char nome[20];
char telefone[14];
char endereco[30];
}Tipo_REGISTRO;
Tipo_REGISTRO vetor[10];
int quantidade_de_registros_inseridos=0;
void mostraTodos(Tipo_REGISTRO v[]);
void insereRegistro(Tipo_REGISTRO v[], char nome[], char telefone[], char endereco[]);
void pesquisaRegistroPorNome(Tipo_REGISTRO v[], char nome[]);


int main()
{
    char nome[20];
    char telefone[14];
    char endereco[30];
    int x;
    while(x!=4)
    {
    printf("     Menu\n[1] - mostra mostra todos os registros na tela\n[2] - Insere um novo registro\n[3] - Pesquisa registro baseado no nome.\n[4] - Para fechar a agenda\n");
    scanf("%d", &x);

    switch(x)
    {
   case 1:
    mostraTodos( vetor);
    break;
    case 2:
     printf("Informe o nome do contato\n");
     getchar();
     fgets(nome, 20, stdin);
     printf("Informe o numero do contato\n");
     fgets(telefone, 14, stdin);
     printf("Informe o endereço do contato\n");
     getchar();
     fgets(endereco, 30, stdin);
     insereRegistro (vetor, nome, telefone, endereco);
     break;
    case 3:
    printf("Informe o nome do contato:\n");
    getchar();
    fgets(nome, 20, stdin);
    pesquisaRegistroPorNome(vetor, nome);
    break;
    default:
        break;
    }
    }
}

void mostraTodos (Tipo_REGISTRO v[])
{
    int z;
    for(z=0;z<quantidade_de_registros_inseridos;z++)
    {
      printf("Nome:%s\nNumero:%s\nEndereco:%s\n", vetor[z].nome, vetor[z].telefone, vetor[z].endereco);
    }
}

void insereRegistro (Tipo_REGISTRO v[], char nome[], char telefone[], char endereco[])
{
    int slotsdisponiveis;
    slotsdisponiveis=10-quantidade_de_registros_inseridos;
    printf("Slots livre %d\n\n", slotsdisponiveis);
    if(slotsdisponiveis==0)
    {
        printf("Slots cheios");
    }
    else
    {
    strcpy(vetor[quantidade_de_registros_inseridos].nome,nome);
    strcpy(vetor[quantidade_de_registros_inseridos].endereco,endereco);
    strcpy(vetor[quantidade_de_registros_inseridos].telefone, telefone);
    quantidade_de_registros_inseridos++;
    }
}

void pesquisaRegistroPorNome(Tipo_REGISTRO v[], char nome[])
{
    int i;
    for(i=0; i<quantidade_de_registros_inseridos; i++)
    {
        if(strcmp(v[i].nome, nome)==0)
        {
            printf("Nome:%s\nNumero:%s\nEndereco:%s\n", v[i].nome, v[i].telefone, v[i].endereco);
            break;
        }
    }

}
