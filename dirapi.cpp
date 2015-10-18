#include "dirapi.h"

NodeList DirAPI::getNodeList(string path, node_t type)
{
    NodeList nodes;
    DIR *directory;
    struct dirent *directory_data;
    if((directory = opendir(path.data())) != NULL)
    {
      while((directory_data = readdir(directory)) != NULL)
      {
          Node node;
          node.path = directory_data->d_name;

          if(directory_data->d_type == DT_REG)
              node.type = NODE_FILE;
          else if(directory_data->d_type == DT_DIR)
              node.type = NODE_DIR;
          else if(directory_data->d_type == DT_UNKNOWN)
              node.type = NODE_UNKNOWN;

          if(type == NODE_ALL)
              nodes.push_back(node);
          else if(type == node.type)
              nodes.push_back(node);
          else if(type == node.type)
              nodes.push_back(node);
      }
      closedir(directory);
    }

    return nodes;
}

int DirAPI::getNodeCount(string path, node_t type)
{
    unsigned int dircount = 0;
    unsigned int filecount = 0;
    DIR *directory;
    struct dirent *directory_data;
    if((directory = opendir(path.data())) != NULL)
    {
      while((directory_data = readdir(directory)) != NULL)
      {
          if(directory_data->d_type == DT_REG)
              filecount++;
          else if(directory_data->d_type == DT_DIR)
              dircount++;
      }
      closedir(directory);
    }


    if(type == NODE_DIR)
        return dircount;
    else if(type == NODE_FILE)
        return filecount;
    else
        return filecount + dircount;
}
