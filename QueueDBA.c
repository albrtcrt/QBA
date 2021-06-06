#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "QueueDBA.h"

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

int queueCapacity(QueueDBA *coda) {
	return coda->capacity;
} /* queueCapacity */

int queueSize(QueueDBA *coda) {
	return coda->size;
} /* queueSize */

int getFirstIndex(QueueDBA *coda) {
	return coda->first;
}

int getLastIndex(QueueDBA *coda) {
	return coda->last;
}

bool queueIsEmpty(QueueDBA *coda) {
	return (coda->size == 0);
} /* queueIsEmpty */

bool isFull(QueueDBA *coda) {
	return (coda->first == coda->capacity - 1);
} /* isFull */

void queueAddLast(QueueDBA *coda, double num) { 
	if(isFull(coda)) {
		printf("coda piena.con numero %f\n", num);
		queueResize(coda);
		printf("resized\n");
	}
	coda->elem[++(coda->last)] = num;
	coda->size++;
} /* queueAddLast */

double queueGetFirst(QueueDBA *coda) {
	if(queueIsEmpty(coda))
		return -1; 
	return coda->elem[coda->first];
} /* queueGetFirst */

double queueRemoveFirst(QueueDBA *coda) {
	int first = coda->first;
	double i;
	i = queueGetFirst(coda);
	if(i == -1)
		return i;
	else {
		coda->size--;
		if(first < coda->capacity)
			coda->first++;
		return i;
	}
} /* queueRemoveFirst */

void queueResize(QueueDBA *coda) {
	int newLength = coda->capacity * 2;
	coda->elem = realloc(coda->elem, newLength * sizeof(double));	
	assert(coda->elem != NULL);
	coda->capacity = newLength;
} /* queueResize */

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
