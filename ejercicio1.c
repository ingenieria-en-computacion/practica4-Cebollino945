#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arreglo, n, cont;
    printf("¿Cuántos elementos tiene el arreglo?\n");
    scanf("%d", &n);
    arreglo = (int*)malloc(n *sizeof(int));
    if(arreglo != NULL){ //indica si malloc pudo reservar la memoria
        for(cont =0; cont <n; cont++){
            printf("Ingresa el elemento %d del arreglo\n", cont+1);
            scanf("%d", (arreglo+cont));
        }
        printf("El arreglo es:\n\t[");
        for(cont =0; cont <n; cont++){
            printf("\t%d", *(arreglo + cont));            
        }
        printf("\t]\n"); 
        printf("Liberando el espacio reservado\n");
        free(arreglo); //libera la memoria     
        arreglo = NULL;  
    }
    return 0; 
}