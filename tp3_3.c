#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



struct Producto{
int productoID; //Numerado en ciclo iterativo
int cantidad; // entre 1 y 10
char *tipoProducto; // Algún valor del arreglo TiposProductos
float precioUnitario; // entre 10 - 100
};

struct Cliente{
int clienteID; // Numerado en el ciclo iterativo
char *nombreCliente; // Ingresado por usuario
int cantidadProductosAPedir; // (aleatorio entre 1 y 5)
struct Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”

};

int main() {

int n, i;
srand (time(NULL));
char *Buff; 
Buff= (char *) malloc(100*sizeof(char));
char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

// ---------------------- PEDIMOS EL INGRESO DE LA CANTIDAD DE CLIENTES ----------------------
printf("\nPor favor ingresar la cantidad de clientes: ");
scanf("%i", &n);
fflush(stdin);

// ---------------------- ASIGNAMOS MEMORIA A LAS ESTRUCTURAS ----------------------
struct Cliente *Clientes;
Clientes = (struct Cliente *) malloc(n * sizeof(struct Cliente)); 



// ---------------------- CARGAMOS LOS DATOS ----------------------
printf("\n\t\t-----Carga de datos-----");

for (int i = 0; i < n; i++)
{   
    fflush(stdin);
    Clientes[i].clienteID = i; 
    printf("\n\nIngrese el nombre del cliente %i:\t", i);
    gets(Buff);
    printf("\nIngresando datos ...");
    Clientes[i].nombreCliente = (char *) malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(Clientes[i].nombreCliente, Buff);
    Clientes[i].cantidadProductosAPedir = rand()%(5)+1;
    Clientes[i].Productos = (struct Producto *) malloc(sizeof(struct Producto) * Clientes[i].cantidadProductosAPedir);

    for (int j = 0; j < Clientes[i].cantidadProductosAPedir ; j++)
    {
        Clientes[i].Productos[j].productoID = j;
        Clientes[i].Productos[j].cantidad = rand()%(10)+1;
        Clientes[i].Productos[j].tipoProducto = (char *) malloc(13*sizeof(char));
        //Luego hacer una nota sobre esto: ¿Por que dejamos de usar las flechas aqui?
        strcpy(Clientes[i].Productos[j].tipoProducto, tiposProductos[rand()%(5)]);
        Clientes[i].Productos[j].precioUnitario = rand()%(100)+1;
    }
    

}

printf("\n\n-----Muestra de clientes y sus productos-----");
for (int i = 0; i < n; i++)
{
    printf("\nCliente ID: %i", Clientes[i].clienteID);
    printf("\nNombre del cliente: %s", Clientes[i].nombreCliente);
    printf("\nCantidad de productos a pedir: %i", Clientes[i].cantidadProductosAPedir);
    printf("\n\n-----------------");
    printf("\nSus productos: ");
    for (int j = 0; j < Clientes[i].cantidadProductosAPedir; j++)
    {
        
        printf("\n\n\tID del producto: %i", Clientes[i].Productos[j].productoID);
        printf("\n\tTipo de producto: %s", Clientes[i].Productos[j].tipoProducto);
        printf("\n\tCantidad: %i", Clientes[i].Productos[j].cantidad);
        printf("\n\tPrecio unitario: %f", Clientes[i].Productos[j].precioUnitario);
    }
    printf("Fin del cliente ID: %i", Clientes[i].clienteID);
    printf("\n\n-----------------");

}







return 0;
}

//Notas aparte

//En el momento que se crea el puntero para Cliente también se "crea" la definicion de Producto, por lo que solamente hay que asignarle memoria

// struct Producto *Productos; Acaso esto se define dentro de la estructura ya? -- Sí

// cliente[i].NombreCliente = (char *)malloc((strlen(Buff)+1)*sizeof(char));

//rand