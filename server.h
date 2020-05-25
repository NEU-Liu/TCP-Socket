#ifndef LEARNING_SERVER_H
#define LEARNING_SERVER_H
#include <iostream>
#include <string>
#include <netinet/in.h>

using namespace std;
class server {
public:
    server();
    server(const string &ip, uint16_t port);
    void setIp(const string &ip);
    void setPort(uint16_t port);
    int socketFF();
    int bindFF() const ;
    int listenFF() const ;
    int acceptFF() ;
    int sendFF(const string & message) const ;
    string recvFF() const ;
private:
    string ip;
    uint16_t port;
    struct sockaddr_in s_addr;
    struct sockaddr_in c_addr;
    void init_sockaddr_in();
    int s_fd;
    int c_fd;
    int backlog;

};


#endif
