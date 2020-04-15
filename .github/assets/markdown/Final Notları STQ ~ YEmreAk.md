# Software Testing and Quality Final Notları 

<!-- > *Yunus Emre Ak* ile çalışılmıştır. -->

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

- [Web Üzerinde Test İşlemleri](#web-%C3%BCzerinde-test-i%CC%87%C5%9Flemleri)
  - [Functionality Testing (İşlevsellik Testi)](#functionality-testing-i%CC%87%C5%9Flevsellik-testi)
    - [Link Testing](#link-testing)
    - [Forms Testing](#forms-testing)
    - [Cookie Testing (Çerez Testi)](#cookie-testing-%C3%A7erez-testi)
    - [HTML / CSS Testing](#html--css-testing)
  - [Business Workflow Testing (İş Akış Testi)](#business-workflow-testing-i%CC%87%C5%9F-ak%C4%B1%C5%9F-testi)
  - [Web için Usability Testing (Kullanılabilirlik Testi)](#web-i%C3%A7in-usability-testing-kullan%C4%B1labilirlik-testi)
  - [Interface Testing (Arayüz Testi)](#interface-testing-aray%C3%BCz-testi)
  - [Database Testing (Veritabanı testi)](#database-testing-veritaban%C4%B1-testi)
  - [Compability Testing (Uyumluluk Testi)](#compability-testing-uyumluluk-testi)
  - [Security Testing (Korunabilirlik Testi)](#security-testing-korunabilirlik-testi)
  - [Performance Testing (Performans Testi)](#performance-testing-performans-testi)
- [Uygulamalı Web Testleri](#uygulamal%C4%B1-web-testleri)
- [Usability Testing (Kullanılabilirlik Testi)](#usability-testing-kullan%C4%B1labilirlik-testi)
  - [Kullanılabilirlik Testinin Amacı](#kullan%C4%B1labilirlik-testinin-amac%C4%B1)
  - [Kullanılabilirlik Testinin Bileşenleri](#kullan%C4%B1labilirlik-testinin-bile%C5%9Fenleri)
  - [Kullanılabilirlik Testinin Aşamaları](#kullan%C4%B1labilirlik-testinin-a%C5%9Famalar%C4%B1)
  - [Kullanılabilirlik Testinin Faydaları](#kullan%C4%B1labilirlik-testinin-faydalar%C4%B1)
- [Kullanıcı Gereksinimli Yazılım Testleri](#kullan%C4%B1c%C4%B1-gereksinimli-yaz%C4%B1l%C4%B1m-testleri)
  - [Alfa - Beta Testleri](#alfa---beta-testleri)
  - [White-Box ve Black-Box Testleri](#white-box-ve-black-box-testleri)
- [Sistem Entegrasyon Testi (System Integration Test - SIT)](#sistem-entegrasyon-testi-system-integration-test---sit)
  - [Sistem Entegrasyon Tesi Faydaları](#sistem-entegrasyon-tesi-faydalar%C4%B1)
  - [Sistem Entegrasyon Testi Bileşenleri](#sistem-entegrasyon-testi-bile%C5%9Fenleri)
  - [Sistem Entegrasyon Testi Çeşitleri](#sistem-entegrasyon-testi-%C3%A7e%C5%9Fitleri)
- [Otomasyon Testi (Test Automation)](#otomasyon-testi-test-automation)
  - [Otomasyon Testinin Kullanılma Sebepleri](#otomasyon-testinin-kullan%C4%B1lma-sebepleri)
  - [Otomasyon Testinin Dezavantajları](#otomasyon-testinin-dezavantajlar%C4%B1)
  - [Otomasyon Testi hangi Uygulamalara Uygulanmaz](#otomasyon-testi-hangi-uygulamalara-uygulanmaz)
  - [Otomasyon Testi İşleyişi](#otomasyon-testi-i%CC%87%C5%9Fleyi%C5%9Fi)

<div class="page"/>

## Web Üzerinde Test İşlemleri

Web testing, web projesinin canlıya ya da üretim moduna geçmeden önce projedeki *bug*'ların tespitini amaçlar. Kontrollerden bazıları:

- Güvenlik
- Sitenin işlevselliği
- *Network* trafiği
- Kullanıcın rahat erişebilmesi

### Functionality Testing (İşlevsellik Testi)

- İstenilenler **düzgün** yapılıyor mu?
- Üretim dökümanında verilen işlemler **düzgün** yapılabiliyor mu?

#### Link Testing

Site linklerinin kontrolü:

| Link             | Bağlatntı Açıklaması          |
| ---------------- | ----------------------------- |
| *Outgoing Links* | Başka siteye yönlendiren      |
| *Internal Links* | Site içi                      |
| *Anchor Links*   | Sayfa içi                     |
| *MailTo Links*   | Mail uygulamasına yönlendiren |

#### Forms Testing

Form elemanlarının düzgün çalışabilirliğini test eder:

- Veri kontrol scriptlerinin çalışabilirliği
- Varsayılan değerlerin uygun doldurulması
- Girdilerin veritabanında doğru yerlere aktarılması
- Formların düzgün ve okunabilirliği

#### Cookie Testing (Çerez Testi)

Çerezlerin istenildiği gibi çalışamını test eder.

- *Cookie*'lerin süresi dolduğunda veya cache'in temizlenmesi durumunda silinmesi
- *Cookie*'lerin kaldırıldıktan sonra yeniden oluşturulabilmesi

> *Cookie*, siteye ilk giriş yaptığımızda yerel hafızada depolanan ve birkaç günlük süre içerisinde bilgilerimizi tekrardan girmememizi sağlayan kullanıcı bilgilerine verilen isim.

<div class="page"/>

#### HTML / CSS Testing

HTML ve CSS sorunlardından kaynak yavaş yüklenmeyi düzeltmek için yapılan testtir.

- *Syntax* hatalarının kontorlleri
- Okunabilir olan renk şemalarının kontorlleri
- HTML vs CSS kullanımlarının W3C, ECMA, OASIS gibi standartlara uygun olması

> *QTP*, *Selenium* gibi araçlar kullanılır

### Business Workflow Testing (İş Akış Testi)

Web sitesinin belli iş süreçlerini tamamlayabilmesi test edilir.

- Kullanıcının yapacağı işlemlerin baştan aşağı kontrol edilmesi
- Kullanıcının yanlışlıkla yapacağı veya yapmaması gereken işlerin kontrol edilmesi
- Gerekli uyarı ve hata mesajlarının verilmesi

### Web için Usability Testing (Kullanılabilirlik Testi)

Hedef kitleye yakın kişiler tarafından yapılan **hayati önem** taşıyan testlerden biridir.

- Site bileşenlerinin erişimi ve görünebilirliğinin kolay olması
- İçeriklerin anlaşılabilir, sade ve açıklamalı olması
  - Resimler için `alt` metni gibi açıklamalar

> *Chalmark*, *Clicktale* gibi araçlar kullanılabilir.

### Interface Testing (Arayüz Testi)

| Application (Uygulama)                                                         | Web Server (Web sunucusu)                             | Database Server (Veritabanı sunucusu)       |
| ------------------------------------------------------------------------------ | ----------------------------------------------------- | ------------------------------------------- |
| İsteklerin veritabanına ulaşması ve istemci (client) tarafından görüntülenmesi | Sunucuya gelen tüm isteklerin reddedilmeden işlenmesi | Veritabanındaki sorguların düzgün çalışması |
| Hataların sadece yetkili kişilere gözükmesi                                    |

> *AlertFox*, *Ranorex* gibi araçlar kullanılabilir.

<div class="page"/>

### Database Testing (Veritabanı testi)

Web uygulamarında veritabanının öneminden dolayı kritik öneme sahiptir.

- Sorguların gerçekleşmesi sırasında hata olmaması
- Ekleme, silme veya güncelleme işlerinde veri bütünlüğünün korunması
- Sorguların yanıt sürelerinin kontrolü ve gerekirse ince ayarların yapılması
- Veritabınında gelen verilerin doğru işlenmesi

### Compability Testing (Uyumluluk Testi)

Farklı cihazlarda çalışılabilirliği test eder.

- Tarayıcı uyumluluk testi
- Mobil tarayıcı uyumluluk testi

### Security Testing (Korunabilirlik Testi)

- Yetkisiz giriş olup olmadığı
- Hassas dosyaların yetkisiz indirilmemesi
- Oturum kontrolleri
- SSL sertifikasına sahip siteler için şifrelenmiş yapıya yönlendirme

> *Babel Enterprise*, *Cross* gibi araçlar kullanılabilir.

### Performance Testing (Performans Testi)

- Aşırı yükleme durumunda sunucunun ayakta kalabilmesi
- Farklı bağlantı hızlarında sunucunun tepkisi

> *Loodrunner*, *JMeter* gibi araçlar kullanılabilir.

## Uygulamalı Web Testleri

- [Cookie testing]
- [Responsive testing]
- [SQL Injected1], [SQL Injected2]
- [Parking Calculator](https://github.com/JustinBonaccorso/parking-calculator-tests)
- [MindbodyParking](https://github.com/lowfr3q/MindbodyParking)

<div class="page"/>

## Usability Testing (Kullanılabilirlik Testi)

- Arayüzün kullanıcı dostu olup olmadığını test eder.
- Verimlilik, etkililik ve memnuniyet değerlerinin yüksek olması
- Kullanışlı, öğrenilebilir ve son kullanıcı için ne kadar uygun

### Kullanılabilirlik Testinin Amacı

- Beklentilerin karşılanması
- Kullanıma uygun olması
- Kullanıcılara önerilen görevlerin yapılabilitesi
- Kullanıcıların geri bildirimleri ile hareket etmek
- Doğru şekilde ilerliyor olabilimek

### Kullanılabilirlik Testinin Bileşenleri

- Öğrenilebilirlik
- Verimlilik
- Hatırlanabilirlik
- Hatalar
- Memnuniyet

### Kullanılabilirlik Testinin Aşamaları

| Test Planı Geliştirme              | Testing Gerçekleştirilmesi                            | Verilerin Analizi (Uzman Analizi)                           | Raporlama              |
| ---------------------------------- | ----------------------------------------------------- | ----------------------------------------------------------- | ---------------------- |
| Amaca uygun senarya                | Uygun ortamda testlerin yapılması                     | Uzmanları test sonuçlarını gözden geçirir                   | Arkaplan özeti         |
| Hedef kitlenin belirlenesi         | Kullanıcıyla etkileşimde bulunan Gerilla test tekniği | Kullanılabilirlik sorunlara yönelik beyin fırtınası yapılır | Metodoloji             |
| Araştırma hedefleri ve senaryoları |                                                       |                                                             | Test Sonuçları         |
| Kimlerle test edilebileceği        |                                                       |                                                             | Bulguler ve tavsiyeler |

<!--
| Aşamalar                          | Adım1                                     | Adım2                                                       | Adım3                              | Adım4                       |
| --------------------------------- | ----------------------------------------- | ----------------------------------------------------------- | ---------------------------------- | --------------------------- |
| Test Planı Geliştirme             | Amaca uygun senarya                       | Hedef kitlenin belirlenesi                                  | Araştırma hedefleri ve senaryoları | Kimlerle test edilebileceği |
| Testing Gerçekleştirilmesi        | Uygun ortamda testlerin yapılması         | Kullanıcıyla etkileşimde bulunan Gerilla test tekniği       |
| Verilerin Analizi (Uzman Analizi) | Uzmanları test sonuçlarını gözden geçirir | Kullanılabilirlik sorunlara yönelik beyin fırtınası yapılır |
| Raporlama                         | Arkaplan özeti                            | Metodoloji                                                  | Test Sonuçları                     | Bulguler ve tavsiyeler      |
-->

### Kullanılabilirlik Testinin Faydaları

- Nasıl tasarlanması gerektiği hakkında fikir verir (yolumuzu biliriz)
- Harcanan vaktin ve enerjinin doğru yere odaklanmasını sağlar (istenmeyen şeyleri yapmayız)
- Kullanıcının belli işlemindeki performansını ölçer ve ona odaklı hareket edilir (uzun sürenler kolaylaştırılır)
- Memnuniyeti ölçer (Beğenilmeyen uygulamaya neden devam edesin)

<div class="page"/>

## Kullanıcı Gereksinimli Yazılım Testleri

- Kullanıcı tarafından test edilir
- Gereksinimlerin karşılanıp karşılanmadığına incelenir
- Odak noktası geliştirme ekibi değil, ekip dışındakilerdir
- Sistem testlerinde olduğu gibi amaç kusur bulmak değildir.

### Alfa - Beta Testleri

| Alfa Testi                                           | Beta Testi                                         |
| ---------------------------------------------------- | -------------------------------------------------- |
| White-Box Test                                       | Black-Box Test                                     |
| Organizasyon içerisinde (bağımsız ekiple) ele alınır | Organizasyon dışarısında (topluma açık) ele alınır |
| *Tester* geliştirme merkezine gelir                  | Kullanıcılara dağıtıldığından herkes *tester*'dır  |
| Geliştirici ve Test Ekibi tarafından yapılır         | Gerçek müşteriler tarafından yapılır               |
| Gereksinimleri karşılamasına odaklanır               | Pazarlanabilirliğine odaklanılır                   |

![alpha_beta_Testing](../res/sqt_alfabeta.png)

### White-Box ve Black-Box Testleri

| White-Box Test                          | Black-Box Test                                   |
| --------------------------------------- | ------------------------------------------------ |
| Koda ve tasarıma odaklanır              | Gereksinim ve fonksiyonlliğe odaklanır           |
| Sorunlu kısmı bulmak için kod incelenir | Uygun veri seçimi ve seçime olan tepki incelenir |

<div class="page"/>

## Sistem Entegrasyon Testi (System Integration Test - SIT)

- Sistemin belirtilen şarlara uygunluğu kontrol eden bir yazılım testidir
- Sistemin modülleri arasındaki etkileşimi doğrulamak için yapılır
- Tüm sistemin davranışını doğrulamak için donanım veya yazılım entegrasyonuyla yapılır

![system ingragration testing](../res/stq_sit.png)

### Sistem Entegrasyon Tesi Faydaları

- Kusurların erken tespiti
- Modüllerin bireysel olarak kabul edilebilirliği hakkında erken geri dönüş
- Hata düzeltmesi esnektir, geliştirme ile aynı anda yapılabilir
- Entegrasyon sırasında meydana gelen hataları düzeltilmesini sağlar

### Sistem Entegrasyon Testi Bileşenleri

| Intra-System Testing                                      | Inter-System Testing                           | Pairwise Testing                                                                                |
| --------------------------------------------------------- | ---------------------------------------------- | ----------------------------------------------------------------------------------------------- |
| Birleşik sistem kurmak amaçlı modülleri bir araya getirir | Bağımsız test edilen sistemlerin arayüzlenmesi | Tüm sistemde birbirine bağlı iki alt sistemi inceler                                            |
| Düşük düzeyde bir test                                    | Yüksek seviyeli bir test                       | Diğerleri çalışıyor varsayımı ile test edilen iki sistemin, beraber iyi çalışabilmesini amaçlar |

<div class="page"/>

### Sistem Entegrasyon Testi Çeşitleri

| Big Bang                          | Top-Down                                                             | Bottom-Up                                                | Sandwich/Hybrid                                      |
| --------------------------------- | -------------------------------------------------------------------- | -------------------------------------------------------- | ---------------------------------------------------- |
| En yaygını                        | Modüller arasında geçiş yapılırken hatalı olanın bulunmasını amaçlar | Unit test ile beraber kullanılır                         | Hem Top-Down hem Bottom-Up yapısı                    |
| Tüm modülleri bir arada test eder | Üst modülden alt mödüle ilerler (Genelden bireye)                    | Unit testten geçirilerek yukarı doğru ilerler            | Modülleri gruplara ayırabilme                        |
| Ortak doğru çalışmayı test eder   | Her bir testin başarılı şekilde gerçekleşmesi gerekir                | Her bir test başarılı bir şekilde gerçekleştirilmedir    | Gruplanmayanların ayrı bir şekilde test edilebilmesi |
| Bireysel doğruluk test edilmez    | Modül ağacın en altındaysa kendi içeirsinde test edilir              | Ağacın en tepesinde ise komple sistem yapısı test edilir |

![sit2](../res/stq_sit2.png)

<div class="page"/>

## Otomasyon Testi (Test Automation)

- Manuel yapılan işlerin otomatize edilmiş halidir
- Tekrar tekrar yapılabilir ve şekillendirilebilir

### Otomasyon Testinin Kullanılma Sebepleri

- El ile yapılan işlemlerin sayısını azaltmak (vakit nakittir)
- İnsana olan gereksinimi kaldırmak (insan = maaliyet)
- Manuel'e göre daha hızlı işlemlerin yapılması
- İnsandan kaynaklı hataların önüne geçme

### Otomasyon Testinin Dezavantajları

- Ek teknolojilere gereksinim duyar
- Ekibin testleri geliştirebilme ve uygulama potansiyelinin olması lazım
- Manuel'e nazaran daha karmaşık
- Manule'e ek farklı hatalar meydana gelebilir

### Otomasyon Testi hangi Uygulamalara Uygulanmaz

- Yeni tasarlanmış ve daha önceden manuel test edilmemiş
- Sık sık yapısı değişen
- Geçici uygulamalara (ad hoc basis)

### Otomasyon Testi İşleyişi

- Test araçlarının seçimi
- Test edilecek alanın tanımlanması
- Testin tasarlanması ve geliştirilmesi
- Testin gerçekleştirilmesi
- Bakım çalışmaları

[Cookie testing]: https://www.guru99.com/cookie-testing-tutorial-with-sample-test-cases.html
[Responsive testing]: https://search.google.com/test/mobile-friendly
[SQL Injected1]: https://tech.io/playgrounds/154/sql-injection-demo/sql-injection-2
[SQL Injected2]: https://sqlzoo.net/hack/
