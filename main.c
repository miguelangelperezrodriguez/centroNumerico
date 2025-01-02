#include <stdio.h>
#include <stdlib.h>

int max_calculos;
long suma_izquierda;
long sol_izqda,sol_derecha;

int b_ok_derecha = 0;

long calcular_suma_izquierda (int max);
int intentar_suma_derecha (int i, long sum_izq ,long *soluc_izda,long *soluc_derecha);

int main()
{

    printf("Centros numéricos.\n");
    printf("===================\n");

    printf("Introduzca número máximo a determinar los centros : ");
    scanf ("%d", &max_calculos);

    for (int i=6;i<=max_calculos;i++)
    {
        suma_izquierda = calcular_suma_izquierda (i);
        b_ok_derecha = intentar_suma_derecha (i,suma_izquierda,&sol_izqda,&sol_derecha);
        if (b_ok_derecha)
           printf ("[%d] Izda : 1-%d - Derecha : %ld-%ld\n" ,i, i-1,sol_izqda,sol_derecha);
    }

    return 0;
}

long calcular_suma_izquierda (int max)
{
    int i;
    long suma = 0;
    for (i=1;i<max;i++)
        suma+=i;
    return suma;
}

// Devuelve 1 si funciono
int intentar_suma_derecha (int i, long sum_izq,long *soluc_izda,long *soluc_derecha)
{
    int centro;
    long acumulado;
    int primer_centro;

    primer_centro = i+1;
    centro = i + 1;
    acumulado = centro;

    while (acumulado <= sum_izq)
    {
        if (acumulado==sum_izq)
        {
            *soluc_izda = primer_centro;
            *soluc_derecha = centro;
            return 1;
        }
        centro = centro+1;
        acumulado += centro;

    }
    return 0;
}

