typedef struct {
	int capacity, size, first, last;
	double *elem;
} QueueDBA;

void queueInit(QueueDBA*);

int queueCapacity(QueueDBA*);

int queueSize(QueueDBA*);

int getFirstIndex(QueueDBA*);

int getLastIndex(QueueDBA*);

bool isFull(QueueDBA*);

bool queueIsEmpty(QueueDBA*);

void queueAddLast(QueueDBA*, double); 

double queueGetFirst(QueueDBA*); 

double queueRemoveFirst(QueueDBA*);

void queueResize(QueueDBA*);

void queueFree(QueueDBA*);

void checkAndSet(QueueDBA*); 
