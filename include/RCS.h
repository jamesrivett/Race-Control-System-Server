#ifndef RACECONTROLSERVER_RCS_H_
#define RACECONTROLSERVER_RCS_H_

// #include <cstring>
#include <string>
#include <vector>
// #include "mosquitto_broker.h"
#include "Track.h"

namespace RCS
{

    class RaceController
    {
    private:
        Track::Track m_track;

    public:
        RaceController();
        void create_track(uint8_t sector_count);
        Track::Track& get_track();
    };

}

#endif