# Acil Servis Sistemi

Bu proje, bir hastane yönetim sistemini oluşturmayı amaçlamaktadır. Sistem, hastane içerisinde hasta ve doktor kayıtlarını tutar, teşhis koyma sürecini yönetir, reçete oluşturur ve HL7 formatında mesajlar üretir.

## Özellikler
- **Yönetici Paneli**: Doktor ve hasta kayıt işlemlerini yönetme.
- **Doktor Paneli**: Hastaları listeleme, teşhis koyma ve reçete yazma işlemleri.
- **Hasta Yönetimi**: Hasta bilgilerini kayıt altına alma ve güncelleme.
- **İlaç Yönetimi**: Sisteme yeni ilaç ekleme ve reçetelere ilaç ekleyebilme.
- **HL7 Mesaj Desteği**: Hasta kayıt işlemleri için HL7 formatında mesaj oluşturma.

## Kullanılan Teknolojiler
- **Programlama Dili**: C
- **Kütüphaneler**: stdio.h, stdlib.h, time.h, string.h

## Kurulum
1. Bilgisayarınızda bir C derleyicisinin (örneğin GCC) kurulu olduğundan emin olun.
2. Proje dosyasını indirin.
3. Terminal veya komut satırını açarak aşağıdaki komutu kullanarak projeyi derleyin:
   ```sh
   gcc -o main main.c
   ```
4. Programı çalıştırmak için şu komutu girin:
   ```sh
   ./main
   ```

## Kullanım
### Giriş Ekranı
- **Admin Girişi**: Kullanıcı Adı: `admin`, Parola: `admin123`
- **Doktor Girişi**: Doktorlar, kendi kullanıcı adı ve şifreleriyle sisteme giriş yapabilir.

### Admin İşlemleri
- Doktor ekleyebilir ve bilgilerini yönetebilir.
- Hasta kaydı yapabilir.
- Sisteme yeni ilaç ekleyebilir.

### Doktor İşlemleri
- Kayıtlı hastaları listeleyebilir.
- Yeni hasta kaydı yapabilir.
- Hastalara teşhis koyabilir.
- Reçete yazabilir.

## Fonksiyonlar
| Fonksiyon              | Açıklama                                     |
|------------------------|----------------------------------------------|
| `girisEkrani()`        | Kullanıcı giriş ekranını yönetir.            |
| `yoneticiPaneli()`     | Yönetici işlemlerini yönetir.                |
| `doktorPaneli()`       | Doktor işlemlerini yönetir.                  |
| `doktorEkle()`         | Yeni doktor kaydı yapar.                     |
| `hastaEkle()`          | Yeni hasta kaydı yapar.                      |
| `teshisGir()`          | Hastalara teşhis koyar.                      |
| `hastaListele()`       | Kayıtlı hastaları listeler.                  |
| `ilacEkle()`           | Yeni ilaç ekler.                             |
| `receteOlustur()`      | Hastaya reçete yazar.                        |
| `ilacListesi()`        | Kayıtlı ilaçları listeler.                   |
| `HL7mesajHazirla()`    | Hasta bilgilerine göre HL7 mesajı oluşturur. |
| `tarihAl()`            | Sistemin mevcut zamanını alır.               |


## HL7 Sistemi Gösterimi
HL7 (Health Level 7), sağlık bilişimi alanında yaygın olarak kullanılan bir veri değişim standardıdır. Hasta bilgileri, teşhisler ve tedavi süreçleri hakkında veri paylaşımını kolaylaştırmak için geliştirilmiştir. HL7 mesajları, belirli veri segmentlerinden oluşur ve her segment, farklı bir bilgi içerir. Örnek bir HL7 mesajı aşağıda verilmiştir:

```
MSH|^~\&|HastaneSistemi|HastaVeriMerkezi|LAB|Hastane|20250314||ADT^A01|MSG00001|P|2.5
PID|1||123456^^^HastaneMRN||Mehmet^Korul||19870205|M|||İzmir, Türkiye||||||
PV1|1|I|Servis1^Oda3^Yatak2||||12345^Dr. Korul|||||||||||20250316
```
Yukarıdaki mesaj, bir hastanın hastaneye kabul işlemi için oluşturulmuş bir ADT (Admit, Discharge, Transfer) mesajıdır.

## Gelecek Güncellemeler
- Doktor-Hasta geçmişi kayıtlarının tutulması
- Veritabanıyla entegre edilmesi
