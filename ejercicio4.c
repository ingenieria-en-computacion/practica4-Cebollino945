#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
} Estudiante;

int main() {
    int capacidad = 2; 
    int cantidad = 0;  

    Estudiante *lista = (Estudiante *)malloc(capacidad * sizeof(Estudiante));
    if (lista == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    char continuar;
    do {
        // Si se alcanza la capacidad máxima, se aumenta el tamaño
        if (cantidad == capacidad) {
            capacidad *= 2;
            Estudiante *temp = (Estudiante *)realloc(lista, capacidad * sizeof(Estudiante));
            if (temp == NULL) {
                printf("Error al reasignar memoria.\n");
                free(lista);
                return 1;
            }
            lista = temp;
        }

        printf("Ingrese el nombre del estudiante: ");
        scanf(" %49[^\n]", lista[cantidad].nombre); // Lee hasta 49 caracteres evitando desbordamiento
        printf("Ingrese la edad del estudiante: ");
        scanf("%d", &lista[cantidad].edad);
        cantidad++;

        printf("¿Desea ingresar otro estudiante? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    // Imprimir la lista de estudiantes
    printf("\nLista de estudiantes:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("Nombre: %s, Edad: %d\n", lista[i].nombre, lista[i].edad);
    }

    free(lista);
    return 0;
}
