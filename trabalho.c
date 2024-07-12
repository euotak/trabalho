#include <stdio.h>
#include <stdbool.h>

#define MAX_DIGITS 19

void read_data(int *base10_1, int *base10_2, int base3_1[], int base3_2[]);
void add(int base3_1[], int base3_2[], int result[]);
void multiply(int base3_1[], int base3_2[], int result[]);
void base10_to_base3(int base10, int base3[]);
int base3_to_base10(int base3[]);
void initialize_array(int array[], int size);

int main() {
    int option;
    int base10_1 = 0, base10_2 = 0;
    int base3_1[MAX_DIGITS] = {0}, base3_2[MAX_DIGITS] = {0}, result[MAX_DIGITS] = {0};

    while (true) {
        printf("Menu:\n");
        printf("1. Ler dados\n");
        printf("2. Somar\n");
        printf("3. Multiplicar\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Digite dois numeros naturais entre 0 e %lld: ", (long long) 1162261466); // 3^19 - 1
                scanf("%d %d", &base10_1, &base10_2);
                read_data(&base10_1, &base10_2, base3_1, base3_2);
                break;
            case 2:
                add(base3_1, base3_2, result);
                printf("Resultado da soma: %d\n", base3_to_base10(result));
                break;
            case 3:
                multiply(base3_1, base3_2, result);
                printf("Resultado da multiplicacao: %d\n", base3_to_base10(result));
                break;
            case 4:
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
        initialize_array(result, MAX_DIGITS);
    }
}

void read_data(int *base10_1, int *base10_2, int base3_1[], int base3_2[]) {
    base10_to_base3(*base10_1, base3_1);
    base10_to_base3(*base10_2, base3_2);
}

void add(int base3_1[], int base3_2[], int result[]) {
    int carry = 0;
    for (int i = 0; i < MAX_DIGITS; i++) {
        int sum = base3_1[i] + base3_2[i] + carry;
        result[i] = sum % 3;
        carry = sum / 3;
    }
}

void multiply(int base3_1[], int base3_2[], int result[]) {
    int temp_result[MAX_DIGITS] = {0};

    for (int i = 0; i < MAX_DIGITS; i++) {
        if (base3_2[i] != 0) {
            int carry = 0;
            for (int j = 0; j < MAX_DIGITS - i; j++) {
                int prod = base3_1[j] * base3_2[i] + carry + temp_result[i + j];
                temp_result[i + j] = prod % 3;
                carry = prod / 3;
            }
        }
    }

    for (int i = 0; i < MAX_DIGITS; i++) {
        result[i] = temp_result[i];
    }
}

void base10_to_base3(int base10, int base3[]) {
    for (int i = 0; i < MAX_DIGITS; i++) {
        base3[i] = base10 % 3;
        base10 /= 3;
    }
}

int base3_to_base10(int base3[]) {
    int base10 = 0;
    int power = 1;
    for (int i = 0; i < MAX_DIGITS; i++) {
        base10 += base3[i] * power;
        power *= 3;
    }
    return base10;
}

void initialize_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
}
