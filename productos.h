#ifndef PRODUCTOS_H
#define PRODUCTOS_H
#define MAX_CODIGO 64
#define MAX_NOMBRE 128
typedef struct {
    char codigo[MAX_CODIGO];
    char nombre[MAX_NOMBRE];
    int cantidad;
    double costo;
    double precio;
} Producto;
typedef struct {
    Producto *items;
    size_t n;
} Inventario;
#endif
