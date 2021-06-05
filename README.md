# Queuebyarray

Argomenti compilazione: gcc -ansi -pedantic -Wall -Werror -c

~ Durante la prova, dovrete postare i "file-soluzione" nell'opportuna attività contenuta sul Moodle del dipartimento. I file
che posterete devono avere il nome indicato nella consegna.
Dopo avete postato una vostra soluzione sul Moodle (e se il tempo di consegna non è scaduto), potrete sostituirla con
un'altra.
~ Sono elementi di valutazione: la correttezza, l'efficienza, la leggibilità del sorgente, la qualità dei commenti.
~ Nella prima linea di ogni file sorgente dovete inserire i vostri cognome e nome dentro un commento.
~ Non potete definire cicli annidati nella stessa funzione; quindi, dovete inserire un eventuale ciclo interno in un'altra funzione
intermedia.
~ Se gestite un sottoarray, dovete farlo mediante la modalità specifica del linguaggio C.
~ Il vostro sorgente deve essere compilabile mediante i parametri contenuti nel file CL.bat, che è disponibile nel Moodle
del corso.
A. Definite un tipo strutturato QueueDBA (= QueueDoubleByArray) e alcune funzioni per gestire una coda di double, che
dovete memorizzare dentro un array.
Definite almeno le seguenti funzioni:
~ queueInit, che deve inizializzare una variabile di tipo QueueDBA vuota; in particolare, deve allocare l’array composto
da esattamente un elemento (vuoto).
~ queueCapacity, che deve dare in output l’attuale capienza dell’array.
~ queueSize, che deve dare in output l’attuale grandezza della coda (cioè, il numero di elementi attualmente presenti).
~ queueIsEmpty, che deve dire se la coda è vuota.
~ queueAddLast
È dato un double elem.
queueAddLast deve inserire elem in una variabile QueueDBA in modo da gestire una politica FIFO.
Se (prima dell’inserimento) l’array è saturo (cioè, la sua capienza e la sua grandezza sono uguali), queueAddLast deve
opportunamente aumentare la capienza dell’array, e poi deve inserire elem.
~ queueGetFirst, che deve dare in output il primo elemento (tra quelli presenti) inserito nella coda (in modo da gestire
una politica FIFO).
Naturalmente, se la coda è vuota, queueGetFirst non può dare nessun elemento; in questo caso, deve indicare opportunamente
questa situazione.
~ queueRemoveFirst, che deve comportarsi come queueGetFirst, con l’unica differenza che deve eliminare dalla coda
(in modo da gestire una politica FIFO) l’elemento che sta dando in output.
~ queueFree, che deve liberare ogni allocazione fatta precedentemente nella variabile di tipo QueueDBA.
B. Definite un programma QueueDBA_Tester per collaudare il tipo QueueDBA.
Il programma deve leggere un file di testo. Ogni linea del file d’ingresso corrisponde a un’operazione, e contiene:
~ La sigla dell’operazione, che è uno di questi valori: IN (= queueInit), CA (= queueCapacity), SI (= queueSize),
IE (= queueIsEmpty), AL (= queueAddLast), GF (= queueGetFirst), RF (= queueRemoveFirst) , FR (= queueFree).
~ Il valore da inserire nella coda, se l’operazione è AL.
Se l’operazione è IN, il programma deve sostituire la coda attuale con una nuova coda vuota.
Es:
IN
CA
AL 4.5
CA
AL 3.5
SI
IE
GF
RF
RF
RF
AL 7.5
AL 8.5
IN
CA
AL 9.5

Il programma deve produrre un file di testo. Ogni linea del file d'uscita corrisponde a un’operazione letta dal file di ingresso,
e contiene, nell’ordine:
~ La sigla dell’operazione.
~ Il valore inserito nella pila, se l’operazione è AL.
~ KO, se l'operazione è fallita.
~ L’eventuale valore ritornato dall’operazione, se è l’operazione è riuscita.
~ Il contenuto della pila dopo l’operazione.
I vari elementi devono essere mostrati: a partire dal primo elemento che sarà estratto; tra una coppia di []; separati da
una virgola.
Con l’esempio sopra, il programma produce un file contenente i valori:
IN []
CA 1 []
AL 4.5 [4.5]
CA 1 [4.5]
AL 3.5 [4.5, 3.5]
SI 2 [4.5, 3.5]
IE false [4.5, 3.5]
GF 4.5 [4.5, 3.5]
RF 4.5 [3.5]
RF 3.5 []
RF KO []
AL 7.5 [7.5]
AL 8.5 [8.5] AL 8.5 [7.5, 8.5]
IN []
CA 1 []
AL 9.5 [9.5]
NB: Il numero 4.5 può comparire anche nel formato 4.500000.
Il programma QueueDBA_Tester deve avere due argomenti, contenenti rispettivamente il nome del file d’input e il nome
del file d’output:
QueueDBA_Tester FileInput.txt FileOutput.txt
Consegnate esattamente i seguenti tre file:
~ QueueDBA.h, che deve contenere la struttura omonima e ciò che riterrete opportuno.
~ QueueDBA.c, che deve contenere almeno le funzioni che ho descritto al punto A.
~ QueueDBA.c QueueDBA_Tester.c, che deve contenere il main e le funzioni che sono necessarie per produrre il main.
Naturalmente, potete definire altre funzioni (che dovrete commentare opportunamente).
