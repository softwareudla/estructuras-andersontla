struct Libro {
    int id;
    char titulo[30];
    char autor[30];
    int anio;
    char estado[20];
};

int menu();
void registrarLibros(struct Libro libros[], int *cantidad);
void mostrarLibros(const struct Libro libros[], int cantidad);
void buscarLibroId(const struct Libro libros[], int cantidad, int id);
void buscarLibroTitulo(const struct Libro libros[], int cantidad, const char *titulo);
void actualizarEstado(struct Libro libros[], int cantidad);
void eliminarLibro(struct Libro libros[], int *cantidad);

