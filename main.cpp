#include <iostream>
#include "dirapi.h"

using namespace std;

int main()
{
    string path = "/home/minhaz";

    int count = DirAPI::getNodeCount(path);
    int dircount = DirAPI::getNodeCount(path, NODE_DIR);
    int filecount = DirAPI::getNodeCount(path, NODE_FILE);

    cout << path << " has " << filecount << " dirs" << endl;
    cout << path << " has " << dircount << " files" << endl;
    cout << path << " has " << count << " nodes in total" << endl;

    NodeList nodes = DirAPI::getNodeList(path);

    for(unsigned int i=0; i<nodes.size(); i++)
    {
        cout << nodes.at(i).path << endl;
    }

    return 0;
}

