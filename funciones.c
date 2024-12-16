#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu() {
    int opcion;
    printf("\n--- Menu de la Biblioteca ---\n");
    printf("1. Registrar libro\n");
    printf("2. Mostrar libros\n");
    printf("3. Buscar libro por ID\n");
    printf("4. Buscar libro por titulo\n");
    printf("5. Prestar el libro\n");
    printf("6. Eliminar libro\n");
    printf("7. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

void registrarLibros(struct Libro libros[], int *cantidad) {
    int id;
    printf("\n--- Registrar Libro ---\n");
    do
    {
        printf("Ingrese el ID del libro: ");
    scanf("%d", &id);
      if (id<0)
    {
        printf ("JASKJKJADJK se equivoco, intentalo de nuevo...\n");
    }
    } while (id<0);

    for (int i = 0; i < *cantidad; i++) {
        if (libros[i].id == id) {
            printf("Error: El ID ingresado ya existe.\n");
            return;
        }
    }

    libros[*cantidad].id = id;
    printf("Ingrese el titulo: ");
    getchar();
    fgets(libros[*cantidad].titulo, 100, stdin);
    libros[*cantidad].titulo[strcspn(libros[*cantidad].titulo, "\n")] = '\0';

    printf("Ingrese el autor: ");
    fgets(libros[*cantidad].autor, 50, stdin);
    libros[*cantidad].autor[strcspn(libros[*cantidad].autor, "\n")] = '\0';

    printf("Ingrese el a\u00f1o de publicacion: ");
    scanf("%d", &libros[*cantidad].anio);

    strcpy(libros[*cantidad].estado, "Disponible");

    (*cantidad)++;
    printf("Libro registrado exitosamente.\n");
}

void mostrarLibros(const struct Libro libros[], int cantidad) {
    printf("\n--- Lista de Libros ---\n");
    if (cantidad == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("%-5s %-30s %-20s %-10s %-15s\n", "ID", "T\u00edtulo", "Autor", "A\u00f1o", "Estado");
    for (int i = 0; i < cantidad; i++) {
        printf("%-5d %-30s %-20s %-10d %-15s\n",
               libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
    }
}

void buscarLibroId(const struct Libro libros[], int cantidad, int id) {
    for (int i = 0; i < cantidad; i++) {
        if (libros[i].id == id) {
            printf("\n--- Informaci\u00f3n del Libro ---\n");
            printf("ID: %d\nT\u00edtulo: %s\nAutor: %s\nA\u00f1o: %d\nEstado: %s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
            return;
        }
    }
    printf("Libro con ID %d no encontrado.\n", id);
}

void buscarLibroTitulo(const struct Libro libros[], int cantidad, const char *titulo) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(libros[i].titulo, titulo) == 0) {
            printf("\n--- Informaci\u00f3n del Libro ---\n");
            printf("ID: %d\nT\u00edtulo: %s\nAutor: %s\nA\u00f1o: %d\nEstado: %s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
            return;
        }
    }
    printf("Libro con t\u00edtulo \"%s\" no encontrado.\n", titulo);
}

void actualizarEstado(struct Libro libros[], int cantidad) {
    int id;
    printf("Ingrese el ID del libro a actualizar: ");
    scanf("%d", &id);

    for (int i = 0; i < cantidad; i++) {
        if (libros[i].id == id) {
            printf("Estado actual: %s\n", libros[i].estado);
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                strcpy(libros[i].estado, "Prestado");
            } else {
                strcpy(libros[i].estado, "Disponible");
            }
            printf("Estado actualizado exitosamente a: %s\n", libros[i].estado);
            return;
        }
    }
    printf("Libro con ID %d no encontrado.\n", id);
}

void eliminarLibro(struct Libro libros[], int *cantidad) {
    int id;
    printf("Ingrese el ID del libro a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < *cantidad; i++) {
        if (libros[i].id == id) {
            for (int j = i; j < *cantidad - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*cantidad)--;
            printf("Libro con ID %d eliminado exitosamente.\n", id);
            return;
        }
    }
    printf("Libro con ID %d no encontrado.\n", id);
}