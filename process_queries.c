#define LOC 0
#define INT 1
#define ORIG 1
#define DEST 0

/*
    Yo creo que cuando pasemos los aeropuertos a memoria, usemos un vector de structs
    que tienen los siguientes datos (unicamente): oaci, desc, iata, local
    Estas son las cosas que irian en el while del main, cada vez que tomamos un vuelo.
*/


//Agrega los datos provisorios al query1.
void process_query1(query1ADT query, vueloADT vuelo){

    //getLocal y getDesc se supone que obtengan los datos correspondientes de la tabla
    //de aeropuertos que pasamos a memoria. No se si se la pasamos a una funcion o usamos
    //una variable global

    add1(query, vuelo->origOaci, getLocal(vuelo->origOaci), getDesc(vuelo->origOaci));
    add1(query, vuelo->destOaci, getLocal(vuelo->destOaci), getDesc(vuelo->destOaci));


}

void process_query2(query2ADT query, vueloADT vuelo){

    if(vuelo->clasificacion==INT){
        if(enListaAero(vuelo->origOaci)){ //Busca al aeropuerto en la lista de aeropuertos locales (segun oaci)
                add2(query, vuelo->origOaci, getIata(vuelo->origOaci), ORIG);
        }
        else if(enListaAero(vuelo->destOaci)){
                add2(query, vuelo->destOaci, getIata(vuelo->destOaci), DEST);
        }
    }
}

void process_query3(query3ADT query, vueloADT vuelo){

    int c;
    if(c=getDayOfWeek(vuelo->fecha)!=-1){  /*getDayOfWeek recibe una fecha y retorna un dia de semana [0-6],
                                                si hay algun error retorna -1*/
        query->days[c]++;
    }
}

void process_query4(query4ADT query,vueloADT vuelo){
	int flagLocDes=enListaAero(vuelo->origOaci)
	,flagLocAter=enListaAero(vuelo->destOaci);
	add4(query,vuelo->origOaci,flagLocDes,vuelo->destOaci,flagLocAter);
}
