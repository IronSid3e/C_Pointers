#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTE_LENGTH 256
#define FILE_NAME "notes.txt"

// Not ekleme fonksiyonu
void add_note() {
    char note[MAX_NOTE_LENGTH];
    FILE *file = fopen(FILE_NAME, "a"); // Dosyayı ekleme modunda aç

    if (file == NULL) {
        printf("Dosya açılamadı!\n");
        return;
    }

    printf("Notunuzu yazın (maksimum %d karakter):\n", MAX_NOTE_LENGTH - 1);
    getchar(); // Boş girdi yakalamak için
    fgets(note, MAX_NOTE_LENGTH, stdin); // Kullanıcıdan not al
    fprintf(file, "%s", note); // Notu dosyaya yaz
    fclose(file); // Dosyayı kapat

    printf("Not başarıyla eklendi!\n");
}

// Notları görüntüleme fonksiyonu
void view_notes() {
    char note[MAX_NOTE_LENGTH];
    FILE *file = fopen(FILE_NAME, "r"); // Dosyayı okuma modunda aç

    if (file == NULL) {
        printf("Henüz hiç not eklenmemiş.\n");
        return;
    }

    printf("Kaydedilmiş Notlar:\n");
    while (fgets(note, MAX_NOTE_LENGTH, file) != NULL) {
        printf("%s", note); // Notu ekrana yazdır
    }
    fclose(file); // Dosyayı kapat
}

// Ana menü
int main() {
    int choice;

    while (1) {
        printf("\n--- Not Defteri ---\n");
        printf("1. Not Ekle\n");
        printf("2. Notları Görüntüle\n");
        printf("3. Çıkış Yap\n");
        printf("Seçiminizi yapın: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_note();
                break;
            case 2:
                view_notes();
                break;
            case 3:
                printf("Programdan çıkılıyor...\n");
                exit(0);
            default:
                printf("Geçersiz seçim. Lütfen tekrar deneyin.\n");
        }
    }

    return 0;
}
