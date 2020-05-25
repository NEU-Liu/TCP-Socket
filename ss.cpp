#include <iostream>
#include <cstdio>
#include "server.h"

using namespace std;


int main(){
    server s("127.0.0.1",9999);
    s.socketFF();
    s.bindFF();
    s.listenFF();
    s.acceptFF();
    string recvmess = s.recvFF();
    s.sendFF(recvmess);
    return 0;
};


