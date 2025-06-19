

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // Necessário para a função isnan()
#include "expressao.h"

// Função para limpar o buffer de entrada, evitando problemas com scanf
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir o menu de opções
void exibir_menu() {
    printf("\n--- Avaliador de Expressoes Matematicas ---\n");
    printf("1. Traduzir Infixa para Pos-fixa\n");
    printf("2. Traduzir Pos-fixa para Infixa\n");
    printf("3. Calcular valor de expressao Infixa\n");
    printf("4. Calcular valor de expressao Pos-fixa\n");
    printf("0. Sair\n");
    printf("-------------------------------------------\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int escolha;
    char buffer[512];
    char* resultado_str;
    float resultado_val;

    while (1) {
        exibir_menu();
        if (scanf("%d", &escolha) != 1) {
            printf("Entrada invalida. Por favor, digite um numero.\n");
            limpar_buffer();
            continue;
        }
        limpar_buffer(); // Limpa o '\n' deixado pelo scanf

        switch (escolha) {
            case 1: // Infixa para Pós-fixa
                printf("Digite a expressao infixa: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0; // Remove o '\n' do final

                resultado_str = getFormaPosFixa(buffer);
                if (resultado_str && strlen(resultado_str) > 0) {
                    printf("Forma Pos-fixa: %s\n", resultado_str);
                } else {
                    printf("Nao foi possivel converter a expressao.\n");
                }
                break;

            case 2: // Pós-fixa para Infixa
                printf("Digite a expressao pos-fixa (com espacos): ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;

                resultado_str = getFormaInFixa(buffer);
                 if (resultado_str && strlen(resultado_str) > 0) {
                    printf("Forma Infixa: %s\n", resultado_str);
                } else {
                    printf("Nao foi possivel converter a expressao.\n");
                }
                break;

            case 3: // Calcular valor de Infixa
                printf("Digite a expressao infixa: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;

                resultado_val = getValorInFixa(buffer);
                if (!isnan(resultado_val)) {
                    printf("Resultado: %.2f\n", resultado_val);
                } else {
                    printf("Erro ao avaliar a expressao.\n");
                }
                break;

            case 4: // Calcular valor de Pós-fixa
                printf("Digite a expressao pos-fixa (com espacos): ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;

                resultado_val = getValorPosFixa(buffer);
                 if (!isnan(resultado_val)) {
                    printf("Resultado: %.2f\n", resultado_val);
                } else {
                    printf("Erro ao avaliar a expressao.\n");
                }
                break;

            case 0:
                printf("Saindo do programa...\n");
                return 0;

            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    }

    return 0;
}