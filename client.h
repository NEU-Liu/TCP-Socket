#ifndef LEARNING_CLIENT_H
#define LEARNING_CLIENT_H
#include <iostream>
#include <string>
#include <netinet/in.h>

using namespace std;

class client {
public:
    client(const string &ip, int port);

    virtual ~client();

    const int socketFF();
    const int connectFF() const ;
    const int sendFF(string message) const ;
    string recvFF() const ;
private:
    string ip;
    int port;
    int c_fd;
    struct sockaddr_in s_addr;
    void init();
};


#endif
