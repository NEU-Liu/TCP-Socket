#include "server.h"
#include <cstdio>
#include <iostream>
#include <cstring>
#include <arpa/inet.h>

using namespace std;

server::server():backlog(1024) {
    init_sockaddr_in();
}

server::server(const string &ip, uint16_t port) : ip(ip), port(port) ,backlog(1024){
    init_sockaddr_in();
}

void server::init_sockaddr_in() {
    memset(&s_addr, 0, sizeof(s_addr));
    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr =  inet_addr(ip.c_str());//htonl(INADDR_ANY);//inet_addr("127.0.0.1");
    s_addr.sin_port = htons(port);
}


void server::setIp(const string &ip) {
    server::ip = ip;
}

void server::setPort(uint16_t port) {
    server::port = port;
}


int server::socketFF(){
    s_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (s_fd == -1)
    {
        cout <<"socket error: "<< strerror(errno) <<"(errno:" << errno << ")"<<endl;
        return -1;
    }
    return s_fd;
}
int server::bindFF() const {
    int value = bind(s_fd,(struct sockaddr *)&s_addr,sizeof(s_addr));
    if (value == -1)
    {
        cout <<"bind error: "<< strerror(errno) <<"(errno:" << errno << ")"<<endl;
        return -1;
    }
    return value;
}

int server::listenFF() const {
    int value = listen(s_fd, backlog);
    if (value == -1)
    {
        cout <<"listen error: "<< strerror(errno) <<"(errno:" << errno << ")"<<endl;
        return -1;
    }
    return value;
}
int server::acceptFF() {
    c_fd = accept(s_fd, NULL, NULL);
    if (c_fd == -1)
    {
        cout <<"listen error: "<< strerror(errno) <<"(errno:" << errno << ")"<<endl;
        return -1;
    }
    return c_fd;
}
int server::sendFF(const string & message) const {
    ssize_t value = send(c_fd, message.c_str(), message.length(), 0);
    if (value == -1)
    {
        cout <<"send error: "<< strerror(errno) <<"(errno:" << errno << ")"<<endl;
        return -1;
    }
    return value;
}
string server::recvFF() const {
    char buf[1024]{};
    ssize_t value = recv(c_fd, buf, 1024, 0);
    if (value == -1)
    {
        cout <<"send error: "<< strerror(errno) <<"(errno:" << errno << ")"<<endl;
        return "error";
    }
    return string (buf,value);
}