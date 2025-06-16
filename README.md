# 📦 Registro de Ventas de Kiosco – Proyecto en C

Este proyecto es un sistema de gestión de ventas desarrollado en lenguaje C, orientado a pequeños comercios como kioscos, cantinas o almacenes. Permite registrar ventas del día, controlar stock, calcular totales y guardar un informe de las operaciones realizadas.

---

## ✅ Características

- 🛍️ **Catálogo de productos:** listado fijo con nombre, precio y stock inicial.
- 🧾 **Registro de ventas:** guarda cada venta realizada con producto, cantidad y total.
- 📉 **Control de stock:** descuenta automáticamente el stock de cada producto vendido.
- 💰 **Cálculo de total diario:** suma automática del total vendido en la jornada.
- 💾 **Guardado en archivo:** genera un archivo de texto (`ventas_dia.txt`) con todas las ventas y el total del día.
- 🖥️ **Compatible con Windows y Linux** (espera de teclas y limpieza de pantalla multiplataforma).

---

## 🧑‍💻 Tecnologías utilizadas

- Lenguaje: **C**
- Entrada/Salida estándar
- Manejo de archivos (`fopen`, `fprintf`, `fclose`)
- Estructuras (`struct`)
- Listas enlazadas dinámicas (`malloc`, `free`)

---

## 🚀 Cómo compilar y ejecutar

### En **Windows** (con [MinGW](https://www.mingw-w64.org/)):

```bash
gcc main.c -o main.exe
./main.exe
```

### En **Linux**:

```bash
gcc main.c -o main
./main
```

> ⚠️ Asegurate de que el archivo `main.c` esté en la misma carpeta desde donde ejecutás el comando.

---

## 📂 Archivo de salida

Al guardar las ventas, se genera un archivo `ventas_dia.txt` con un resumen como el siguiente:

```
=== Registro de Ventas ===
Producto: Lata de Pepsi | Cantidad: 2 | Total: $2800.00
Producto: Alfajor Milka | Cantidad: 3 | Total: $4500.00
...
Total del día: $7300.00
```

---

## 🧠 Aprendizajes del proyecto

Este sistema fue desarrollado como ejercicio práctico de:

- Programación estructurada en C
- Gestión dinámica de memoria
- Entrada/salida por consola
- Persistencia de datos en archivos

---

## 🛠️ Autor

**Maxi**  
Estudiante de Programación 1  
GitHub: [Tu usuario de GitHub]
