#ifndef USUARIOS_H
#define USUARIOS_H
#define MAX_USER 64
#define MAX_PASS 64
#define MAX_NOM 128
typedef struct {
    char usuario[MAX_USER];
    char clave[MAX_PASS];
    char nombre[MAX_NOM];
} Vendedor;
#endif
