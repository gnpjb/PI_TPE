#ifndef TAD_H_INCLUDED
#define TAD_H_INCLUDED

//definicion de constantes que usara el TAD AeropuertoCDT
#define LONG_CODIGO_LOCAL 3
#define LONG_CODIGO_OACI 4
#define LONG_CODIGO_IATA 4

enum{A_AERODROMO,A_HELIPUERTO};
enum{A_PUBLICO,A_PRIVADO};
enum{A_NACIONAL, A_INTERNACIONAL};
enum{V_INTERNACIONAL,V_CABOTAJE,V_NA};
enum{V_ATERRIZAJE,V_DESPEGUE};

typedef struct VEFecha{
	int dia;
	int mes;
	int anio;
}VTFecha;

typedef struct VEHora{
	int hora;
	int minuto
}VTHora;


typedef struct vueloCDT* vueloADT;


typedef struct *AeropuertoCDT AeropuertoADT;

#endif
