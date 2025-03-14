#include <stdio.h>

int main() {
    // Declaração de variáveis para Carta 1 e Carta 2
    char estado1, estado2;
    int codigo1, codigo2, menuOpcaoEscolhida1, menuOpcaoEscolhida2, resultado1, resultado2;  
    char nomeCidade1[50], nomeCidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontosTuristicos1, pontosTuristicos2;
    char estadoConcatenado1[5], estadoConcatenado2[5];

    printf("*** INPUT DOS DADOS ***\n\n");

    // Cadastro da Carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o Estado da Carta (A a H): ");
    scanf(" %c", &estado1);
    printf("Digite o Codigo da Carta (1 a 4): ");
    scanf("%d", &codigo1);
    sprintf(estadoConcatenado1, "%c%02d", estado1, codigo1);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]s", nomeCidade1); //Usado %49 para limitar a leitura e evitar estouro de buffer.
    printf("Populacao (em milhares de habitantes): ");
    scanf("%lu", &populacao1);
    printf("Area (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\n");

    // Cadastro da Carta 2
    printf("=== Cadastro da Carta 2 ===\n");
    printf("Digite o Estado da Carta (A a H): ");
    scanf(" %c", &estado2);
    printf("Digite o Codigo da Carta (1 a 4): ");
    scanf("%d", &codigo2);
    sprintf(estadoConcatenado2, "%c%02d", estado2, codigo2);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]s", nomeCidade2); //Usado %49 para limitar a leitura e evitar estouro de buffer.
    printf("Populacao (em milhares de habitantes): ");
    scanf("%lu", &populacao2);
    printf("Area (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Conversões para valores reais
    unsigned long int populacaoReal1 = populacao1 * 1000;
    unsigned long int populacaoReal2 = populacao2 * 1000;
    unsigned long int pibEmReais1 = pib1 * 1e9;
    unsigned long int pibEmReais2 = pib2 * 1e9;

    // Cálculo dos atributos derivados
    float densidadePopulacional1 = populacaoReal1 / area1;
    float pibPerCapita1 = pibEmReais1 / populacaoReal1;
    float densidadePopulacional2 = populacaoReal2 / area2;
    float pibPerCapita2 = pibEmReais2 / populacaoReal2;

    // Cálculo do Super Poder
    float superPoderCarta1 = populacaoReal1 + area1 + pibEmReais1 + pontosTuristicos1 + pibPerCapita1 + (1 / densidadePopulacional1);
    float superPoderCarta2 = populacaoReal2 + area2 + pibEmReais2 + pontosTuristicos2 + pibPerCapita2 + (1 / densidadePopulacional2);

    // Exibição das Cartas
    printf("\n*** Exibição das Cartas ***\n\n");
    printf("\n=== CARTA 1 ===\n");
    printf("Estado: %s\n", estadoConcatenado1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu habitantes\n", populacaoReal1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: R$ %.2f bilhões\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoderCarta1);

    printf("\n=== CARTA 2 ===\n");
    printf("Estado: %s\n", estadoConcatenado2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %lu habitantes\n", populacaoReal2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: R$ %.2f bilhões\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita2);
    printf("Super Poder: %.2f\n\n", superPoderCarta2);

    printf("== DUELO DE ATRIBUTOS ==\n");
    printf("Escolha 2 atributos para serem comparados:\n");

    //MENU INTERATIVO
    printf("### MENU ###\n");
    printf("Escolha o primeiro atributo: \n");
    printf("1. POPULAÇÃO\n");
    printf("2. AREA\n");
    printf("3. PIB\n");
    printf("4. PONTOS TURISTICOS\n");
    printf("5. DENSIDADE POPULACIONAL\n");
    printf("6. PIB PER CAPITA\n");
    printf("7. SUPER PODER\n");
    printf("8. ENCERRAR PROGRAMA\n");
    printf("Escolha: \n");

    scanf("%d", &menuOpcaoEscolhida1);

    //ABAIXO LOGICA SWITCH CASE
    switch (menuOpcaoEscolhida1)
    {
    case 1:
        // Comparação de População
        if (populacaoReal1 > populacaoReal2) {
            resultado1 = 1;
            printf("Comparação de cartas (Atributo: População):\n\n");
            printf("Carta 1 - %s: %lu habitantes\n", nomeCidade1, populacaoReal1);
            printf("Carta 2 - %s: %lu habitantes\n", nomeCidade2, populacaoReal2);
            printf("Resultado: Carta 1 (%s) venceu!\n\n", nomeCidade1);
        } else if (populacaoReal2 > populacaoReal1) {
            resultado1 = 0;
            printf("Comparação de cartas (Atributo: População):\n\n");
            printf("Carta 1 - %s: %lu habitantes\n", nomeCidade1, populacaoReal1);
            printf("Carta 2 - %s: %lu habitantes\n", nomeCidade2, populacaoReal2);
            printf("Resultado: Carta 2 (%s) venceu!\n\n", nomeCidade2);
        } else {
            printf("Comparação de cartas (Atributo: População):\n\n");
            printf("Carta 1 - %s: %lu habitantes\n", nomeCidade1, populacaoReal1);
            printf("Carta 2 - %s: %lu habitantes\n", nomeCidade2, populacaoReal2);
            printf("Resultado: Empate!\n\n");
        }
        break;

    case 2:
        // Comparação de Área
        if (area1 > area2) {
            resultado1 = 1;
            printf("Comparação de cartas (Atributo: Área):\n\n");
            printf("Carta 1 - %s: %.2f km²\n", nomeCidade1, area1);
            printf("Carta 2 - %s: %.2f km²\n", nomeCidade2, area2);
            printf("Resultado: Carta 1 (%s) venceu!\n\n", nomeCidade1);
        } else if (area2 > area1) {
            resultado1 = 0;
            printf("Comparação de cartas (Atributo: Área):\n\n");
            printf("Carta 1 - %s: %.2f km²\n", nomeCidade1, area1);
            printf("Carta 2 - %s: %.2f km²\n", nomeCidade2, area2);
            printf("Resultado: Carta 2 (%s) venceu!\n\n", nomeCidade2);
        } else {
            printf("Comparação de cartas (Atributo: Área):\n\n");
            printf("Carta 1 - %s: %.2f km²\n", nomeCidade1, area1);
            printf("Carta 2 - %s: %.2f km²\n", nomeCidade2, area2);
            printf("Resultado: Empate!\n\n");
        }
        break;

    case 3:
        // Comparação de PIB
        if (pibEmReais1 > pibEmReais2) {
            resultado1 = 1;
            printf("Comparação de cartas (Atributo: PIB):\n\n");
            printf("Carta 1 - %s: R$ %.2f bilhões\n", nomeCidade1, pib1);
            printf("Carta 2 - %s: R$ %.2f bilhões\n", nomeCidade2, pib2);
            printf("Resultado: Carta 1 (%s) venceu!\n\n", nomeCidade1);
        } else if (pibEmReais2 > pibEmReais1) {
            resultado1 = 0;
            printf("Comparação de cartas (Atributo: PIB):\n\n");
            printf("Carta 1 - %s: R$ %.2f bilhões\n", nomeCidade1, pib1);
            printf("Carta 2 - %s: R$ %.2f bilhões\n", nomeCidade2, pib2);
            printf("Resultado: Carta 2 (%s) venceu!\n\n", nomeCidade2);
        } else {
            printf("Comparação de cartas (Atributo: PIB):\n\n");
            printf("Carta 1 - %s: R$ %.2f bilhões\n", nomeCidade1, pib1);
            printf("Carta 2 - %s: R$ %.2f bilhões\n", nomeCidade2, pib2);
            printf("Resultado: Empate!\n\n");
    }
        break;

    case 4:
        // Comparação de Pontos Turísticos
        if (pontosTuristicos1 > pontosTuristicos2) {
            resultado1 = 1;
            printf("Comparação de cartas (Atributo: Pontos Turísticos):\n\n");
            printf("Carta 1 - %s: %d pontos turísticos\n", nomeCidade1, pontosTuristicos1);
            printf("Carta 2 - %s: %d pontos turísticos\n", nomeCidade2, pontosTuristicos2);
            printf("Resultado: Carta 1 (%s) venceu!\n\n", nomeCidade1);
        } else if (pontosTuristicos2 > pontosTuristicos1) {
            resultado1 = 0;
            printf("Comparação de cartas (Atributo: Pontos Turísticos):\n\n");
            printf("Carta 1 - %s: %d pontos turísticos\n", nomeCidade1, pontosTuristicos1);
            printf("Carta 2 - %s: %d pontos turísticos\n", nomeCidade2, pontosTuristicos2);
            printf("Resultado: Carta 2 (%s) venceu!\n\n", nomeCidade2);
        } else {
            printf("Comparação de cartas (Atributo: Pontos Turísticos):\n\n");
            printf("Carta 1 - %s: %d pontos turísticos\n", nomeCidade1, pontosTuristicos1);
            printf("Carta 2 - %s: %d pontos turísticos\n", nomeCidade2, pontosTuristicos2);
            printf("Resultado: Empate!\n\n");
        }
        break;

    case 5:
        // Comparação de Densidade Populacional (MENOR vence)
        if (densidadePopulacional1 < densidadePopulacional2) {
            resultado1 = 1;
            printf("Comparação de cartas (Atributo: Densidade Populacional - MENOR vence):\n\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", nomeCidade1, densidadePopulacional1);
            printf("Carta 2 - %s: %.2f hab/km²\n", nomeCidade2, densidadePopulacional2);
            printf("Resultado: Carta 1 (%s) venceu!\n\n", nomeCidade1);
        } else if (densidadePopulacional2 < densidadePopulacional1) {
            resultado1 = 0;
            printf("Comparação de cartas (Atributo: Densidade Populacional - MENOR vence):\n\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", nomeCidade1, densidadePopulacional1);
            printf("Carta 2 - %s: %.2f hab/km²\n", nomeCidade2, densidadePopulacional2);
            printf("Resultado: Carta 2 (%s) venceu!\n\n", nomeCidade2);
        } else {
            printf("Comparação de cartas (Atributo: Densidade Populacional - MENOR vence):\n\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", nomeCidade1, densidadePopulacional1);
            printf("Carta 2 - %s: %.2f hab/km²\n", nomeCidade2, densidadePopulacional2);
            printf("Resultado: Empate!\n\n");
        }
        break;

    case 6:
        // Comparação de PIB per Capita
        if (pibPerCapita1 > pibPerCapita2) {
            resultado1 = 1;
            printf("Comparação de cartas (Atributo: PIB per Capita):\n\n");
            printf("Carta 1 - %s: R$ %.2f\n", nomeCidade1, pibPerCapita1);
            printf("Carta 2 - %s: R$ %.2f\n", nomeCidade2, pibPerCapita2);
            printf("Resultado: Carta 1 (%s) venceu!\n\n", nomeCidade1);
        } else if (pibPerCapita2 > pibPerCapita1) {
            resultado1 = 0;
            printf("Comparação de cartas (Atributo: PIB per Capita):\n\n");
            printf("Carta 1 - %s: R$ %.2f\n", nomeCidade1, pibPerCapita1);
            printf("Carta 2 - %s: R$ %.2f\n", nomeCidade2, pibPerCapita2);
            printf("Resultado: Carta 2 (%s) venceu!\n\n", nomeCidade2);
        } else {
            printf("Comparação de cartas (Atributo: PIB per Capita):\n\n");
            printf("Carta 1 - %s: R$ %.2f\n", nomeCidade1, pibPerCapita1);
            printf("Carta 2 - %s: R$ %.2f\n", nomeCidade2, pibPerCapita2);
            printf("Resultado: Empate!\n\n");
        }
        break;

    case 7:
        //Comparação do Super Poder
        if (superPoderCarta1 > superPoderCarta2) {
            resultado1 = 1;
            printf("Comparação de cartas (Atributo: Super Poder):\n\n");
            printf("Carta 1 - %s: %.2f pontos\n", nomeCidade1, superPoderCarta1);
            printf("Carta 2 - %s: %.2f pontos\n", nomeCidade2, superPoderCarta2);
            printf("Resultado: Carta 1 (%s) venceu!\n\n", nomeCidade1);
        } else if (superPoderCarta2 > superPoderCarta1) {
            resultado1 = 0;
            printf("Comparação de cartas (Atributo: Super Poder):\n\n");
            printf("Carta 1 - %s: %.2f pontos\n", nomeCidade1, superPoderCarta1);
            printf("Carta 2 - %s: %.2f pontos\n", nomeCidade2, superPoderCarta2);
            printf("Resultado: Carta 2 (%s) venceu!\n\n", nomeCidade2);
        } else {
            printf("Comparação de cartas (Atributo: Super Poder):\n\n");
            printf("Carta 1 - %s: %.2f pontos\n", nomeCidade1, superPoderCarta1);
            printf("Carta 2 - %s: %.2f pontos\n", nomeCidade2, superPoderCarta2);
            printf("Resultado: Empate!\n\n");
        }
        break;

    case 8:
        //Encerra o programa
        return 0;

    default:
        printf("### Opcao Invalida! ###\n");
        break;
    }




    //MENU INTERATIVO
    printf("### MENU ###\n");
    printf("Escolha o segundo atributo: \n");
    printf("1. POPULAÇÃO\n");
    printf("2. AREA\n");
    printf("3. PIB\n");
    printf("4. PONTOS TURISTICOS\n");
    printf("5. DENSIDADE POPULACIONAL\n");
    printf("6. PIB PER CAPITA\n");
    printf("7. SUPER PODER\n");
    printf("8. ENCERRAR PROGRAMA\n");
    printf("Escolha: \n");

    scanf("%d", &menuOpcaoEscolhida1);

    //ABAIXO LOGICA SWITCH CASE
    switch (menuOpcaoEscolhida1)
    {
    case 1:
        // Comparação de População
        if (populacaoReal1 > populacaoReal2) {
            resultado2 = 0;
            printf("Comparação de cartas (Atributo: População):\n\n");
            printf("Carta 1 - %s: %lu habitantes\n", nomeCidade1, populacaoReal1);
            printf("Carta 2 - %s: %lu habitantes\n", nomeCidade2, populacaoReal2);
            printf("Resultado: Carta 1 (%s) venceu!\n\n", nomeCidade1);
        } else if (populacaoReal2 > populacaoReal1) {
            resultado2 = 1;
            printf("Comparação de cartas (Atributo: População):\n\n");
            printf("Carta 1 - %s: %lu habitantes\n", nomeCidade1, populacaoReal1);
            printf("Carta 2 - %s: %lu habitantes\n", nomeCidade2, populacaoReal2);
            printf("Resultado: Carta 2 (%s) venceu!\n\n", nomeCidade2);
        } else {
            printf("Comparação de cartas (Atributo: População):\n\n");
            printf("Carta 1 - %s: %lu habitantes\n", nomeCidade1, populacaoReal1);
            printf("Carta 2 - %s: %lu habitantes\n", nomeCidade2, populacaoReal2);
            printf("Resultado: Empate!\n\n");
        }
        break;

    case 2:
        // Comparação de Área
        if (area1 > area2) {
            resultado2 = 0;
            printf("Comparação de cartas (Atributo: Área):\n\n");
            printf("Carta 1 - %s: %.2f km²\n", nomeCidade1, area1);
            printf("Carta 2 - %s: %.2f km²\n", nomeCidade2, area2);
            printf("Resultado: Carta 1 (%s) venceu!\n\n", nomeCidade1);
        } else if (area2 > area1) {
            resultado2 = 1;
            printf("Comparação de cartas (Atributo: Área):\n\n");
            printf("Carta 1 - %s: %.2f km²\n", nomeCidade1, area1);
            printf("Carta 2 - %s: %.2f km²\n", nomeCidade2, area2);
            printf("Resultado: Carta 2 (%s) venceu!\n\n", nomeCidade2);
        } else {
            printf("Comparação de cartas (Atributo: Área):\n\n");
            printf("Carta 1 - %s: %.2f km²\n", nomeCidade1, area1);
            printf("Carta 2 - %s: %.2f km²\n", nomeCidade2, area2);
            printf("Resultado: Empate!\n\n");
        }
        break;

    case 3:
        // Comparação de PIB
        if (pibEmReais1 > pibEmReais2) {
            resultado2 = 0;
            printf("Comparação de cartas (Atributo: PIB):\n\n");
            printf("Carta 1 - %s: R$ %.2f bilhões\n", nomeCidade1, pib1);
            printf("Carta 2 - %s: R$ %.2f bilhões\n", nomeCidade2, pib2);
            printf("Resultado: Carta 1 (%s) venceu!\n\n", nomeCidade1);
        } else if (pibEmReais2 > pibEmReais1) {
            resultado2 = 1;
            printf("Comparação de cartas (Atributo: PIB):\n\n");
            printf("Carta 1 - %s: R$ %.2f bilhões\n", nomeCidade1, pib1);
            printf("Carta 2 - %s: R$ %.2f bilhões\n", nomeCidade2, pib2);
            printf("Resultado: Carta 2 (%s) venceu!\n\n", nomeCidade2);
        } else {
            printf("Comparação de cartas (Atributo: PIB):\n\n");
            printf("Carta 1 - %s: R$ %.2f bilhões\n", nomeCidade1, pib1);
            printf("Carta 2 - %s: R$ %.2f bilhões\n", nomeCidade2, pib2);
            printf("Resultado: Empate!\n\n");
    }
        break;

    case 4:
        // Comparação de Pontos Turísticos
        if (pontosTuristicos1 > pontosTuristicos2) {
            resultado2 = 0;
            printf("Comparação de cartas (Atributo: Pontos Turísticos):\n\n");
            printf("Carta 1 - %s: %d pontos turísticos\n", nomeCidade1, pontosTuristicos1);
            printf("Carta 2 - %s: %d pontos turísticos\n", nomeCidade2, pontosTuristicos2);
            printf("Resultado: Carta 1 (%s) venceu!\n\n", nomeCidade1);
        } else if (pontosTuristicos2 > pontosTuristicos1) {
            resultado2 = 1;
            printf("Comparação de cartas (Atributo: Pontos Turísticos):\n\n");
            printf("Carta 1 - %s: %d pontos turísticos\n", nomeCidade1, pontosTuristicos1);
            printf("Carta 2 - %s: %d pontos turísticos\n", nomeCidade2, pontosTuristicos2);
            printf("Resultado: Carta 2 (%s) venceu!\n\n", nomeCidade2);
        } else {
            printf("Comparação de cartas (Atributo: Pontos Turísticos):\n\n");
            printf("Carta 1 - %s: %d pontos turísticos\n", nomeCidade1, pontosTuristicos1);
            printf("Carta 2 - %s: %d pontos turísticos\n", nomeCidade2, pontosTuristicos2);
            printf("Resultado: Empate!\n\n");
        }
        break;

    case 5:
        // Comparação de Densidade Populacional (MENOR vence)
        if (densidadePopulacional1 < densidadePopulacional2) {
            resultado2 = 0;
            printf("Comparação de cartas (Atributo: Densidade Populacional - MENOR vence):\n\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", nomeCidade1, densidadePopulacional1);
            printf("Carta 2 - %s: %.2f hab/km²\n", nomeCidade2, densidadePopulacional2);
            printf("Resultado: Carta 1 (%s) venceu!\n\n", nomeCidade1);
        } else if (densidadePopulacional2 < densidadePopulacional1) {
            resultado2 = 1;
            printf("Comparação de cartas (Atributo: Densidade Populacional - MENOR vence):\n\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", nomeCidade1, densidadePopulacional1);
            printf("Carta 2 - %s: %.2f hab/km²\n", nomeCidade2, densidadePopulacional2);
            printf("Resultado: Carta 2 (%s) venceu!\n\n", nomeCidade2);
        } else {
            printf("Comparação de cartas (Atributo: Densidade Populacional - MENOR vence):\n\n");
            printf("Carta 1 - %s: %.2f hab/km²\n", nomeCidade1, densidadePopulacional1);
            printf("Carta 2 - %s: %.2f hab/km²\n", nomeCidade2, densidadePopulacional2);
            printf("Resultado: Empate!\n\n");
        }
        break;

    case 6:
        // Comparação de PIB per Capita
        if (pibPerCapita1 > pibPerCapita2) {
            resultado2 = 0;
            printf("Comparação de cartas (Atributo: PIB per Capita):\n\n");
            printf("Carta 1 - %s: R$ %.2f\n", nomeCidade1, pibPerCapita1);
            printf("Carta 2 - %s: R$ %.2f\n", nomeCidade2, pibPerCapita2);
            printf("Resultado: Carta 1 (%s) venceu!\n\n", nomeCidade1);
        } else if (pibPerCapita2 > pibPerCapita1) {
            resultado2 = 1;
            printf("Comparação de cartas (Atributo: PIB per Capita):\n\n");
            printf("Carta 1 - %s: R$ %.2f\n", nomeCidade1, pibPerCapita1);
            printf("Carta 2 - %s: R$ %.2f\n", nomeCidade2, pibPerCapita2);
            printf("Resultado: Carta 2 (%s) venceu!\n\n", nomeCidade2);
        } else {
            printf("Comparação de cartas (Atributo: PIB per Capita):\n\n");
            printf("Carta 1 - %s: R$ %.2f\n", nomeCidade1, pibPerCapita1);
            printf("Carta 2 - %s: R$ %.2f\n", nomeCidade2, pibPerCapita2);
            printf("Resultado: Empate!\n\n");
        }
        break;

    case 7:
        //Comparação do Super Poder
        if (superPoderCarta1 > superPoderCarta2) {
            resultado2 = 0;
            printf("Comparação de cartas (Atributo: Super Poder):\n\n");
            printf("Carta 1 - %s: %.2f pontos\n", nomeCidade1, superPoderCarta1);
            printf("Carta 2 - %s: %.2f pontos\n", nomeCidade2, superPoderCarta2);
            printf("Resultado: Carta 1 (%s) venceu!\n\n", nomeCidade1);
        } else if (superPoderCarta2 > superPoderCarta1) {
            resultado2 = 1;
            printf("Comparação de cartas (Atributo: Super Poder):\n\n");
            printf("Carta 1 - %s: %.2f pontos\n", nomeCidade1, superPoderCarta1);
            printf("Carta 2 - %s: %.2f pontos\n", nomeCidade2, superPoderCarta2);
            printf("Resultado: Carta 2 (%s) venceu!\n\n", nomeCidade2);
        } else {
            printf("Comparação de cartas (Atributo: Super Poder):\n\n");
            printf("Carta 1 - %s: %.2f pontos\n", nomeCidade1, superPoderCarta1);
            printf("Carta 2 - %s: %.2f pontos\n", nomeCidade2, superPoderCarta2);
            printf("Resultado: Empate!\n\n");
        }
        break;

    case 8:
        //Encerra o programa
        return 0;
        break;
    
    default:
        printf("### Opcao Invalida! ###\n");
        break;
    }

    


    //Resumo Todos os Atributos das Cartas
    printf("\n*** RESUMO DE COMPARACAO DAS CARTAS ***\n");
    printf("LEGENDA:\n(1 = Carta 1, 0 = Carta 2)\n");
    printf("População: Carta %d venceu\n", populacaoReal1 > populacaoReal2);
    printf("Área: Carta %d venceu\n", area1 > area2);
    printf("PIB: Carta %d venceu\n", pibEmReais1 > pibEmReais2);
    printf("Pontos Turísticos: Carta %d venceu\n", pontosTuristicos1 > pontosTuristicos2);
    printf("Densidade Populacional: Carta %d venceu (menor vence)\n", densidadePopulacional1 < densidadePopulacional2); //utilização do operador Menor
    printf("PIB per Capita: Carta %d venceu\n", pibPerCapita1 > pibPerCapita2);
    printf("Super Poder: Carta %d venceu\n\n\n", superPoderCarta1 > superPoderCarta2);

    return 0;
}
