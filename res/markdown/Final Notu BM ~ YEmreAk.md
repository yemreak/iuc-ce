# Bilgisayar Mimarisi Final Notları 

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

- [Pipeline](#pipeline)
  - [Pipeline Hazards](#pipeline-hazards)
  - [Pipeline Örneği](#pipeline-%C3%B6rne%C4%9Fi)
- [Hız Hesaplama](#h%C4%B1z-hesaplama)
- [Bellek Yönetim Sistemi](#bellek-y%C3%B6netim-sistemi)
- [Hız ve Maaliyet Kıyaslaması](#h%C4%B1z-ve-maaliyet-k%C4%B1yaslamas%C4%B1)
- [Cache-Memory Terimleri](#cache-memory-terimleri)
- [Memory with Cache (Önbellekli Bellek) Erişme](#memory-with-cache-%C3%B6nbellekli-bellek-eri%C5%9Fme)
- [Cache-Memory Hesaplamaları](#cache-memory-hesaplamalar%C4%B1)
  - [Cache Uzunluğu](#cache-uzunlu%C4%9Fu)
  - [Hit ve Miss Oranları](#hit-ve-miss-oranlar%C4%B1)
  - [Hit ve Miss Süreleri](#hit-ve-miss-s%C3%BCreleri)
  - [Etkin Bellek Varış Zamanı](#etkin-bellek-var%C4%B1%C5%9F-zaman%C4%B1)
  - [Ortalama Erişim Süresi](#ortalama-eri%C5%9Fim-s%C3%BCresi)
- [Mapping Function](#mapping-function)
  - [Associative Mapping (Birleşik Adresleme)](#associative-mapping-birle%C5%9Fik-adresleme)
  - [Direct Mapping](#direct-mapping)
  - [Set Associative Mapping](#set-associative-mapping)
- [Yerleştirme Algorimalatı](#yerle%C5%9Ftirme-algorimalat%C4%B1)
- [Cache Üzerinde Yazma İşlemleri (Cache Write)](#cache-%C3%BCzerinde-yazma-i%CC%87%C5%9Flemleri-cache-write)
  - [Write Through (Direkt Yazma)](#write-through-direkt-yazma)
  - [Write-Back (Sonradan Yazma)](#write-back-sonradan-yazma)
- [Cache Üzerinde Yazma İşleml Hesaplamaları](#cache-%C3%BCzerinde-yazma-i%CC%87%C5%9Fleml-hesaplamalar%C4%B1)
- [I / O Arabirimi](#i--o-arabirimi)
  - [I/O Temel Görevleri](#io-temel-g%C3%B6revleri)
  - [I/O Blok Diyagramı](#io-blok-diyagram%C4%B1)
  - [Asenkron Data Transfer Yöntemleri](#asenkron-data-transfer-y%C3%B6ntemleri)
    - [Strobe Darbesi](#strobe-darbesi)
  - [El Sıkışma (Hand-Shaking)](#el-s%C4%B1k%C4%B1%C5%9Fma-hand-shaking)
  - [I/0 Etkileşimlier](#i0-etkile%C5%9Fimlier)

<div class="page"/>

## Pipeline

Pipeline durumunda her *cycle*'da birden fazla işlem yapılır.

### Pipeline Hazards

- Structural hazards
  - Aynı işlem birden fazla yapılamaz
  - Örn: Alt alta 2 tane IF olamaz
- Data hazards
  - Register verileri hazırlanmadan kullanılamaz
  - Örn: R1'e 5 atanıyorsa, Memory işlemi yapılmadan R1'e erişilemez
- Control hazards
  - Koşula bağlı bir durum varsa koşul gerçekleştirilmeden işleme sokulamaz

### Pipeline Örneği

![pipeline](../res/bm_pipeline.png)

## Hız Hesaplama

$CycleTime = (IF + n_m \times n_c) \times CPI$

- $CycleTime$, Saat çevrim sayısı
- $IF$, ilk komuttaki IF katı
  - Genelde 1 olur
- $n_m$, Döngüdeki komut sayısı
- $n_c$, Döngüdeki çevrim sayısı
- $CPI$, Her talimat için çevrim sayısı (Cycle per instruction)
  - Genelde 1 olur

<div class="page"/>

## Bellek Yönetim Sistemi

## Hız ve Maaliyet Kıyaslaması

$Register > Cache > Memory > Disk > Tape$

> Kapasite için tam tersi

## Cache-Memory Terimleri

| Terim  | Açıklama                                  |
| ------ | ----------------------------------------- |
| Cache  | Önbellek                                  |
| Memory | Bellek                                    |
| Hit    | Cache üzerinde verinin buluması           |
| Miss   | Hit olmaz ise verinin memory'den alınması |

## Memory with Cache (Önbellekli Bellek) Erişme

`lw $t0 0($t1)` instruction (talimat) için:

- `$t1` $1022_{ten}$ verisini içerir
- $Memory[1022] = 99$ olsun
- Cache varsa:
  - İşlemci $1022_{ten}$ adersini cache belirtir
  - Cache $1022_{ten}$ verisinin kopyası var mı kontrol eder
  - Eğer kopyası varsa (hit):
    - Cache $99$'u okur ve işlemciye gönderir
  - Eğer kopyası yoksa (miss):
    - Cache $1022_{ten}$'u memory'e gönderir
    - Memory $99$ verisini $1022_{ten}$ adresinden okur
    - Memory $99$ verisini cache'e gönderir
    - Cache verisini yeni $99$ verisiyle değiştirir
    - Cache $99$ verisini işlemciye gönderir

<div class="page"/>

## Cache-Memory Hesaplamaları

### Cache Uzunluğu

$S_{catch} = 2 ^ {S_{index}} \times S_{tag} \times S_{line}$

- $S$ Uzunluk (size)

### Hit ve Miss Oranları

$R_{miss} = 1 - R_{hit}$

- $R$: Rate, oran değeri (<1)

### Hit ve Miss Süreleri

$T_{cache} = T_{replace}$

$T_{miss} = T_{replace} + T_{deliver}$

- $T_{miss}$: Miss durumunda harcanan süre (penalty)
- $T_{replace}$: Cache'deki bloğu yeniden yerleştirme süresi
- $T_{deliver}$: Bloğun işlemciye aktarılma süresi

### Etkin Bellek Varış Zamanı

**Etkin bellek varış zamanı** aşağıdaki gibi tanımlanır:

$T_{e} = T_{cache} \times R_{hit} + (1 - R_{hit}) \times T_{memory}$

- $T$: Time, tamamlanması için geçen süre (penalty)
- $R$: Rate, oran

### Ortalama Erişim Süresi

$T_{avg} = T_{hit} \times R_{hit} + T_{miss} \times R_{mis}$

- $T$: Time, tamamlanması için geçen süre (penalty)
- $R$: Rate, oran

<div class="page"/>

## Mapping Function

- Associative mapping (birleşik adresleme)
  - Cache'deki her block memory bloğunu taşıyabilir
  - En hızlı ve en pahalı yöntemdir
- Direct mapping
  - Memory blokları için cache'ye $1$ yer vardır
- Set-associative mapping
  - Memory blokları için cache'de $N$ farklı yer vardır, daha fazla $R_{hit}$ mümkün
- Fully Associative Mapping
  - Memory blokları cache'de **herhangi** bir yere gidebilir

> Set ya da Fully ASsociative Cache'lerde cache bloklarının nereye atılacağı sorun oluşturur

### Associative Mapping (Birleşik Adresleme)

- En hızlı ve en pahalı yöntemdir
- Cache'deki her block memory bloğunu taşıyabilir
- Hem adres hem de içerik bilgisi *mapping table*'da saklanır ve **CAM** tarafından yapılır

### Direct Mapping

- Her memory bloğu için cache'de ayrılan **sadece bir yer** vardır
- Adressleme tablosu (*mapping table*) **RAM** tarafından yapılır
- Adres bitleri 3 parçaya ayrılır
  - Tag
  - Index, kelimenin indeks verisi
  - Offset, index'den kaç adım sonrası olacağını söyler
- Index alanından cache data tablosuna bakalır
  - Valid = 0 ise:
    - Veri cache'e aktarılır
    - Tag verisi aktarılır
    - Valid = 1 yapılır
  - Valid = 1 ise:
    - Tag kontrol edilir, uyuşuyorsa (hit):
      - Offset değeri kadar kaydırılara gerekli kelime alınır
    - Uyuşmuyorsa (miss):
      - Blok, yeni veri ve *tag* ile güncellenir
      - Offset değeri kadar kaydırılara gerekli kelime alınır

### Set Associative Mapping

- Birden fazla alan olduğu için birden fazla yere bakılır
- Döngüsel olarak *Direct Mapping* işlemi yapılıyor denebilir (?)
  - Veriler Hit / Miss döngüsünden sonra gelecektir
  - *Direct Mapping*'de hit edip devam edebilme şansı var
- Mux olmasından dolayı işlemler daha yavaş tamamlanacaktır

<div class="page"/>

## Yerleştirme Algorimalatı

Yeni blok alındığında hangi bloğun yerine koyulacak.

| Algoritma                 | Seçme Koşulu               | Hız                    |
| ------------------------- | -------------------------- | ---------------------- |
| Optimal                   | Uzun süredir kullanılmayan | İleride öğrenilecek 🤔 |
| Least Recently Used (LRU) | Az çağrılan                | Çok zor 😢             |
| First-in First-out (FIFO) | İlk giren                  | Kolay                  |
| Random (RAND)             | Rastgele                   | Aşırı kolay 😅         |

<div class="page"/>

## Cache Üzerinde Yazma İşlemleri (Cache Write)

| Metod        | Cache Yapısı |
| ------------ | ------------ |
| Write-Throug | V Tag Data   |
| Write-Back   | V D Tag Data |

### Write Through (Direkt Yazma)

- `V Tag Data` yapısına sahiptir
- Ld (load) komutu için:
  - Veri cache'de varsa (Hit):
    - Register'a yazılır
  - Yoksa (Miss):
    - Memory'deki bloklar cache alınır (*mem-read*)
    - Cache'deki veriler hesaplanır
      - $V = 1$ yapılır
      - $X_{tag} = X_{Adress} \div S_{data}$
      - $X_{data} = X_{memory}$
- St (store) komutu için:
  - Veri cache'de yoksa (Miss):
    - Memory'deki bloklar cache alınır (*mem-read*)
    - Cache'deki veriler hesaplanır
      - $V = 1$ yapılır
      - $X_{tag} = X_{Adress} \div S_{data}$
      - $X_{data} = X_{memory}$
  - Veri önce cache'e sonra memory'e yazılır (*mem-write*)

> $X$: Değer, $S_{data}$: Blok boyutu (kaç byte),  $X_{memory}$: Memory'deki değer

### Write-Back (Sonradan Yazma)

- `V D Tag Data` yapısına sahiptir
- Ld komutu için ek olarak $d = 0$ işlemi yapılır
- St komutunu işleyiş şekli:
  - Veri cache'de yoksa (Miss):
    - Cache üzerinde $d = 0$ olan blok yoksa:
      - $d = 1$ olan bloklardan biri memory'e yazılır (*mem-write*)
    - Memory'deki bloklar cache alınır (*mem-read*)
    - Cache'deki veriler hesaplanır
      - $V = 1$ ve $d = 0$ yapılır
      - $X_{tag} = X_{Adress} \div S_{data}$
      - $X_{data} = X_{memory}$
  - Veri cache'e yazılır

> $d$: Dirty Cache, cache'deki veri memory'den farklıysa yani cache'e yazma işlemi yapıldıysa 1 değerini alır

<div class="page"/>

## Cache Üzerinde Yazma İşleml Hesaplamaları

- Her *miss* işlemi için 1 **blok** okunur (*mem-read*)
  - $S_{data}$ kadar byte demek
- Her *store* işlemi için 1 **byte** yazılır (*mem-write*)
- Her *dirty cache* işlemi için 1 **blok** yazılır (*mem-write*)

Alttaki sistem içim:

| Write-Through         | Write-Back                 |
| --------------------- | -------------------------- |
| 4 Miss 1 Hit  2 store | 4 Miss 1 Hit 2 dirty cache |
| Toplam read: 8 bytes  | Toplam read: 8 bytes       |
| Toplam write: 2 bytes | Toplam write: 4 bytes      |

![write_throug](../res/bm_write_through.png)

<div class="page"/>

## I / O Arabirimi

### I/O Temel Görevleri

- Eleman adreslerinin kod çözümü
- Komutların kod çözümü
- Çevresel kontrolör için gerekli işaratleri seçer
- Data akşını senkronize eder ve yönlendirir
- Çevresel elemanlar ve CPU veya Bellek arasında transfer hızını ayarlar

### I/O Blok Diyagramı

![io_block_diagram](../res/bm_i0_block_diagram.png)

### Asenkron Data Transfer Yöntemleri

#### Strobe Darbesi

- Transfer meydana gelmek zorunda olduğunda diğer bir birimi göstermek için üretilen işaret
- Her transferi zamanlamada tek bir kontrol işareti kullanılır
- Kaynak veya hedef birim tarafında gönderilebilir

### El Sıkışma (Hand-Shaking)

- Verinin varlığını göstermek için iletilen her veriye eklenen kontrol işaraetidir
- Alıcı birim veriyi kabul ettiğinde bir başka işaret daha gönderir

### I/0 Etkileşimlier

| Etkileşim     | Açıklama                                                                        |
| ------------- | ------------------------------------------------------------------------------- |
| Kaynak Etkili | Verinin alınıp alınmadığı ile ilgilenmez                                        |
| Hedef Etkili  | Verinin bus'a aktarıldığı hakkında bilgi yoktur, el sıkışma yöntemi ile çözülür |
