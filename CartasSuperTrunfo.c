#include <stdio.h>

int main() {
    // Declaração de variáveis para Carta 1 e Carta 2
    char estado1, estado2;
    int codigo1, codigo2, menuOpcaoEscolhida1, menuOpcaoEscolhida2, resultado1 = 0, resultado2 = 0;  
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
    scanf(" %49[^\n]", nomeCidade1); // Usado %49 para limitar a leitura e evitar estouro de buffer.
    printf("Populacao (em milhares de habitantes): ");
    scanf("%lu", &populacao1);
    printf("Area (em km quadrados): ");
    scanf("%f", &area1);
    printf("PIB (em bilhoes de reais): ");
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
    scanf(" %49[^\n]", nomeCidade2); // Usado %49 para limitar a leitura e evitar estouro de buffer.
    printf("Populacao (em milhares de habitantes): ");
    scanf("%lu", &populacao2);
    printf("Area (em km quadrados): ");
    scanf("%f", &area2);
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Conversões para valores reais
    unsigned long long int populacaoReal1 = populacao1 * 1000;
    unsigned long int populacaoReal2 = populacao2 * 1000;
    unsigned long long int pibEmReais1 = pib1 * 1e9;
    unsigned long long int pibEmReais2 = pib2 * 1e9;

    // Cálculo dos atributos derivados
    float densidadePopulacional1 = populacaoReal1 / area1;
    float pibPerCapita1 = pibEmReais1 / populacaoReal1;
    float densidadePopulacional2 = populacaoReal2 / area2;
    float pibPerCapita2 = pibEmReais2 / populacaoReal2;

    // Cálculo do Super Poder
    float superPoderCarta1 = populacaoReal1 + area1 + pibEmReais1 + pontosTuristicos1 + pibPerCapita1 + (1 / densidadePopulacional1);
    float superPoderCarta2 = populacaoReal2 + area2 + pibEmReais2 + pontosTuristicos2 + pibPerCapita2 + (1 / densidadePopulacional2);

    printf("== DUELO DE ATRIBUTOS ==\n");
    // MENU INTERATIVO
    printf("### MENU ###\n");
    printf("1. POPULACAO\n");
    printf("2. AREA\n");
    printf("3. PIB\n");
    printf("4. PONTOS TURISTICOS\n");
    printf("5. DENSIDADE POPULACIONAL\n");
    printf("6. PIB PER CAPITA\n");
    printf("7. SUPER PODER\n");
    printf("ESCOLHA O PRIMEIRO ATRIBUTO:\n");

    scanf("%d", &menuOpcaoEscolhida1);

    //Cria variaveis para armazenar os valores dos atributos selecionados para na frente soma-los.
        float valor1Carta1;
        float valor2Carta1;
        float valor1Carta2;
        float valor2Carta2;

    //Estrutura Switch para gerar o placar do duelo de atributos.
    switch (menuOpcaoEscolhida1)
{
    case 1: // População
        resultado1 = (populacaoReal1 > populacaoReal2) ? 1 : 0;
        resultado2 = (populacaoReal2 > populacaoReal1) ? 1 : 0;
        valor1Carta1 = populacaoReal1;
        valor1Carta2 = populacaoReal2;
        break;
    case 2: // Área
        resultado1 = (area1 > area2) ? 1 : 0;
        resultado2 = (area2 > area1) ? 1 : 0;
        valor1Carta1 = area1;
        valor1Carta2 = area2;
        break;
    case 3: // PIB
        resultado1 = (pibEmReais1 > pibEmReais2) ? 1 : 0;
        resultado2 = (pibEmReais2 > pibEmReais1) ? 1 : 0;
        valor1Carta1 = pibEmReais1;
        valor1Carta2 = pibEmReais2;
        break;
    case 4: // Pontos Turísticos
        resultado1 = (pontosTuristicos1 > pontosTuristicos2) ? 1 : 0;
        resultado2 = (pontosTuristicos2 > pontosTuristicos1) ? 1 : 0;
        valor1Carta1 = pontosTuristicos1;
        valor1Carta2 = pontosTuristicos2;
        break;
    case 5: // Densidade Populacional (MENOR vence)
        resultado1 = (densidadePopulacional1 < densidadePopulacional2) ? 1 : 0;
        resultado2 = (densidadePopulacional2 < densidadePopulacional1) ? 1 : 0;
        valor1Carta1 = densidadePopulacional1;
        valor1Carta2 = densidadePopulacional2;
        break;
    case 6: // PIB per Capita
        resultado1 = (pibPerCapita1 > pibPerCapita2) ? 1 : 0;
        resultado2 = (pibPerCapita2 > pibPerCapita1) ? 1 : 0;
        valor1Carta1 = pibPerCapita1;
        valor1Carta2 = pibPerCapita2;
        break;
    case 7: // Super Poder
        resultado1 = (superPoderCarta1 > superPoderCarta2) ? 1 : 0;
        resultado2 = (superPoderCarta2 > superPoderCarta1) ? 1 : 0;
        valor1Carta1 = superPoderCarta1;
        valor1Carta2 = superPoderCarta2;
        break;
    default:
        printf("### OPCAO INVALIDA! ###\n");
        return 1;
}

    // MENU INTERATIVO SEGUNDA ESCOLHA
    printf("### MENU ###\n");
    printf("1. POPULACAO\n");
    printf("2. AREA\n");
    printf("3. PIB\n");
    printf("4. PONTOS TURISTICOS\n");
    printf("5. DENSIDADE POPULACIONAL\n");
    printf("6. PIB PER CAPITA\n");
    printf("7. SUPER PODER\n");
    printf("ESCOLHA O SEGUNDO ATRIBUTO:\n");

    scanf("%d", &menuOpcaoEscolhida2);

    if (menuOpcaoEscolhida1 == menuOpcaoEscolhida2)
    {
        printf("### VOCE ESCOLHEU O MESMO ATRIBUTO. O JOGO SERA ENCERRADO! ###\n");
        return 0;
    } 
    else
    {
        // ABAIXO LOGICA SWITCH CASE DA OPÇÃO 2
        switch (menuOpcaoEscolhida2)
        {
            case 1: // População
                resultado1 += (populacaoReal1 > populacaoReal2) ? 1 : 0;
                resultado2 += (populacaoReal2 > populacaoReal1) ? 1 : 0;
                valor2Carta1 = populacaoReal1;
                valor2Carta2 = populacaoReal2;
                break;
            case 2: // Área
                resultado1 += (area1 > area2) ? 1 : 0;
                resultado2 += (area2 > area1) ? 1 : 0;
                valor2Carta1 = area1;
                valor2Carta2 = area2;
                break;
            case 3: // PIB
                resultado1 += (pibEmReais1 > pibEmReais2) ? 1 : 0;
                resultado2 += (pibEmReais2 > pibEmReais1) ? 1 : 0;
                valor2Carta1 = pibEmReais1;
                valor2Carta2 = pibEmReais2;
                break;
            case 4: // Pontos Turísticos
                resultado1 += (pontosTuristicos1 > pontosTuristicos2) ? 1 : 0;
                resultado2 += (pontosTuristicos2 > pontosTuristicos1) ? 1 : 0;
                valor2Carta1 = pontosTuristicos1;
                valor2Carta2 = pontosTuristicos2;
                break;
            case 5: // Densidade Populacional (MENOR vence)
                resultado1 += (densidadePopulacional1 < densidadePopulacional2) ? 1 : 0;
                resultado2 += (densidadePopulacional2 < densidadePopulacional1) ? 1 : 0;
                valor2Carta1 = densidadePopulacional1;
                valor2Carta2 = densidadePopulacional2;
                break;
            case 6: // PIB per Capita
                resultado1 += (pibPerCapita1 > pibPerCapita2) ? 1 : 0;
                resultado2 += (pibPerCapita2 > pibPerCapita1) ? 1 : 0;
                valor2Carta1 = pibPerCapita1;
                valor2Carta2 = pibPerCapita2;
                break;
            case 7: // Super Poder
                resultado1 += (superPoderCarta1 > superPoderCarta2) ? 1 : 0;
                resultado2 += (superPoderCarta2 > superPoderCarta1) ? 1 : 0;
                valor2Carta1 = superPoderCarta1;
                valor2Carta2 = superPoderCarta2;
                break;
            default:
                printf("### OPCAO INVALIDA! ###\n");
                return 1;
        }
    }

    //Soma os valores dos atributos selecioandos para definir o vencedor do Jogo da soma
    float somaValoresCarta1 = valor1Carta1 + valor2Carta1;
    float somaValoresCarta2 = valor1Carta2 + valor2Carta2;
    

    // Exibir os valores comparados e o resultado
    printf("*** ATRIBUTOS COMPARADOS ***\n");
    switch (menuOpcaoEscolhida1)
    {
    case 1:
        printf("%s %s POPULACAO: %lu\n", estadoConcatenado1, nomeCidade1, populacaoReal1);
        printf("%s %s POPULACAO: %lu\n", estadoConcatenado2, nomeCidade2, populacaoReal2);
        break;

    case 2:
        printf("%s %s AREA: %.2f\n", estadoConcatenado1, nomeCidade1, area1);
        printf("%s %s AREA: %.2f\n", estadoConcatenado2, nomeCidade2, area2);
        break;

    case 3:
        printf("%s %s PIB: %llu\n", estadoConcatenado1, nomeCidade1, pibEmReais1);
        printf("%s %s PIB: %llu\n", estadoConcatenado2, nomeCidade2, pibEmReais2);
        break;

    case 4:
        printf("%s %s PONTOS TURISTICOS: %d\n", estadoConcatenado1, nomeCidade1, pontosTuristicos1);
        printf("%s %s PONTOS TURISTICOS: %d\n", estadoConcatenado2, nomeCidade2, pontosTuristicos2);
        break;

    case 5:
        printf("%s %s DENSIDADE POPULACIONAL: %.2f\n", estadoConcatenado1, nomeCidade1, densidadePopulacional1);
        printf("%s %s DENSIDADE POPULACIONAL: %.2f\n", estadoConcatenado2, nomeCidade2, densidadePopulacional2);
        break;

    case 6:
        printf("%s %s PIB PER CAPITA: %.2f\n", estadoConcatenado1, nomeCidade1, pibPerCapita1);
        printf("%s %s PIB PER CAPITA: %.2f\n", estadoConcatenado2, nomeCidade2, pibPerCapita2);
        break;
        
    case 7:
        printf("%s %s SUPER PODER: %.2f\n", estadoConcatenado1, nomeCidade1, superPoderCarta1);
        printf("%s %s SUPER PODER: %.2f\n", estadoConcatenado2, nomeCidade2, superPoderCarta2);
        break;
    
    default:
        printf("OPCAO INVALIDA\n");
        break;
    }

    switch (menuOpcaoEscolhida2)
    {
    case 1:
        printf("%s %s POPULACAO: %lu\n", estadoConcatenado1, nomeCidade1, populacaoReal1);
        printf("%s %s POPULACAO: %lu\n", estadoConcatenado2, nomeCidade2, populacaoReal2);
        break;

    case 2:
        printf("%s %s AREA: %.2f\n", estadoConcatenado1, nomeCidade1, area1);
        printf("%s %s AREA: %.2f\n", estadoConcatenado2, nomeCidade2, area2);
        break;

    case 3:
        printf("%s %s PIB: %llu\n", estadoConcatenado1, nomeCidade1, pibEmReais1);
        printf("%s %s PIB: %llu\n", estadoConcatenado2, nomeCidade2, pibEmReais2);
        break;

    case 4:
        printf("%s %s PONTOS TURISTICOS: %d\n", estadoConcatenado1, nomeCidade1, pontosTuristicos1);
        printf("%s %s PONTOS TURISTICOS: %d\n", estadoConcatenado2, nomeCidade2, pontosTuristicos2);
        break;

    case 5:
        printf("%s %s DENSIDADE POPULACIONAL: %.2f\n", estadoConcatenado1, nomeCidade1, densidadePopulacional1);
        printf("%s %s DENSIDADE POPULACIONAL: %.2f\n", estadoConcatenado2, nomeCidade2, densidadePopulacional2);
        break;

    case 6:
        printf("%s %s PIB PER CAPITA: %.2f\n", estadoConcatenado1, nomeCidade1, pibPerCapita1);
        printf("%s %s PIB PER CAPITA: %.2f\n", estadoConcatenado2, nomeCidade2, pibPerCapita2);
        break;
        
    case 7:
        printf("%s %s SUPER PODER: %.2f\n", estadoConcatenado1, nomeCidade1, superPoderCarta1);
        printf("%s %s SUPER PODER: %.2f\n", estadoConcatenado2, nomeCidade2, superPoderCarta2);
        break;
    
    default:
        printf("OPCAO INVALIDA\n");
        break;
    }

    //Exibe o placar
    printf("\n");
    printf("PONTUACAO DA CARTA %s %s: %d\n", estadoConcatenado1, nomeCidade1, resultado1);
    printf("PONTUACAO DA CARTA %s %s: %d\n", estadoConcatenado2, nomeCidade2, resultado2);

    printf("\n");

    //Define o vencedor
    if (resultado1 == resultado2) {
        printf("### O JOGO EMPATOU!! ###\n");
    } 
    else if (resultado1 > resultado2) {
        printf("### %s VENCEU O DUELO DE ATRIBUTOS! ###\n", nomeCidade1);
    } 
    else {
        printf("### %s VENCEU O DUELO DE ATRIBUTOS! ###\n", nomeCidade2);
    }

    printf("\n");

    //Segunda modalidade de Jogo - Jogo da soma dos atributos
    printf("*** JOGO DA SOMA DE ATRIBUTOS ***\n");
    printf("%s SOMA DOS ATRIBUTOS:  %.2f\n", nomeCidade1, somaValoresCarta1);
    printf("%s SOMA DOS ATRIBUTOS:  %.2f\n", nomeCidade2, somaValoresCarta2);
    printf("\n");

    //Define o vencedor
    if (somaValoresCarta1 > somaValoresCarta2){
        printf("### %s VENCEU A SOMA DOS ATRIBUTOS! ###\n", nomeCidade1);
    } else if(somaValoresCarta1 < somaValoresCarta2){
        printf("### %s VENCEU A SOMA DOS ATRIBUTOS! ###\n", nomeCidade2);
    }else{
        printf("O JOGO EMPATOU!\n\n\n");
    }
    

    return 0;
}
