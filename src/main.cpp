#include "CSensorEcho.h"

int main(int argc, char const *argv[])
{
    CSensorEcho sensorEcho("13", "12");

    sensorEcho.Start();

    std::this_thread::sleep_for(std::chrono::seconds(5));
    sensorEcho.Stop();
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}
