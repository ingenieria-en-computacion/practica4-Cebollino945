#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    
    printf("Ingrese el numero de filas (m): ");
    scanf("%d", &m);
    printf("Ingrese el numero de columnas (n): ");
    scanf("%d", &n);

    int *matriz = (int *)calloc(m * n, sizeof(int));
    if (matriz == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("\nMatriz inicializada con ceros:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i * n + j]);
        }
        printf("\n");
    }

    // Permitir al usuario modificar valores
    int fila, columna, valor, continuar;
    do {
        printf("\nIngrese la fila y columna del valor a modificar (rango: 1-%d para filas y 1-%d para columnas): ", m, n);
        scanf("%d %d", &fila, &columna);

        // Ajustar a índices basados en 0
        fila--;
        columna--;

        if (fila >= 0 && fila < m && columna >= 0 && columna < n) {
            printf("Ingrese el nuevo valor: ");
            scanf("%d", &valor);
            matriz[fila * n + columna] = valor;
        } else {
            printf("Posición fuera de rango. Intente de nuevo.\n");
        }
        
        printf("¿Desea modificar otro valor? (1: Si, 0: No): ");
        scanf("%d", &continuar);
    } while (continuar);

    // Imprimir matriz actualizada
    printf("\nMatriz actualizada:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i * n + j]);
        }
        printf("\n");
    }

    free(matriz);
    return 0;
}

