#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// Resim fonksiyonu
void resim() {
    printf("      ||   || ||||||||  |||||||  |||||||| |||||||  ||       |||||    || |||     ||     \n"); 
    printf("      ||   || ||    ||  ||       ||       ||       ||       ||   ||     || ||   || \n");
    printf("      ||||||| ||    ||  |||||||  || ||||| |||||||  ||       ||    || || ||  ||  ||       \n");
    printf("      ||   || ||    ||       ||  ||    || ||       ||       ||   ||  || ||   || ||   \n");  
    printf("      ||   || ||||||||  |||||||  |||||||| |||||||  |||||||  |||||    || ||    ||||           \n"); 
    printf("                                        \n");
    printf("                                        \n");
}

// Toplama fonksiyonu
float topla(float sepet1, float sepet2, float sepet3, float sepet4, float sepet5) {
    float tutar;
    tutar = sepet1 + sepet2 + sepet3 + sepet4 + sepet5;
    return tutar;
}

// Birinci Struct
struct kullanici {
    char ad[15], soyad[15], sifre[20], sifre2[20];
} k1;

// İkinci Struct
struct {
    int numara, secilenMasa; 
} m1;

// Üçüncü Struct
struct sicakicecekler {
    char icecek[30];
    float tutar;
} u1, u2, u3, u4, u5;

// Dördüncü Struct
struct sogukicecekler {
    char icecek[30];
    float tutar;
} s1, s2, s3, s4, s5;

// Beşinci Struct
struct kahvalti {
    char yemek[30];
    float tutar;
} o1, o2, o3, o4, o5;

