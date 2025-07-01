#include <iostream>
#include "paket_yakalayici.h"

int main() {
    std::string arayuz;
    std::system("ip link show");
    std::cout << "Dinlemek istediginiz ag arayuzu (ornegin: eth0): ";
    std::cin >> arayuz;

    if (!paketleri_yakala(arayuz)) {
        std::cerr << "Ag arayuzu acilamadi." << std::endl;
        return 1;
    }

    return 0;
}
