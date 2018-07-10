#include <stdio.h>
#include <string.h>
#include "TAD.h"
#include "cargarNextVuelo.h"

#define DELIM ";"
#define MAX_LONG_LINEA 500
#define ASCIINUM_TO_INT(c) ((int)(c-'0'))

vueloADT cargarNextVuelo(FILE *f,vueloADT vuelo){
	char *field,linea[MAX_LONG_LINEA];
	VTFecha fecha;
	VTHora hora;
	if(!feof(f)){

		//obtenemos la linea
		fgets(linea,MAX_LONG_LINEA,f);
		//obtenemos el primer campo(el dia)
		field=strtok(linea,DELIM);
		fecha.dia=ASCIINUM_TO_INT(field[0])*10+ASCIINUM_TO_INT(field[1]);
		fecha.mes=ASCIINUM_TO_INT(field[3])*10+ASCIINUM_TO_INT(field[4]);
		fecha.anio=ASCIINUM_TO_INT(field[6])*1000+ASCIINUM_TO_INT(field[7])*100+ASCIINUM_TO_INT(field[8])*10+ASCIINUM_TO_INT(field[9]);
		setVueloFecha(vuelo,fecha);
		//luego la hora
		field=strtok(NULL,DELIM);
		hora.hora=ASCIINUM_TO_INT(field[0])*10+ASCIINUM_TO_INT(field[1]);
		hora.minuto=ASCIINUM_TO_INT(field[3])*10+ASCIINUM_TO_INT(field[4]);
		setVueloHora(vuelo,hora);
		//luego ignoramos el siguiente
		strtok(NULL,DELIM);
		//luego leemos clasificacion
		field=strtok(NULL,DELIM);
		if(strcmp(field,"Internacional")==0){
			setVueloClasificacion(vuelo,V_INTERNACIONAL);
		}
		else if(strcmp(field,"Cabotaje")==0){
			setVueloClasificacion(vuelo,V_CABOTAJE);
		}
		else{
			setVueloClasificacion(vuelo,V_NA);
		}
		//luego leemos tipo de movimiento
		field=strtok(NULL,DELIM);
		if(strcmp(field,"Aterrizaje")==0){
			setVueloTipoDeMov(vuelo,V_ATERRIZAJE);
		}
		else{
			setVueloTipoDeMov(vuelo,V_DESPEGUE);
		}

		//luego leemos oaci de origen
		field=strtok(NULL,DELIM);
		setVueloOrigOaci(vuelo,field);
		//luego leemos el oaci de dest
		field=strtok(NULL,DELIM);
		setVueloDestOaci(vuelo,field);
		//luego el nombre de la aerolinea
		field=strtok(NULL,DELIM);
		setVueloNomAerolin(vuelo,field);
		//luego la aeronave
		field=strtok(NULL,DELIM);
		setVueloAeronave(vuelo,field);
		//y por ultimo el apc
		field=strtok(NULL,DELIM);
		setVueloANAPC(vuelo,field[0]);
	}

	return vuelo;
}
