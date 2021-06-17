#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "QueueDBA.h"

/*Inizializzazione della struttura per la coda.
IP coda Struttura da inizializzare.
*/
void queueInit(QueueDBA *coda) {
	if(coda->elem != NULL)
		free(coda->elem);
	coda->capacity = 1;
	coda->size = 0;
	coda->first = 0;
	coda->last = -1;
	coda->elem = malloc(coda->capacity * sizeof(double));
	assert(coda->elem != NULL);
} /* queueInit */

/* Restituisce la capacita' della coda.
IP coda Struttura di cui si vuole la capacita'.
OR Capacita' della coda.
*/
int queueCapacity(QueueDBA *coda) {
	return coda->capacity;
} /* queueCapacity */

/*Restituisce numero di elememti della coda.
IP coda Coda di cui si vuole sapere il numero di elementi.
OR Numero elementi.
*/
int queueSize(QueueDBA *coda) {
	return coda->size;
} /* queueSize */

/* Restituisce indice primo elemento della coda.
IP coda Coda di cui si vuole l'indice del primo elemento.
OR Indice primo elemento.
*/
int getFirstIndex(QueueDBA *coda) {
	return coda->first;
} /* getFirstIndex */

/* Restituisce indice ultimo elemento della coda.
IP coda Coda di cui si vuole l'indice ultimo elemento.
OR Indice ultimo elemento.
*/
int getLastIndex(QueueDBA *coda) {
	return coda->last;
} /* getLastIndex */

/* Verifica se coda è vuota.
IP coda Coda da verificare.
OR Ritorno true se la coda è vuota, false se sono presenti elementi.
*/
bool queueIsEmpty(QueueDBA *coda) {
	return (coda->size == 0);
} /* queueIsEmpty */

/* Verifica se coda è piena.
IP coda Coda da verificare.
OR Ritorno true se la coda è piena, false se sono presenti spazi vuoti.
*/
bool isFull(QueueDBA *coda) {
	return (coda->last  == coda->capacity - 1);
} /* isFull */

/* Aggiunge un elemento alla fine della coda.
IP coda Coda a cui aggiungere l'elemento.
IP num Elemento da aggiungere.
*/
void queueAddLast(QueueDBA *coda, double num) { 
	if(isFull(coda))
		queueResize(coda);
	coda->elem[++(coda->last)] = num;
	coda->size++;
} /* queueAddLast */

/* Restituisce il primo elemento della coda.
IP coda Coda di cui si vuole il primo elemento.
OR Restituisce primo elemento, se presente, altrimenti restituisce -1.
*/
double queueGetFirst(QueueDBA *coda) {
	if(queueIsEmpty(coda))
		return -1; 
	return coda->elem[coda->first];
} /* queueGetFirst */

/* Restituisce ed elimina il primo elemento dalla coda.
IP coda Coda di cui si vuole il primo elemento e successivamente toglierlo.
OR Restituisce primo elemento, se presente, altrimenti restituisce -1.
*/
double queueRemoveFirst(QueueDBA *coda) {
	int first = coda->first;
	double i;
	i = queueGetFirst(coda);
	if(i == -1)
		return i;
	else {
		coda->size--;
		if(first < coda->capacity)
			(coda->first)++;
		return i;
	} /* else */
} /* queueRemoveFirst */

/* Aumenta la memoria a disposizione della struttura, e quindi la sua capacita'.
IP coda Struttura di cui si vuole aumentare la memoria allocata.
*/
void queueResize(QueueDBA *coda) {
	int newLength = (coda->capacity) * 2;
	coda->elem = realloc(coda->elem, newLength * sizeof(double));	
	assert(coda->elem != NULL);
	coda->capacity = newLength;
} /* queueResize */

/* Verifico e correggo indice last della coda vuota.
IP coda Struttura coda da esaminare.
*/
void checkAndSet(QueueDBA *coda) {
	if(coda->first == coda->last && coda->size == 0 )
		coda->last = coda->first - 1;
} /* checkAndSet */

/* Libera l'area di memoria allocata dalla struttura.
IP coda Struttura di cui si vuole liberare l'area di memoria.
*/
void queueFree(QueueDBA *coda) {
	if(coda != NULL && coda->elem != NULL){
		free(coda->elem);
		coda->elem = NULL;
		coda->capacity = 0;
		coda->size = 0;
		coda->first = 0;
		coda->last = -1;
	} /* if */
} /* queueFree */
