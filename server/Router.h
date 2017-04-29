#ifndef ROUTER_H
#define ROUTER_H
#include <Wt/WResource>
#include <Wt/WServer>
#include "FileManager.h"
#include "Track.h"
#include "Login.h"

using namespace Wt;


class Router {
public:
    void route(WServer& server)
    {
        //server.addResource(&login, "/login");


    }

private: // :)
   //Login login;


};

#endif // ROUTER_H
