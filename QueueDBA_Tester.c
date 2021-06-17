#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "QueueDBA.h"

#define L_STRING 81
#define OP_LENGTH 10

/* Stampa il contenuto della coda su file.
IP coda Coda di cui si vogliono stampare gli elementi.
OF out File su cui viene stampata la coda.
*/
void printQueue(QueueDBA *coda, FILE *out) {
	int i;
	if( queueSize(coda) == 0) {
		fprintf(out, "[ ]\n");
		return;
	} else {
		fprintf(out, "[ ");
		for(i = getFirstIndex(coda); i < getLastIndex(coda) + 1; i++) {
			fprintf(out, "%.1f", coda->elem[i]);
			if(i+1 < coda->last + 1)
				fprintf(out, ", ");
		} /* for */
	fprintf(out, " ]\n");
	} /* else */
}


int main(int argc, char const **argv) {	
	char nameFileIn[L_STRING], nameFileOut[L_STRING];
	char read[OP_LENGTH];
	double temp = 0;
	FILE *inF, *outF;
	QueueDBA coda = {0};
	if(argc < 3) {
		printf("Numero file di input errato.");
		exit(0);
	} /* if */
	strcpy(nameFileIn, argv[1]);
	strcpy(nameFileOut, argv[2]);
	inF = fopen(nameFileIn, "r");
	if (inF == NULL)
		return -1;											/* apertura fallita di $nameFileIn */
	outF = fopen(nameFileOut, "w");
	if (outF == NULL) {
		fclose(inF);
		return -2;											/* apertura fallita di $nameFileOut */
	} /* if */
	
	while(!feof(inF)) {
		fscanf(inF, "%s", read);
		
		if(strcmp(read ,"IN") == 0) {						/* queueInit */
			queueInit(&coda);
			fprintf(outF, "%s [ ]\n", read);
		} /* if */
		
		else if(strcmp(read ,"CA") == 0) {					/* queueCapacity */
			fprintf(outF, "CA %d ", queueCapacity(&coda));
			printQueue(&coda, outF);
		} /* else if */
		
		else if(strcmp(read ,"SI") == 0) {					/* queueSize */
			fprintf(outF, "SI %d ", queueSize(&coda));
			printQueue(&coda, outF);
		} /* else if */
		
		else if(strcmp(read ,"IE") == 0) {					/* queueIsEmpty */
			if (queueIsEmpty(&coda))
				fprintf(outF, "IE true ");
			else
				fprintf(outF, "IE false ");
			printQueue(&coda, outF);
		} /* else if */
		
		else if(strcmp(read ,"AL") == 0) {					/* queueAddLast */
			fscanf(inF, "%4s", read);
			temp = atof(read);
			queueAddLast(&coda, temp);
			fprintf(outF, "AL %.1f ", temp);
			printQueue(&coda, outF);
		} /* else if */
		
		else if(strcmp(read ,"GF") == 0) {					/* queueGetFirst */
			temp = queueGetFirst(&coda);
			if(temp == -1) {
				fprintf(outF, "GF KO ");
				printQueue(&coda, outF);
			} else {
				fprintf(outF, "GF %.1f ", queueGetFirst(&coda));
				printQueue(&coda, outF);
			}
		} /* else if */
		
		else if(strcmp(read ,"RF") == 0) {					/* queueRemoveFirst */
			temp = queueRemoveFirst(&coda);
			if(temp == -1) {
				fprintf(outF, "RF KO ");
				checkAndSet(&coda);
				printQueue(&coda, outF);
			} else {
				fprintf(outF, "RF %.1f ", temp);
				printQueue(&coda, outF);
			}
		} /* else if */
		
		else if(strcmp(read ,"FR") == 0) {					/* queueFree */
			fprintf(outF, "FR\n");
			queueFree(&coda);
		} /* else if */
	} /* while */
	
	fclose(inF);
	fclose(outF);
	queueFree(&coda);
	return 0;
} /* main */
