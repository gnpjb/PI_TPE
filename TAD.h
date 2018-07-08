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

typedef struct vueloCDT{
	VTFecha fecha;
	VTHora hora;
	char clasificacion;
	char tipoDeMov;
	char origOaci[4];
	char destOaci[4];
	char *nomAerolin;
	char *aeronave;
	char anAPC;
}vueloCDT;


typedef struct *AeropuertoCDT AeropuertoADT;
typedef struct *AeroListaCDT AeroListaADT;

AeroListaADT newAeroLista();
void addAeroLista(AeroListaADT,AeropuertoADT);
//dado un oaci lo busca en la tabla de aeropuertos, devuelve 1 si esta y 0 si no
int enAeroLista(AeroListaADT,char oaci[]);
#endif
