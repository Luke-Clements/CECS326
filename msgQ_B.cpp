/* 

This is a simple illustration of the use of:
	ftok, msgget, msgsnd, msgrcv

Program B creates a message queue to be shared with Program A.
Then, they will pass messages back and forth.

Program A sends the first message and reads the reply. Program A
also sends a "fake" message to the msgQ that will never be read
by Program B.

Both child processes use message type mtype = 113 and 114.

//use no error handling//

*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;

int main() {

	// create my msgQ with key value from ftok()
	/*
	msgget:
	either allocates or locates existing queue
	2 parameters
	
	IPC_CREAT -> using this to allocate the queue
	IPC_EXCL -> brand new queue
	0600 	-> access permission (octal)
		-> each digit(last three) represents RWX (Read Write Execute) mix 
			-> 0600 => 6 = 110 -> R = 1, W = 1, X = 0 (read write access)
		-> first zero is required to fill space
		-> second digit is in regardsd to the owner
		-> third digit regards the group
		-> fourth group regards others
		persmission should be as strict as possible
	
	ftok(".", 'u') 	-> internal OS identifier
			-> better to let the OS allocate these identifiers to avoid conflicts (can be hard coded, but don't do that)
			-> generates an id for the system to use based on the two parameters in ftok
				-> first paramater: string path to your program (eg. /USBDRIVE/eclipseworkspace/...)
				-> second parameter: user selected integer
	*/
	//qid -> an id that is internal to this program
	int qid = msgget(ftok(".",'u'), IPC_EXCL|IPC_CREAT|0600);

	/*
	holds the messages that is passed between the programs
	the OS uses some information in this struct, so the "long mtype" must go first so it can find it
	*/
	// declare my message buffer
	struct buf {
		long mtype; // required long datatype, and required to be first
		char greeting[50]; // mesg content
	};

	buf msg;
	
	/*
	Calculate the size of the message
	OS needs to know how much meory to allocate for the passed message
	*/
	int size = sizeof(msg)-sizeof(long);

	/*
	Used by this program to receive a message
	each receive removes one message from the queue if successful
	
	qid 	-> see above
	(struct msgbuf *) -> typecast so the OS will "understand" what is being passed since this function is provided by the OS
	msg 	-> received message passed by reference
	size 	-> see above (how many bytes of message to copy)
	117 	-> mtype 	-> used to differentiate between messages
				-> must be accurate in order for a passed message te be received
				-> within a given mtype (if there were multiple of the same mtype) they will behave FIFO
				-> abstractions will help (hint)
	0 	-> determines how function behaves
		-> 0 -> synchronice (wait until we get the message to continue)[forces a halt in execution until the message is available]
			-> do not put IPC_NOWAIT here!!!
		-> IPC_NOWAIT -> asynchronice -> NEVER USE THIS!!!!!!!!!!!!!!
	*/
	msgrcv(qid, (struct msgbuf *)&msg, size, 117, 0); // read mesg
						// don't read "fake" mesg
	cout << getpid() << ": gets message" << endl;
	cout << "message: " << msg.greeting << endl;
	
	strcat(msg.greeting, " and Adios.");
	cout << getpid() << ": sends reply" << endl;
	msg.mtype = 314; // only reading mesg with type mtype = 314
	msgsnd(qid, (struct msgbuf *)&msg, size, 0);
	cout << getpid() << ": now exits" << endl;

	msgrcv (qid, (struct msgbuf *)&msg, size, -112, 0);
	msgrcv (qid, (struct msgbuf *)&msg, size, 0, 0);
	msgrcv (qid, (struct msgbuf *)&msg, size, 117, 0);

	// now safe to delete message queue
	msgctl (qid, IPC_RMID, NULL);

	exit(0);
}


