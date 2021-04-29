#include <ChessController.h>
#include <thread>

static pthread_cond_t SHUTDOWN_CONDL = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t SHUTDOWN_MUTEX = PTHREAD_MUTEX_INITIALIZER; //Lock that determines if the loop keeps going

int main() {


    ChessController a;
    a.run();

    // Sample move say is b6,b5 or can be a6,a4.

    //a.playGame();
    pthread_cond_wait(&SHUTDOWN_CONDL, &SHUTDOWN_MUTEX); // Signals the thread that called this function to 'sleep.' never ends.



    return 0;
}
