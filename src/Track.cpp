#include "Track.h"
#include <iostream>

namespace Track
{

    // Global
    std::string get_flag_str(Flag flag)
    {
        switch (flag)
        {
            case Flag::red: return "red";
            case Flag::yellow: return "yellow";
            case Flag::orange: return "orange";
            case Flag::green: return "green";
            case Flag::black: return "black";
            case Flag::white: return "white";
            case Flag::chequered: return "chequered";
            default: return "ERROR - No Flag";
        }
    }

    std::string get_flag_str(Sector &sector)
    {
        return get_flag_str(sector.get_flag());
    }

    std::string get_flag_str(Track &track)
    {
        return get_flag_str(track.get_flag());
    }


    // Sector
    Sector::Sector(){}

    Sector::Sector(uint8_t id)
    {
        m_id = id;
        m_flag = Flag::red;
    }

    void Sector::set_flag(Flag new_flag)
    {
        m_flag = new_flag;
    }

    Flag Sector::get_flag()
    {
        return m_flag;
    }

    Track::Track(){}

    Track::Track(uint8_t sector_count)
    {
        m_track_flag = Flag::red;

        for (int i = 1; i < sector_count; i++)
        {
            m_sectors.push_back(new Sector(i));
        }
    }

    std::vector<Sector*> Track::get_sectors()
    {
        return m_sectors;
    }

    Flag Track::get_flag()
    {
        return m_track_flag;
    }
}