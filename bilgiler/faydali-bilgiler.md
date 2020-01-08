# 📗 Faydalı Bilgiler

## 👨‍🎓 CV Hazırlama

- CV'ni tasarım sitesi olan [canva][Canva]'dan hazırlayabilirsin

## 📶 Eduroamda Çalışan VPN

- [Psiphon](https://psiphon3.com/en/index.html) ile VPN kullanabilirsin.

## 🌞 Yaz Okulu

| Okul        | Açıklanma Tarihi |
| ----------- | ---------------- |
| Marmara Üni | 26 Haziran 2019  |

### ⏯ Yaz Okulu Sürecinin İşleyişi

Bizim fakültenin dekanlığının en son almış olduğu karara göre; hangi yıl yaz okuluna başvuracaksan, başvuracağın üniversitenin ilgili bölümünün bir önceki yıla ait yerleştirme puanı, bizim bölümün puanından yüksekse kabul ediliyor. Dersin dilinin İngilizce Türkçe olması, yerel kredi veya akts kredisinden herhangi birisine eşit veya fazla krediye sahip olması ve içeriğinin, yani konularının en az %70 tutuyor olması gerekiyor bizim bölümdeki ilgili dersle. Selçuk Sevgen hoca bakıyor o içeriğin ve kredinin uygun olduğuna dair onaylama işine. Önce gidip yaz okuluna başvurmak istediğin üniversitenin ilgili derslerinin içeriklerini o üniversitenin bölüm sitesinden çıktısını alıp, oranın fakültesinin veya bölümünün yetkili birine imzalattırıp getiriyorsun bizim öğrenci işlerine, o onaylı imzalı içeriklerin olduğu evraklarla, bir de dilekçe yazıyorsun, açıkça belirterek, hangi üniversiteden, bölümden hangi koda ve isme sahip dersi, anlatım dilinin uygunluğunu da belirterek, bizim bölümdeki hangi koda, isme ve kredi sayısına sahip dersin yerine almak istediğini belirterek dilekçe yazıyorsun, öğrenci işlerimize veriyorsun. Sonra Selçuk hocanın önüne geliyor o evrak, bir de haftanın belli bir günü var dekanlık kurulu toplanıyor, hocaların onay verdiği evrakları imzalıyor galiba. O kuruldan karar çıkıyor her hafta, sonra sen o kurul kararının olduğu e imzalı kağıdı bizim öğrenci işlerinden alıyorsun, başvuracağın üniversiteye gidip başvuruyorsun, zaten bizim öğrenci işleri e imzalı kurul kararının olduğu kağıt için, ilgili okulun öğrenci işleri daire başkanlığına yazı yazıyor, e imzalı olduğunu karşı tarafın teyit etmesi için. Her neyse işte artık sen ilgili okula başvuruyorsun, kabul edilirse paranı yatırıp dersine de gidiyorsun yazın sınavlarından hangi harf notunu aldığını falan yaz okulunun sonuçlarının açıklanmasından sonra karşı okul, bizim okula yazı yazıyor. 

Bu arada her üniversitenin, ilgili bölümlerinin mesela geçen yıl yani 2018 yerleştirme taban sıralamasına da zaten internetten iki üç siteden bakıp emin olabilirsiniz ya da ösym nin sitesinden bakabilirsiniz.

Bir de bazen aynı üniversitenin mesela Ankara üniversitesinin hem ingilizce bilgisayar mühendisliği bölümü var hem de Türkçe. İkisinin de taban sıralaması farklı oluyor, ilgili koda sahip dersi hangi bölüm açıyorsa o bölümün taban puanına bakacaksınız, bizim bölümün geçen yılki taban puanıyla karşılaştıracaksınız.

> Alıntıdır ~ Hüseyin Karademir

## 🚗 Yatay Geçiş Notları

### 🎇 İTÜ'ye Yatay Geçiş

- [Yatay geçiş süreci][Yatay geçiş Süreci - İTÜ]
- [Çalışma yeri](http://www.testatolyesi.com/download_1_18.htm)

> Türkçe veya %30 İngilizce programlarından 5.yarıyıl için %100 İngilizce programlarına  yatay geçiş yapılamaz.

[Canva]: https://www.canva.com/
[Yatay geçiş Süreci - İTÜ]: http://www.sis.itu.edu.tr/tr/akademik_takvim/takvim2020/ycy_takvim.htm

## 👨‍💻 Aksisc Anketlerini Otomatik Dolduran Script

- [Aksisc](https://aksis.istanbulc.edu.tr/) -> [OBS](http://obs.istanbulc.edu.tr/) -> Öğrenim Bilgileri -> [Sınav Sonuçları](http://obs.istanbulc.edu.tr/OgrenimBilgileri/SinavSonuclariVeNotlar/Index) kısmına gelin.
- Sağ tıklayıp '**Sayfa Kaynağını Görüntüle**' / '**Inspect**' seçeneğini seçin.
- Bu seçenekler yoksa **F12** tuşuna basabilirsiniz.
- Çıkan ekrandan '**Console**' kısmını seçin.
- Konsola altta verdiğim kodu yapıştırın.

```js
for(let i=0; i<$(".btn-danger").length; i++){
    setTimeout(function(){
        $(".btn-danger:eq(0)").click();
        setTimeout(function(){
            $('.panel-body input[type=radio]:nth-child(5)').prop('checked',true);
            $('#soru_CevapMetin').val('skip');
            $(".panel-footer > a").click();
        }, 2000);
    }, 5000*i);
}
```
