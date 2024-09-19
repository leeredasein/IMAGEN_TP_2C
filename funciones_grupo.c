/*
    Integrantes del grupo. En caso de ser un grupo de dos integrantes, no completar el último campo.
    Si alguno de los integrantes del grupo dejara la materia, completar de todos modos sus datos, aclarando que no entrega.
    -----------------
    Apellido: Alvarez, Gisele
    DNI: 34579954
    Entrega: Sí
    -----------------
    Apellido:
    DNI:
    Entrega:
    -----------------
    Apellido:
    DNI:
    Entrega:
    -----------------
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones_alvarez.h"


int solucion(int argc, char* argv[])
{
    /*
        Aquí deben hacer el código que solucione lo solicitado.
        Todas las funciones utilizadas deben estar declaradas en este archivo, y en su respectivo .h
    */

    if (argc != 3)
    {
        printf("Uso: bmpmanipuleitor <opcion> <archivo>\n");
        return 1;
    }

    char* opcion = argv[1];
    char* archivo_entrada = argv[2];
    char* archivo_salida = malloc(strlen(archivo_entrada) + strlen(opcion) + 20);

    if (archivo_entrada == NULL)
    {
        fprintf(stderr, "Error: archivo de entrada NULO\n");
        return 1;
    }

    if (archivo_salida == NULL)
    {
        perror("Error asignando memoria archivo de salida");
        return 1;
    }

    strcpy(archivo_salida, "IMAGEN_");
    strcat(archivo_salida, opcion);
    strcat(archivo_salida, "_");
    strcat(archivo_salida, archivo_entrada);

    FILE* archivo = fopen(archivo_entrada, "rb");
    if (archivo == NULL)
    {
        printf("No se puede abrir el archivo %s\n", archivo_entrada);
        free(archivo_salida);
        return 1;
    }

    t_metadata metadata = obtener_metadata(archivo);
    int ancho = metadata.ancho;
    int alto = metadata.alto;

    t_pixel** imagen = malloc(sizeof(t_pixel*) * alto);
    if (imagen == NULL)
    {
        perror("Error asignando memoria alto");
        fclose(archivo);
        free(archivo_salida);
        return 1;
    }

    printf("Ancho: %d, Alto: %d\n", ancho, alto); // Mensaje de depuración

    for (int i = 0; i < alto; i++)
    {
        imagen[i] = malloc(sizeof(t_pixel) * ancho);
        if (imagen[i] == NULL)
        {
            perror("Error asignando memoria ancho");
            for (int j = 0; j < i; j++)
            {
                free(imagen[j]);
            }
            free(imagen);
            fclose(archivo);
            free(archivo_salida);
            return 1;
        }
    }

    for (int i = 0; i < alto; i++)
    {
        if (fread(imagen[i], sizeof(t_pixel), ancho, archivo) != ancho)
        {
            perror("Error leyendo la imagen");
            for (int j = 0; j < alto; j++)
            {
                free(imagen[j]);
            }
            free(imagen);
            fclose(archivo);
            free(archivo_salida);
            return 1;
        }
    }

    fclose(archivo);

    if (strcmp(opcion, "--negativo") == 0)
    {
        negativo(imagen, ancho, alto);
    }
    else if (strcmp(opcion, "--escala-de-grises") == 0)
    {
        escala_de_grises(imagen, ancho, alto);
    }
    else
    {
        printf("Opción Inválida\n");
        for (int i = 0; i < alto; i++)
        {
            free(imagen[i]);
        }
        free(imagen);
        free(archivo_salida);
        return 1;
    }

    archivo = fopen(archivo_salida, "wb");
    if (archivo == NULL)
    {
        printf("No es posible crear el archivo %s\n", archivo_salida);
        for (int i = 0; i < alto; i++)
        {
            free(imagen[i]);
        }
        free(imagen);
        free(archivo_salida);
        return 1;
    }

    guardar_imagen(archivo, imagen, ancho, alto, metadata);

    fclose(archivo);

    for (int i = 0; i < alto; i++)
    {
        free(imagen[i]);
    }

    free(imagen);
    free(archivo_salida);

    return 0;
}
