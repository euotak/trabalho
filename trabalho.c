#include <stdio.h>
#include <stdbool.h>

#define MAX_DIGITS 19  // Máximo de dígitos

// Declaração das funções
// Função para ler dados e inicializar variáveis
void ler_dados(int *base10_1, int *base10_2, int base3_1[], int base3_2[]) {
    // Solicita ao usuário que insira dois números em base 10
    // Converte os números inseridos para base 3 e armazena em base3_1 e base3_2
}

// Função para somar dois números representados em base 3
void somar(int base3_1[], int base3_2[], int resultado[]) {
    // Implementa a soma de dois números em base 3
    // Considera o carry (retenção) e a adição em base 3
    // Armazena o resultado da soma no array resultado
}

// Função para multiplicar dois números representados em base 3
void multiplicar(int base3_1[], int base3_2[], int resultado[]) {
    // Implementa a multiplicação de dois números em base 3
    // Considera a multiplicação e a acumulação em base 3
    // Armazena o resultado da multiplicação no array resultado
}

// Função para converter um número de base 10 para base 3
void base10_para_base3(int base10, int base3[]) {
    // Converte um número de base 10 para base 3
    // Divide o número por 3 e armazena os restos no array base3
    // Preenche o array base3 com os dígitos da base 3 do número
}

// Função para converter um número de base 3 para base 10
int base3_para_base10(const int base3[]) {
    // Converte um número de base 3 para base 10
    // Reconstrói o número a partir dos valores armazenados no array base3
    // Retorna o número convertido em base 10
}

// Função para inicializar um array com zeros
void inicializar_array(int array[], int tamanho) {
    // Preenche o array com zeros
    // Utiliza um loop para definir todos os elementos como zero
}


int main() {
    int opcao;
    int base10_1 = 0, base10_2 = 0;  // Armazena os números em base 10
    int base3_1[MAX_DIGITS] = {0}, base3_2[MAX_DIGITS] = {0}, resultado[MAX_DIGITS] = {0};  // Arrays para números na base 3

    while (true) {
        printf("Menu:\n");
        printf("1. Ler dados\n");
        printf("2. Somar\n");
        printf("3. Multiplicar\n");
        printf("4. Sair\n");
        printf("5. Executar testes\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);  // Lê a opção do usuário

        switch (opcao) {
            case 1:
                // Lê dois números naturais do usuário
                printf("Digite dois números naturais entre 0 e %lld: ", (long long) 1162261466); // 3^19 - 1
                if (scanf("%d %d", &base10_1, &base10_2) != 2 || base10_1 < 0 || base10_1 > 1162261466 || base10_2 < 0 || base10_2 > 1162261466) {
                    printf("Entrada inválida. Por favor, insira números naturais dentro do intervalo válido.\n");
                    while (getchar() != '\n');  // Limpar o buffer de entrada para evitar loop infinito
                    break;
                }
                ler_dados(&base10_1, &base10_2, base3_1, base3_2);  // Converte para base 3 e armazena nos arrays
                break;
            case 2:
                // Soma os números em base 3
                somar(base3_1, base3_2, resultado);
                printf("Resultado da soma: %d\n", base3_para_base10(resultado));  // Converte o resultado para base 10 e imprime
                break;
            case 3:
                // Multiplica os números em base 3
                multiplicar(base3_1, base3_2, resultado);
                printf("Resultado da multiplicação: %d\n", base3_para_base10(resultado));  // Converte o resultado para base 10 e imprime
                break;
            case 4:
                // Sai do programa
                return 0;
            case 5:
                // Executa testes
                executar_testes();
                break;
            default:
                // Opção inválida
                printf("Opção inválida!\n");
        }
        inicializar_array(resultado, MAX_DIGITS);  // Inicializa o array de resultado para a próxima operação
    }
}

// Função para ler dados e converter para base 3
void ler_dados(int *base10_1, int *base10_2, int base3_1[], int base3_2[]) {
    base10_para_base3(*base10_1, base3_1);  // Converte o primeiro número para base 3
    base10_para_base3(*base10_2, base3_2);  // Converte o segundo número para base 3
}

// Função para somar dois números em base 3
void somar(int base3_1[], int base3_2[], int resultado[]) {
    int carry = 0;  // Variável para armazenar o carry
    for (int i = 0; i < MAX_DIGITS; i++) {
        int soma = base3_1[i] + base3_2[i] + carry;  // Soma os dígitos correspondentes e o carry
        resultado[i] = soma % 3;  // Armazena o resultado no dígito atual
        carry = soma / 3;  // Calcula o novo carry
    }
}

// Função para multiplicar dois números em base 3
void multiplicar(int base3_1[], int base3_2[], int resultado[]) {
    int resultado_temp[MAX_DIGITS] = {0};  // Array temporário para armazenar o resultado intermediário

    for (int i = 0; i < MAX_DIGITS; i++) {
        if (base3_2[i] != 0) {  // Verifica se o dígito atual de base3_2 é diferente de zero
            int carry = 0;
            for (int j = 0; j < MAX_DIGITS - i; j++) {
                int produto = base3_1[j] * base3_2[i] + carry + resultado_temp[i + j];  // Multiplica os dígitos e adiciona o carry
                resultado_temp[i + j] = produto % 3;  // Armazena o resultado no dígito correspondente
                carry = produto / 3;  // Calcula o novo carry
            }
        }
    }

    for (int i = 0; i < MAX_DIGITS; i++) {
        resultado[i] = resultado_temp[i];  // Copia o resultado temporário para o resultado final
    }
}

// Função para converter um número da base 10 para a base 3
void base10_para_base3(int base10, int base3[]) {
    for (int i = 0; i < MAX_DIGITS; i++) {
        base3[i] = base10 % 3;  // Calcula o dígito atual na base 3
        base10 /= 3;  // Divide o número por 3 para calcular o próximo dígito
    }
}

// Função para converter um número da base 3 para a base 10
int base3_para_base10(const int base3[]) {
    int base10 = 0;
    int potencia = 1;
    for (int i = 0; i < MAX_DIGITS; i++) {
        base10 += base3[i] * potencia;  // Calcula o valor do dígito atual na base 10
        potencia *= 3;  // Multiplica a potência por 3 para o próximo dígito
    }
    return base10;  // Retorna o número convertido
}

// Função para inicializar um array com zeros
void inicializar_array(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = 0;  // Inicializa cada elemento do array com zero
    }
}
