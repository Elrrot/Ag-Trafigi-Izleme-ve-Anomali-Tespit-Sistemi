#include "trafik_analiz.h"
#include "gunluk_kayit.h"
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <chrono>

// MAC adresini string formatina cevirir: aa:bb:cc:dd:ee:ff
std::string mac_adresi_str(const u_char* mac) {
    std::stringstream ss;
    for (int i = 0; i < 6; ++i) {
        if (i != 0) ss << ":";
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)mac[i];
    }
    return ss.str();
}

std::map<std::string, int> ip_sayac;
std::map<std::string, std::chrono::steady_clock::time_point> son_uyari_zamani;

const int PAKET_ESIGI = 500;          // Anomali icin paket sayisi esigi
const int UYARI_INTERVAL = 3;         // Uyarilar arasi minimum saniye

void analiz_et(const u_char* veri, int uzunluk) {
    if (uzunluk < 14) return;

    const struct ether_header* eth = (struct ether_header*)veri;

    std::string kaynak_mac = mac_adresi_str(eth->ether_shost);
    std::string hedef_mac = mac_adresi_str(eth->ether_dhost);

    if (ntohs(eth->ether_type) != ETHERTYPE_IP) {
        return;
    }

    const struct ip* ip_basligi = (struct ip*)(veri + 14);
    std::string kaynak_ip = inet_ntoa(ip_basligi->ip_src);
    std::string hedef_ip = inet_ntoa(ip_basligi->ip_dst);
    std::string protokol;

    int kaynak_port = 0;
    int hedef_port = 0;

    switch (ip_basligi->ip_p) {
        case IPPROTO_TCP:
            protokol = "TCP";
            {
                const tcphdr* tcp_basligi = (tcphdr*)(veri + 14 + ip_basligi->ip_hl * 4);
                kaynak_port = ntohs(tcp_basligi->th_sport);
                hedef_port = ntohs(tcp_basligi->th_dport);
            }
            break;
        case IPPROTO_UDP:
            protokol = "UDP";
            {
                const udphdr* udp_basligi = (udphdr*)(veri + 14 + ip_basligi->ip_hl * 4);
                kaynak_port = ntohs(udp_basligi->uh_sport);
                hedef_port = ntohs(udp_basligi->uh_dport);
            }
            break;
        case IPPROTO_ICMP:
            protokol = "ICMP";
            break;
        default:
            protokol = "Diger";
            break;
    }

    std::string kaynak_ip_port = kaynak_ip;
    if (kaynak_port != 0) {
        kaynak_ip_port += ":" + std::to_string(kaynak_port);
    }

    std::string hedef_ip_port = hedef_ip;
    if (hedef_port != 0) {
        hedef_ip_port += ":" + std::to_string(hedef_port);
    }

    kayit_yaz(protokol, kaynak_ip_port + " (" + kaynak_mac + ")", hedef_ip_port);

    ip_sayac[kaynak_ip]++;
    auto suanki_zaman = std::chrono::steady_clock::now();
    auto& son_zaman = son_uyari_zamani[kaynak_ip];

    if (ip_sayac[kaynak_ip] > PAKET_ESIGI) {
        if (suanki_zaman - son_zaman > std::chrono::seconds(UYARI_INTERVAL)) {
            std::cout << "[!] Anomali: " << kaynak_ip_port << " (" << kaynak_mac << ") cok fazla paket gonderiyor!" << std::endl;
            son_zaman = suanki_zaman;
        }
    }
}
