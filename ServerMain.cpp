//
// Created by knavy on 03-Dec-20.
//

#include "ServerStub.h"
#include <iostream>
#include <vector>

using namespace std;

int isMultipleOf3(int n) {
    int odd_count = 0;
    int even_count = 0;

    if (n < 0)
        n = -n;
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;

    while (n) {
        if (n & 1)
            odd_count++;
        if (n & 2)
            even_count++;
        n = n >> 2;
    }

    return isMultipleOf3(abs(odd_count - even_count));
}

int main(int argc, char **argv) {
    if (argc < 4) {
        std::cout << "not enough arguments" << std::endl;
        std::cout << argv[0] << "[port #] [# unique id] [skipped slot] [# peers] (repeat for peers [ID] [IP] [ port #])"
                  << std::endl;
        return 0;
    }

    int arg_count = argc;
    int port;
    int unique_id;
    int num_of_peers;
    int skipped_slot;
    std::vector <PeerInfo> peerInfos;

    arg_count = arg_count - 5;
    port = atoi(argv[1]);
    unique_id = atoi(argv[2]);
    skipped_slot = atoi(argv[3]);
    num_of_peers = atoi(argv[4]);
    int tmp = 5;

    if (num_of_peers > 0) {
        if (arg_count == 0) {
            std::cout << "not enough arguments for peers" << std::endl;
            std::cout << argv[0] << "[port #] [# unique id] [# peers] (repeat for peers [ID] [IP] [ port #])"
                      << std::endl;
            return 0;
        } else if (isMultipleOf3(arg_count) == 1) {
            int num_of_loops = arg_count / 3;
            for (int i = 0; i < num_of_loops; i++) {
                PeerInfo peerInfo;
                int id = atoi(argv[tmp]);
                tmp++;
                std::string ip = argv[tmp];
                tmp++;
                int pport = atoi(argv[tmp]);
                tmp++;
                peerInfo.SetPeerInfo(id, ip, pport);
                peerInfos.push_back(peerInfo);
            }
        } else {
            std::cout << "not enough arguments for peers" << std::endl;
            std::cout << argv[0] << "[port #] [# unique id] [# peers] (repeat for peers [ID] [IP] [ port #])"
                      << std::endl;
            return 0;
        }
    }

    ServerStub server(port, unique_id, peerInfos, skipped_slot);
    server.Init();
}