#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char ten[50];
    int tuoi;
    char soDienThoai[15];
} SinhVien;

void sapXepSinhVienTheoTen(SinhVien sinhVien[], int soLuong) {
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if (strcmp(sinhVien[i].ten, sinhVien[j].ten) > 0) {
                SinhVien temp = sinhVien[i];
                sinhVien[i] = sinhVien[j];
                sinhVien[j] = temp;
            }
        }
    }
}

void inDanhSachSinhVien(SinhVien sinhVien[], int soLuong) {
    for (int i = 0; i < soLuong; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n", 
               sinhVien[i].id, sinhVien[i].ten, sinhVien[i].tuoi, sinhVien[i].soDienThoai);
    }
}

int main() {
    SinhVien sinhVien[5] = {
        {1, "Cong", 20, "123456789"},
        {2, "Nhat", 22, "987654321"},
        {3, "Duy", 21, "555123456"},
        {4, "Nam", 23, "444987654"},
        {5, "Huy", 20, "333444555"}
    };

    printf("Danh sach sinh vien truoc khi sap xep:\n");
    inDanhSachSinhVien(sinhVien, 5);

    sapXepSinhVienTheoTen(sinhVien, 5);

    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    inDanhSachSinhVien(sinhVien, 5);

    return 0;
}

