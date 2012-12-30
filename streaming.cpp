#include "streaming.h"

streaming::streaming()
{
    // Begin by setting up our usage environment:
     scheduler = BasicTaskScheduler::createNew();
     env = BasicUsageEnvironment::createNew(*scheduler);
     authDB = NULL;

      /*
      On créé le serveur RSTP avec le port 8554 étant donné qu'il faut être root pour
      le port 554
      */

      if (rtspServer == NULL) {
        int rtspServerPortNum = 8554;
        rtspServer = DynamicRTSPServer::createNew(*env, rtspServerPortNum, authDB);
      }
      if (rtspServer == NULL) {
        *env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
        exit(1);
      }

      *env << "LIVE555 Media Server\n";
      *env << "\tversion " << MEDIA_SERVER_VERSION_STRING
           << " (LIVE555 Streaming Media library version "
           << LIVEMEDIA_LIBRARY_VERSION_STRING << ").\n";

      char* urlPrefix = rtspServer->rtspURLPrefix();
      *env << "Play streams from this server using the URL\n\t"
           << urlPrefix << "<filename>\nwhere <filename> is a file present in the current directory.\n";
      *env << "Each file's type is inferred from its name suffix:\n";
      *env << "\t\".264\" => a H.264 Video Elementary Stream file\n";
      *env << "\t\".aac\" => an AAC Audio (ADTS format) file\n";
      *env << "\t\".ac3\" => an AC-3 Audio file\n";
      *env << "\t\".amr\" => an AMR Audio file\n";
      *env << "\t\".dv\" => a DV Video file\n";
      *env << "\t\".m4e\" => a MPEG-4 Video Elementary Stream file\n";
      *env << "\t\".mkv\" => a Matroska audio+video+(optional)subtitles file\n";
      *env << "\t\".mp3\" => a MPEG-1 or 2 Audio file\n";
      *env << "\t\".mpg\" => a MPEG-1 or 2 Program Stream (audio+video) file\n";
      *env << "\t\".ts\" => a MPEG Transport Stream file\n";
      *env << "\t\t(a \".tsx\" index file - if present - provides server 'trick play' support)\n";
      *env << "\t\".wav\" => a WAV Audio file\n";
      *env << "\t\".webm\" => a WebM audio(Vorbis)+video(VP8) file\n";
      *env << "See http://www.live555.com/mediaServer/ for additional documentation.\n";

      env->taskScheduler().doEventLoop(); // does not return
}

streaming::~streaming() {
    delete scheduler;
    //delete env;
    //delete rtspServer;
}

