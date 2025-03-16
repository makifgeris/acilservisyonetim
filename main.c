#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LISTE 100
#define MAX_HASTA 100
#define MAX_DOKTOR 100

// Hasta ve doktor yap�lar�
typedef struct {
    char kimlikNo[12];
    char adSoyad[50];
    int hastaNumarasi;
    char sikayet[255];
    char teshis[255];
} Hasta;

typedef struct {
    char isim[50];
    char kullanici[20];
    char sifre[20];
} Doktor;

Hasta hastalar[MAX_HASTA];
Doktor doktorlar[MAX_DOKTOR];
int hastaIndex = 0;
int doktorIndex = 0;

typedef struct {
    char isim[50];
} Ilac;

Ilac ilaclar[MAX_LISTE];
Ilac yazilanIlaclar[MAX_LISTE];
int ilacIndex = 0;
int yazilanIlacIndex = 0;

// Fonksiyon bildirimleri
void girisEkrani();
void yoneticiPaneli();
void doktorPaneli(const char* doktorAdi);
void doktorEkle();
void hastaEkle();
void teshisGir();
void hastaListele();
void ilacEkle();
void receteOlustur();
void HL7MesajHazirla(Hasta h, char *mesaj);
void tarihAl(char *buffer);
void ilacListesi();

int main(void) {
    girisEkrani();
    return 0;
}

void girisEkrani() {
    char kullanici[20];
    char sifre[20];

    while (1) {
        printf("Kullanici Adi: ");
        scanf("%s", kullanici); // Boşlukları engellemek için direk %s kullandık.

        printf("Sifre: ");
        scanf("%s", sifre); // Şifre girişini düzgün almak için boşlukları engelledik.

        if (strcmp(kullanici, "admin") == 0 && strcmp(sifre, "admin123") == 0) {
            yoneticiPaneli();
        } else {
            int bulundu = 0;
            for (int i = 0; i < doktorIndex; i++) {
                if (strcmp(doktorlar[i].kullanici, kullanici) == 0 && strcmp(doktorlar[i].sifre, sifre) == 0) {
                    doktorPaneli(doktorlar[i].isim);
                    bulundu = 1;
                    break;
                }
            }
            if (!bulundu) {
                printf("Hatali giris! Tekrar deneyin.\n");
            }
        }
    }
}

void yoneticiPaneli() {
    int secim;
    do {
        printf("\n--- Yonetici Paneli ---\n");
        printf("1. Doktor Ekle\n");
        printf("2. Hasta Ekle\n");
        printf("3. Ilac Ekle\n");
        printf("4. Ana Menu\n");
        printf("Secim: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1: doktorEkle(); break;
            case 2: hastaEkle(); break;
            case 3: ilacEkle(); break;
            case 4:
                printf("Ana menuye donuluyor...\n");
                return; // Ana menüye dönmek için return kullanıldı.
            default:
                printf("Gecersiz giris! Tekrar deneyin.\n");
        }
    } while (1);
}

void doktorPaneli(const char* doktorAdi) {
    printf("Hos geldiniz, Dr. %s\n", doktorAdi);
    int secim;
    do {
        printf("\n--- Doktor Paneli ---\n");
        printf("1. Hastalari Listele\n");
        printf("2. Hasta Ekle\n");
        printf("3. Teshis Gir\n");
        printf("4. Recete Yaz\n");
        printf("5. Ana Menu\n");
        printf("Secim: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1: hastaListele(); break;
            case 2: hastaEkle(); break;
            case 3: teshisGir(); break;
            case 4: receteOlustur(); break;
            case 5:
                printf("Ana menuye donuluyor...\n");
                return; // Ana menüye dönüş için return
            default:
                printf("Gecersiz secim! Tekrar deneyin.\n");
        }
    } while (1);
}


void doktorEkle() {
    Doktor d;
    printf("Doktor Adi: ");
    scanf(" %[^\n]", d.isim); // D�ZELT�LD�
    printf("Kullanici Adi: ");
    scanf("%s", d.kullanici);
    printf("Sifre: ");
    scanf("%s", d.sifre);
    
    doktorlar[doktorIndex++] = d;
    printf("Doktor %s basariyla eklendi.\n", d.isim);
}

void hastaEkle() {
    Hasta h;
    printf("TC Kimlik No: ");
    scanf("%s", h.kimlikNo);
    printf("Hasta Adi: ");
    scanf(" %[^\n]", h.adSoyad); // D�ZELT�LD�
    h.hastaNumarasi = hastaIndex + 1;
    hastalar[hastaIndex++] = h;
}

void hastaListele() {
    printf("--- Hasta Listesi ---\n");
    for (int i = 0; i < hastaIndex; i++) {
        printf("Hasta No: %d, Ad: %s, TC: %s\n", hastalar[i].hastaNumarasi, hastalar[i].adSoyad, hastalar[i].kimlikNo);
    }
}

void ilacEkle() {
    printf("Ilac Adi: ");
    scanf(" %[^\n]", ilaclar[ilacIndex].isim); // D�ZELT�LD�
    ilacIndex++;
    printf("Ilac basariyla eklendi.\n");
}

void teshisGir() {
    int hastaNo;
    printf("Teshis girilecek hasta numarasi: ");
    scanf("%d", &hastaNo);

    for (int i = 0; i < hastaIndex; i++) {
        if (hastalar[i].hastaNumarasi == hastaNo) {
            printf("Teshis: ");
            scanf(" %[^\n]", hastalar[i].teshis); // D�ZELT�LD�
            printf("Teshis eklendi.\n");
            return;
        }
    }
    printf("Hasta bulunamadi.\n");
}

void receteOlustur() {
    int hastaNo;
    printf("Recete yazilacak hasta numarasi: ");
    scanf("%d", &hastaNo);

    for (int i = 0; i < hastaIndex; i++) {
        if (hastalar[i].hastaNumarasi == hastaNo) {
            printf("Ilac adi: ");
            scanf(" %[^\n]", yazilanIlaclar[yazilanIlacIndex].isim); // D�ZELT�LD�
            yazilanIlacIndex++;
            printf("Recete olusturuldu.\n");
            return;
        }
    }
    printf("Hasta bulunamadi.\n");
}
