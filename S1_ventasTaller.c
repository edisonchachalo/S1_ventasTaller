#include <stdio.h>

int main()
{
    int stock, cantidad, opcion;
    char id[20];
    float precio, total_ganancias = 0, venta = 0, dscto;
    char nombre[30];
    int val;

    do
    {
        printf("\nMenú de Opciones:\n");
        printf("1. Registro producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar información del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese el ID del producto: ");
            scanf("%s", id);

            printf("Ingrese el nombre del producto: ");
            fflush(stdin);
            fgets(nombre, 30, stdin);

            do
            {
                printf("Ingrese la cantidad incial en stock: ");
                fflush(stdin);
                val = scanf("%d", &stock);
                if (stock < 1)
                {
                    printf("El stcok no puede ser negativo ni cero, vuelva a ingresar el valor\n");
                }
                if (val != 1)
                {
                    printf("Ingreso un valor incorrecto, vuelva a ingresar el valor\n");
                }
            } while (val != 1 || stock < 1);

            printf("Ingrese el precio unitario del producto: ");
            scanf("%f", &precio);

            break;
        case 2:
            do
            {
                printf("Ingrese la cantidad a vender: ");
                val = scanf("%d", &cantidad);
                if (cantidad < 1)
                {
                    printf("La cantidad no puede ser negativo ni cero, vuelva a ingresar el valor\n");
                }
                if (val != 1)
                {
                    printf("Ingreso un valor incorrecto, vuelva a ingresar el valor\n");
                }
                if (cantidad > stock)
                {
                    printf("No se puede vender esa cantidad, no hay stock suficiente\n");
                }
            } while (val != 1 || cantidad < 1 || cantidad > stock);
            if (cantidad > 10)
            {
                dscto = (cantidad * precio) * 0.1;
                venta = (cantidad * precio) - dscto;
                printf("Obtuvo un 10%% de descuento. Su descuento es: %f\n", dscto);
            }
            else
            {
                venta = cantidad * precio;
            }

            printf("El valor de la venta actual es; %f\n", venta);
            stock -= cantidad;
            total_ganancias += venta;
            break;

        case 3:
            printf("Ingrese la cantidad a agregar al stock: ");
            scanf("%d", &cantidad);
            stock += cantidad;

            break;

        case 4:
            printf("\nInformación del producto:\n");
            printf("ID: %s\n", id);
            printf("Nombre: %s", nombre);
            printf("Stock disponible: %d\n", stock);
            printf("Precio unitario: %.2f\n", precio);
            break;

        case 5:
            printf("Total de ganancias: $%.2f\n", total_ganancias);
            break;

        case 6:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}
