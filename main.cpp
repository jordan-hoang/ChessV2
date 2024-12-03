#include <thread>
#include "ChessController.h"


static pthread_cond_t SHUTDOWN_CONDL = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t SHUTDOWN_MUTEX = PTHREAD_MUTEX_INITIALIZER; //Lock that determines if the loop keeps going

int main() {


    ChessController chessGame;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    chessGame.run();


    // Sample move say is b6,b5 or can be a6,a4.
    pthread_cond_wait(&SHUTDOWN_CONDL, &SHUTDOWN_MUTEX); // Signals the thread that called this function to 'sleep.' never ends.

    return 0;
}
