#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "productos.h"
#include "usuarios.h"

#define RUTA_PRODUCTOS "producto.txt"
#define RUTA_VENTAS "ventas.txt"
#define RUTA_VENDEDORES "vendedores.txt"

typedef struct {
    char codigo[64];
    char nombre[128];
    int cantidad;
    double costo;
    double precio;
} ItemVenta;

static void imprimir_linea_factura(ItemVenta *it) {
    double subtotal = it->cantidad * it->precio;
    printf("%-8s %-25s %5d  %8.2f  %8.2f\n",
           it->codigo, it->nombre, it->cantidad, it->precio, subtotal);
}

static int obtener_ultimo_num_factura(const char *ruta) {
    FILE *f = fopen(ruta, "r");
    if (!f) return 0;
    char linea[512];
    int ult = 0;
    while (fgets(linea, sizeof(linea), f)) {
        if (strlen(linea) < 3) continue;
        char *p = strtok(linea, ",");
        if (!p) continue;
        int num = atoi(p);
        if (num > ult) ult = num;
    }
    fclose(f);
    return ult;
}

static void obtener_fecha_actual(char *out, size_t n) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(out, n, "%04d-%02d-%02d", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday);
}

int main(void) {
    printf("Programa principal de ejemplo\n");
    return 0;
}
