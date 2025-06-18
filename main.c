
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
    #include <conio.h>
    void esperarTecla() {
        printf("Presione cualquier tecla para continuar...");
        getch();
        printf("\n");
    }
#else
    #include <termios.h>
    #include <unistd.h>
    void esperarTecla() {
        struct termios oldt, newt;
        printf("Presione cualquier tecla para continuar...");
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        printf("\n");
    }
#endif
#define MAX_PRODUCTOS 9
#define MAX_NOMBRE 50

typedef struct {
    int id;
    char nombre[MAX_NOMBRE];
    float precio;
    int stock;
} producto;

typedef struct Venta {
    int idProducto;
    int cantidad;
    float total;
    struct Venta siguiente;
} Venta;

void mostrarProductos(producto productos[], int n);
Venta registrarVenta(producto productos[], int n, Venta* listaVentas);
void guardarVentasArchivo(Venta* lista, producto productos[], const char* nombreArchivo);
void mostrarVentas(Venta* lista);
float calcularTotal(Venta* lista);
