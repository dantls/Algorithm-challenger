#include <stdio.h>
#include <stdlib.h>
#include "geometric.h"

int main (int argc, char *argv[]){
   
    FILE *arquivoSaida;
     double value = 0;

    value = atoi(argv[1]);

    int op;

    printf("Digite a opcao:");
    scanf("%d", &op);

    if(op == 1){
        double p = 0;
        peri = perimetroCirculo(value);
        arquivoSaida = fopen("perimetroCirculo.txt", "a+");
        fprintf(arquivoSaida, "Perimetro do Circulo: %2.f\n", p);
        fclose(arquivoSaida);        
    }else if(op == 2){
        double p = 0;
        p = perimetroQuadrado(value);
        arquivoSaida = fopen("perimetroQuadrado.txt", "a+");
        fprintf(arquivoSaida, "Perimetro do Quadrado: %2.f\n", p);
        fclose(arquivoSaida);
    }else if(op == 3){
        double a = 0;
        a = areaQuadrado(value);
        arquivoSaida = fopen("areaQuadrado.txt", "a+");
        fprintf(arquivoSaida, "Area do Quadrado: %2.f\n", a);
        fclose(arquivoSaida);
    }else if(op == 4){
        double a = 0;
        a = areaCirculo(value);
        arquivoSaida = fopen("areaCirculo.txt", "a+");
        fprintf(arquivoSaida, "Area do Circulo: %2.f\n", a);
        fclose(arquivoSaida);
    }else if(op == 5){
        double v = 0;
        v = volumeEsfera(value);
        arquivoSaida = fopen("volumeEsfera.txt", "a+");
        fprintf(arquivoSaida, "Volume da Esfera: %2.f\n", v);
        fclose(arquivoSaida);
        
    }else if(op == 6){
        double v = 0;
        v = volumeCubo(value);
        arquivoSaida = fopen("volumeCubo.txt", "a+");
        fprintf(arquivoSaida, "Volume do Cubo: %2.f\n", v);
        fclose(arquivoSaida);
    }
}