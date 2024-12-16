#include <stdio.h>
#include "funciones.h"

int main() {
    struct Libro libros[20];
    int cantidadLibros = 0;
    int opc;

    do {
        
        opc = menu();
        switch (opc) {
            case 1:
                if (cantidadLibros <= 20) {
                    registrarLibros(libros, &cantidadLibros);
                } else {
                    printf("No se pueden registrar mas libros (limite alcanzado).\n");
                }
                break;
            case 2:
                mostrarLibros(libros, cantidadLibros);
                break;
            case 3: {
                int id;
                printf("Ingrese el ID del libro a buscar: ");
                scanf("%d", &id);
                buscarLibroId(libros, cantidadLibros, id);
                break;
            }
            case 4: {
                char titulo[100];
                printf("Ingrese el ttulo del libro a buscar: ");
                getchar();
                fgets(titulo, 100, stdin);
                titulo[strcspn(titulo, "\n")] = '\0'; 
                buscarLibroTitulo(libros, cantidadLibros, titulo);
                break;
            }
            case 5:
                actualizarEstado(libros, cantidadLibros);
                break;
            case 6:
                eliminarLibro(libros, &cantidadLibros);
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida... \n !!Intente de nuevo!!\n");
                break;
        }
    } while (opc != 7);

    return 0;
}
