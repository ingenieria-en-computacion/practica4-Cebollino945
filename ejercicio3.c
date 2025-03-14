#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacidad = 2;  
    int *lista = (int *)malloc(capacidad * sizeof(int));
    if (lista == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    int num, cantidad = 0;
    char continuar;

    printf("Ingrese numeros (presione 'n' para detenerse):\n");
    do {
        if (cantidad == capacidad) { // Si se alcanza la capacidad, se duplica el tamaño
            capacidad *= 2;
            int *temp = (int *)realloc(lista, capacidad * sizeof(int));
            if (temp == NULL) {
                printf("Error al reasignar memoria.\n");
                free(lista);
                return 1;
            }
            lista = temp;
        }

        printf("Numero %d: ", cantidad + 1);
        scanf("%d", &num);
        lista[cantidad++] = num;

        printf("¿Desea ingresar otro numero? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    // Imprimir la lista final
    printf("\nLista ingresada:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    free(lista);
    return 0;
}
