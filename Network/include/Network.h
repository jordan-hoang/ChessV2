//
// Created by jordan on 2021-04-29.
//

#include <thread>
#ifndef CHESSV2_NETWROK_H
#define CHESSV2_NETWROK_H



class Network {
public:
    /* Explicitly using the default constructor to
     * underline the fact that it does get called */
    Network()= default;

    ~Network(){
        continueRunning = false;
        if(the_thread.joinable()) the_thread.join();
    }

    void start(){
        // This will start the thread. Notice move semantics!
        the_thread = std::thread(&Network::ThreadMain, this);
    }


    std::thread the_thread;
    bool continueRunning = true; // Super simple thread stopping.
    void ThreadMain();
    void socketLoop();


};


#endif //CHESSV2_NETWROK_H
