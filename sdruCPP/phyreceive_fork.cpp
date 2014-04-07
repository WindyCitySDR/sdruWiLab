#include "libReceive.h"
#include "libTransmit.h"
#include <iostream>
#include <thread>
#include <unistd.h>
#include <string>

#define MSGLEN  64


void Process_TX(int *fd)
{
            
	// Initialize the MATLAB Compiler Runtime global state
	if (!mclInitializeApplication(NULL,0)) 
	{
	std::cerr << "Could not initialize the application properly."
		  << std::endl;
	//return -1;
	}

	// Initialize the Vigenere library
	if( !libTransmitInitialize() )
	{
	std::cerr << "Could not initialize the library properly."
		  << std::endl;
	//return -1;
	}

	mwArray ObjAGC_tx,ObjSDRuTransmitter_tx,ObjDetect_tx,ObjPreambleDemod_tx,ObjDataDemod_tx,estimate_tx,rx_tx,timeoutDuration_tx,messageBits_tx,SamplingFreq_tx;
	mwArray destNodeID_tx, originNodeID_tx, inputPayloadMessage_tx;

	CreateTXRX_TX(10, ObjAGC_tx,ObjSDRuTransmitter_tx,ObjDetect_tx,ObjPreambleDemod_tx,ObjDataDemod_tx,estimate_tx,rx_tx,timeoutDuration_tx,messageBits_tx,SamplingFreq_tx, destNodeID_tx,originNodeID_tx, inputPayloadMessage_tx);

	//Call Transmitter
	//char *message = "HelloFromTX";
	std::string message = "HelloFromTX";
	while (1)
	{
	PHYTransmit(ObjSDRuTransmitter_tx,inputPayloadMessage_tx,SamplingFreq_tx,originNodeID_tx,destNodeID_tx);
        //Writing message to the pipe
        //write(fd[1], message, strlen(message));
        write(fd[1], "HelloFromTX",11 );
	}

	// Shut down the library and the application global state.
	libTransmitTerminate();
	mclTerminateApplication();


}

void Process_RX(int *fd)
{

	// Initialize the MATLAB Compiler Runtime global state
	if (!mclInitializeApplication(NULL,0)) 
	{
	std::cerr << "Could not initialize the application properly."
	  << std::endl;
	//return -1;
	}

	// Initialize the Vigenere library
	if( !libReceiveInitialize() )
	{
	std::cerr << "Could not initialize the library properly."
	  << std::endl;
	//return -1;
	}

	// Must declare all MATLAB data types after initializing the 
	// application and the library, or their constructors will fail.
	mwArray ObjAGC,ObjSDRuReceiver,ObjDetect,ObjPreambleDemod,ObjDataDemod,estimate,rx,timeoutDuration,messageBits,SamplingFreq;
	mwArray result;

	//Create Required Objeccts/Structs/Variables
	CreateTXRX(10, ObjAGC,ObjSDRuReceiver,ObjDetect,ObjPreambleDemod,ObjDataDemod,estimate,rx,timeoutDuration,messageBits,SamplingFreq);

	int k;
	//char *message = "HelloFromRX";
	std::string message = "HelloFromRX";
	for (k=0;k<100;k++){
	// Initialization succeeded. Encrypt or decrypt.
	PHYReceive(1, result,ObjAGC,ObjSDRuReceiver,ObjDetect,ObjPreambleDemod,ObjDataDemod,estimate,rx,timeoutDuration,messageBits);
        write(fd[1], "HelloFromRX", 11);
	}

	// Shut down the library and the application global state.
	libReceiveTerminate();
	mclTerminateApplication();
	//mxfree(objSDRuReceiver);
}



int main(){

//int	pid;
int     fd[2];
pid_t pid;
int     result;


//Creating a pipe
result = pipe (fd);
if (result < 0) {
	//failure in creating a pipe
	perror("pipe");
	exit (1);
}

//Creating a child process
pid = fork();
if (pid < 0) {
	//failure in creating a child
	perror ("fork");
	exit(2);
}
if (pid > 0) {
	pid = fork();
	if (pid > 0){
		std::cout<<"Parent"<<std::endl;
		char message[MSGLEN];
		while (1){
		    std::cout << "##################" << std::endl;
                    //Clearing the message buffer
                    memset (message, 0, sizeof(message));

                    //Reading message from the pipe
                    read (fd[0], message, sizeof(message));
                    printf("-- %s\n",message);
		    std::cout << "##################" << std::endl;
		}
		}
	else{
		std::cout<<"Child"<<std::endl;
		Process_TX( fd );
	}
}
else if (pid == 0) {
	std::cout<<"Child"<<std::endl;
	Process_RX( fd );
}

return 0;

}


