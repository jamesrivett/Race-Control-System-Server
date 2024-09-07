#ifndef RACECONTROLSERVER_TRACK_H_
#define RACECONTROLSERVER_TRACK_H_

#include <string>
#include <vector>
#include <iostream>

namespace track
{
    enum class Flag
    {
        kRed,
        kYellow,
        kOrange,
        kGreen,
        kBlack,
        kWhite,
        kChequered
    };

    class Sector
    {
    private:
        int m_id;
        Flag m_flag;

    public:
        explicit Sector(int id) : m_id(id), m_flag(Flag::kRed) {};
        explicit Sector(int id, Flag flag) : m_id(id), m_flag(flag) {}; // Not used at the moment
        void set_flag(Flag new_flag);
        Flag get_flag() const;
    };

    class Track
    {
    private:
        Flag m_flag;
        std::vector<Sector> m_sectors;

    public:
        explicit Track(int sector_count);
        std::vector<Sector> get_sectors() const;
        void set_flag(Flag new_flag);
        Flag get_flag() const;
    };

    template <class T>
    void set_flag(T &source, Flag flag)
    {
        source.set_flag(flag);
    };

    template <class T>
    const Flag get_flag(T &source)
    {
        return source.get_flag();
    };

    template <class T>
    const std::string get_flag_str(const T &source)
    {
        return get_flag_str(get_flag(source));
    };

    const std::string get_flag_str(const Flag &flag);
}

#endif