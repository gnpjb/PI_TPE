trabajo final de Programacion imperativa

Para funcionar es necesario cambiar los
";;" por "; ;" .Esto es de vital importancia
para el funcionamiento correcto del programa

Tambien es necesario llamar aeropuertos.csv 
al archivo de datos de aeropuertos y 
vuelos.csv al de datos de vuelos

compilar con
gcc -Wall -pedantic -std=c99 -g cargarAeropuertos.c cargarNextVuelo.c main.c process_queries.c query1ADT.c query2ADT.c query3ADT.c query4ADT.c TAD.c -o test.o

