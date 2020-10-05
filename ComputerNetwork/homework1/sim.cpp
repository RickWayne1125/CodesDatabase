# include<iostream>
#include<assert.h>
#include<string.h>

using namespace std;

string layerList[7] = {"ApplicationLayerHeader::", "PresentationLayerHeader::", "SessionLayerHeader::",
                       "TransportLayerHeader::", "NetworkLayerHeader::", "DatalinkLayerHeader::",
                       "PhysicalLayerHeader::"};

string attachHeader(string header, string buff, int *len) {
    *len = header.length() + buff.length();
    string nbuff = header + buff;
    return nbuff;
}

void sendLayer(string buff, int len) {
    for (int i = 0; i < 7; i++) {
        string header = layerList[i];
        assert(buff.length() == len);
        int nlen = 0;
        string nbuff = attachHeader(header, buff, &nlen);
        cout << nbuff << endl;
        buff = nbuff;
        len = nlen;
    }
}

int main() {
    string msg;
    cout << "Plz enter the message: ";
    cin >> msg;
    sendLayer(msg, msg.length());
    return 0;
}