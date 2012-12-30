#ifndef STREAMING_H
#define STREAMING_H

#endif // STREAMING_H
#include <BasicUsageEnvironment.hh>
#include "DynamicRTSPServer.hh"
#include "version.hh"


class streaming
{
    RTSPServer * rtspServer;
    UsageEnvironment* env;
    TaskScheduler* scheduler;
    UserAuthenticationDatabase* authDB;

    public:

    /**
      \brief Permet de créer un nouveau serveur qui va s'occuper de tout ce qui est relatif
      au streaming

      Attention cette méthode ne peut être lancée qu'une seule fois
    */
    streaming();
    ~streaming();
};
