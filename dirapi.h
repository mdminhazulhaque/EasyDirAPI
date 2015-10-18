#ifndef DIRAPI_H
#define DIRAPI_H

#include <iostream>
#include <vector>
#include <string>
#include <dirent.h>

using namespace std;

typedef enum
{
    NODE_UNKNOWN, NODE_ALL, NODE_DIR, NODE_FILE
} node_t;

typedef struct
{
    string path;
    node_t type;
} Node;

typedef vector<Node> NodeList;

class DirAPI
{
public:
    static NodeList getNodeList(string path, node_t type = NODE_ALL);
    static int getNodeCount(string path, node_t type = NODE_ALL);
};

#endif // DIRAPI_H
