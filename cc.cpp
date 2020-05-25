#include <iostream>
#include <cstdio>
#include "client.h"

using namespace std;

int main(){
    client s("127.0.0.1",9999);
    s.socketFF();
    s.connectFF();
    s.sendFF("FGF");
    string recvmess = s.recvFF();
    cout << recvmess.size()  << endl;
    cout << recvmess <<endl;
    return 0;
};


