//
// Created by knavy on 02-Dec-20.
//
#include <iostream>
#include <string.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <sys/types.h>

#include <mutex>
#include <thread>
#include <condition_variable>

#include <deque>
#include <vector>
#include <utility>
#include <map>
#include <cassert>
#include <cstring>
#include <chrono>
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <unordered_map>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <random>
#include <ctime>

#include "ServerStub.h"

using namespace std;

vector<struct sockaddr_in> ServerStub::addrs;

void ServerStub::Init() {

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;

    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    // setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (char*) &timeout, sizeof(timeout));

    if (fd < 0) {
        cerr << "ERROR opening socket" << endl;
        exit(1);
    }

    struct sockaddr_in server_addr, cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    bzero((char *) &server_addr, sizeof(server_addr));

    // Initialize the server address
    server_addr.sin_family = AF_INET;
    //server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the server address to the sockets
    if (bind(fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        cerr << "ERROR on binding" << endl;
        exit(1);
    }

    if (listen(fd, SOMAXCONN) < 0) {
        cerr << "ERROR　on listening" << endl;
        exit(1);
    }

    std::cout << "sid is " << std::endl;

    while (true) {
        // receive any client messages
    }
}

void ServerStub::initAddrs(const vector <string> &_hosts, const vector<int> &_ports) {
    for (size_t i = 0; i < _hosts.size(); ++i) {
        struct sockaddr_in servAddr;
        memset(&servAddr, 0, sizeof(servAddr));
        servAddr.sin_family = AF_INET;
        servAddr.sin_port = htons(_ports[i]);
        inet_pton(AF_INET, _hosts[i].c_str(), &servAddr.sin_addr);
        addrs.push_back(servAddr);
    }
}

PeerInfo::PeerInfo() {
    peer_unique_id = -1;
    peer_ip = "";
    peer_port = -1;
    //   peer_csocket = NULL;
}

void PeerInfo::SetPeerInfo(int unique_id, std::string ip, int port) {
    peer_unique_id = unique_id;
    peer_ip = ip;
    peer_port = port;
}

std::string PeerInfo::GetPeerIp() {
    return peer_ip;
};

int PeerInfo::GetPeerPort() {
    return peer_port;
};


