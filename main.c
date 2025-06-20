
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

producto productos[MAX_PRODUCTOS] = {
    {1, "Lata de Pepsi", 1400.0, 20},
    {2, "Coca Cola", 3900.0, 15},
    {3, "Pancho", 1000.0, 30},
    {4, "Pebete", 1500.0, 20},
    {5, "Hamburguesa", 4000.0, 10},
    {6, "Alfajor Oreo", 1500.0, 30},
    {7, "Alfajor Milka", 1500.0, 30},
    {8, "Bon o Bon", 1100.0, 20},
    {9, "Empanadas", 600.0, 12}
};

int main() {
    int opcion;
    Venta* listaVentas = NULL;

    do {
        printf("\n===== CANTINA UTN FRRE =====\n");
        printf("1 - Ver productos\n");
        printf("2 - Registrar venta\n");
        printf("3 - Mostrar ventas del dia\n");
        printf("4 - Calcular total vendido\n");
        printf("5 - Guardar ventas en archivo\n");
        printf("6 - Salir\n");
        printf("===========================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:

                mostrarProductos(productos, MAX_PRODUCTOS);
                esperarTecla();
                system("cls");
                break;
            case 2:
                listaVentas = registrarVenta(productos, MAX_PRODUCTOS, listaVentas);
                esperarTecla();
                system("cls");
                break;
            case 3:
                mostrarVentas(listaVentas);
                esperarTecla();
                system("cls");
                break;
            case 4:
                printf("\n===== TOTAL VENDIDO =====\n");
                printf("$%.2f\n", calcularTotal(listaVentas));
                printf("=========================\n");
                esperarTecla();
                system("cls");
                break;
            case 5:
                guardarVentasArchivo(listaVentas, productos, "ventas_dia.txt");
                printf("\n=========================\n");
                printf("Ventas guardadas en 'ventas_dia.txt'\n");
                printf("=========================\n");
                esperarTecla();
                system("cls");
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion Invalida\n");
        }
    } while(opcion != 6);


    return 0;
}

void mostrarProductos(producto productos[], int n) {
	int i;
    printf("\n=================PRECIOS=============\n");
    printf("Producto\t|  Precio    | Stock\n");
    for (i = 0; i < n; i++) {
        printf("%d.%s\t  $%.2f\t%d\n", productos[i].id, productos[i].nombre, productos[i].precio, productos[i].stock);
    }
    printf("=====================================\n");
}

Venta* registrarVenta(producto productos[], int n, Venta* listaVentas) {
    int id, cantidad,i;
    mostrarProductos(productos, n);
    printf("Ingrese ID del Producto: ");
    scanf("%d", &id);
    printf("Ingrese cantidad: ");
    scanf("%d", &cantidad);

    for (i = 0; i < n; i++) {
        if (productos[i].id == id) {
            if (productos[i].stock >= cantidad) {
                productos[i].stock -= cantidad;

                Venta* nuevaVenta = (Venta*)malloc(sizeof(Venta));
                nuevaVenta->idProducto = id;
                nuevaVenta->cantidad = cantidad;
                nuevaVenta->total = productos[i].precio * cantidad;
                nuevaVenta->siguiente = listaVentas;
                listaVentas = nuevaVenta;

                printf("Venta registrada: %d x %s = $%.2f\n", cantidad, productos[i].nombre, nuevaVenta->total);
                return listaVentas;
            } else {
                printf("Stock insuficiente.\n");
                return listaVentas;
            }
        }
    }

    printf("Producto no encontrado.\n");
    return listaVentas;
}
