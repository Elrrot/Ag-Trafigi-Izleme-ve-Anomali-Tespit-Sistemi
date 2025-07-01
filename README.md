# Ağ Trafiği İzleme ve Anomali Tespiti (IDS) Projesi

## Proje Hakkında

Bu proje, C++ ve libpcap kütüphanesi kullanılarak geliştirilmiş gerçek zamanlı bir Ağ Trafiği İzleme ve Anomali Tespit Sistemi (IDS) uygulamasıdır. Program, belirlenen ağ arayüzünden geçen paketleri yakalar, IP ve MAC adresleri gibi önemli bilgileri analiz eder, anormal trafik durumlarını tespit ederek kullanıcıya bildirir.

---

## Özellikler

- Gerçek zamanlı paket yakalama ve analiz
- Paketlerin IP ve MAC adresi bilgilerini toplama
- Anormal trafik tespiti için esnek eşik değer sistemi
- Aynı anomali için uyarıların belirli aralıklarla gösterilmesi (örneğin 10 saniye)
- Anomali yapan cihazın IP ve MAC adresinin ekranda gösterilmesi
- Minimum çıktı ile gereksiz bilgi yükünün önlenmesi
- Log dosyasına anomali kayıtlarının tutulması (opsiyonel)

---

## Gereksinimler

- Linux tabanlı işletim sistemi (Kali Linux, Ubuntu,Parrot OS)
- GCC / G++ derleyicisi
- libpcap ve geliştirme paketleri (`libpcap-dev`)
- Root yetkisi (paket yakalamak için)

### Paketlerin Kurulumu (Debian/Ubuntu)

```bash
sudo apt update
sudo apt install build-essential libpcap-dev
