#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones_alvarez.h"
#include "estructuras.h"


void moverCursor(FILE* archivo, int cant_posicion)
{
    unsigned char aux;
    for(int i = 0; i <cant_posicion; i++)
    {
        fread(&aux, sizeof(unsigned char), 1, archivo);
    }
}


t_metadata obtener_metadata(FILE* archivo)
{
    t_metadata metadata;
    moverCursor(archivo,2);

    if (fread(&metadata.tamArchivo, sizeof(unsigned int), 1, archivo) != 1)
    {
        perror("Error leyendo tamArchivo");
    }
    else
    {
        printf("tamArchivo: %u\n", metadata.tamArchivo);
    }

    moverCursor(archivo,8);

    if (fread(&metadata.tamEncabezado, sizeof(unsigned int), 1, archivo) != 1)
    {
        perror("Error leyendo tamEncabezado");
    }
    else
    {
        printf("tamEncabezado: %u\n", metadata.tamEncabezado);
    }

    if (fread(&metadata.ancho, sizeof(unsigned int), 1, archivo) != 1)
    {
        perror("Error leyendo ancho");
    }
    else
    {
        printf("ancho: %u\n", metadata.ancho);
    }

    if (fread(&metadata.alto, sizeof(unsigned int), 1, archivo) != 1)
    {
        perror("Error leyendo alto");
    }
    else
    {
        printf("alto: %u\n", metadata.alto);
    }

     moverCursor(archivo,2);

    if (fread(&metadata.profundidad, sizeof(unsigned short), 1, archivo) != 1)
    {
        perror("Error leyendo profundidad");
    }
    else
    {
        printf("profundidad: %u\n", metadata.profundidad);
    }

    return metadata;
}



void guardar_imagen(FILE* archivo,t_pixel** imagen, int ancho, int alto, t_metadata metadata)
{
    fwrite(&metadata, sizeof(t_metadata),1,archivo);
    for (int i = 0; i <alto; i++)
    {
        for (int j = 0; j <alto; j++)
        {
            fwrite(imagen[i][j].pixel,sizeof(unsigned char),3,archivo);
        }

    }

}

void negativo(t_pixel** imagen, int ancho, int alto)
{
    for (int i =0; i<alto; i++)
    {
        for (int j = 0; j < ancho; j++)
        {
            imagen[i][j].pixel[0] = 255 - imagen[i][j].pixel[0];
            imagen[i][j].pixel[1] = 255 - imagen[i][j].pixel[1];
            imagen[i][j].pixel[2] = 255 - imagen[i][j].pixel[2];
        }
    }
}

void escala_de_grises(t_pixel** imagen, int ancho, int alto)
{
    for (int i =0; i<alto; i++)
    {
        for (int j = 0; j < ancho; j++)
        {
            unsigned char promedio = (imagen[i][j].pixel[0]+imagen[i][j].pixel[1]+imagen[i][j].pixel[2])/3;
            imagen[i][j].pixel[0] = promedio;
            imagen[i][j].pixel[1] = promedio;
            imagen[i][j].pixel[2] = promedio;
        }
    }
}







