#include "System/System.h"

#include <signal.h>
#include <unistd.h>
#include <memory>
#include <iostream>

bool running = false;

void ExitHandler(int s){
    std::cout << std::endl << "EXIT: CTRL+C" << std::endl;
    running = false;
}

int main(int argc, char const *argv[])
{
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = ExitHandler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);

    std::shared_ptr<System> system(System::Instance(running));
    
    running = true;
    
    system->Init();
    system->Run();
    
    return 0;
}
