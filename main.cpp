#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <thread>

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%d-%m %X", &tstruct);

    return buf;
}

int main() {
    /* Inhalt des While-Loops weiter unten
    std::string ping;
    int ping_return = (system("ping 8.8.8.8 -c 1"));

    std::cout << ping_return << std::endl;
    //ping_return = 512   without network connection
    //ping_return = 0     with network connection


    if (ping_return == 0){
        std::cout << "All fine!" << std::endl;
    } else {
        std::ofstream outfile;
        outfile.open("/home/julian/Dokumente/ausfallchecker/log.log", std::ios_base::app);
        outfile << "Keine Internetverbindung: " << currentDateTime() << std::endl;
    }
    */

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while (true){
        std::string ping;
        int ping_return = (system("ping 8.8.8.8 -c 1"));

        std::cout << ping_return << std::endl;
        //ping_return = 512   without network connection
        //ping_return = 0     with network connection


        if (ping_return == 0){
            std::cout << "All fine!" << std::endl;
        } else {
            std::ofstream outfile;
            outfile.open("/home/julian/Dokumente/ausfallchecker/log.log", std::ios_base::app);
            outfile << "Keine Internetverbindung: " << currentDateTime() << std::endl;
        }
        std::chrono::milliseconds timespan(9000);
        std::this_thread::sleep_for(timespan);
    }
#pragma clang diagnostic pop


    return 0;
}
