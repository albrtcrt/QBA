#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "QueueDBA.h"

#define L_STRING 81
#define OP_LENGTH 10

/* DA INSERIRE NEI METODI
IP nameFileIn Nome del file da elaborare.
IP nameFileOut Nome del file elaborato.
IF File $nameFileIn da elaborare.
OF File $nameFileOut elaborato.
OR Esito (
   0: elaborazione riuscita;
  -1: apertura fallita di $nameFileIn;
  -2: apertura fallita di $nameFileOut).
OF File $nameFileOut contenente ogni parola di $nameFileIn in una nuova linea.
*/


void printQueue(QueueDBA *coda, FILE *out) {
	int i;
	if( queueSize(coda) == 0) {
		printf("WUT\n");
		fprintf(out, "[ ]\n");
		return;
	} else {
	fprintf(out, "[ ");
	printf("for(i = %d; i< %d; i++)\n", getFirstIndex(coda), getLastIndex(coda) + 1);
	for(i = getFirstIndex(coda); i < getLastIndex(coda) + 1; i++) {
		printf("loop for elem[%d] (%f)\n", i, coda->elem[i]);
		fprintf(out, "%.1f", coda->elem[i]);
		if(i+1 < coda->last + 1)
			fprintf(out, ", ");
	}
	fprintf(out, " ]\n");
	}
}


int main(int argc, char const **argv) {	
	char nameFileIn[L_STRING], nameFileOut[L_STRING];
	char read[OP_LENGTH];
	double temp = 0;
	FILE *inF, *outF;
	QueueDBA coda = {0};
	if(argc < 3)
        exit(0);
	strcpy(nameFileIn, argv[1]);
	strcpy(nameFileOut, argv[2]);
	inF = fopen(nameFileIn, "r");
	if (inF == NULL)
        return -1;
	outF = fopen(nameFileOut, "w");
    if (outF == NULL) {
        fclose(inF);
        return -2;
    } /* if */
	
	while(!feof(inF)) {
		fscanf(inF, "%s", read);
        if(strcmp(read ,"IN") == 0) {		/* queueInit */
			queueInit(&coda);/*qui il problema */
			printf("test");
			fprintf(outF, "%s [ ]\n", read);
		} 
		else if(strcmp(read ,"CA") == 0) {	/* queueCapacity */
			fprintf(outF, "CA %d ", queueCapacity(&coda));
			printQueue(&coda, outF);
		} 
		else if(strcmp(read ,"SI") == 0) {	/* queueSize */
			fprintf(outF, "SI %d ", queueSize(&coda));
			printQueue(&coda, outF);
		} 
		else if(strcmp(read ,"IE") == 0) {	/* queueIsEmpty */
			if (queueIsEmpty(&coda))
				fprintf(outF, "IE true ");
			else
				fprintf(outF, "IE false ");
			printQueue(&coda, outF);
		} 
		else if(strcmp(read ,"AL") == 0) {	/* queueAddLast */
			fscanf(inF, "%4s", read);
			temp = atof(read);
			queueAddLast(&coda, temp);			
			fprintf(outF, "AL %.1f ", temp);
			printQueue(&coda, outF);
		} 
		else if(strcmp(read ,"GF") == 0) {	/* queueGetFirst */
			temp = queueGetFirst(&coda);
			if(temp == -1) {
				fprintf(outF, "GF KO ");
				printQueue(&coda, outF);
			} else {
				fprintf(outF, "GF %.1f ", queueGetFirst(&coda));
				printQueue(&coda, outF);
			}
		} 
		else if(strcmp(read ,"RF") == 0) {	/* queueRemoveFirst */
			temp = queueRemoveFirst(&coda);
			if(temp == -1) {
				printf("coda vuota");
				fprintf(outF, "RF KO ");
				printQueue(&coda, outF);
			} else {
				fprintf(outF, "RF %.1f ", temp);
				printQueue(&coda, outF);
			}
		} 
		else if(strcmp(read ,"FR") == 0) {	/* queueFree */
			fprintf(outF, "FR\n");
			queueFree(&coda);
		}		
	} /* while */
	
	fclose(inF);
    fclose(outF);
	queueFree(&coda);
	return 0;
}
