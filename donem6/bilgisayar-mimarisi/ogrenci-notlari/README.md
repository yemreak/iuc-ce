---
description: >-
  Bilgisayar Mimarisi için öğrenci notları, el yazıları, tutulmuş veya alınmış notlar
---

# 📕 Öğrenci Notları \| BM

## 📂 Dosyalar

<!--YPackage.YGitbookIntegration-tarafından-otomatik-oluşturulmuştur-->

- [Final 2018 Notu BM ~ YEmreAk.pdf](Final%202018%20Notu%20BM%20~%20YEmreAk.pdf)
- [Vize 2018 Notları BM ~ YEmreAk.pdf](Vize%202018%20Notlar%C4%B1%20BM%20~%20YEmreAk.pdf)

<!--YPackage.YGitbookIntegration-tarafından-otomatik-oluşturulmuştur-->

## ⭐ 2019 Proje Ödevi

### 🗽 Açıklama

Proje ödevinin PDF'ine [buradan](../../../res/2019_bilgisayar_mimarisi_proje.pdf) ulaşabilirsin.

- Proje için hazırladığımız [PDF](../../../res/16BitMipsVHDL.pdf)'e ve [repository][16bit Mips VHDL - Repo]'e yazılara tıklayarak erişebilirsin
- Grup sayısı 5 kişiliktir
- Son teslim tarihi: 20 Mayıs 2019 Pazartesi
- Proje'yi yapabilmek için **XILINX ISE Design Studio kurulumu** yapmanız gerekmekte

### 🌃 XILINX ISE Design Studio

- Resmi sitesinde indirmek için [buraya][XILINX ISE Design Studio] tıklayabilirsin
  - Username: `yemreak`
  - Password: `yemreak.com1`
- **XILINX ISE Design Studio**'yu direkt olarak [buradan][XILINX ISE Design Studio - Direct] indirebilirsin.
- **Drive** üzerinden indirmek için [buraya][XILINX ISE Design Studio - Drive] bakabilirsin.
- `VirtualBox host only adaptor disappeared (Interface (‘VirtualBox Host-Only Ethernet Adapter’) is not a Host-Only Adapter interface (VERR_INTERNAL_ERROR) SOLVED` hatası için [buraya][Hata Çözümü 1] bakabilirsin.

### 🎌 XILINX Kullanımı

Hocanın hazırlamış olduğu videolar:

- [XILINX ile VHDL PROGRAMLAMA! - Full Adder (Tam Toplayıcı) Tasarımı #1](https://www.youtube.com/watch?v=-SZuTT3xa18)
- [XILINX ile VHDL PROGRAMLAMA! - Full Adder (Tam Toplayıcı) Tasarımı #2](https://www.youtube.com/watch?v=H7jihUQz-Io)
- [XILINX ile VHDL PROGRAMLAMA! - Full Adder (Tam Toplayıcı) Tasarımı #3](https://www.youtube.com/watch?v=Sw5ktjHl1zc)

> Alttaki bilgilerde yapılacak işlermler özetlenmiştir.

#### ✨ Proje Oluşturma

- `New Project`
- Top-level source type: `HDL`
- `XST`, `ISIM`, Preffered Language: `VHDL`

#### 🚧 Proje İşlemleri

- `New Source` > `VHDL_module`
- Modülü boş bırakın devam edin.

#### 🕹️ Simüle Etme

- Similasyon oluşturmak için [buraya][XILINX ISE - Simulation] bakabilirsin.
  - `Start with a semantic of the top-level block`
- Simülasyona veri girişi için [buraya][ISIM Simulator] bakabailirsin.
  - `restart` Yeniden başlatma
  - `put <pbje_ismi> <değer>` Veri atama
    - Örn: `put tt_g1 0`
  - `run all` Hepsini çalıştırma

#### 🎁 Teslim Şekli

- Similasyon sonuçları raporlanacak ve pdf haline getirilecek
- Verilen *instruction*'ların hepsi gerçekleştirilecek
- Sonuçlar similatörde gösterilecek
- PDF ile `.vhd` uzantılı kaynak kodlarını sisteme yüklenecek
  - Aksis - Döküman paylaşımı - Bilgisayar Mimarisi - Proje

### 🔗 Faydalı Bağlantılar

- [16bit Mips VHDL]
- [MIPS-Processor-VHDL - Github]
- [PiJoules/MIPS-processor]

[XILINX ISE Design Studio]: https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/design-tools.html
[XILINX ISE Design Studio - Direct]: https://xilinx-ax-dl.entitlenow.com/dl/ul/2018/02/21/R209898474/Xilinx_ISE_S6_Win10_14.7_ISE_VMs_0206_1.zip/70f417f0787735862bdf9e9e3107e2af/5CC73BF4?akdm=0&filename=Xilinx_ISE_S6_Win10_14.7_ISE_VMs_0206_1.zip
[XILINX ISE Design Studio - Drive]: https://drive.google.com/open?id=1-4j-ZBZmA5axu2G3ebxcITROWsR2IUny
[XILINX ISE - Simulation]: https://youtu.be/H7jihUQz-Io?t=637
[ISIM Simulator]: https://youtu.be/Sw5ktjHl1zc?t=576
[Hata Çözümü 1]: https://darrenoneill.eu/?p=627

[16bit Mips VHDL]: https://www.fpga4student.com/2017/09/vhdl-code-for-mips-processor.html
[MIPS-Processor-VHDL - Github]: https://github.com/cm4233/MIPS-Processor-VHDL
[PiJoules/MIPS-processor]: https://github.com/PiJoules/MIPS-processor

[16bit Mips VHDL - Repo]: https://github.com/yedhrab/16BitMipsVHDL


## 🔗 Faydalı Siteler

- [MIPS Visual]

[MIPS Visual]: http://www3.ntu.edu.sg/home/smitha/FYP_Gerald/index.html
