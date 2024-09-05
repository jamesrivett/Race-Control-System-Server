#include "RCS.hpp"

namespace RCS
{

    RaceController::RaceController()
    {

    }

    void RaceController::create_track(int sector_count)
    {
        m_track = Track::Track(sector_count);
    }

    Track::Track& RaceController::get_track()
    {
        return m_track;
    }
}