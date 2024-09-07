#include <iostream>
#include <string>
#include <algorithm>
// #include "mqtt/client.h"
#include "RCS.hpp"

using namespace std;
using namespace track;

const string SERVER_ADDRESS { "mqtt://localhost:1883" };
const string CLIENT_ID      { "paho_cpp_sync_consume" };

int main()
{

    // mosquitto::mqtt::client client(SERVER_ADDRESS, CLIENT_ID);


    std::cout.flush();
    RCS::RaceController controller = RCS::RaceController();

    controller.create_track(8);
    Track track = controller.get_track();

    cout << "Start\n";
    std::vector<Sector> sectors = track.get_sectors();
    set_flag(sectors.at(2), Flag::kGreen);

    for (int iter = 0; iter < sectors.size(); iter++)
    {
        std::cout << "Sector " << get_flag_str<Sector>(sectors.at(iter)) << ";\n";
    };
    cout << "End\n";

    return 1;
}
