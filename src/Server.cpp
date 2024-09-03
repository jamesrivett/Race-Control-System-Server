#include <iostream>
#include <string>
#include <algorithm>
// #include "mosquitto_broker.h"
#include "RCS.h"

using namespace std;


int main()
{
    std::cout.flush();
    RCS::RaceController controller = RCS::RaceController();

    controller.create_track(8);
    Track::Track track = controller.get_track();

    cout << "Start\n";
    std::vector<Track::Sector*> sectors = track.get_sectors();
    for (int iter = 0; iter < sectors.size(); iter++)
    {
        std::cout << "Sector " << Track::get_flag_str(*sectors.at(iter)) << ";\n";
    };
    cout << "End\n";

    return 1;
}
