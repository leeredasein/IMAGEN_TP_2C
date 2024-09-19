#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#pragma pack(push, 1) // Asegura que no haya relleno entre los campos

typedef struct
{
    unsigned short tipo;              // Tipo de archivo, debe ser 'BM'
    unsigned int tamano;              // Tama�o del archivo en bytes
    unsigned short reservado1;        // Reservado, debe ser 0
    unsigned short reservado2;        // Reservado, debe ser 0
    unsigned int offsetDatos;         // Offset a los datos de la imagen
} BMPHeader;

typedef struct
{
    unsigned int tamano;              // Tama�o de este encabezado (40 bytes)
    int ancho;                        // Ancho de la imagen
    int alto;                         // Alto de la imagen
    unsigned short planos;            // N�mero de planos de color, debe ser 1
    unsigned short bitsPorPixel;      // Bits por pixel, debe ser 24 para BMP de 24 bits
    unsigned int compresion;          // Tipo de compresi�n (0 = sin compresi�n)
    unsigned int tamanoImagen;        // Tama�o de la imagen en bytes
    int xPixelsPorMetro;              // Resoluci�n horizontal en p�xeles por metro
    int yPixelsPorMetro;              // Resoluci�n vertical en p�xeles por metro
    unsigned int coloresUsados;       // N�mero de colores en la paleta
    unsigned int coloresImportantes;  // N�mero de colores importantes
} BMPInfoHeader;

typedef struct
{
    unsigned char pixel[3];
} t_pixel;


typedef struct
{
    unsigned int tamArchivo;
    unsigned int tamEncabezado;
    unsigned int ancho;
    unsigned int alto;
    unsigned short profundidad;
} t_metadata;

#pragma pack(pop) // Restaura el empaquetado predeterminado
#endif // ESTRUCTURAS_H_INCLUDED
