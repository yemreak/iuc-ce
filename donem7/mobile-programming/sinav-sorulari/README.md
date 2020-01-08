---
description: >-
  Mobile Programming için sınav soruları, çıkmış sorular, çıkmışlar veya önceki senelerde çıkan sorular
---

# 📃 Sınav Soruları \| MP

<!--YPackage.YGitbookIntegration-tarafından-otomatik-oluşturulmuştur-->

- [2018 Bitirme MP.pdf](2018%20Bitirme%20MP.pdf)
- [Final 2018 İÖ MP.pdf](Final%202018%20%C4%B0%C3%96%20MP.pdf)
- [Vize 2015 MP.pdf](Vize%202015%20MP.pdf)
- [Vize 2017 MP.pdf](Vize%202017%20MP.pdf)
- [Vize 20172 MP.pdf](Vize%2020172%20MP.pdf)

<!--YPackage.YGitbookIntegration-tarafından-otomatik-oluşturulmuştur-->

## 📅 Vize 2019 Hakkında

Bir kaç arkadaştan sınavda sorumlu olduğunuz içerik hakkında mailler aldım. Buna istinaden Ara Sınav hakkında bilgilendirmeleri buradan alabilirsiniz.

1. Sınavımız **not açık** olacaktır. Sınavda dağılmayacak şekilde sipirallenmiş veya ciltlenmiş olarak 2 adet kaynak getirebilirsiniz. (Biri defteriniz de olabilir. 2 den fazla olmamalıdır).
2. Sınavda hiçbir elektronik alet -cep telefonu -dijital sözlük kullanamazsınız. Sözlük ihtiyacınız varsa basılı bir sözlük sınava girmeden edininiz.
3. Sınav %50 - %70 oranında test kalanıda klasik soru (kod yazımı şeklinde ) olacaktır.
4. Sorumlu olduğunuz içerik: [Android Developer Fundementals V2](https://google-developer-training.github.io/android-developer-fundamentals-course-concepts-v2/index.html) içerisindeki aşağıdaki chapterlar olacaktır.

- Lesson 1: Build your first app (tüm konular)
- Lesson 2: Activities and intents (tüm konular)
- Lesson 3: Testing, debugging, and using support libraries (tüm konulartemel seviyede bilinmesi yeterli)
- Lesson 4: User interaction (tüm konular )
- Lesson 7: Background tasks ( sadece 7.1 Async task ve loader

> [2019 Mobile Programming Google Classroom](https://classroom.google.com/u/1/c/MTc5NjQ0NTE4OTJa/p/NDM0Nzg2MDkxNzVa/details)

## 📃 Android Developer Fundamentals için Print metodu

[Android Developer Fundamentals (Version 2) — Concepts](https://google-developer-training.github.io/android-developer-fundamentals-course-concepts-v2/) bağlantısındaki sayfaları yazdırmak için:

- Sitede yazdırmak istediğiniz sayfaya girin
- Chrome console'u açın
- Alttaki scripti kopyalayın
- Ardından sayfalarda ilerleyip `print()` yazın

```js
function print() {
    var mywindow = window.open('', 'PRINT', 'height=400,width=600');

    mywindow.document.write('<html><head><title>' + document.title  + '</title>');
    mywindow.document.write('</head><body >');
    mywindow.document.write('<h1>' + document.title  + '</h1>');
    mywindow.document.write($("div.page-inner")[0].innerHTML);
    mywindow.document.write('</body></html>');

    mywindow.document.close(); // necessary for IE >= 10
    mywindow.focus(); // necessary for IE >= 10*/
	mywindow.print()
}
```
