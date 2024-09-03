#ifndef RACECONTROLSERVER_TRACK_H_
#define RACECONTROLSERVER_TRACK_H_

// #include <cstring>
#include <string>
#include <vector>

namespace Track
{
    enum Flag
    {
        red,
        yellow,
        orange,
        green,
        black,
        white,
        chequered
    };

    class Sector
    {
    private:
        uint8_t m_id;
        Flag m_flag;

    public:
        Sector();
        explicit Sector(uint8_t id);
        void set_flag(Flag new_flag);
        Flag get_flag();
    };

    class Track
    {
    private:
        Flag m_track_flag;
        std::vector<Sector*> m_sectors;

    public:
        Track();
        explicit Track(uint8_t sector_count);
        std::vector<Sector*> get_sectors();
        Flag get_flag();
    };

    std::string get_flag_str(Flag flag);
    std::string get_flag_str(Sector &sector);
    std::string get_flag_str(Track &track);
}

#endif