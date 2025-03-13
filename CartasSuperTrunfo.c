#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta do Super Trunfo
typedef struct {
    char estado;
    char codigo[4]; // Código da carta (ex: A01, B03)
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} CartaSuperTrunfo;

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para ler os dados de uma carta
void lerCarta(CartaSuperTrunfo *carta, int num) {
    printf("\nCadastro da Carta %d:\n", num);
    
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);
    limparBuffer();
    
    printf("Código da Carta (ex: A01): ");
    scanf(" %s", carta->codigo);
    limparBuffer();
    
    printf("Nome da Cidade: ");
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = '\0'; // Remover a quebra de linha
    
    printf("População: ");
    scanf("%d", &carta->populacao);
    
    printf("Área (em km²): ");
    scanf("%f", &carta->area);
    
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);
    
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para exibir os dados de uma carta
void exibirCarta(const CartaSuperTrunfo *carta, int num) {
    printf("\nCarta %d:\n", num);
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nomeCidade);
    printf("População: %d habitantes\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("Número de Pontos Turísticos: %d\n", carta->pontosTuristicos);
}

int main() {
    CartaSuperTrunfo carta1, carta2;
    
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);
    
    printf("\nExibindo as cartas cadastradas:\n");
    exibirCarta(&carta1, 1);
    exibirCarta(&carta2, 2);
    
    return 0;
    
}
