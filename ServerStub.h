//
// Created by knavy on 02-Dec-20.
//

#ifndef FINAL_PROJECT_SERVERSTUB_H
#define FINAL_PROJECT_SERVERSTUB_H

#include <iostream>
#include <vector>

using namespace std;

class PeerInfo {
private:
    int peer_unique_id;
    std::string peer_ip;
    int peer_port;
public:
    PeerInfo();

    bool isActive;

    void operator=(const PeerInfo &peerInfo) {
        peer_unique_id = peerInfo.peer_unique_id;
        peer_ip = peerInfo.peer_ip;
        peer_port = peerInfo.peer_port;
    }

    void SetPeerInfo(int unique_id, std::string ip, int port);

    std::string GetPeerIp();

    int GetPeerPort();

//std::unique_ptr<ClntSocket> cs;
};


class ServerStub {
public:
    int port;
    int server_id;
    string server_ip;
    std::vector<PeerInfo> peerInfo;
    int skippedSlot;
    vector<struct sockaddr_in> addrs;

    void initAddrs(const vector<string> &_hosts, const vector<int> &_ports);

    ServerStub(int pport, int sid, std::vector<PeerInfo> peerInfos, int skipped_slot) {
        port = pport;
        server_id = sid;
        peerInfo = peerInfos;
        skippedSlot = skipped_slot;
    }

    void Init();

};


#endif //FINAL_PROJECT_SERVERSTUB_H
