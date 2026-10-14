#include <stdio.h>

int main() {
    int opcao;

 
    while (1) {
      
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Dizer Ola\n");
        printf("2. Mostrar data de hoje\n");
        printf("3. Sair do programa\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("\nOlá! Bem-vindo ao programa.\n");
        }
        else if (opcao == 2) {
            printf("\nHoje e dia 14 de Outubro de 2026.\n");
        }
        else if (opcao == 3) {
            printf("\nA terminar o programa... Adeus!\n");
            break; 
        }
        else {
            printf("\nOpcao invalida! Tente novamente.\n");
        }
    }

    printf("Programa finalizado com sucesso.\n");
    return 0;
}
