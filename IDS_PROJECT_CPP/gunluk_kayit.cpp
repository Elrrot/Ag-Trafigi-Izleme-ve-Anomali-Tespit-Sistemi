#include "gunluk_kayit.h"
#include "yardimci.h"
#include <fstream>

void kayit_yaz(const std::string& protokol, const std::string& kaynak, const std::string& hedef) {
    std::ofstream dosya("trafik.log", std::ios::app);
    if (dosya.is_open()) {
        dosya << zaman_damgasi_getir() << " | " << protokol << " | " << kaynak << " --> " << hedef << std::endl;
        dosya.close();
    }
}
