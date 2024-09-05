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
        int m_id;
        Flag m_flag;

    public:
        Sector();
        explicit Sector(int id);
        void set_flag(Flag new_flag);
        Flag get_flag() const;
    };

    class Track
    {
    private:
        Flag m_track_flag;
        std::vector<Sector> m_sectors;

    public:
        Track();
        explicit Track(int sector_count);
        std::vector<Sector> get_sectors() const;
        Flag get_flag() const;
    };

    const std::string get_flag_str(const Flag &flag);
    const std::string get_flag_str(const Sector &sector);
    const std::string get_flag_str(const Track &track);
}

#endif