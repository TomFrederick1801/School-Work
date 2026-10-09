#include <stdio.h>
#include <math.h>  


#define GRAVIDADE 9.81


float calcular_altura_maxima(float velocidade, float angulo_graus);

int main() {
    float v0, angulo;

 
    printf("Insira a velocidade inicial (m/s): ");
    if (scanf("%f", &v0) != 1) { 
        printf("Erro: Entrada invalida.\n");
        return 1; 
    }

    printf("Insira o angulo de lancamento (0 a 90 graus): ");
    if (scanf("%f", &angulo) != 1) {
        printf("Erro: Entrada invalida.\n");
        return 1;
    }

   
    if (v0 < 0) {
        printf("Erro Cientifico: A velocidade nao pode ser negativa.\n");
        return 1; 
    }
    if (angulo < 0 || angulo > 90) {
        printf("Erro Cientifico: O angulo deve estar entre 0 e 90 graus.\n");
        return 1;
    }

    
    float altura_max = calcular_altura_maxima(v0, angulo);

  
    printf("\n--- Relatorio de Trajetoria ---\n");
    printf("Velocidade Inicial: %.2f m/s\n", v0);
    printf("Angulo: %.1f graus\n", angulo);
    printf("Altura Maxima Atingida: %.4f metros\n", altura_max);

    return 0;
}


float calcular_altura_maxima(float velocidade, float angulo_graus) {
   
    float angulo_radianos = angulo_graus * (M_PI / 180.0);
    
   
    float velocidade_vertical = velocidade * sin(angulo_radianos);
    
    
    float altura = (velocidade_vertical * velocidade_vertical) / (2 * GRAVIDADE);
    
    return altura;
}
