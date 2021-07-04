#include "server.h"

namespace Logic
{
    Server::Server(){}
    Server::~Server(){}
    Server::RegisterEntityDelete(Entity* Entity)
    {
        deletedEntites.push_back(Entity);
    }
}