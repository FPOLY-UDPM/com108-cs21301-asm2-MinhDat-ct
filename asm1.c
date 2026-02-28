/******************************************************************************
 * Họ và tên: [Lý Minh Đạt]
 * MSSV:      [PS48658]
 * Lớp:       [CS21302]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
void kiemTrasoNguyen() {
    float so;
    printf("Nhap so nguyen: ");
    scanf("%f", &so);
   if (so == (int)so) {
        printf("%f la so nguyen.\n", so);
    } else {
        printf("%f khong phai la so nguyen.\n", so);
    }
}
void kiemTraSonguyenTo() {
    int n, i, dem = 0;
    printf("Nhap so nguyen: ");
    scanf("%d", &n);
    if (n < 2) {
        printf("%d khong phai la so nguyen to.\n", n);
        return;
    }
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            dem++;
            break;
        }
    }
    if (dem == 0) {
        printf("%d la so nguyen to.\n", n);
    } else {
        printf("%d khong phai la so nguyen to.\n", n);
    }
}
void kiemTrasoChinhphuong() {
        int n, i, dem = 0;
    printf("Nhap so nguyen: ");
    scanf("%d", &n);
    for (i = 0; i * i <= n; i++) {
        if (i * i == n) {
            dem++;
            break;
        }
    }
    if (dem > 0) {
        printf("%d la so chinh phuong.\n", n);
    } else {
        printf("%d khong phai la so chinh phuong.\n", n);
    }
}
void timUocSoChungVaBoiSoChung() {
    int a, b;
    printf("Nhap so thu nhat: ");
    scanf("%d", &a);
    printf("Nhap so thu hai: ");
    scanf("%d", &b);

    // Tìm Ước số chung lớn nhất (USCLN)
    int uscln = 1;
    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            uscln = i;
        }
    }

    // Tìm Bội số chung nhỏ nhất (BSCNN)
    int bscnn = (a * b) / uscln;

    printf("Uoc so chung lon nhat cua %d va %d la: %d\n", a, b, uscln);
    printf("Boi so chung nho nhat cua %d va %d la: %d\n", a, b, bscnn);
}
void tinhTienKaraoke() {
    int gioVao, gioRa;
    printf("Nhap gio vao: ");
    scanf("%d", &gioVao);
    printf("Nhap gio ra: ");
    scanf("%d", &gioRa);
    int soGio = gioRa - gioVao;
    int tien = soGio * 50000;
    // Giảm 30% khi số giờ trên 3
    if (soGio > 3) {
        tien = tien * 0.7;
    }
    // Karaoke chỉ hoạt động từ 12 đến 23 giờ
    if (gioVao < 12 || gioRa > 23) {
        printf("Karaoke chi hoat dong tu 12 den 23 gio.\n");
        return;
    }
    // Giảm tiếp 10% nếu giờ vào từ 14 đến 17 giờ
    if (gioVao >= 14 && gioVao <= 17) {
        tien = tien * 0.9;
    }
    printf("Tien phai tra cho quan Karaoke la: %d VND\n", tien);
}
void tinhTienDien() {
   int sodien;
    float tien;
    printf("nhap so dien tieu thu trong thang: ");
    scanf("%d", &sodien);
    if(sodien <=50 && sodien >=0){
        tien = sodien * 1678;
        printf("So tien phai dong: %.2f\n", tien);
    }
    else if(sodien <=100 && sodien >=51){
        tien = 50 * 1678 + (sodien - 50) * 1734;
        printf("So tien phai dong: %.2f\n", tien);
    }
    else if(sodien <=200 && sodien >=101){
        tien = 50 * 1678 + 50 * 1734 + (sodien - 100) * 2014; }
    else if(sodien <=300 && sodien >=201){
        tien = 50 * 1678 + 50 * 1734 + 100
    * 2014 + (sodien - 200) * 2536;
    }
    else if(sodien <=400 && sodien >=301){
        tien = 50 * 1678 + 50 * 1734 + 100
    * 2014 + 100 * 2536 + (sodien - 300) * 2834; }
    else if (sodien >400){
        tien = 50 * 1678 + 50 * 1734 + 100
    * 2014 + 100 * 2536 + 100 * 2834 + (sodien - 400) * 2927;
        printf("So tien phai dong: %.2f\n", tien);
    }
}
void doiTien() {
     int sotien;
    int menhgia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int i;

    printf("Nhap so tien can doi: ");
    scanf("%d", &sotien);

    printf("Cac menh gia duoc doi:\n");

    for(i = 0; i < 9; i++) {
        if(sotien >= menhgia[i]) {
            int soluong = sotien / menhgia[i];
            printf("%d to %d\n", soluong, menhgia[i]);
            sotien = sotien % menhgia[i];
        }
    }
}
void tinhLaiSuatVayNganHang() {
    double tienvay;
    double laisuat = 0.05;   // 5% / tháng
    int kyhan = 12;
    int i;

    printf("Nhap so tien muon vay: ");
    scanf("%lf", &tienvay);

    double goc_thang = tienvay / kyhan;
    double conlai = tienvay;

    printf("\nKy han | Lai phai tra | Goc phai tra | Tong phai tra | Con lai\n");
    printf("-------------------------------------------------------------------\n");

    for(i = 1; i <= kyhan; i++) {

        double lai = conlai * laisuat;
        double tong = goc_thang + lai;

        printf("%6d | %12.0lf | %12.0lf | %13.0lf | %10.0lf\n",
               i, lai, goc_thang, tong, conlai - goc_thang);

        conlai = conlai - goc_thang;
    }
}
void vayTienMuaXe() {
     double giaxe = 500000000;      // 500 triệu
    double laisuat_nam = 0.072;    // 7.2%/năm
    int thoihan_nam = 24;

    double phantram_vay;
    printf("Nhap phan tram vay (vi du 80): ");
    scanf("%lf", &phantram_vay);

    double tien_vay = giaxe * phantram_vay / 100;
    double tra_truoc = giaxe - tien_vay;

    int tong_thang = thoihan_nam * 12;
    double laisuat_thang = laisuat_nam / 12;

    double goc_thang = tien_vay / tong_thang;
    double conlai = tien_vay;

    printf("\nSo tien tra truoc: %.0lf VND\n", tra_truoc);
    printf("So tien vay: %.0lf VND\n", tien_vay);

    printf("\nBang tra gop hang thang:\n");
    printf("Thang | Lai | Goc | Tong | Con lai\n");
    printf("-----------------------------------------------------\n");

    for(int i = 1; i <= tong_thang; i++) {

        double lai = conlai * laisuat_thang;
        double tong = goc_thang + lai;

        printf("%5d | %10.0lf | %10.0lf | %10.0lf | %12.0lf\n",
               i, lai, goc_thang, tong, conlai - goc_thang);

        conlai -= goc_thang;
    }
}

void sapXepThongTinSinhVien() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    char hoten[100][50];
    float diem[100];

    for(int i = 0; i < n; i++) {
        printf("Nhap ho ten sinh vien %d: ", i + 1);
        scanf(" %[^\n]s", hoten[i]);
        printf("Nhap diem cua sinh vien %d: ", i + 1);
        scanf("%f", &diem[i]);
    }

    // Sắp xếp theo điểm giảm dần
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(diem[j] < diem[j + 1]) {
                // Đổi chỗ điểm
                float tempDiem = diem[j];
                diem[j] = diem[j + 1];
                diem[j + 1] = tempDiem;

                // Đổi chỗ họ tên tương ứng
                char tempHoten[50];
                strcpy(tempHoten, hoten[j]);
                strcpy(hoten[j], hoten[j + 1]);
                strcpy(hoten[j + 1], tempHoten);
            }
        }
    }

    // Hiển thị thông tin sinh viên sau khi sắp xếp
    printf("\nThong tin sinh vien sau khi sap xep:\n");
    for(int i = 0; i < n; i++) {
        printf("Ho ten: %s, Diem: %.2f, Hoc luc: ", hoten[i], diem[i]);
        if(diem[i] >= 9) {
            printf("Xuat sac\n");
        } else if(diem[i] >= 8) {
            printf("Gioi\n");
        } else if(diem[i] >= 7) {
            printf("Kha\n");
        } else if(diem[i] >= 5) {
            printf("Trung binh\n");
        } else {
            printf("Yeu\n");
        }
    }
}

    void gameFpolyLott() {
    int so1, so2;
    printf("Nhap so thu nhat (1-15): ");
    scanf("%d", &so1);
    printf("Nhap so thu hai (1-15): ");
    scanf("%d", &so2);
    if(so1 < 1 || so1 > 15 || so2 < 1 || so2 > 15) {
        printf("Vui long nhap so tu 1 den 15.\n");
        return;
    }
    srand(time(0));
    int soTrung1 = rand() % 15 + 1;
    int soTrung2 = rand() % 15 + 1;
    printf("So trung thuong la: %d va %d\n", soTrung1, soTrung2);
    int trung = 0;
    if(so1 == soTrung1 || so1 == soTrung2) {
        trung++;
    }
    if(so2 == soTrung1 || so2 == soTrung2) {
        trung++;
    }
    if(trung == 0) {
        printf("Chuc ban may man lan sau.\n");
    } else if(trung == 1) {
        printf("Chuc mung ban da trung giai nhi!\n");
    } else {
        printf("Chuc mung ban da trung giai nhat!\n");
    }
}

void tinhToanPhanSo() {
    int tu1, mau1, tu2, mau2;
    printf("Nhap tu so phan so 1: ");
    scanf("%d", &tu1);
    printf("Nhap mau so phan so 1: ");
    scanf("%d", &mau1);
    printf("Nhap tu so phan so 2: ");
    scanf("%d", &tu2);
    printf("Nhap mau so phan so 2: ");
    scanf("%d", &mau2);

    // Tính tổng
    int tongTu = tu1 * mau2 + tu2 * mau1;
    int tongMau = mau1 * mau2;

    // Tính hiệu
    int hieuTu = tu1 * mau2 - tu2 * mau1;
    int hieuMau = mau1 * mau2;

    // Tính tích
    int tichTu = tu1 * tu2;
    int tichMau = mau1 * mau2;

    // Tính thương
    int thuongTu = tu1 * mau2;
    int thuongMau = mau1 * tu2;

    printf("Tong: %d/%d\n", tongTu, tongMau);
    printf("Hieu: %d/%d\n", hieuTu, hieuMau);
    printf("Tich: %d/%d\n", tichTu, tichMau);
    printf("Thuong: %d/%d\n", thuongTu, thuongMau);
}
int main() {
    int chonChucNang;
    do {
        printf("Chon chuc nang:\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va boi so chung cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chonChucNang);

        switch (chonChucNang) {
            case 1:
                // Gọi hàm kiểm tra số nguyên
                printf("DA CHON CHUC NANG 1: KIEM TRA SO NGUYEN\n");
                kiemTrasoNguyen();
                kiemTraSonguyenTo();
                kiemTrasoChinhphuong();
                return 0;
                break;
            case 2:
                // Gọi hàm tìm Ước số chung và bội số chung
                printf("DA CHON CHUC NANG 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO\n");
                timUocSoChungVaBoiSoChung();
                return 0;
                break;
            case 3:
                // Gọi hàm tính tiền cho quán Karaoke
                printf("DA CHON CHUC NANG 3: TINH TIEN CHO QUAN KARAOKE\n");
                tinhTienKaraoke();
                return 0;
                break;
            case 4:
                // Gọi hàm tính tiền điện
                printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
                tinhTienDien();
                return 0;
                break;
            case 5:
                // Gọi hàm đổi tiền
                printf("DA CHON CHUC NANG 5: DOI TIEN\n");
                doiTien();
                return 0;
                break;
            case 6:
                // Gọi hàm tính lãi suất vay ngân hàng
                printf("DA CHON CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG VAY TRA GOP\n");
                tinhLaiSuatVayNganHang();
                return 0;
                break;
            case 7:
                // Gọi hàm vay tiền mua xe
                printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
                vayTienMuaXe();
                return 0;
                break;
            case 8:
                // Gọi hàm sắp xếp thông tin sinh viên
                printf("DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN\n");
                sapXepThongTinSinhVien();
                return 0;
                break;
            case 9:
                // Gọi hàm game FPOLY-LOTT
                printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
                gameFpolyLott();
                return 0;
                break;
            case 10:
                // Gọi hàm tính toán phân số
                printf("DA CHON CHUC NANG 10: TINH TOAN PHAN SO\n");
                tinhToanPhanSo();
                return 0;
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (chonChucNang != 0);

    return 0;
}
