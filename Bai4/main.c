#include <stdio.h>

#define MAX 100

int main() {
    int so_thu_tu[MAX];
    char ten_benh_nhan[MAX][30];
    int tuoi[MAX];
    int uu_tien[MAX];
    int bao_hiem_y_te[MAX];
    int phi_kham[MAX];

    int so_benh_nhan = 0;
    int lua_chon;

    do {
        printf("\n========== MEDCARE CLINIC ==========\n");
        printf("1. Tiep nhan benh nhan moi\n");
        printf("2. Hien thi danh sach\n");
        printf("3. Cap nhat thong tin\n");
        printf("4. Huy benh nhan\n");
        printf("5. Tim kiem benh nhan\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &lua_chon);
        getchar();

        switch (lua_chon) {

            case 1:
                if (so_benh_nhan >= MAX) {
                    printf("Hang doi da day!\n");
                    break;
                }

                so_thu_tu[so_benh_nhan] = so_benh_nhan + 1;

                printf("Nhap ten: ");
                fgets(ten_benh_nhan[so_benh_nhan], 30, stdin);

                printf("Nhap tuoi: ");
                scanf("%d", &tuoi[so_benh_nhan]);

                while (tuoi[so_benh_nhan] <= 0 ||
                       tuoi[so_benh_nhan] > 120) {
                    printf("Tuoi khong hop le! Nhap lai: ");
                    scanf("%d", &tuoi[so_benh_nhan]);
                }

                printf("Co BHYT? (1-Co, 0-Khong): ");
                scanf("%d", &bao_hiem_y_te[so_benh_nhan]);

                while (bao_hiem_y_te[so_benh_nhan] != 0 &&
                       bao_hiem_y_te[so_benh_nhan] != 1) {
                    printf("Chi nhap 0 hoac 1: ");
                    scanf("%d", &bao_hiem_y_te[so_benh_nhan]);
                }

                if (tuoi[so_benh_nhan] > 70) {
                    uu_tien[so_benh_nhan] = 1;
                } else {
                    uu_tien[so_benh_nhan] = 0;
                }

                if (bao_hiem_y_te[so_benh_nhan] == 1) {
                    phi_kham[so_benh_nhan] = 40000;
                } else {
                    phi_kham[so_benh_nhan] = 200000;
                }

                so_benh_nhan++;

                printf("Dang ky thanh cong!\n");
                break;


            case 2:
                if (so_benh_nhan == 0) {
                    printf("Hang doi dang trong!\n");
                    break;
                }

                for (int i = 0; i < so_benh_nhan; i++) {
                    printf("\nSTT: %d\n", so_thu_tu[i]);
                    printf("Ten: %s", ten_benh_nhan[i]);
                    printf("Tuoi: %d\n", tuoi[i]);

                    if (uu_tien[i] == 1) {
                        printf("Uu tien: CO\n");
                    } else {
                        printf("Uu tien: KHONG\n");
                    }

                    if (bao_hiem_y_te[i] == 1) {
                        printf("BHYT: CO\n");
                    } else {
                        printf("BHYT: KHONG\n");
                    }

                    printf("Phi kham: %d VND\n", phi_kham[i]);
                }

                break;


            case 3: {
                int stt;
                int vi_tri = -1;

                printf("Nhap STT can sua: ");
                scanf("%d", &stt);
                getchar();

                for (int i = 0; i < so_benh_nhan; i++) {
                    if (so_thu_tu[i] == stt) {
                        vi_tri = i;
                        break;
                    }
                }

                if (vi_tri == -1) {
                    printf("Khong tim thay!\n");
                    break;
                }

                printf("Nhap ten moi: ");
                fgets(ten_benh_nhan[vi_tri], 30, stdin);

                printf("Nhap tuoi moi: ");
                scanf("%d", &tuoi[vi_tri]);

                printf("Nhap BHYT moi (1-Co, 0-Khong): ");
                scanf("%d", &bao_hiem_y_te[vi_tri]);

                if (tuoi[vi_tri] > 70) {
                    uu_tien[vi_tri] = 1;
                } else {
                    uu_tien[vi_tri] = 0;
                }

                if (bao_hiem_y_te[vi_tri] == 1) {
                    phi_kham[vi_tri] = 40000;
                } else {
                    phi_kham[vi_tri] = 200000;
                }

                printf("Cap nhat thanh cong!\n");
                break;
            }


            case 4: {
                int stt;
                int vi_tri = -1;

                printf("Nhap STT can huy: ");
                scanf("%d", &stt);

                for (int i = 0; i < so_benh_nhan; i++) {
                    if (so_thu_tu[i] == stt) {
                        vi_tri = i;
                        break;
                    }
                }

                if (vi_tri == -1) {
                    printf("Khong tim thay!\n");
                    break;
                }

                for (int i = vi_tri; i < so_benh_nhan - 1; i++) {

                    so_thu_tu[i] = so_thu_tu[i + 1];

                    for (int j = 0; j < 30; j++) {
                        ten_benh_nhan[i][j] =
                            ten_benh_nhan[i + 1][j];
                    }

                    tuoi[i] = tuoi[i + 1];
                    uu_tien[i] = uu_tien[i + 1];
                    bao_hiem_y_te[i] = bao_hiem_y_te[i + 1];
                    phi_kham[i] = phi_kham[i + 1];
                }

                so_benh_nhan--;

                for (int i = 0; i < so_benh_nhan; i++) {
                    so_thu_tu[i] = i + 1;
                }

                printf("Huy thanh cong!\n");
                break;
            }


            case 5: {
                int kieu_tim;

                printf("1. Tim theo STT\n");
                printf("2. Tim theo ten\n");
                printf("Nhap lua chon: ");
                scanf("%d", &kieu_tim);
                getchar();

                if (kieu_tim == 1) {
                    int stt;
                    int tim_thay = 0;

                    printf("Nhap STT: ");
                    scanf("%d", &stt);

                    for (int i = 0; i < so_benh_nhan; i++) {
                        if (so_thu_tu[i] == stt) {
                            printf("\nSTT: %d\n", so_thu_tu[i]);
                            printf("Ten: %s", ten_benh_nhan[i]);
                            printf("Tuoi: %d\n", tuoi[i]);
                            printf("Phi: %d VND\n", phi_kham[i]);

                            tim_thay = 1;
                            break;
                        }
                    }

                    if (tim_thay == 0) {
                        printf("Khong tim thay!\n");
                    }
                }

                else if (kieu_tim == 2) {
                    char ten_can_tim[30];
                    int tim_thay = 0;

                    printf("Nhap ten: ");
                    fgets(ten_can_tim, 30, stdin);

                    for (int i = 0; i < so_benh_nhan; i++) {

                        int giong_nhau = 1;
                        int j = 0;

                        while (ten_benh_nhan[i][j] != '\0' ||
                               ten_can_tim[j] != '\0') {

                            if (ten_benh_nhan[i][j] !=
                                ten_can_tim[j]) {
                                giong_nhau = 0;
                                break;
                            }

                            j++;
                        }

                        if (giong_nhau == 1) {
                            printf("\nSTT: %d\n", so_thu_tu[i]);
                            printf("Ten: %s", ten_benh_nhan[i]);
                            printf("Tuoi: %d\n", tuoi[i]);
                            printf("Phi: %d VND\n", phi_kham[i]);

                            tim_thay = 1;
                        }
                    }

                    if (tim_thay == 0) {
                        printf("Khong tim thay!\n");
                    }
                }

                break;
            }


            case 0:
                printf("Thoat chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (lua_chon != 0);

    return 0;
}

