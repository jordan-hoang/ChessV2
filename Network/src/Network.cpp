//
// Created by jordan on 2021-04-29.
//
#include <string.h> // For memset
#include <unistd.h>   // for close()
#include <thread>
#include <iostream>
#include <netdb.h>

#include "Network.h"

#define MSG_MAX_LEN 1024
#define PORT 3000

static struct sockaddr_in sin;
static int socketDescriptor;



static void parseClientMessage(char* msgFromClient, char* msgToClient,
                               struct sockaddr_in * sinRemote, unsigned int * sin_len) {

    printf("Msg from client is : %s\n", msgFromClient);
    if( strncmp(msgFromClient, "help", strlen("help")) == 0 ){
        printf( " Hello World!\n");
    }

}
void Network::socketLoop(){

    while(continueRunning){
        // Get the data (blocking)
        // Will change sin (the address to be the address of the client)
        // Note: sin passes info in and out of the call!
        struct sockaddr_in sinRemote;              // Return address label
        unsigned int sin_len = sizeof(sinRemote);
        char messageRx[MSG_MAX_LEN];

        // Message recieved
        int bytesRx = recvfrom(socketDescriptor,
                               messageRx, MSG_MAX_LEN, 0,
                               (struct sockaddr *) &sinRemote, &sin_len );

        // Make it null terminated (so string functions work):
        int terminateIdx = (bytesRx < MSG_MAX_LEN) ? bytesRx : MSG_MAX_LEN - 1;
        messageRx[terminateIdx] = 0;

        //Rx is from client, Tx is message to send to client
        char messageTx[MSG_MAX_LEN];
        snprintf(messageTx, 10, "fromC++" ); // This just for testing purposes.

        parseClientMessage(messageRx, messageTx, &sinRemote, &sin_len);

        // Transmits a reply to the client
        sin_len = sizeof(sinRemote);
        sendto( socketDescriptor,
                messageTx, strlen(messageTx),
                0,
                (struct sockaddr *) &sinRemote, sin_len);

    }

    close(socketDescriptor);
}


void Network::ThreadMain() {

    printf("Server starting at PORT %d\n", PORT);
    printf("Connect by typing... \n");
    printf("192.168.7.1:%d into your browser\n", PORT);

    memset(&sin, 0, sizeof(sin));

    sin.sin_family = AF_INET;                 //Connection may be from internet
    sin.sin_addr.s_addr = htonl(INADDR_ANY);  // Host to network long
    sin.sin_port = htons(PORT);
    socketDescriptor = socket(PF_INET, SOCK_DGRAM, 0);

    bind(socketDescriptor, (struct sockaddr*)&sin, sizeof(sin));
    socketLoop();

}


