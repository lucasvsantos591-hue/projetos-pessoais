#include <stdio.h>
#include <string.h>

/*
  Super Trunfo - comparação entre duas cartas
  Requisitos:
  - Cada carta tem: Estado, Código, Nome, População, Área, PIB, Pontos turísticos
  - Calcula Densidade populacional (população / área) e PIB per capita (PIB / população)
  - Compara apenas um atributo numérico (definido abaixo em 'atributoEscolhido')
  - Para Densidade: menor valor vence. Para os demais: maior valor vence.
*/

/* Tipos de atributos possíveis para comparação */
typedef enum {
    ATTR_POPULACAO,
    ATTR_AREA,
    ATTR_PIB,
    ATTR_DENSIDADE,     /* densidade populacional: população / área */
    ATTR_PIB_PER_CAPITA  /* pib per capita: pib / população */
} AtributoComparacao;

/* Estrutura que representa uma carta */
typedef struct {
    char estado[50];
    char codigo[16];
    char nome[60];
    int populacao;       /* número inteiro */
    float area;          /* em km², por exemplo */
    double pib;          /* em unidades monetárias (ex.: reais) */
    int pontos_turisticos;
    /* campos calculados: */
    double densidade;    /* população / área */
    double pib_per_capita; /* pib / população */
} Carta;

/* Função para calcular atributos derivados com checagens de divisão por zero */
void calcular_derived(Carta *c) {
    if (c->area > 0.0f) {
        c->densidade = (double)c->populacao / (double)c->area;
    } else {
        c->densidade = -1.0; /* indicador de valor inválido */
    }

    if (c->populacao > 0) {
        c->pib_per_capita = c->pib / (double)c->populacao;
    } else {
        c->pib_per_capita = -1.0; /* indicador de valor inválido */
    }
}

/* Função auxiliar para imprimir um número (double) com mensagem curta */
void imprimir_valor_atributo(AtributoComparacao attr, double valor) {
    switch (attr) {
        case ATTR_POPULACAO:
            printf("%.0f\n", valor);
            break;
        case ATTR_AREA:
            printf("%.2f\n", valor);
            break;
        case ATTR_PIB:
            printf("%.2f\n", valor);
            break;
        case ATTR_DENSIDADE:
            printf("%.4f\n", valor);
            break;
        case ATTR_PIB_PER_CAPITA:
            printf("%.4f\n", valor);
            break;
        default:
            printf("%.4f\n", valor);
    }
}

int main(void) {
    /* ---------- DEFINIÇÃO DAS CARTAS (pré-definidas) ---------- */
    Carta carta1;
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo, "C001");
    strcpy(carta1.nome, "São Paulo");
    carta1.populacao = 12300000;   /* exemplo */
    carta1.area = 1521.11f;        /* exemplo em km² */
    carta1.pib = 700000000000.0;   /* exemplo em reais */
    carta1.pontos_turisticos = 10;

    Carta carta2;
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.codigo, "C002");
    strcpy(carta2.nome, "Rio de Janeiro");
    carta2.populacao = 6000000;    /* exemplo */
    carta2.area = 1182.30f;        /* exemplo em km² */
    carta2.pib = 250000000000.0;   /* exemplo em reais */
    carta2.pontos_turisticos = 12;

    /* Calcula densidade e pib per capita (com tratamento de divisões inválidas) */
    calcular_derived(&carta1);
    calcular_derived(&carta2);

    /* ---------- ESCOLHA DO ATRIBUTO PARA COMPARAÇÃO ----------
       Defina aqui qual atributo será usado para decidir o vencedor.
       Opções: ATTR_POPULACAO, ATTR_AREA, ATTR_PIB, ATTR_DENSIDADE, ATTR_PIB_PER_CAPITA

       Observação: a escolha é feita diretamente no código conforme requisitos do exercício.
    */
    AtributoComparacao atributoEscolhido = ATTR_POPULACAO; /* <-- ajuste aqui conforme*_
