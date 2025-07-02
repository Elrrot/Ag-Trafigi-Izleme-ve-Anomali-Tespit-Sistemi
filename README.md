# Ağ Trafiği İzleme ve Anomali Tespiti (IDS) Projesi

## Proje Hakkında

Bu proje, C++ ve libpcap kütüphanesi kullanılarak geliştirilmiş gerçek zamanlı bir Ağ Trafiği İzleme ve Anomali Tespit Sistemi (IDS) uygulamasıdır. Program, belirlenen ağ arayüzünden geçen paketleri yakalar, IP ve MAC adresleri gibi önemli bilgileri analiz eder, anormal trafik durumlarını (Yüksek paket gönderme ve alma vs.) tespit ederek kullanıcıya bildirir.

---

## Özellikler

- Gerçek zamanlı paket yakalama ve analiz
- Paketlerin IP ve MAC adresi bilgilerini toplama
- Anormal trafik tespiti için esnek eşik değer sistemi
- Aynı anomali için uyarıların belirli aralıklarla gösterilmesi (örneğin 10 saniye)
- Anomali yapan cihazın IP ve MAC adresinin ekranda gösterilmesi
- Minimum çıktı ile gereksiz bilgi yükünün önlenmesi
- Log dosyasına anomali kayıtlarının tutulması



## PROJE KAYNAK DOSYALARI AÇIKLAMALARI
🔹 main.cpp
// Ana dosya. Programın başlangıç noktasıdır.
// Ağ arayüzünü belirler, paket dinlemeyi başlatır ve programın genel kontrolünü sağlar.

🔹 paket_yakalayici.cpp
// libpcap kütüphanesi ile ağ paketlerini yakalayan ve her paketi analiz modülüne gönderen kodları içerir.

🔹 trafik_analiz.cpp
// Yakalanan her paketi analiz eder. IP ve MAC adreslerini inceler,
// belirlenen eşik değerlere göre anomali olup olmadığını kontrol eder.

🔹 gunluk_kayit.cpp
// Anomali tespit edildiğinde olayları log dosyasına kaydeden fonksiyonları içerir.

🔹 yardimci.cpp
// Zaman kontrolü, string işlemleri gibi yardımcı işlevlerin tanımlandığı modüldür.


🔸 paket_yakalayici.h
// paket_yakalayici.cpp dosyasındaki fonksiyonların prototiplerini içerir.
// pcap ile ilgili tanımlar burada yapılır.

🔸 trafik_analiz.h
// trafik_analiz.cpp dosyasındaki analiz fonksiyonlarının prototipleri tanımlanır.

🔸 gunluk_kayit.h
// Anomali loglamasıyla ilgili fonksiyonların başlıkları burada bulunur.

🔸 yardimci.h
// Ortak kullanılan yardımcı fonksiyonların prototiplerini içerir.

📝 Açıklama:
- Tüm .cpp dosyaları ilgili .h dosyalarıyla birlikte çalışır.
- Program modüler bir yapıya sahiptir.
- Kodlar C++ dilinde yazılmıştır ve libpcap kütüphanesi kullanılmıştır.


## Gereksinimler

- Linux tabanlı işletim sistemi (Kali Linux, Ubuntu,Parrot OS)
- GCC / G++ derleyicisi
- libpcap ve geliştirme paketleri (`libpcap-dev`)
- Root yetkisi (paket yakalamak için)

## Paketlerin Kurulumu(Debian/Ubuntu)
```bash
  sudo apt update
  sudo apt install build-essential libpcap-dev

  git clone https://github.com/Elrrot/Ag-Trafigi-Izleme-ve-Anomali-Tespit-Sistemi.git
```
## Programı Derleme ve Çalıştırma
```bash
  cd Ag-Trafigi-Izleme-ve-Anomali-Tespit-Sistemi #proje klasörüne geçiş
  cd IDS_PROJECT_CPP  #projenin ana klasörüne geçiş
  sudo make   #programı derleme komutu
  sudo ./ids  #programı çalıştırma komutu 


