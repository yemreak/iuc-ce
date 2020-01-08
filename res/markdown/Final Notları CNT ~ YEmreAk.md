# Computer Networks and Technologies Final Notları 

Bu yazı **MIT** lisanslıdır. Lisanslar hakkında bilgi almak için [buraya](https://choosealicense.com/licenses/) bakmanda fayda var.

- Copyright © ~ *Yunus Emre AK*

> *Sefa Yalçındağ* ile çalışılmıştır.

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

- [Network Layer](#network-layer)
  - [Forward & Route](#forward--route)
  - [Network Layer Service Models](#network-layer-service-models)
  - [Router Mimarisi](#router-mimarisi)
    - [Import Port Function](#import-port-function)
    - [Switching Fabric](#switching-fabric)
    - [Input & Output Queuing](#input--output-queuing)
  - [The Internet Network Layer](#the-internet-network-layer)
    - [IP Protocol](#ip-protocol)
    - [IP Adressing](#ip-adressing)
    - [Subnet (Alt ağlar)](#subnet-alt-a%C4%9Flar)
    - [CIDR (Classless InterDomain Routing)](#cidr-classless-interdomain-routing)
    - [DHCP (Dynamic Host Configuration Protocol)](#dhcp-dynamic-host-configuration-protocol)
    - [DHCP Client-Server Senaryasu](#dhcp-client-server-senaryasu)
    - [ISP Adresleme](#isp-adresleme)
    - [ISP Adressleme Hiyerarşisi](#isp-adressleme-hiyerar%C5%9Fisi)
    - [NAT (Network Adress Translation)](#nat-network-adress-translation)
- [Hauwei Dersi](#hauwei-dersi)
  - [Temel Kavramlar](#temel-kavramlar)
  - [SubnetMask Host ve Bit Hesaplamaları](#subnetmask-host-ve-bit-hesaplamalar%C4%B1)
  - [IPv4 Classes](#ipv4-classes)
  - [Layer Özellikleri](#layer-%C3%B6zellikleri)
  - [*MAC* varken Neden *IP* Adresi Var](#mac-varken-neden-ip-adresi-var)
  - [Static Route](#static-route)
  - [RIP - Routing Information Protocol](#rip---routing-information-protocol)
    - [RIP-2 Özellikleri](#rip-2-%C3%B6zellikleri)
    - [RIP-2 Örneği](#rip-2-%C3%B6rne%C4%9Fi)
  - [OSPF Open Shortest Part First](#ospf-open-shortest-part-first)
    - [OSPF Package Types](#ospf-package-types)
  - [BGP](#bgp)
  - [Comparing Protocol](#comparing-protocol)
  - [Collision & Broadcast Domain](#collision--broadcast-domain)
  - [TCP / IP Model](#tcp--ip-model)
    - [TCP Transmission Types](#tcp-transmission-types)
  - [Virtual LAN (VLAN)](#virtual-lan-vlan)
    - [VLAN Avantajları](#vlan-avantajlar%C4%B1)
  - [Spanning Tree Protocol (STP)](#spanning-tree-protocol-stp)
    - [STP Port State](#stp-port-state)

<div class="page"/>

## Network Layer

- Veriler segment
- Application data
- Network katmanına geçerken bilgi datagram olarak devam ediyor
- Router'larda network katmanından sonrakiler var network dahil
- Transport katmanında TCP / UDP, ağ katmanında IP protokolleri uygulanır

### Forward & Route

- Routung, 2 route arası aktarma
- Routing, kaynaktan asıl hedefe iletişim algoritması. Bir sürü forward
- Tablonun genel adı *control plane*'dir
- Forward işlemlerindeki router'lardaki control pane kullanılır, her bir route'un control pane'i bitlere karşılık hedef bilgisi taşır
- Remote Controller ile tablolar manuel olarak dolduruluyor (?)

### Network Layer Service Models

- İnternet hız sunuyor, güvenlik değil. Güvenlik işlemlerini application katmanında yapıyor (Best efford)
- ATM güvenilik sağlayabilyor (4-9 sayfa 5)

<div class="page"/>

### Router Mimarisi

Yönlendircinin 2 görevi vardır:

- Yönlendirme algoritmaları ve protocol'lerin (RIP, OSPF, BGP) çalıştırılması
- Datagram'ları gelen porttan giden port'a yönlendirilmesi
- Datagram'lar hedefe *Control Panel* tablosuyla yönlendirilir

#### Import Port Function

| Import Port Function         | Açıklama |
| ---------------------------- | -------- |
| Destination-Based Forwarding | 7        |
| Longest Prefix Mathcing      | 8        |

#### Switching Fabric

| Switching Fabric | Açıklama                                                                                   |
| ---------------- | ------------------------------------------------------------------------------------------ |
| Memory           | Eski düzen, yavaş                                                                          |
| Bus              | Paket kaybı olabiliyor, kurumsal ağlar için uygundur                                       |
| Crossbar         | Datagramlar parçalanıyor, parçalar işlemciler üzerinde birleştiriliyor, en hızlı yöntemdir |

#### Input & Output Queuing

- *Queue delay* ve *buffer*'ın dolu olmasından dolayı kayıp olur (Output)
  - $(RTT.C) / \sqrt{N}$
- Gecikme ve giriş buffer'ında yer kalmaz ise kayıp oluşabilir (Input)
  - Head of the Line (HOL)
- Scheduling mechanisims
  - *FIFO* first in first out
  - *Priority schedulung*, en az bekleyeceği yere yönlendirir
  - *Round Rubin (RR)*, boyutu az olanı önce işleme sokma
  - *Weighted Fair Queuing (WFQ)*, RR'ın genelleştirilmiş hali
    - Büyük paketleri parçalasyarak adil miktarda alır ve gönderir

<div class="page"/>

### The Internet Network Layer

- Segment (TCP; UDP)
- Datagram (IP, ROUTE vs)
- Frame (link layer)

#### IP Protocol

- IPv4 = 4byte (32 bit)
- IPv6 = 16byte (128 bit)
- Büyük IP datagramları ağ içlerinde parçalanıp (*fragmentation*) yollanır, son hedefte (*final destination*) da işlemcide birleştirilir (*reassambled*)
  - Üst bilgi uzunluğu $Head = 20$bit
  - Bölünme varsa $fragflag = 1$
  - $Offset = (length - Head) / 8$

#### IP Adressing

- IP Adresleri kablonun (switch, router) adresidir, PC'nin değil
- Her bir bağlantı *interface* olarak tanımalanır (253.1.1.1)
- IPv4 32 bittir, uzun olduğunda 4x8bit olarak parçalanır (x.x.x.x)

#### Subnet (Alt ağlar)

- IP'lerin ortak kısmı yazılır, değişken kısmı $0$ olarak gösterilir
- 223.1.1.1, 223.1.1.4 vs. için 223.1.1.0 *subnet*'i kullanılır
  - IP'in sol kısmı 223.1.1 **subnet**, sağ kısmı **host** bölümüdür
  - 223.1.3.0 / 24 değerinden 24 kısmı subnet için ayrılan biti (*subnet mask*) temsil eder
  - Sadece *host* arası değil *router* arasında da *subnet* olur
- Subnet'ler birbiri ile iletişimde değildir (*isolated*)

#### CIDR (Classless InterDomain Routing)

- Özel bir class yapısı yoktur
- Kendimize ait *subnet* ve *host* adresimiz vardır
- Belirli *class* verilerine uygun olarak maske kullanılırsa *classful* olur

<div class="page"/>

#### DHCP (Dynamic Host Configuration Protocol)

- Bu protokol sayesinde IP adresleri otomatik olarak atanır
- Dinamik olarak IP ataması yapılır, boş IP adresleri hemen başkalarına verilir

| DHCP Mesaj Tipi | Açıklama                             | İsteğe Bağlı |
| --------------- | ------------------------------------ | ------------ |
| discover        | Broadcast (yayınlama) bulunma işlemi | Evet         |
| offer           | Sunucunun verdiği cevap              | Evet         |
| request         | Sunucudan IP isteme                  | Hayır        |
| ack             | Sunucunun IP adresini göndermesi     | Hayır        |

#### DHCP Client-Server Senaryasu

- Bilgisayar ağa bağlanır
- DHCP Discover mesajını gönderir
  - IP adresi almak için DHCP *server*'ını bulmaya çaışıyor
  - Kendi IP'sine 0.0.0.0 dest IP'ye 255.255.255.255
- DHCP offer mesajı alır
  - *DHCP*, *IP* adresi sunuyor, istiyor musun diyor
- DHCP request mesajı gönderir
  - *Host* verilen *IP*'yi kabul ettiği bilgisini gönderiyor
- DHCP ack mesajı alır
  - *IP* adresini atanıyor
  - *Subnet* bilgisi atanıyor
  - *DNS server*'ın IP adresi bilgisi veriliyor
  - *Gateway*, Diğer ağalara çıkısı sağlayan adresi
- ilerleme hiyerarşisi: `DHCP -> UDP -> IP -> Ethernet -> Physical`
  - App - Transport - Network - Link - Physical
  - Sistemdeki tüm bilgisayarları geziyor

> Default Gateway, internete erişim yaptığımız IP adresimizdir, *local network* üzerinden olan IP adresi ile internete erişmeyiz. Her *local network*'ün çıkış IP'si aynıdır

<div class="page"/>

#### ISP Adresleme

ISP adres bloğu ICANN (Internet Corporation for Assigned Names and Numbers)

- IP adresi
- DNS
- Domaint

#### ISP Adressleme Hiyerarşisi

Yeni bir ISP'ye geçildiğinde yeni olandaki IP adresinin **subnet mask** değeri daha fazladır, bu sebeple

- İlk arama yenisinde yapılır yenide yoksa eski IP'ye bakılır
- Aktarımlarda sorun oluşturulması engellenir
- Örn: Turkcell'ten TTNet'e taşındığı zaman, TTNeT'deki IP verisinde olan *subnet mask* değeri (x.x.x.x / 23) değeri fazladır

> *Subnet mask*, subnet için ayrılan bit sayısı

#### NAT (Network Adress Translation)

*Local network*'ler internet ile etkileşime geçerken tek bir IP kullanırlar

- ISP'lerde IP uzunluğu önemsizdir, tek IP kullanılır
- *Local network* (yerel ağ) üzerindeki değişikler ISP'yi etkilemez (tam tersi de geçerli)
- *Local network* içindeki kullanıcılar internet üzerinde gözükmez (güvenlik amaçlı)
- Giden *datagram* verilerinde IP adresi yerine NAT IP adresi konulur, gelenlerde de NAT IP yerine IP adresine çevrilir
- LAN = Local area network (IP)
- WAN = World area network (NAT IP)
- NAT 16bit *port-number* alanı sayesinde 60.000 *LAN-side adress* destekler

<div class="page"/>

## Hauwei Dersi

`eNSP`, Hauwei'nin sunduğu *network* similasyın uygulaması

> Notlar tam değildir, katıldığım (ve dinlediğim 😄) kısımlar yazılmıştır.

### Temel Kavramlar

| Kavram          | Açıklama                                                                         |
| --------------- | -------------------------------------------------------------------------------- |
| IP Adresi       | İnternete bağlanma adresimiz                                                     |
| SubnetMask      | Kimlik ve grupları ayırmak için kullanılır                                       |
| Default Gateway | İki farklı *network*'ün iletişimini sağlar, local networkten çıkış IP'si aynıdır |
| Subnet ID       | Last IP & (logic and) SubnetMask                                                 |

### SubnetMask Host ve Bit Hesaplamaları

$255.255.b.a$ olan subnetmask için:

- $host = (256 - b)(256 - a) - 2$
  - 0 ve 255 kullanılamaz, ondan - 2
- $bit = 32 - log_2 (host + 2)$
  - Subnet içina ayrılan bit (*subnet mask*)

Subnet splitting:

- $m \geq log_2(subnet)$
  - $subnet$: istenen subnet sayısı
  - $m$ kadar host kısmına 1 yazılır (x.x.x.x / 21 ise 22 olacak)
- $host = 2^n - 2$
  - $n$: Bir subnetteki host sayısı
- $2^n$ kadar arttırılacak şekilde IP'ler gruplanır
- Başlangıç ve bitiş dahil olmaz

<div class="page"/>

### IPv4 Classes

$IP.0.0.0$ için temel formül:

- $IP_{class} = IP_{class - 1} + 2^{8 - harf}$
  - $harf$ A -> 0 olmak üzere alfabetik sıra
  - $IP_{0} = 0$

| Class | IP Karşılığı | Artış |
| ----- | ------------ | ----- |
| A     | 0.0.0.0      | 0     |
| B     | 128.0.0.0    | 128   |
| C     | 192.0.0.0    | 64    |
| D     | 224.0.0.0    | 32    |
| E     | 240.0.0.0    | 16    |

### Layer Özellikleri

| Layer2                                 | Layer3                                                                                 |
| -------------------------------------- | -------------------------------------------------------------------------------------- |
| Aynı *network*'teki haberleşme (local) | Farklı *network*'teki haberlerşme                                                      |
| Modemlerdeki *LAN* portlarının katmanı | Modemdeki *ADSL* portunun katmanı                                                      |
| *Switch* ile gerçekleşir               | *Router* ile gerçekleşir                                                               |
| *MAC* adresleri ile haberleşilir       | Asıl hedefe *IP* adresi ile gidilir, *MAC* adresleri hedefe gidiş sırasında kullanılır |
| *Gateway* olmaz                        | *Gateway* olur                                                                         |

- *Router*, *switch*lerin haberleşmesini sağlar
- *switch*, aynı ağdaki bilgisayarların haberleşmesini sağlar
- *Gateway*, asıl hedefini belirtir ve hedefe giderken başka yerlere gitmesiyle ilgilnemez bilgisi olmaz. (kargo şirkerlerine paket vermek gibi)

<div class="page"/>

### *MAC* varken Neden *IP* Adresi Var

- Paket alışverisi *IP* adresi ile yapılmaktadır (layer3)
- Router arasında aktarım yapılırken, Source *MAC* adresi sabit kalarak, Destination *MAC* adresleri değişmektedir
  - Source *MAC*, kaynağın kimliğini tutar
  - Destination *MAC*, paketin gönderileceği kaynağın adresini tutar.
  - *IP*, asıl kaynağın sanal adresini tutar
- Her kaynak bildiği hedefe paketi yollar (gateway yapısı)
  - Bildiği adres olarak ifade edilen *MAC* adresidir

### Static Route

Her iki router için de bu komutlardan biri tanımlanırsa bağlantı mümkün olur.

- ip route-static [dest_ip] [subnet] [dest_port]
- ip route-static [dest_ip] [subnet] Serial [port_number]
- ip route-static [dest_ip] [subnetmask] Serial [port_number]

### RIP - Routing Information Protocol

- Interior Gateway Protocol (IGP)
- Distance vector algorithm
- Ufak çaplı *network*'lerde kullanılır

| Rip - 1                              | Rip - 2                                         |
| ------------------------------------ | ----------------------------------------------- |
| Classful routing protocol            | Classless routuing protocol                     |
| Broadcast route updates              | Multicast route updates 224.0.0.9               |
| UDP 520 port send and recieve packet | UDP 520 port send and recieve packet            |
| Metric (Hop count)                   | Metric (Hop count)                              |
|                                      | Support external route tag, route summarization |
|                                      | Specified next hop and authentication (MD5)     |
|                                      | Classless inter-domain routing (CIDR)           |

<div class="page"/>

#### RIP-2 Özellikleri

- Timer
- Split Horizon
- Poison Reverse
- Trigger Update
  - Route bilgisi değişirse hemen güncelleme paketini komşusuna gönderir

#### RIP-2 Örneği

Temel sistem:

- `rip`
- `version 2`
- `network <network_id>`
  - Kaç *network*'e bağlıysa o kadar `network ...` komutu yazılır
  - `<network_id>` sonu `.0` olan IP adresidir
- `quit`

![huaweri_rip_ex](../res/huawei_rip_ex.png)

<div class="page"/>

### OSPF Open Shortest Part First

- Link State interior gateway protocol (IGP)
- SPF Algorith
- Kurumsal *network*'lerde kullanılır

#### OSPF Package Types

> Genel olarak Link State (LS) olanları barındırır.

- Hello
- Database Description (DD)
- Link State Request (LSR)
- Link State Update (LSU)
- Link State Acknowledgement (LSAck)

### BGP

- BGP, **TCP 179** portunu kullanır
- Büyük çaplı *network*'lerde kullanılır
- BGP neighbor reletionship yapısı: `Idle - Connect - Opensent - OenConnect - Estanblished`

### Comparing Protocol

| RIP - 2                               | OSPF                                       | IS - IS                                    | BGP                                    |
| ------------------------------------- | ------------------------------------------ | ------------------------------------------ | -------------------------------------- |
| Interior Gateway Protocol (IGP)       | Link State interior gateway protocol (IGP) | Link State Interior Gateway Protocol (IGP) | Exterior Gateway Protocol (EGP)        |
| Distance vector algorithm             | SPF Algorith                               | SPF algorithm                              | Optimal route between ASs              |
| Ufak çaplı *network*'lerde kullanılır | Kurumsal *network*'lerde kullanılır        | Büyük çaplı *network*'lerde kullanılır     | Büyük çaplı *network*'lerde kullanılır |

### Collision & Broadcast Domain

| Metod            | Hub     | Repeater | Switch          | Bridge   | Router   |
| ---------------- | ------- | -------- | --------------- | -------- | -------- |
| Collision Domain | Geçirir | Geçirir  | Geçirmez        | Geçirmez | Geçirmez |
| Broadcast Domain | Geçirir | Geçirir  | Seçici geçirgen | Geçirir  | Geçirmez |

<div class="page"/>

### TCP / IP Model

| TCP                 | UDP               |
| ------------------- | ----------------- |
| Connection-Oriented | Connection-less   |
| Windowing           | No Windowing      |
| Error Recovery      | No Error Recovery |
| Ordered Data        | No Ordered Data   |

> UDP hız odaklıdır.

#### TCP Transmission Types

- Connection 3-Way Handshake
- Connection Termination
- Normal Data Transmission
- Error Recovery
- Windowing

<div class="page"/>

### Virtual LAN (VLAN)

Switch içerisinde switch yapısı oluştururak, sanal bir ağ yapısı sunar

- VLAN içerisindeki kendi aralarında haberleşebilir, diğer LAN üyeleri mesaj gönderemez
  - VLAN'ı switch, LAN'ı da router'a bağlı host'lar olarak düşünebiliriz.
  - VLAN, little switch olarak da tanımlanır
- Güvenlik amaçlı yapılmıştır, fiziksel olarak Router ve Switch almak pahalıya gelmektedir
- *Access* ve *Trunk Port* olarak 2 *port*'u vardır
- *Trunk port*, switchler arası portlar

#### VLAN Avantajları

- Geliştirilmiş güvenlik
- Düşük maalyet
- Verimli performans
- Yönetim kolaylığı

### Spanning Tree Protocol (STP)

- *Root bridge*'ın tüm portları elden atanır (*designated port*)
- *Root bridge*'e giden en kısa yol *root port* olarak seçilir

#### STP Port State

- Listening
- Learning
- Forwarding
- Disabled
