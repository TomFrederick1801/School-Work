#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { ESQUERDA, DIREITA, PARAR } Direcao;


typedef struct No {
    char simbolo;
    struct No* esquerdo;
    struct No* direito;
} No;


typedef struct {
    int estado_atual;
    char simbolo_lido;
    int proximo_estado;
    char simbolo_escrita;
    Direcao movimento;
} Transicao;


No* criar_no(char simbolo) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        fprintf(stderr, "Erro de alocação de memória!\n");
        exit(1);
    }
    novo->simbolo = simbolo;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}


void executar_turing(No** cabeca, Transicao tabela[], int total_regras, int estado_inicial, int estado_final) {
    int estado = estado_inicial;
    No* atual = *cabeca;

    while (estado != estado_final) {
        int regra_encontrada = 0;
        char simbolo_atual = atual->simbolo;

       
        for (int i = 0; i < total_regras; i++) {
            if (tabela[i].estado_atual == estado && tabela[i].simbolo_lido == simbolo_atual) {

                
                atual->simbolo = tabela[i].simbolo_escrita;

                
                estado = tabela[i].proximo_estado;

                
                if (tabela[i].movimento == DIREITA) {
                    if (atual->direito == NULL) {
                        atual->direito = criar_no('_'); 
                        atual->direito->esquerdo = atual;
                    }
                    atual = atual->direito;
                }
                else if (tabela[i].movimento == ESQUERDA) {
                    if (atual->esquerdo == NULL) {
                        atual->esquerdo = criar_no('_');
                        atual->esquerdo->direito = atual;
                    }
                    atual = atual->esquerdo;
                }

                regra_encontrada = 1;
                break; 
            }
        }

        
        if (!regra_encontrada) {
            printf("Máquina travou: nenhuma transição encontrada para o Estado %d com o símbolo '%c'.\n", estado, simbolo_atual);
            return;
        }
    }
    printf("Execução concluída com sucesso! Estado Final alcançado.\n");
}


void exibir_fita(No* no_inicial) {
    
    while (no_inicial->esquerdo != NULL) {
        no_inicial = no_inicial->esquerdo;
    }
    
    while (no_inicial != NULL) {
        printf("%c ", no_inicial->simbolo);
        no_inicial = no_inicial->direito;
    }
    printf("\n");
}

int main() {
    
    No* fita = criar_no('1');
    fita->direito = criar_no('1'); fita->direito->esquerdo = fita;
    fita->direito->direito = criar_no('0'); fita->direito->direito->esquerdo = fita->direito;

   
    Transicao programa[] = {
        
        {0, '1', 0, '1', DIREITA},
        {0, '0', 0, '0', DIREITA},
        {0, '_', 1, '_', ESQUERDA},  

        {1, '0', 2, '1', PARAR},     
        {1, '1', 1, '0', ESQUERDA}, 
        {1, '_', 2, '1', PARAR}     
    };

    int total_regras = sizeof(programa) / sizeof(programa[0]);

    printf("Fita antes: ");
    exibir_fita(fita);

    
    executar_turing(&fita, programa, total_regras, 0, 2);

    printf("Fita depois: ");
    exibir_fita(fita);

    return 0;
}
