# Computer Networks and Technologies Vize Notları 

Bu yazı **MIT** lisanslıdır. Lisanslar hakkında bilgi almak için [buraya](https://choosealicense.com/licenses/) bakmanda fayda var.

- Copyright © ~ *Yunus Emre AK*

<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config">
    MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });
</script>

<br>
<br>
<br>
<br>
<br>

---

![PDF Yapısı Hakkında Bilgilendirme](https://bit.ly/2QmZtIc)

---

<div class="page"/>

## İçerikler 

- [Temel Terimler](#temel-terimler)
- [Network Structure (Ağ Yapısı)](#network-structure-a%C4%9F-yap%C4%B1s%C4%B1)
- [Network Edge](#network-edge)
  - [Access Network (Bağlantı Türleri)](#access-network-ba%C4%9Flant%C4%B1-t%C3%BCrleri)
  - [Physcial Media (Fiziksel Veri İşlemleri)](#physcial-media-fiziksel-veri-i%CC%87%C5%9Flemleri)
    - [Fiber Optik Kablo](#fiber-optik-kablo)
  - [Radya Bağlantı](#radya-ba%C4%9Flant%C4%B1)
    - [Satellite (Uydu Bağlantısı)](#satellite-uydu-ba%C4%9Flant%C4%B1s%C4%B1)
- [Network Core](#network-core)
  - [Circuit Switching (Devre Anahtarlama)](#circuit-switching-devre-anahtarlama)
  - [Packet Switching (Paket Anahtarlama)](#packet-switching-paket-anahtarlama)
  - [Packet Yönteminin Circuit Switching Yöntemine Göre Farkı](#packet-y%C3%B6nteminin-circuit-switching-y%C3%B6ntemine-g%C3%B6re-fark%C4%B1)
- [Internet Structure (Internet Alt yapısı)](#internet-structure-internet-alt-yap%C4%B1s%C4%B1)
  - [Interter Tiers](#interter-tiers)
  - [Paketlerin iletimi](#paketlerin-iletimi)
  - [Packet Delay & Loss (Gecikme ve Kayıp)](#packet-delay--loss-gecikme-ve-kay%C4%B1p)
  - [Packet Switching Delay](#packet-switching-delay)
  - [Internet Delay](#internet-delay)
  - [Protocol Layers (Protokol Katmanları)](#protocol-layers-protokol-katmanlar%C4%B1)
  - [Internet Protocol Stack (TCP / IP)](#internet-protocol-stack-tcp--ip)
    - [ISO / OSI Reference Model](#iso--osi-reference-model)
  - [Encapsulation (Kapsülleme)](#encapsulation-kaps%C3%BClleme)
- [Network Security](#network-security)
  - [Kötü Niyetli Uygulamalar](#k%C3%B6t%C3%BC-niyetli-uygulamalar)
    - [Trojan Horse](#trojan-horse)
    - [Worm](#worm)
    - [Virus](#virus)
    - [Spyware Malwawre](#spyware-malwawre)
  - [Kötü Niyetli Saldırılar](#k%C3%B6t%C3%BC-niyetli-sald%C4%B1r%C4%B1lar)
    - [DoS](#dos)
    - [Packet Sniffing (Paket Yakalama)](#packet-sniffing-paket-yakalama)
    - [IP Spoofing (IP Aldatmacası)](#ip-spoofing-ip-aldatmacas%C4%B1)
- [Internetin Geçmişi](#internetin-ge%C3%A7mi%C5%9Fi)
- [Application Layer (Uygulama Katmanı)](#application-layer-uygulama-katman%C4%B1)
- [*Network* Uygulaması Oluşturmak](#network-uygulamas%C4%B1-olu%C5%9Fturmak)
- [Application Architectures (Uygulama Mimarileri)](#application-architectures-uygulama-mimarileri)
  - [Client-Server Architecture](#client-server-architecture)
  - [Pear-to-Pear Architecture (Kişiden kişiye Mimarisi)](#pear-to-pear-architecture-ki%C5%9Fiden-ki%C5%9Fiye-mimarisi)
  - [Client-Server ve Peer-to-Peer Karışımı](#client-server-ve-peer-to-peer-kar%C4%B1%C5%9F%C4%B1m%C4%B1)
- [Processes Communicating (İletişim Sistemleri)](#processes-communicating-i%CC%87leti%C5%9Fim-sistemleri)
  - [Socket Yapısı](#socket-yap%C4%B1s%C4%B1)
  - [Adressing Processes (İşlemleri Adresleme)](#adressing-processes-i%CC%87%C5%9Flemleri-adresleme)
- [Transport Service Requirements](#transport-service-requirements)
- [Internet Transport Protocols Services (Taşıma Protokolleri Hizmetleri)](#internet-transport-protocols-services-ta%C5%9F%C4%B1ma-protokolleri-hizmetleri)
  - [TCP (Transmission Control Protocol) Review](#tcp-transmission-control-protocol-review)
  - [UDP (User Datagram Protocol) Review](#udp-user-datagram-protocol-review)
  - [Securing TCP (TCP'de Güvenlik)](#securing-tcp-tcpde-g%C3%BCvenlik)
- [Web ve HTTP](#web-ve-http)
- [HTTP (Hypertext Transfer Protocol)](#http-hypertext-transfer-protocol)
  - [Temel HTTP Yapısı](#temel-http-yap%C4%B1s%C4%B1)
  - [HTTP Veri Aktarımı](#http-veri-aktar%C4%B1m%C4%B1)
  - [HTTP Bağlantıları](#http-ba%C4%9Flant%C4%B1lar%C4%B1)
    - [Non-Persistent HTTP](#non-persistent-http)
    - [Persistent HTTP](#persistent-http)
  - [HTTP Request Message (İstek Mesajı)](#http-request-message-i%CC%87stek-mesaj%C4%B1)
  - [HTTP Status Code (Durum Kodları)](#http-status-code-durum-kodlar%C4%B1)
  - [Cookie (Çerezler)](#cookie-%C3%A7erezler)
  - [Proxy Server & Cache](#proxy-server--cache)
    - [Conditional GET (Koşullu GET)](#conditional-get-ko%C5%9Fullu-get)
- [Domain Name System (DNS)](#domain-name-system-dns)
  - [DNS Resolution Examples (DNS Çözümleme Örnekleri)](#dns-resolution-examples-dns-%C3%A7%C3%B6z%C3%BCmleme-%C3%B6rnekleri)
  - [DNS Record (DNS Kayıtları)](#dns-record-dns-kay%C4%B1tlar%C4%B1)
    - [Inserting DNS Record](#inserting-dns-record)
    - [Attacking DNS](#attacking-dns)
- [P2P (Peer to Peer)](#p2p-peer-to-peer)
  - [P2p File Distribution (Dosya Paylaşımı)](#p2p-file-distribution-dosya-payla%C5%9F%C4%B1m%C4%B1)
- [Video Streaming and CDNs: context](#video-streaming-and-cdns-context)
  - [Video Streamin](#video-streamin)
  - [Content Distribution Networks (İçerik Dağıtım Ağları)](#content-distribution-networks-i%CC%87%C3%A7erik-da%C4%9F%C4%B1t%C4%B1m-a%C4%9Flar%C4%B1)
- [Transport Layer](#transport-layer)
- [Internet Transport Layer Protocols](#internet-transport-layer-protocols)
- [Multiplexing (Çoğullama)](#multiplexing-%C3%A7o%C4%9Fullama)
- [Demultiplexing (Azaltma / Parçalama)](#demultiplexing-azaltma--par%C3%A7alama)
  - [TCP / UDP Demux](#tcp--udp-demux)
  - [UDP Demux Örneği](#udp-demux-%C3%B6rne%C4%9Fi)
  - [TCP Demux Örneği](#tcp-demux-%C3%B6rne%C4%9Fi)
- [UDP (User Datagram Protocol)](#udp-user-datagram-protocol)
  - [UDP Checksum](#udp-checksum)
- [Reliable Data Transfer (RDT)](#reliable-data-transfer-rdt)
  - [Rdt 1.0](#rdt-10)
  - [Rdt 2.0](#rdt-20)
    - [Rdt 2.0 Kusurları](#rdt-20-kusurlar%C4%B1)
  - [Rdt 2.1](#rdt-21)
  - [Rdt 2.2](#rdt-22)
  - [Rdt 3.0](#rdt-30)
- [Pipelined Protocols](#pipelined-protocols)
- [TCP (Transmission Control Protocol)](#tcp-transmission-control-protocol)

<div class="page"/>

## Temel Terimler

| Terim             | Açıklama                                                       |
| ----------------- | -------------------------------------------------------------- |
| ISP               | İnternet servis sağlayıcıları                                  |
| Packets           | İnternet üzerinde gönderilen veriler                           |
| Protocols         | *Packet* aktarım kuralları ve hiyerarşisi                      |
| Routers ve Switch | *Packet*'ların yönlendirilmesini sağlarlar                     |
| Client            | Ağa bağlandığımzı araç (bilgisayarımız)                        |
| Server            | Ağ hizmetini sunan, sunucu                                     |
| Host              | End system, son *server* ya da *client*                        |
| RFS, IETF         | İnternet standartları                                          |
| Stream            | Veri akışı                                                     |
| Upstream          | Bizden internete *stream*                                      |
| Downstream        | İnternetten bize *stream*                                      |
| Bandwitdh         | Bant genişliği, saniye aktarılan bit (1sn de olan *streaming*) |
| Transmission rate | Saniyede aktarılan bit                                         |

<div class="page"/>

## Network Structure (Ağ Yapısı)

| Terim                           | Açıklama                                                    |
| ------------------------------- | ----------------------------------------------------------- |
| Network Edge                    | Ağdaki uç noktaları ele alır (bilgisayarlar ve uygulamalar) |
| Access networks, physical media | Kablolu ve kablosuz iletişim bağlantıları                   |
| Network Core                    | Birbirine bağlı router'lar ve internet (network of network) |

- Edge router: İnternete ilk adımın atıldığı yönlendiriciler (routers)

![network sturcture](../res/network%20structures.png)

<div class="page"/>

## Network Edge

Bizden internete olan gerçekleşen adımları ele alır.

| Yöntem          | Açıklama                                          | Örnek             |
| --------------- | ------------------------------------------------- | ----------------- |
| Hosts System    | *Host*'lar arası iletişim                         | Web, email        |
| Client / Server | *Client* istekte bulunur, *server* karşılık verir | Web browsers      |
| Peer to peer    | Neredeyse hiç *server* kullanılmaz                | Skype, BitTorrent |

### Access Network (Bağlantı Türleri)

- Dial Up: Telefon çalışırken modem, modem çalışırken telefonun çalışmadığı eski bir sistem.
- DSL: *Splitter* ile telefon ve internet eş zamanlı kullanabilmekte.
  - ADSL: Asimetrik anlamındadır, download ve upload hızı farklı olur.
- Wireless LAN: Ev içerisindeki kablasuz ağlar: WiFi
- Wide-Area wireless acces: Mobil operatörler tarafından sunulan ağlar: 3G, 4G, LTE

### Physcial Media (Fiziksel Veri İşlemleri)

Fiziksel verilerin (*bit*'lerin) aktarılmasını ele alır.

- Kablo yapısı TP (twisted pair) iç içe sarmal 2 kablodur.
- Guided: yönetimli (kablo vs ile), unguided: dağınık olarak yayılan (radyo dalgaları) verilerdir.

#### Fiber Optik Kablo

- Cam içerisinde bilgiler ışık yoluyla aktarılır
- Işığın farklı frekanslarıyla birden fazla bilgi yollanabilir
- Işık hızıyla iletilir
- Elektromanyetik gürültüden etkilenmez
- Veri kaybı çok düşüktür

### Radya Bağlantı

- LAN (WiFi)
- Wide-area (geniş alan bağlantıları) 3G, 4G

#### Satellite (Uydu Bağlantısı)

- Gecikmesi çok fazladır. (250ms)

<div class="page"/>

## Network Core

Birbirine bağlı çok sayıda *router*'dan oluşur. Network of network olarak da tabir edilen interneti ele alır.

![network_core](../res/network_core.png)

| Aktarım Yöntemi   | Açıklama                                               |
| ----------------- | ------------------------------------------------------ |
| Circuit Switching | Her arama için özel devre kullanılır, telefon ağı gibi |
| Packet Switching  | Veri ağa ayrık *packet*'lar halinde gönderilir         |

### Circuit Switching (Devre Anahtarlama)

*Bandwitdh* parçalara bölünür, her parça sadece kendi sahibi tarafından kullanılır.

- Genellikle telefon hatlarında kullanılır
- Garantili performans sunar
- Kaynaklar paylaşılmaz, kullanılmayanlar boşta bekler (verimsiz)
- Frekans ve Zaman bölme olarak iki yöntemi vardır. (FDM, TDM)

![fdm_tdm](../res/fdm_tdm.png)

<div class="page"/>

### Packet Switching (Paket Anahtarlama)

*Hostlar* çok yüksek miktarda gelen veriyi parçalayarak yollarlar, her bir parçaya **packets** denir. Her bir *packet* tam *bandwitdh* kullanır ve host tarafından **tamamlanmadan** yollanmaz (storage & forward).

- *Packet*'ların bir sırası yoktur
- Her bilgisayar *packet* iletimi için aynı yolu kullanır
- Kaynaklar boşta kalmaz. (verimli)
- Her bir *packet* $L$ kadar bit içeriyor ve *transmission rate* $R$ ise transmission delay $D=L/R$ formülü ile bulunur
- Kaynak çekişmesi olabilir. (olumsuz)
  - Toplamk kaynak talebi kullanılanı aşabilir
  - Trafik sıkışıklığı, *packet*'in kuyruğu ve bağlatıyı kullanmak için beklemesi
  - *Packet*'lar aynı anda bir yönlendiriciye iletirilir
    - Buffer'ı yetmezse *packet* kaybı olur

![packet_switching](../res/packet_switching.png)

### Packet Yönteminin Circuit Switching Yöntemine Göre Farkı

- Basit, arama algoritmalarının kurulmaına gerek yoktur
- Kaynaklar paylaşıldığından ağı daha fazla kullanıcı kullanabilir
- Güvenilir veri transferi ve sıkışıklık için protokellere ihtiyaç vardır.
  - Yoksa verilerinizi çalarlar 🙁

<div class="page"/>

## Internet Structure (Internet Alt yapısı)

### Interter Tiers

Her bir katman üst katmanının müşterisidir.

| Tier (Katman) | Açıklama                                                                                        |
| ------------- | ----------------------------------------------------------------------------------------------- |
| *Tier-1*      | Global *ISP* evrensel servis sağlayıcılarıdır. Birbirlerine bağlıdırlar Örn: Superonline, TTNet |
| *Tier-2*      | Regional *ISP* bölgesel servis sağlayıcılarıdır. Birbirlerine değil *Tier-1*'e bağlıdırlar      |
| *Tier-3*      | Son kullanıcı ağlarıdır, *Tier-2*'e bağlanırlar                                                 |

![isps](../res/ısps.png)

<div class="page"/>

### Paketlerin iletimi

Paketler *tier-3*'ten *tier-1*'e ardından hedef *tier-3*'e doğru yol izlerler.

![packet_forwarding](../res/packet_forwarding.png)

- *Router*'lar arası verilerin yayıldığı alana **pipe** denir
- Kalın bağlantılarda (links) veri aktarımı daha fazladır
- Ince alanlara **bottleneck link** denir

![throughput](../res/throughput.png)

<div class="page"/>

### Packet Delay & Loss (Gecikme ve Kayıp)

*Packet*'lar *router*'ın *buffer* (arrabellek) alanında kuytukta beklerler

- Gelen *packet* sayısı çıkandan fazla ise fazlalık *packet*'lar *buffer*'a konulur
- *Buffer* yeterli alana sahip değilse *packet* atılır, kayıp *packet*'lar önceki *node*'dan tekrar istenir

![packet_loss](../res/packet_loss_delay.png)

### Packet Switching Delay

| Olay              | Açıklama                                          |
| ----------------- | ------------------------------------------------- |
| Nodel Processing  | Hatalı bitlerin kontrol edildiği aşama            |
| Queueing Delay    | *Buffer*'da sıralanmanın olduğu aşama             |
| Transmisson Delay | Yayılım için *packet*'ların *router*'a iletilmesi |
| Propagation Delay | *Router*'daki paketlerin yayılması                |

![caravan_analogy](../res/caravan_analogy.png)
![caravan_analogy2](../res/caravan_analogy2.png)

### Internet Delay

Traceroute programı kaynaktan hedefe yol üzerinde bulunan *router*'lardaki gecikmenin ölçümünü sağlar.

- Windows için tracert
- Linux için tracepath

![tracepath](../res/tracepath.png)

### Protocol Layers (Protokol Katmanları)

Ağ yapıları karmaşıktır. Bilgisayarlar, *routers*, *protocols* ... Katman yapısıyla:

- Karmaşık sistem parçalarının ilişkilerini tanımlamaya olanak sağlar
- Modüler olması sistemin bakımını ve güncelleştirilmesini kolaylaştırır
  - Bir katmandaki servis uygulamasını değiştirmek, sistemi etkilemez

<div class="page"/>

### Internet Protocol Stack (TCP / IP)

| Öge         | Açıklama                                                                   |
| ----------- | -------------------------------------------------------------------------- |
| application | Ağ uygulamalarını destekleyen uygulamalar                                  |
| transport   | Veri aktarımı, TCP, UDP                                                    |
| network     | Kaynaktan hedefe *datagram*'ları yönlendirir: IP, yönlendirme protokolleri |
| link        | Komşu ağ elemanları arasında veri transferi: PPP, Ethernet                 |
| physical    | Hattaki bitler (*bits in wire*)                                            |

![ips](../res/ips.png)

#### ISO / OSI Reference Model

Internet protocol *stack*'te bu katmanlar yoktur, gerekirse program ile uygulanır

| Ek Öğe       | Açıklama                                                                                  |
| ------------ | ----------------------------------------------------------------------------------------- |
| presentation | Uygulamaların verilerin anlamlarını yorumlamasını sağlar: *encryption*, *compression* ... |
| session      | Senkronizasyon, denetim veri değişimi ...                                                 |

![iso_osi](../res/iso_osi.png)

<div class="page"/>

### Encapsulation (Kapsülleme)

Veri transferleri *encapsulation* ile yapılmaktadır.

![encopsulation](../res/encapsulation.png)

<div class="page"/>

## Network Security

Hiçbir *protocol* güvenlik tedbirleri barındırmaz. 📛

### Kötü Niyetli Uygulamalar

#### Trojan Horse

Faydalı yazılımların gizli bir parçasıdır, web sayfalarında bulunur. (Acitve-x, plugin)

#### Worm

Pasif olarak alınan nesnenin kendini çalıştırması ile bulaşır, çoğalır diğer bilgisayarlara da yayılır.

#### Virus

Alınan nesne ile bulaşır (e-posta). Nesne açıldığında *virus* bulaşır, çoğalır diğer bilgisayarlara da yayılır.

#### Spyware Malwawre

Casus yazılımlar olarak da bilinir. Klavye tuş basımlarını ve girdiğimiz web sitelerinin bilgilerini çalar.

### Kötü Niyetli Saldırılar

#### DoS

Denial of service olarak da bilinir. Saldırganların kaynağa çok fazla *packet* göndererek erişim dışı bırakmasıdır.

![dos](../res/dos.png)

<div class="page"/>

#### Packet Sniffing (Paket Yakalama)

Yerel ağa bağlı bir ağ kartından *Wireshark* uygulaması ile başka *packet*'lar de yakalanır.

![packet_sniffing](../res/packet_sniffing.png)

#### IP Spoofing (IP Aldatmacası)

Yanlış IP adresiyle *packet* gönderilir

![ip_spoofing](../res/ip_spoofing.png)

<div class="page"/>

## Internetin Geçmişi

[Buradaki](https://drive.google.com/drive/folders/1d3JzZlHNYqeE3RryDVdAyHKTSmSykjGt) slaytın 62. sayfasına bakarak erişebilirsin.

<!-- TODO -->

## Application Layer (Uygulama Katmanı)

![network_apps](../res/network_apps.png)

## *Network* Uygulaması Oluşturmak

Farkı *end systems* (son kullanıcı sistemleri) üzeründe  çalıştırılır. Örneğin, web server yazılımı ağ üzerinden web browser yazılımı ile bağlantı kurar

> Temel ağ cihazları, kullanıcı programlarını çalıştırmaz. 😔

<div class="page"/>

## Application Architectures (Uygulama Mimarileri)

2 farklı yapı kullanılmaktadır; client-server, peer-to-peer (P2P)

### Client-Server Architecture

Server Özellikleri:

- Her zaman açık
- *Static IP* (değişmeyen, kalıcı IP)

*Client* özellikleri:

- Belirlenen zamanlarda *server* ile iletişim kurabilirler
- *Dynamic IP*
- Birbiri ile iletişim kuramazlar

### Pear-to-Pear Architecture (Kişiden kişiye Mimarisi)

- *Server* her zaman açık değildir
- Rastgele *end system*'lerle doğrudan iletişim olur (arada *server* olmaz)
- Bilgisayarlar zaman zaman bağlanabilir ve *dynamic IP* kullanabilirler

> Yönetmesi oldukça zordur.

### Client-Server ve Peer-to-Peer Karışımı

![client_p2p](../res/client-p2p.png)

<div class="page"/>

## Processes Communicating (İletişim Sistemleri)

| İşlem          | Açıklama                                              |
| -------------- | ----------------------------------------------------- |
| Process        | Bir bilgisayarda çalışan programlar, yapılan işlemler |
| Client Process | İletişimi başlatan *process*'ler                      |
| Server Process | Bağlantıyı bekleyen *process*'ler                     |

### Socket Yapısı

*IP* adresi ve *port* numarasından oluşan, *process*'lerin alınıp / verildiği kısma **socket** adı verilir.

- *Client*, *process*'i kapının dışına koyar.
- *Server*, *process*'i kapıdan içeri alır
- Buradaki kapı olarak adlandırılan *socket*'tir

### Adressing Processes (İşlemleri Adresleme)

Mesajların alınması için *process*'in bir tanımlayıcısı (*identifier*) olması gerekmektedir. 0 ile 1023 arası *well-known ports* olarak bilinmektedir. Tanımlayıcı:

- *IP* adresi, örn: 128.119.245.12
- *Port* numarası, örn: 80

içerir.

Örnek *port* numaraları:

- *HTTP* server: 80
- *Mail* server: 25

> Windows için `ipconfig`, linux için `ifconfig` ile IP adresinizi öğrenebilirsiniz.

<div class="page"/>

## Transport Service Requirements

| Özellik        | Açıklama                                                                         |
| -------------- | -------------------------------------------------------------------------------- |
| Data Integrity | Metin aktarımlarında çok önemlidir, ses gibi verilerim aktarılmasında önemsizdir |
| Timing         | Ses aktarımlarında gecikmenin en az olması gereklidir.                           |
| Throughput     | Multimedya uygulamaları etkili olmak için daha az veri kullanmayı tercihi eder   |
| Security       | Şifreleme ve verinin değiştirilmemesini ele alır                                 |

![trans_services](../res/trans_services.png)

<div class="page"/>

## Internet Transport Protocols Services (Taşıma Protokolleri Hizmetleri)

*Protocol*'lerin hiç biri alttaki özellikleri taşımaz, sonradan bunlara uygun sistemler oluşturulur ve entegre edilir.

- Timing (düşük gecikme)
- Min throughput (düşük veri aktarımı)
- Guarantee (garantili taşıma)
- Security (güvenli taşıma)
  - Şifreleme (*enctryption*) içermez
  - Socket ve internet verileri olduğu gibi (*cleartext*) gönderilir.

![tcp_udp_segment_format](../res/tcp_udp_segment_format.png)

### TCP (Transmission Control Protocol) Review

| Özellik            | Açıklama                                             |
| ------------------ | ---------------------------------------------------- |
| Reliable transport | Güvenilir veri aktarımı                              |
| Flow control       | Veri akışı denetimi                                  |
| Congestion control | *Network* aşırı yoğun olduğunda veri akışını azaltır |

> Detayları *transport layer* altında işlenmekte, [buraya](#tcp-transmission-control-protocol) tıklayarak gidebilirsin.

<div class="page"/>

### UDP (User Datagram Protocol) Review

UDP yayıncılıkta tercih edilen bir *protocol*'dür. Amacı tamamıyla hızı arttırmak ve maaliyeti düşürmektir.

- *Packet*'in varıp, varmadığıyla ve güvenliğiyle ilgilenmez (*Unreliable transport*), varmazsa tekrar gönderir.
- Tıkanıklık kontrolüne (*congestion control*) ihtiyaç yoktur, olabildiğince hızlı gönderir
- Bağlantı kurmaya gerek yok, zaman kaybına neden olur
- Basitir, *sender* ve *reciver* asla birbiriyle iletişimde değildiir
- Olumsuz geri dönüş yoktur.

> Detayları *transport layer* altında işlenmekte, [buraya](#udp-user-datagram-protocol) tıklayarak gidebilirsin.

### Securing TCP (TCP'de Güvenlik)

TCP'de güvenlik SSL ile sağlanır, uygulamalar **SSL kütüphanesi** yardımıyla TCP ile etkileşir. SSL'in sağladıkları:

- Şifreli (*encreypted*) TCP bağlantısı
- Veri bütunlüğü (*data integrity*)
- Uç sistem doğrulaması (*end-point authentication*)

## Web ve HTTP

- Web sayfası *base HTML* dosyasının referans ettiği objelerden oluşur.
- Web sayfaları objelerden oluşur, bu dosyalar; HTML, JPEG, JAVA applet vs. olabilir.
- Her obje *URL*'ler ile adreslenir.

![url_ex](../res/url_ex.png)

<div class="page"/>

## HTTP (Hypertext Transfer Protocol)

### Temel HTTP Yapısı

*Applicataion Layer* (uygulama katmanı) *protocol*'üdür.

![http_overview](../res/http_overview.png)

- *Client*: Tarayıcılar, *Server*: Apache Web Server

### HTTP Veri Aktarımı

HTTP, TCP kullanır.

- *Client* TCP bağlantısını başlatır.
  - *Server*'a 80 *port*'unda *socket* oluşturur
- *Server* TCP bağlantısını kabul eder
- *Client* ve *Server* arasında HTTP mesajları aktarılır
- TCP bağlantısı kapatılır

> HTTP *stateless* (durumsuz) olarak tanımlanır. Eski istekler (*requests*) hakkında bilgi sahibi değildir.

<div class="page"/>

### HTTP Bağlantıları

| Bağlantı Türü                   | Açıklama                                                               |
| ------------------------------- | ---------------------------------------------------------------------- |
| non-persistent (kalıcı olmayan) | En fazla bir obje TCP üzerinden gönderilir ardından bağlantı kapatılır |
| persistent (kalıcı)             | Çok sayıda obje TCP üzerinden gönderilebilir                           |

> **RTT**, bir *packet*'in *client-server* arasında gidiş geliş süresi

#### Non-Persistent HTTP

Sunucuyu her defasında açmak için *RTT* kaybı yaşanacaktır, tek bir veri alınacaksa ideal seçimdir

![non_persistend_http](../res/non_persistent_http.png)

#### Persistent HTTP

- Sunucu tek bir seferde açılacak lakin kapatılmak için *request* bekleyecektir, bu da fazladan *RTT* kaybı demektir.

<div class="page"/>

### HTTP Request Message (İstek Mesajı)

![http_request](../res/http_request.png)

- `sp`: Boşluk
- `cr`: \r karakteri
- `lf`: \n, satır sonu karakteri

![http_request_ex](../res/http_request_ex.png)

<div class="page"/>

### HTTP Status Code (Durum Kodları)

| Status Code | Açıklama                   |
| ----------- | -------------------------- |
| 200         | OK                         |
| 301         | Moved Permanently          |
| 400         | Bad Request                |
| 404         | Not Found                  |
| 505         | HTTP Version not Supported |

### Cookie (Çerezler)

Bir websitesine ilk kez girdiğimizde bilgilerimiz **cookie** adıyla *server* veri tabanında saklanır.

> Web siteleri kişisel bilgilerimizi saklarlar. 😕

![cookie_ex](../res/cookie_ex.png)

<div class="page"/>

### Proxy Server & Cache

*Client* isteklerini *server* ile uzun süren bağlantılardan kaçınarak hızlıca halletmeyi amaçlar. Belli başlı *server*'lar *cache*'e atılır ve *server*'a istek yollamak yerine yerel ağdaki *proxy server*'a istek yollanarak çok hızlıca işlem halledilir.

> *LAN* (yerel ağ) diğer *network*'lere kıyasla çok hızlıdır.

![proxy_ex](../res/proxy_ex.png)

<div class="page"/>

#### Conditional GET (Koşullu GET)

Bu yöntemler *Proxy server* önbelleğinde (*cache*) bulunan verilerin güncel olup olmadığı sorgulanır.

![conditional_get](../res/conditional_get.png)

## Domain Name System (DNS)

Internette adresler IP (192.168.1.1) ile tanımlanır. DNS'ler ile IP'lere isimler (google.com) atanır.

> DNS eşleştirilmesi yapıldığında *Local DNS*'de *cache*'e alınır, bundan dolayı TLD sık kullanılmaz.

| DNS Türü      | Açıklama                                                                            |
| ------------- | ----------------------------------------------------------------------------------- |
| Local         | DNS hiyerarşisine ait değildir, her istek ilk burada eşleştirilmeye çalışılır       |
| Root          | Yerel (*local*) DNS sunucularının çözemedikleri isimler için buraya danışılır       |
| TLD           | Top-level domain, *com, org, net, tr ...* gibi ülke etki alanlarından sorumludurlar |
| Authoritative | Yetkili isim sunucuları, kurumlardaki sunucuların isimlerini eşleştirir             |

![dns_hierarchy](../res/dns_hierarchy.png)

<div class="page"/>

### DNS Resolution Examples (DNS Çözümleme Örnekleri)

![dns_resolution_ex1](../res/dns_resolution_ex1.png)
![dns_resolution_ex2](../res/dns_resolution_ex2.png)

<div class="page"/>

### DNS Record (DNS Kayıtları)

Kayıtların formatı `(name, value, type, ttl)` şeklindedir.

| Type  | Açıklama                                     |
| ----- | -------------------------------------------- |
| A     | `name`: hostname, `value`: IP                |
| NS    | `name`: domain, `value`: hostname            |
| CNAME | `name`: takma isim, `value`: domain          |
| MX    | name: alakalı isim, value: *mailserver* ismi |

#### Inserting DNS Record

- DNS *server* ismi ve IP adersi belirlenir
- TLD *Server*'lara alttaki şekilde kayıt edilir

```sh
(dns1.manolyatekstil.com, 212.212.212.1, A)
(manolyatekstil.com, dns1.manolyatekstil.com, NS) # Nameserver
```

#### Attacking DNS

![attacking_dns](../res/attacking_dns.png)

<div class="page"/>

## P2P (Peer to Peer)

![p2p_scheme](../res/p2p_schema.png)

- *Server* *torrent*'e katılanları izler ve her zaman açık olmaz
- *Network*'teki bilgisayarlar rastgele erişim kurarlar
- Eş bilgisayarlar zaman zaman bağlantı kurarlar ve IP adresleri değişebilir

| Terim   | Açıklama                       |
| ------- | ------------------------------ |
| Chunk   | 256KB'lik *packet*'lar         |
| Torrent | *Chunk* alışveriişi yapan grup |

<div class="page"/>

### P2p File Distribution (Dosya Paylaşımı)

Hızlı veri aktarımı sağlayan bir yapıdır.

![p2p_client_graph](../res/p2p_client_graph.png)

- *Chunk*'lar indirilirken aynı zamanda karşıya da yüklenir
- Çok yükleme yapan çok hızlı indirir
- İsteğe bağlı yükleme veya indirme iptal edilebilir

<div class="page"/>

## Video Streaming and CDNs: context

### Video Streamin

Her video, resin topluluğundan ver resimler de *pixel*'lerden oluşur. Her *pixel* de *bit*'lerden oluşmakta ve bunların aktarımları gerçekleşmektedir. *Bit* sayısını azaltmak için;

| Yöntem               | Açıklama                                                             |
| -------------------- | -------------------------------------------------------------------- |
| spatial (uzaysal)    | N tane renk göndermek yerine, rengi ve tekrar etme sayısını gönderir |
| Temportal (zamansal) | Sadece bir önceki resim ile farklı olaran yerleri gönderir           |

### Content Distribution Networks (İçerik Dağıtım Ağları)

İçerikler kopyalanarak birden fazla *server*'dan akatarılır.

![netflix_structure](../res/netflix_structure.png)

<div class="page"/>

## Transport Layer

*Network layer*, *host*'lar arası mantıksal iletişimi sağlarken; *transport layer*, ***process***'ler arası mantıksal iletişimi sağlar

![transport_layer](../res/transport_layer.png)

<div class="page"/>

## Internet Transport Layer Protocols

Yine, [UDP](#udp-user-datagram-protocol) ve [TCP](#tcp-transmission-control-protocol) protocolleri kullanılır. 😉

## Multiplexing (Çoğullama)

| Multiplexing Yeri   | Açıklama                                                                              |
| ------------------- | ------------------------------------------------------------------------------------- |
| Gönderen bilgisayar | Birden çok *socket*'ten verileri toplar, başlık ekliyerek **segment** haline getirir. |
| Alıcı bilgisayar    | Alınan *segment*'leri doğru *socket*'e teslim eder                                    |

![multiplexing_transport_layer](../res/multiplexing_transport_layer.png)

## Demultiplexing (Azaltma / Parçalama)

- Bilgisayarlardan IP *datagram*'ları alınır.
  - *Datagram*'larda *source IP* ve *dest IP* vardır
  - Her *datagram* bir *segment* taşır
  - Her *segment*'in kaynak ve *dest port* numaları vardır

### TCP / UDP Demux

| UDP Yönelendirme            | TCP Yönelendirme            |
| --------------------------- | --------------------------- |
| *Source IP*                 | *Source IP*                 |
|                             | *Destination IP*            |
|                             | *Source port* numarası      |
| *Destination port* numarası | *Destination port* numarası |

> *Socket*, *source IP* ve *destination port* numarasından oluşur.

<div class="page"/>

### UDP Demux Örneği

![udp_demux](../res/udp_demux.png)

### TCP Demux Örneği

![tcp_demux](../res/tcp_demux.png)

<div class="page"/>

## UDP (User Datagram Protocol)

UDP yayıncılıkta tercih edilen bir *protocol*'dür. Amacı tamamıyla hızı arttırmak ve maaliyeti düşürmektir.

- *Packet*'in varıp, varmadığıyla ve güvenliğiyle ilgilenmez (*Unreliable transport*), varmazsa tekrar gönderir.
- Tıkanıklık kontrolüne (*congestion control*) ihtiyaç yoktur, olabildiğince hızlı gönderir
- Bağlantı kurmaya gerek yok, zaman kaybına neden olur
- Basitir, *sender* ve *reciver* asla birbiriyle iletişimde değildiir
- Olumsuz geri dönüş yoktur.

![udp_segment](../res/udp_segment.png)

### UDP Checksum

Aktarılan *segment*'deki hataları algılamak için kullanılan yöntemdir.

![udp_checksum](../res/udp_checksum.png)

<div class="page"/>

## Reliable Data Transfer (RDT)

### Rdt 1.0

Tam güvenlikli bir kanaldır.

- *Bit* ve *packet* kayıpları yoktur
- *Sender* ve *reciver* verileri güvenli kanaldan (*underlying channel*) alır

### Rdt 2.0

Bitlerde hatalar söz konusu olabilir.

- *Bit* hataları *checksum* ile algılanır.
- *Acknowledgements (ACKs)* paket alındı bilgisi, *negative acknowledgements (NAKs)* paketin hatalı olduğu bilgisi gibi *feedback*'ler vardır.

#### Rdt 2.0 Kusurları

- ACK / NAK mesajları bozulması durumunda geçerli *packet* yeniden gönderilir
- *Sender* her gelen *packet*'e *segment* numarası ekler, birden fazla gelen *packet*'ları *reciever* atar
- *Sender* bir *packet* gönderdikten sonra *feedback* için bekler, bu da zamandan kayıp demektir.

### Rdt 2.1

*Sender*:

- *Packet*'lara *segment* numarası ekler.
- ACK / NAK bozuk alınıp alınmadığını kontrol eder

*Reciever*:

- Alınan *packet*'ların eşsiz olup olmadığını kontrol eder
- ACK / NAK mesajlarının *sender* tarafından alınıp alınmadığını bilmez

### Rdt 2.2

NAK içermez, sadece ACK kullanarak rdt 2.1 ile aynı görevi yapar.

- NAK yerine *packet* başarılı alındığında ACK mesajları gönderilir.
- Çift ACK mesajı NAK gibi kabul edilir, *packet* yeniden gönderilir.

<div class="page"/>

### Rdt 3.0

Rdt 2.2'ye ek olarak:

- *Sender* belli sürede ACK mesajı almazsa (*timeout*) *packet* yeniden gönderilir.
- Eşsiz olmayan *packet*'lar *segment* numaraları ile ayırt edilir.

![rdt_3.0](../res/rdt_3.0.png)

<div class="page"/>

## Pipelined Protocols

Bir *packet* göndermek yerine birden fazla gönderilir.

- *Reciver* aldığı her sağlam *packet* için *ack* gönderir
  - Hatalı *packet*'ler için *ack* gitmez
  - Kaçırılan paketler için en son gönderilen *ack* gönderilir
- Tekrar eden *ack*'lar *sender* tarafından görmezden gelinir ve *packet* yeniden gönderilir
  - Bu yapıya **Go back N (GDN)** adı verilir.

> Selective repeat ?

![pipeline_gbn](../res/pipeline_gbn.png)

## TCP (Transmission Control Protocol)

> Sıkıldım 😓
