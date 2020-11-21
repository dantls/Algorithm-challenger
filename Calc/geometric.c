#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

double perimetroQuadrado(double lado){
return 4 * lado;
}
double perimetroCirculo(double raio) {
return 2 * PI * raio;
}
double areaQuadrado(double lado) {
return lado * lado;
}
double areaCirculo(double raio) {
return PI * raio * raio;
}
double volumeCubo(double lado) {
return lado * lado * lado;
}
double volumeEsfera(double raio) {
return (double)4/3 * PI * raio * raio;
}