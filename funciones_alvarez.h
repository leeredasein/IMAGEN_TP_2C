#ifndef FUNCIONES_ALVAREZ_H_INCLUDED
#define FUNCIONES_ALVAREZ_H_INCLUDED
#include "estructuras.h"

int solucion(int argc, char* argv[]);
void negativo(t_pixel** imagen, int ancho, int alto);
void escala_de_grises(t_pixel** imagen, int ancho, int alto);
t_metadata obtener_metadata(FILE* archivo);
void guardar_imagen(FILE* archivo,t_pixel** imagen, int ancho, int alto, t_metadata metadata);


//void espejar_horizontal(t_pixel*);
//void espejar_vertical(t_pixel*);
//unsigned char aumentar_contraste_10(t_pixel*);
//unsigned char reducir_contraste_20(t_pixel*);
//unsigned char tonalidad_azul_50(t_pixel*);
//unsigned char tonalidad_verde_5(t_pixel*);
//unsigned char tonalidad_roja_15(t_pixel*);
//int recortar_30(FILE*, t_metadata*);
//int achicar_10(FILE*, t_metadata*);
//int rotar_derecha(FILE*, t_metadata *);
//int rotar_izquierda(FILE*, t_metadata *);
//void concatenar_horizontal(t_pixel*);
//void concatenar_vertical(t_pixel*);
//int comodin(FILE*, t_metadata*);

#endif // FUNCIONES_ALVAREZ_H_INCLUDED