int main() { 
          
    // Ana menü
    int dizi[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     
    int temelmenu, anamenu, menu, veri, tercih, masa, islem, anamenudonus;
    float sepet1 = 0, sepet2 = 0, sepet3 = 0, sepet4 = 0, sepet5 = 0, tutar;
  
    FILE *dosya;
    dosya = fopen("restoran.txt", "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi!");
        exit(1);
    }
    fscanf(dosya, "%*s %s", k1.ad);
    fscanf(dosya, "%*s %s", k1.soyad);
    fscanf(dosya, "%*s %s", k1.sifre);
    fclose(dosya);

    resim();

    printf("\t\t1-HESAP OLUSTUR #\n");
    printf("\t\t2-GIRIS YAP     #\n");
    printf("\t\t3-CIKIS         #\n\t\t");
    scanf("%d", &veri);
hesap:
    // Hesap oluştur
    if (veri == 1) {
        printf("\t\tAdinizi Giriniz: ");
        scanf("%s", k1.ad);
        printf("\t\tSoyadinizi Giriniz: ");
        scanf("%s", k1.soyad);
        printf("\t\tSifre Giriniz: ");
        scanf("%s", k1.sifre);
        printf("\t\tSifreyi Tekrar Giriniz: ");
        scanf("%s", k1.sifre2);

        // Dosyaya yazma
        dosya = fopen("restoran.txt", "w");
        if (dosya == NULL) {
            printf("Dosya acilamadi!");
            exit(1);
        }
        fprintf(dosya, "Ad: %s\n", k1.ad);
        fprintf(dosya, "Soyad: %s\n", k1.soyad);
        fprintf(dosya, "Sifre: %s\n", k1.sifre);
        fclose(dosya);

        printf("\t\tHesap basariyla olusturuldu!\n");
    } 
    // Giriş yap
    else if (veri == 2) {
    char girilenAd[15], girilenSifre[20];
    printf("\t\tAdinizi Giriniz: ");
    scanf("%s", girilenAd);
    printf("\t\tSifre Giriniz: ");
    scanf("%s", girilenSifre);

    // Dosyadan okuma ve kontrol
    if (strcmp(girilenAd, k1.ad) == 0 && strcmp(girilenSifre, k1.sifre) == 0) {
        printf("\t\tHosgeldin %s %s\n", k1.ad, k1.soyad);
        goto temelmenu; // Hoşgeldin mesajı sadece burada
    } else {
        printf("\t\tHatali giris!\n");
        goto hesap;
    }
}
    // Çıkış
    else if (veri == 3) {
        printf("Cikis yapiliyor...\n");
        exit(0);
    }
    
    
    while (1) {
        system("cls");
        resim();
        temelmenu:
        printf("1-Masa Listele\n2-Menu\n3-Sepet\n4-Cikis\n");
        printf("Isleminizi seciniz: ");
        scanf("%d", &islem);

        switch (islem) {
        // Masalar
        case 1:
            printf("Masalar: ");
            for (int i = 0; i < 10; i++) {
                printf("%d ", dizi[i]);
            }
            printf("\n");
            printf("Lutfen bir masa numarasi secin: ");
            scanf("%d", &m1.secilenMasa);

            if (m1.secilenMasa >= 1 && m1.secilenMasa <= 10) {
                printf("Masa %d secildi.\n", m1.secilenMasa);
            } else {
                printf("Gecersiz masa numarasi!\n");
            }
            goto temelmenu;
        
        // Menu
        case 2:
        menu:
            system("cls");
            printf("Menu:\n");
            printf("1. Sicak Icecekler\n2. Soguk Icecekler\n3. Kahvalti\n4. Sandvicler\n5. Tatlilar\n6. Ana Menu\n");
            printf("Isleminizi secin: ");
            scanf("%d", &islem);

            switch (islem) {
            // Sicak Icecekler
            case 1:
                while (1) {
                    system("cls");
                    int islem, adet1;
                    struct sicakicecekler u1 = {"1-Espresso", 25};
                    struct sicakicecekler u2 = {"2-Americano", 20};
                    struct sicakicecekler u3 = {"3-Filtre Kahve", 20};
                    struct sicakicecekler u4 = {"4-Macchiato", 22};
                    struct sicakicecekler u5 = {"5-Cappuccino", 22};

                    printf("\n");
                    printf("%s\n%s\n%s\n%s\n%s\n", u1.icecek, u2.icecek, u3.icecek, u4.icecek, u5.icecek);
                    printf("6. Geri\n");
                    printf("*\n");
                    printf("Isleminizi seciniz: ");
                    scanf("%d", &islem);

                    switch (islem) {
                    case 1: printf("Espresso fiyati 25 TL\nEspresso adetini giriniz: "); scanf("%d", &adet1); sepet1 += adet1 * 25; break;
                    case 2: printf("Americano fiyati 20 TL\nAmericano adetini giriniz: "); scanf("%d", &adet1); sepet1 += adet1 * 20; break;
                    case 3: printf("Filtre Kahve fiyati 20 TL\nFiltre Kahve adetini giriniz: "); scanf("%d", &adet1); sepet1 += adet1 * 20; break;
                    case 4: printf("Macchiato fiyati 22 TL\nMacchiato adetini giriniz: "); scanf("%d", &adet1); sepet1 += adet1 * 22; break;
                    case 5: printf("Cappuccino fiyati 22 TL\nCappuccino adetini giriniz: "); scanf("%d", &adet1); sepet1 += adet1 * 22; break;
                    case 6: printf("Geri yonlendiriliyorsunuz\n"); break;
                    default: printf("Hatali bir tuslama yaptiniz\n"); break;
                    }

                    if (islem == 6) {
                        printf("\n");
                        goto menu; 
                    }
                }

            // Soguk Icecekler
            case 2:
                while (1) {
                    system("cls");
                    int secim, adet2;
                    struct sogukicecekler s1 = {"1-Kola", 20};
                    struct sogukicecekler s2 = {"2-Fanta", 20};
                    struct sogukicecekler s3 = {"3-Soda", 10};
                    struct sogukicecekler s4 = {"4-Ice Mocha", 30};
                    struct sogukicecekler s5 = {"5-Ice Latte", 30};

                    printf("\n");
                    printf("%s\n%s\n%s\n%s\n%s\n", s1.icecek, s2.icecek, s3.icecek, s4.icecek, s5.icecek);
                    printf("6. Geri\n");
                    printf("\n");
                    printf("Isleminizi seciniz: ");
                    scanf("%d", &secim);

                    switch (secim) {
                    case 1: printf("Kola fiyati 20 TL\nKola adetini giriniz: "); scanf("%d", &adet2); sepet2 += adet2 * 20; break;
                    case 2: printf("Fanta fiyati 20 TL\nFanta adetini giriniz: "); scanf("%d", &adet2); sepet2 += adet2 * 20; break;
                    case 3: printf("Soda fiyati 10 TL\nSoda adetini giriniz: "); scanf("%d", &adet2); sepet2 += adet2 * 10; break;
                    case 4: printf("Ice Mocha fiyati 30 TL\nIce Mocha adetini giriniz: "); scanf("%d", &adet2); sepet2 += adet2 * 30; break;
                    case 5: printf("Ice Latte fiyati 30 TL\nIce Latte adetini giriniz: "); scanf("%d", &adet2); sepet2 += adet2 * 30; break;
                    case 6: printf("Geri yonlendiriliyorsunuz\n"); break;
                    default: printf("Hatali bir tuslama yaptiniz\n"); break;
                    }

                    if (secim == 6) {
                        printf("\n");
                        goto menu; 
                    }
                }

            // Kahvalti
            case 3:
                while (1) {
                    system("cls");
                    int tercih, adet3;
                    struct kahvalti o1 = {"1-Serpme Kahvalti", 150};
                    struct kahvalti o2 = {"2-Omlet", 60};
                    struct kahvalti o3 = {"3-Kahvalti Tabağı", 120};
                    struct kahvalti o4 = {"4-Acma", 20};
                    struct kahvalti o5 = {"5-Simit", 20};

                    printf("\n");
                    printf("%s\n%s\n%s\n%s\n%s\n", o1.yemek, o2.yemek, o3.yemek, o4.yemek, o5.yemek);
                    printf("6. Geri\n");
                    printf("\n");
                    printf("Isleminizi seciniz: ");
                    scanf("%d", &tercih);

                    switch (tercih) {
                    case 1: printf("Serpme Kahvalti fiyati 150 TL\nSerpme Kahvalti adetini giriniz: "); scanf("%d", &adet3); sepet3 += adet3 * 150; break;
                    case 2: printf("Omlet fiyati 60 TL\nOmlet adetini giriniz: "); scanf("%d", &adet3); sepet3 += adet3 * 60; break;
                    case 3: printf("Kahvalti Tabağı fiyati 120 TL\nKahvalti Tabağı adetini giriniz: "); scanf("%d", &adet3); sepet3 += adet3 * 120; break;
                    case 4: printf("Acma fiyati 20 TL\nAcma adetini giriniz: "); scanf("%d", &adet3); sepet3 += adet3 * 20; break;
                    case 5: printf("Simit fiyati 20 TL\nSimit adetini giriniz: "); scanf("%d", &adet3); sepet3 += adet3 * 20; break;
                    case 6: printf("Geri yonlendiriliyorsunuz\n"); break;
                    default: printf("Hatali bir tuslama yaptiniz\n"); break;
                    }

                    if (tercih == 6) {
                        printf("\n");
                        goto menu; 
                    }
                }

            // Sandvicler
            case 4:
                while (1) {
                    system("cls");
                    int Fiyatlar[] = {0, 100, 130, 120, 110, 120, 150};
                    char *sandvicTurleri[] = {"Peynirli", "Tavuklu", "Ton balikli", "Vejetaryen", "Patoslu", "Kavurmali"};
                    int secim = 0;
                    int adet = 0;

                    while (secim < 1 || secim > 7) {
                        printf("Sandvic Listesi:\n");
                        printf("1. Peynirli - %d TL\n", Fiyatlar[1]);
                        printf("2. Tavuklu - %d TL\n", Fiyatlar[2]);
                        printf("3. Ton balikli - %d TL\n", Fiyatlar[3]);
                        printf("4. Vejeteryan - %d TL\n", Fiyatlar[4]);
                        printf("5. Patoslu - %d TL\n", Fiyatlar[5]);
                        printf("6. Kavurmali - %d TL\n", Fiyatlar[6]);
                        printf("7. Geri\n");
                        printf("Lutfen sandvic seciniz: ");
                        scanf("%d", &secim);

                        if (secim < 1 || secim > 7) {
                            printf("Hatali bir islem yaptiniz\n");
                        }
                        if (secim == 7) {
                            printf("Geri yonlendiriliyorsunuz");
                            goto menu;
                        }
                    }

                    printf("Kac adet istersiniz?: ");
                    scanf("%d", &adet);
                    sepet4 = Fiyatlar[secim] * adet;
                }

            // Tatlilar
            case 5:
                while (1) {
                    system("cls");
                    int islem;
                    int adet4;
                    printf("1. Tiramisu\n");
                    printf("2. Ekler\n");
                    printf("3. Trilece\n");
                    printf("4. Orman Meyveli Pasta\n");
                    printf("5. Brownie\n");
                    printf("6. Geri\n");
                    
                    printf("Isleminizi seciniz: ");
                    scanf("%d", &islem);
                    
                    switch (islem) {
                    case 1: printf("Tiramisu 50 TL\n"); printf("Tiramisu adetini giriniz: "); scanf("%d", &adet4); sepet4 += adet4 * 50; break;
                    case 2: printf("Ekler 40 TL\n"); printf("Ekler adetini giriniz: "); scanf("%d", &adet4); sepet4 += adet4 * 40; break;
                    case 3: printf("Trilece 35 TL\n"); printf("Trilece adetini giriniz: "); scanf("%d", &adet4); sepet4 += adet4 * 35; break;
                    case 4: printf("Orman Meyveli Pasta 60 TL\n"); printf("Orman Meyveli Pasta adetini giriniz: "); scanf("%d", &adet4); sepet4 += adet4 * 60; break;
                    case 5: printf("Brownie 40 TL\n"); printf("Brownie adetini giriniz: "); scanf("%d", &adet4); sepet4 += adet4 * 40; break;
                    case 6: printf("Geri yonlendiriliyorsunuz.\n"); break;
                    default: printf("Hatali bir tuslama yaptiniz\n"); break;
                    }

                    if (islem == 6) {
                        printf("\n");
                        goto menu;
                    }
                }

            case 6:
                goto temelmenu;
            default:
                printf("Hatali bir tuslama yaptiniz\n");
                goto menu;
            }

        // Sepet
        case 3:
            system("cls");
            printf("Sepetinizdeki urunler ve fiyatlari:\n");
            if (sepet1 > 0) printf("Espresso: %.2f TL\n", sepet1);
            if (sepet2 > 0) printf("Kola: %.2f TL\n", sepet2);
            if (sepet3 > 0) printf("Serpme Kahvalti: %.2f TL\n", sepet3);
            if (sepet4 > 0) printf("Tatli: %.2f TL\n", sepet4);
            if (sepet5 > 0) printf("Sandvic: %.2f TL\n", sepet5);

            tutar = topla(sepet1, sepet2, sepet3, sepet4, sepet5);
            printf("Toplam tutar: %.2f TL\n", tutar);
            printf("1. Sepeti Onayla\n2. Ana Menu\n");
            printf("Seciminizi yapin: ");
            int sepetSecim;
            scanf("%d", &sepetSecim);

            if (sepetSecim == 1) {
                printf("Bizi tercih ettiginiz icin tesekkur ederiz.\n");
                sleep(2); // 2 saniye bekleme
                goto temelmenu;
            } else if (sepetSecim == 2) {
                goto temelmenu;
            } else

        // Cikis
        case 4:
        cikis:
            printf("Cikis yapiliyor...\n");
            exit(0);

        default:
            printf("Hatali bir tuslama yaptiniz\n");
            goto temelmenu;
        }
    }
    
    return 0;
}
