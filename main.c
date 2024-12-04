#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da struct para armazenar os dados do lançamento
typedef struct {
    int lados;
    int lancamentos;
    int total;
    char dataHora[20]; // Para armazenar a data e hora do lançamento
} Historico;

// Função para lançar o dado
void lancarDado(Historico *dado) {
    int valorDado;
    dado->total = 0;

    printf("\nLançando um dado de %d lados %d vez(es):\n\n", dado->lados, dado->lancamentos);
    for (int i = 0; i < dado->lancamentos; i++) {
        valorDado = (rand() % dado->lados) + 1;
        dado->total += valorDado;
        printf("Lançamento %d: %d\n", i + 1, valorDado);
    }

    if (dado->lancamentos > 1) {
printf("++++++++++++++++++++\n");
printf("+    Total: %5d  +\n", dado->total);
printf("++++++++++++++++++++\n");

    // Capturando a data e hora do lançamento
    time_t agora = time(NULL);
    struct tm *tempo = localtime(&agora);
    strftime(dado->dataHora, sizeof(dado->dataHora), "%d/%m/%Y %H:%M:%S", tempo);
        
    }
}

// Função para salvar os dados no arquivo
void salvarLancamentoEmArquivo(Historico dado, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a"); // Abre o arquivo em modo de adição
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os dados.\n");
        return;
    }

    fprintf(arquivo, "Data/Hora: %s | Dado: %d lados | Lançamentos: %d | Total: %d\n",
            dado.dataHora, dado.lados, dado.lancamentos, dado.total);

    fclose(arquivo);
}

int main() {
    int escolha;
    Historico dado; // Struct para armazenar o histórico do lançamento
    const char *nomeArquivo = "lancamentos.txt"; // Nome do arquivo de saída

    // Inicializando a semente do gerador de números aleatórios
    srand(time(NULL));

    do {
        printf("\nEscolha um dado para lançar:\n");
        printf("1. 4 lados\n");
        printf("2. 6 lados\n");
        printf("3. 8 lados\n");
        printf("4. 10 lados\n");
        printf("5. 12 lados\n");
        printf("6. 20 lados\n");
        printf("7. 100 lados\n");
        printf("8. Personalizado\n");
        printf("0. Finalizar programa\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            printf("\nEncerrando o programa. Obrigado por jogar!\n");
            break;
        }

        // Validando a escolha do dado
        switch (escolha) {
            case 1: dado.lados = 4; break;
            case 2: dado.lados = 6; break;
            case 3: dado.lados = 8; break;
            case 4: dado.lados = 10; break;
            case 5: dado.lados = 12; break;
            case 6: dado.lados = 20; break;
            case 7: dado.lados = 100; break;
            case 8:
                printf("\nDigite o número de lados para o dado personalizado: ");
                scanf("%d", &dado.lados);
                if (dado.lados <= 0) {
                    printf("Número de lados inválido.\n");
                    continue;
                }
                break;
            default:
                printf("\nEscolha inválida. Tente novamente.\n");
                continue;
        }

        printf("\nDigite o número de vezes para lançar o dado: ");
        scanf("%d", &dado.lancamentos);

        if (dado.lancamentos <= 0) {
            printf("Número de lançamentos inválido. Tente novamente.\n");
            continue;
        }

        lancarDado(&dado); // Realiza o lançamento
        salvarLancamentoEmArquivo(dado, nomeArquivo); // Salva os dados no arquivo

    } while (escolha !=0);
return 0;
}