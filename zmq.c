
/*This file Provides you the ZMQ APIs used in our CA Application*/
//Add zmq.h in your applciation 

void *context = zmq_ctx_new(); //This function creates a new ZeroMQ context. It initializes the underlying resources needed for managing sockets, threads and communication.

void *txsocket = zmq_socket(context, ZMQ_REQ);
void *rxsocket = zmq_socket(context, ZMQ_REP);
/* The socket is associated with the context (context) passed as the first argument. This ensures the socket inherits the properties and resources of the context.
and second argument will be your messaging pattern */

zmq_connect(sock, "tcp://localhost:1122");
/* In this we are fixing one port number which will be used for communication. */

zmq_bind(sock, "tcp://*:1122");
/* The other side client will be binding to the port number to receive messages */

zmq_setsockopt(zmq->bsmrxsocket, ZMQ_SUBSCRIBE, "sample", 7);
/* In PUB-SUB message pattern we need to tell the topic name for the subscribers to get the data here the payload starting with sample name will be recievd by the  subscribers.*/

zmq_send(txsocket,req, sizeof(struct bct_req), 0);
/* In this we are sending a structure through txsocket with size of that strcture and fourth argument will be your flag to modify the behaviour */

zmq_recv(rxsocket, r_buff, sizeof(r_buff), 0);
/* In this we are receiving a structure through rxsocket with size of that strcture and fourth argument will be your flag to modify the behaviour */

zmq_close(zmq->bsmrxsocket);
zmq_ctx_destroy(zmq->context);
/* For closing the socket and destroying the context */
