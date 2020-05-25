#include <zconf.h>
#include <cstring>
#include <arpa/inet.h>
#include "client.h"

client::client(const string &ip, int port) : ip(ip), port(port) {
    init();
}

client::~client() {
    close(c_fd);
}

const int client::socketFF() {
    c_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (c_fd == -1)
    {
        cout <<"socket error: "<< strerror(errno) <<"(errno:" << errno << ")"<<endl;
        return -1;
    }
    return c_fd;
}
void client::init(){
    memset(&s_addr,0,sizeof(s_addr));
    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr =  inet_addr(ip.c_str());
    s_addr.sin_port = htons(port);
}
const int client::connectFF() const {
    int value = connect(c_fd, (struct sockaddr *) &s_addr, sizeof(s_addr));
    if (value == -1)
    {
        cout <<"connect error: "<< strerror(errno) <<"(errno:" << errno << ")"<<endl;
        return -1;
    }
    return value;
}
const int client::sendFF(string message) const {
    int value = send(c_fd,message.c_str(),message.size()+1,0);
    if (value == -1)
    {
        cout <<"send error: "<< strerror(errno) <<"(errno:" << errno << ")"<<endl;
        return -1;
    }
    return value;

}
string client::recvFF() const {
    char buf[1024];
    int value = recv(c_fd,buf,1024,0);
    if (value == -1)
    {
        cout <<"recv error: "<< strerror(errno) <<"(errno:" << errno << ")"<<endl;
        return "error";
    }
    return string (buf);
}