#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.

typedef struct No
{
    char valor[50];
    struct No *direita;
    struct No *esquerda;
} no_arvore_binaria_t;

no_arvore_binaria_t *criarSala(char *valor);
no_arvore_binaria_t *explorarSalas(no_arvore_binaria_t *proximaSala, no_arvore_binaria_t *salaOriginal);
void liberarMemoria(no_arvore_binaria_t *mapa);

int main()
{

    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    // Criando Salas
    no_arvore_binaria_t *mapa = criarSala("Hall de Entrada");

    mapa->direita = criarSala("Sala de Lazer");
    mapa->esquerda = criarSala("Biblioteca");

    mapa->direita->direita = criarSala("Cozinha");
    mapa->direita->esquerda = criarSala("Sótão");

    int opcao;
    no_arvore_binaria_t *jogador = mapa;

    do
    {
        printf("\n\n SALA ATUAL: %s\n", jogador->valor);

        printf("\n === MENU DE AÇÕES ===\n");
        printf(" 1. Caminhar para a ESQUERDA\n");
        printf(" 2. Caminhar para a DIREITA\n");
        printf(" 0. Sair\n");

        printf("\nDigite uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 0:
            liberarMemoria(mapa);
            break;
        case 1:
            jogador = explorarSalas(jogador->esquerda, mapa);
            break;
        case 2:
            jogador = explorarSalas(jogador->direita, mapa);
            break;
        default:
            printf("Opção inválida, escolha uma opção do menu!\n");
            break;
        }
    } while (opcao != 0);

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().

    return 0;
}

no_arvore_binaria_t *criarSala(char *valor)
{
    no_arvore_binaria_t *no = malloc(sizeof(no_arvore_binaria_t));
    strcpy(no->valor, valor);
    no->direita = NULL;
    no->esquerda = NULL;
    return no;
}

no_arvore_binaria_t *explorarSalas(no_arvore_binaria_t *proximaSala, no_arvore_binaria_t *salaOriginal)
{
    if(proximaSala == NULL) {
        printf("Não há mais salas para explorar, retornando a sala original...\nAperte qualquer tecla para continuar");
        getchar();
        return salaOriginal;
    }
    return proximaSala;
}

void liberarMemoria(no_arvore_binaria_t *mapa) {
    if(mapa != NULL) {
        liberarMemoria(mapa->esquerda);
        liberarMemoria(mapa->direita);
        free(mapa);
    }
}