#include "yardimci.h"
#include <ctime>
#include <sstream>

std::string zaman_damgasi_getir() {
    time_t simdi = time(0);
    struct tm* zaman = localtime(&simdi);
    char zaman_karakter[80];
    strftime(zaman_karakter, sizeof(zaman_karakter), "%Y-%m-%d %H:%M:%S", zaman);
    return std::string(zaman_karakter);
}
