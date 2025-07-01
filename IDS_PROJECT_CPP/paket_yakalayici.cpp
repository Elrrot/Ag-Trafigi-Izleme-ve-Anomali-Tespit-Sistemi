#include "paket_yakalayici.h"
#include "trafik_analiz.h"
#include "gunluk_kayit.h"
#include <pcap.h>
#include <iostream>

void paket_isleyici(u_char* kullanici_verisi, const struct pcap_pkthdr* baslik, const u_char* veri) {
    analiz_et(veri, baslik->len);
}

bool paketleri_yakala(const std::string& arayuz) {
    char hata[PCAP_ERRBUF_SIZE];
    pcap_t* tanimlayici = pcap_open_live(arayuz.c_str(), BUFSIZ, 1, 1000, hata);

    if (tanimlayici == nullptr) {
        std::cerr << "pcap_open_live hatasi: " << hata << std::endl;
        return false;
    }

    std::cout << "[+] Dinleme baslatildi: " << arayuz << std::endl;
    pcap_loop(tanimlayici, 0, paket_isleyici, nullptr);

    pcap_close(tanimlayici);
    return true;
}
