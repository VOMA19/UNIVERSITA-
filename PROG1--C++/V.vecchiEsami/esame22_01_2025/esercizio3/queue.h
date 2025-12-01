#include <cstdlib>

using namespace std;

typedef struct _Queue * Queue;

Queue init_queue();
void enqueue(Queue q, char c);
char dequeue(Queue q);
bool queue_is_empty(Queue q);
void delete_queue(Queue q);
