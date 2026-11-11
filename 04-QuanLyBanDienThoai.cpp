/* 01 – Quản lý bán điện thoại
1.	Nguyễn Tiến Đức – MSV: 25A1001D0088 – Lớp: 2510A01
2.	Nguyễn Long Khánh – MSV: 25A1001D0187 – Lớp: 2510A01
3.  Tô Xuân Thắng – MSV: 25A1001D0329 – Lớp: 2510A01
4.  Vũ Phú Thịnh – MSV: 25A1001D0334 –Lớp: 2510A01
*/
/*  Phân chia công việc
1.	Nguyễn Tiến Đức – Nội dung: 7, 9, 4
2.	Nguyễn Long Khánh – Nội dung: 2, 3, 6
3.  Tô Xuân Thắng – Nội dung: 6, 8, 10
4.  Vũ Phú Thịnh – Nội dung: 1, 5, 4
*/
#include <bits/stdc++.h>
using namespace std;

struct Dienthoai {
    string MaLo,TenMay,HangSX;
    double GiaNhap,GiaBan;
    int SLNhap,SLConLai;
};

struct NodeDT{
Dienthoai info ;
struct NodeDT *next;
};

struct QLDT{
    NodeDT *head;
    NodeDT *tail;
};

void init(QLDT &Q){
Q.head = NULL;
Q.tail = NULL;
}

NodeDT *get_Node(Dienthoai x){
    NodeDT *p = new NodeDT;
    if(p==NULL){
        cout<<"Cap nhat khong thanh cong";
        exit(1);
    }
    p -> info = x;
    p -> next=NULL;

    return p;
}

//Hỗ trợ cho void NhapDSLo()
void addTailDT(QLDT &Q, Dienthoai x) {
    NodeDT *p = get_Node(x);
    if (Q.head == NULL) {
        Q.head = Q.tail = p;
    } else {
        Q.tail->next = p;
        Q.tail = p;
    }
}

NodeDT* timLoByMa(QLDT &Q, string maLo) {
    NodeDT *p = Q.head;
    while (p != NULL) {
        if (p->info.MaLo == maLo) return p;
        p = p->next;
    }
    return NULL;
}

//1.Nhập ds lô đt, dừng khi mã lô là *, kiểm tra mã ch trùng
void NhapDSLo(QLDT &Q){
    cout<< "\n===Nhap danh sach lo Dien thoai (Dung khi Nhap la *)===\n";
    while (true){
        Dienthoai x;
        cout<<"\nNhap ma lo: ";
        cin>>x.MaLo;
        if(x.MaLo=="*") break;
        if(timLoByMa(Q,x.MaLo)!=NULL){
            cout<<"ERROR! Ma lo '"<<x.MaLo<<"' da ton tai trong he thong.\n";
            continue;
        }
        cin.ignore();
        cout << "Ten model may: "; getline(cin, x.TenMay);
        cout << "Hang san xuat (Apple/Samsung/Oppo/Xiaomi/Vivo/...): "; getline(cin, x.HangSX);
        cout << "Gia nhap: "; cin >> x.GiaNhap;
        cout << "Gia ban: "; cin >> x.GiaBan;
        cout << "So luong nhap: "; cin >> x.SLNhap;
        cout << "So luong con lai: "; cin >> x.SLConLai;

        addTailDT(Q, x);
        cout<<"-> Them Lo DT thanh cong!\n";
    }
}

//5.Tìm lô theo maLo.
void TimLoTheoMaLo(QLDT &Q){
    string Ma;
    cout << "Nhap Ma Lo can tim: ";
    cin >> Ma;
    NodeDT *p = timLoByMa(Q, Ma);
    if (p == NULL) {
        cout << "-> Khong tim thay lo dien thoai co ma: " << Ma << endl;
    } else {
        cout << "\nTHONG TIN LO DIEN THOAI:\n";
        cout << "- Ma Lo: " << p->info.MaLo << "\n"
             << "- Ten Model: " << p->info.TenMay << "\n"
             << "- Hang SX: " << p->info.HangSX << "\n"
             << "- Gia Nhap: " << fixed << setprecision(0) << p->info.GiaNhap << " VNĐ\n"
             << "- Gia Ban: " << fixed << setprecision(0) << p->info.GiaBan << " VNĐ\n"
             << "- SL Nhap: " << p->info.SLNhap << "\n"
             << "- SL Con Lai: " << p->info.SLConLai << "\n";
    }
}

//7.Tìm  mọi lô hàng theo hãng sản xuất
void TimLoTheoHang(QLDT &Q){
    string Hangcantim;
    cout <<"Nhap hang can tim \n";
    cin >> Hangcantim;
    NodeDT *p = Q.head;
    int dem = 0;
    while (p !=NULL){
        if(p ->info.HangSX==Hangcantim){
        cout << " \n Ma : " << p->info.MaLo;
        cout << " \n Ten:"<<p->info.TenMay;
        cout << " \n Gia nhap" << p->info.GiaNhap;
        cout << " \n Gia ban" << p->info.GiaBan;
        cout << " \n so luong nhap" << p->info.SLNhap;
        cout << " \n so luong con lai " << p->info.SLConLai << endl;
        dem ++;
        }
    p = p->next;
    }
    if (dem == 0) {
        cout << "\n Khong co lo nao trong hang~";
}
}
//9.Tổng doanh thu
void TongDoanhThu(QLDT &Q){
    NodeDT *p =Q.head;
    double Tongdoanhthu=0;
    double Tongloinhuan=0;
    while(p !=NULL){
    int SLdaban= p->info.SLNhap- p->info.SLConLai;
    Tongdoanhthu +=(double)SLdaban *  p-> info.GiaBan;
    Tongloinhuan +=(double)SLdaban * (p->info.GiaBan - p->info.GiaNhap);
    p =p-> next;
    }
    cout<<"Tong doanh thu la: \n"<<fixed << setprecision(0)<<Tongdoanhthu<<endl;
    cout<<"Tong loi nhuan la: \n"<<fixed << setprecision(0)<<Tongloinhuan;
}

// DSK
struct Date {
    int day, month, year;
};
struct PhieuBanHang {
    string maPhieu, maLo, imei, tenKhachHang, soDienThoai, trangThaiBaoHanh;
    Date ngayBan;
};
struct DNode {
    PhieuBanHang info;
    struct DNode *next;
    struct DNode *prev;
};

struct DDanh_sach_Kep_DT2 {
    DNode *Head;
    DNode *Tail;
};


void DDanh_sach_Kep_DT2_Rong (DDanh_sach_Kep_DT2 &Q){
    Q.Head = NULL;
    Q.Tail = NULL;
}

DNode *getNode (PhieuBanHang x) {
    DNode *p;
    p = new DNode;
    if (p == NULL) {
        cout << "Cap nhat khong thanh cong";
        exit (1);
    }
    p -> info = x;
    p -> prev = NULL;
    p -> next = NULL;
    return p;
}

void addTailPB(DDanh_sach_Kep_DT2 &Q, PhieuBanHang x) {
    DNode *p = getNode(x);
    if (Q.Head == NULL) {
        Q.Head = Q.Tail = p;
    } else {
        p->prev = Q.Tail;
        Q.Tail->next = p;
        Q.Tail = p;
    }
}

void ChenVaoCuoi (DDanh_sach_Kep_DT2 &DQ, DNode *PhanTuMoi) {
    if (DQ.Head == NULL) {
        DQ.Head = PhanTuMoi;
        DQ.Tail = PhanTuMoi;
    }
    else {
        DQ.Tail -> next = PhanTuMoi;
        PhanTuMoi -> prev = DQ.Tail;
        DQ.Tail = PhanTuMoi;
    }
}

// Hàm ho tro kiem tra IMEI co ton tai trong danh sach chua
bool KiemTraImeiTrung(DDanh_sach_Kep_DT2 Q, string imei) {
    DNode *p = Q.Head;
    while (p != NULL) {
        if (p->info.imei == imei) return true;
        p = p->next;
    }
    return false;
}

// Ham Nhap
void NhapPhieuBanHang (DDanh_sach_Kep_DT2 &Q,QLDT &q) {
    int n;
    NodeDT *p = q.head;
    cout << "Nhap so luong Phieu Ban Hang: "; cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "\n--- Nhap Phieu Ban Hang thu: " << i << " ---\n";
        PhieuBanHang pbh;

        cout << "Nhap Ma phieu: "; cin >> pbh.maPhieu;

        // Vòng lặp bắt buộc: Kiểm tra maLo tồn tại và lô còn hàng
        while (true) {
            cout << "Nhap Ma lo: "; cin >> pbh.maLo;
            bool timThayLo = false;


            // Duyệt danh sách lô được truyền vào từ hàm main để kiểm tra
            while(p !=NULL){
                if(p->info.MaLo == pbh.maLo){
                    timThayLo=true;
                    break;
                }
                p=p->next;
            }
            if (!timThayLo) {
                cout << " Ma lo khong ton tai trong danh sach lo thiet bi\n";
            } else if (p->info.SLConLai <=0) {
                cout << " Lo hang nay da het sach hang! Vui long nhap lai\n";
            } else {
                p->info.SLConLai --;
                break;
            }
        }

        // Kiem tra IMEI duy nhat
        while (true) {
            cout << "Nhap IMEI: "; cin >> pbh.imei;
            if (KiemTraImeiTrung(Q, pbh.imei)) {
                cout << "=> Loi: IMEI nay da xuat hien o mot phieu khac! Vui long nhap lai.\n";
            } else {
                break;
            }
        }

        cin.ignore();
        cout << "Nhap Ten khach hang: "; getline(cin, pbh.tenKhachHang);
        cout << "Nhap So dien thoai: "; cin >> pbh.soDienThoai;

        cout << "Nhap Ngay ban (Ngay Thang Nam rieng re):\n";
        cout << " + Nhap ngay: "; cin >> pbh.ngayBan.day;
        cout << " + Nhap thang: "; cin >> pbh.ngayBan.month;
        cout << " + Nhap nam: "; cin >> pbh.ngayBan.year;

        cout << "Nhap Trang thai bao hanh (ConBaoHanh/HetBaoHanh/DangSuaChua): "; cin >> pbh.trangThaiBaoHanh;

        DNode *moi = getNode(pbh);
        ChenVaoCuoi(Q, moi);
    }
}

// Ham xuat
void XuatPhieuBanHang(DDanh_sach_Kep_DT2 &Q) {
    if (Q.Head == NULL) {
        cout << "\nDanh sach rong\n";
        return;
    }

    cout << "\n" << left << setw(10) << "Ma Phieu"
                         << setw(10) << "Ma Lo"
                         << setw(15) << "IMEI"
                         << setw(20) << "Ten Khach"
                         << setw(15) << "Ngay Ban"
                         << setw(15) << "Trang Thai\n";
    cout << string(93, '-') << "\n";
    DNode *p = Q.Head;
    while (p != NULL) {
    stringstream ss;
        ss << p->info.ngayBan.day << "/"
           << p->info.ngayBan.month << "/"
           << p->info.ngayBan.year;
        string ngayBanStr = ss.str();
      cout << left << setw(12) << p->info.maPhieu
             << left << setw(10) << p->info.maLo
             << left << setw(15) << p->info.imei
             << left << setw(20) << p->info.tenKhachHang
             << left << setw(15) << ngayBanStr
             << left << setw(20) << p->info.trangThaiBaoHanh << "\n";
        p = p->next;
    }
    cout << "\n";
}

void TimTheoImei(DDanh_sach_Kep_DT2 &Q, string imeiCanTim) {
    DNode *p = Q.Head;
    while (p != NULL) {
        if (p->info.imei == imeiCanTim) {
            cout << "Tim thay Ma phieu: " << p->info.maPhieu << ", Khach hang: " << p->info.tenKhachHang << "\n";
            return;
        }
        p = p->next;
    }
    cout << "Khong tim thay phieu co IMEI: " << imeiCanTim << "\n";
}

// Ham tro giup so sanh ngay
bool doiChoNgay(Date d1, Date d2) {
    if (d1.year != d2.year) return d1.year < d2.year;
    if (d1.month != d2.month) return d1.month < d2.month;
    return d1.day < d2.day;
}

void SapXepNgayGiamDan(DDanh_sach_Kep_DT2 &Q) {
    for (DNode *p = Q.Head; p != NULL; p = p->next) {
        for (DNode *q = p->next; q != NULL; q = q->next) {
            if (doiChoNgay(p->info.ngayBan, q->info.ngayBan)) {
                swap(p->info, q->info);
            }
        }
    }
    cout << "\nDa sap xep danh sach giam dan theo ngay ban\n";
}

// Tiep nhan bao hanh
void TiepNhanBaoHanh(DDanh_sach_Kep_DT2 &Q, string target) {
    DNode *p = Q.Head;
    while (p != NULL) {
        if (p->info.imei == target) {
            if (p->info.trangThaiBaoHanh == "HetBaoHanh") {
                cout << "Thiet bi da het han bao hanh\n";
            } else {
                p->info.trangThaiBaoHanh = "DangSuaChua";
                cout << "Da chuyen trang thai sang DangSuaChua\n";
            }
            return;
        }
        p = p->next;
    }
    cout << "Khong tim thay thiet bi co IMEI da nhap\n";
}


//4. Lưu và đọc lại cả hai danh sách từ tệp, giữ nguyên cả hai loại liên kết.
void luuFile(QLDT Q_DT, DDanh_sach_Kep_DT2 Q_PB) {
    ofstream fLo("lodienthoai.txt");
    NodeDT *pDT = Q_DT.head;
    while (pDT != NULL) {
        fLo << pDT->info.MaLo << "|" << pDT->info.TenMay << "|" << pDT->info.HangSX << "|"
            << fixed << setprecision(0) << pDT->info.GiaNhap << "|" << pDT->info.GiaBan << "|"
            << pDT->info.SLNhap << "|" << pDT->info.SLConLai << "\n";
        pDT = pDT->next;
    }
    fLo.close();

    ofstream fPhieu("phieubanhang.txt");
    DNode *pPB = Q_PB.Head;
    while (pPB != NULL) {
        fPhieu << pPB->info.maPhieu << "|" << pPB->info.maLo << "|" << pPB->info.imei << "|"
               << pPB->info.tenKhachHang << "|" << pPB->info.soDienThoai << "|"
               << pPB->info.ngayBan.day << "/" << pPB->info.ngayBan.month << "/" << pPB->info.ngayBan.year << "|"
               << pPB->info.trangThaiBaoHanh << "\n";
        pPB = pPB->next;
    }
    fPhieu.close();
    cout << "-> Luu du lieu vao tep lodienthoai.txt va phieubanhang.txt thanh cong!\n";
}

void docFile(QLDT &Q_DT, DDanh_sach_Kep_DT2 &Q_PB) {
    ifstream fLo("lodienthoai.txt");
    if (fLo.is_open()) {
        string line;
        while (getline(fLo, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            Dienthoai x;
            string temp;
            getline(ss, x.MaLo, '|');
            getline(ss, x.TenMay, '|');
            getline(ss, x.HangSX, '|');
            getline(ss, temp, '|'); x.GiaNhap = stod(temp);
            getline(ss, temp, '|'); x.GiaBan = stod(temp);
            getline(ss, temp, '|'); x.SLNhap = stoi(temp);
            getline(ss, temp, '|'); x.SLConLai = stoi(temp);
            addTailDT(Q_DT, x);
        }
        fLo.close();
    }

    ifstream fPhieu("phieubanhang.txt");
    if (fPhieu.is_open()) {
        string line;
        while (getline(fPhieu, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            PhieuBanHang x;
            string tempNgay;
            getline(ss, x.maPhieu, '|');
            getline(ss, x.maLo, '|');
            getline(ss, x.imei, '|');
            getline(ss, x.tenKhachHang, '|');
            getline(ss, x.soDienThoai, '|');
            getline(ss, tempNgay, '|');
            if (!tempNgay.empty()) {
                stringstream ssNgay(tempNgay);
                string d, m, y;
                getline(ssNgay, d, '/');
                getline(ssNgay, m, '/');
                getline(ssNgay, y, '/');
                x.ngayBan.day = stoi(d);
                x.ngayBan.month = stoi(m);
                x.ngayBan.year = stoi(y);
            }
            getline(ss, x.trangThaiBaoHanh, '|');
            addTailPB(Q_PB, x);
        }
        fPhieu.close();
    }
    cout << "-> Da doc du lieu tu tep thanh cong!\n";
}
// Hàm hỗ trợ in danh sách Lô điện thoại dạng bảng (Bổ sung cho Case 3)
void XuatDSLo(QLDT Q) {
    if (Q.head == NULL) {
        cout << "\nDanh sach lo dien thoai dang rong!\n";
        return;
    }
    cout << "\n======================= DANH SACH LO DIEN THOAI =======================\n";
    cout << left << setw(10) << "Ma Lo" << setw(20) << "Ten May" << setw(15) << "Hang SX"
         << setw(15) << "Gia Nhap" << setw(15) << "Gia Ban" << setw(10) << "SL Nhap" << setw(10) << "SL Con\n";
    cout << string(95, '-') << "\n";
    NodeDT *p = Q.head;
    while (p != NULL) {
        cout << left << setw(10) << p->info.MaLo
             << setw(20) << p->info.TenMay
             << setw(15) << p->info.HangSX
             << setw(15) << fixed << setprecision(0) << p->info.GiaNhap
             << setw(15) << fixed << setprecision(0) << p->info.GiaBan
             << setw(10) << p->info.SLNhap
             << setw(10) << p->info.SLConLai << "\n";
        p = p->next;
    }
    cout << "\n";
}

int main() {
    QLDT Q_DT;
    DDanh_sach_Kep_DT2 Q_PB;

    init(Q_DT);
    DDanh_sach_Kep_DT2_Rong(Q_PB);
    int chon;
    string tempStr;
    do {
        cout << "\n================ MENU QUAN LY CUA HANG BAN DIEN THOAI ================\n";
        cout << "1. Nhap danh sach lo dien thoai\n";
        cout << "2. Nhap danh sach phieu ban hang \n";
        cout << "3. In danh sach lo & phieu ban hang dang bang (Noi dung 3)\n";
        cout << "4. Luu hai danh sach ra tep (.txt) (Noi dung 4)\n";
        cout << "5. Doc file tu hai danh sach (.txt) (Noi dung 4)\n";
        cout << "6. Tim lo dien thoai theo Ma Lo (Noi dung 5)\n";
        cout << "7. Tra cuu bao hanh theo so IMEI  (Noi dung 6)\n";
        cout << "8. Tim cac lo dien thoai theo Hang san xuat (Noi dung 7)\n";
        cout << "9. Sap xep phieu ban hang theo ngay ban giam dan (Noi dung 8)\n";
        cout << "10. Tong doanh thu va tong loi nhuan (Noi dung 9)\n";
        cout << "11. Tiep nhan bao hanh (Noi dung 10)\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "=====================================================================\n";
        cout << "Nhap lua chon cua ban (0-1): ";

        // Chống lặp vô tận nếu gõ ký tự/chữ thay vì số
        if (!(cin >> chon)) {
            cout << "\nLoi! Vui long chi nhap so tu 0 den 10.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (chon) {
            case 1:
                NhapDSLo(Q_DT);
                break;
            case 2:
                NhapPhieuBanHang(Q_PB, Q_DT);
                break;
            case 3:
                XuatDSLo(Q_DT);         // In bảng Danh sách Lô
                XuatPhieuBanHang(Q_PB); // In bảng Danh sách Phiếu
                break;
            case 4:
                luuFile(Q_DT, Q_PB);
                break;
            case 5:
                docFile(Q_DT,Q_PB);
                break;
            case 6:
                TimLoTheoMaLo(Q_DT);
                break;
            case 7:
                cout << "Nhap so IMEI can tim: ";
                cin >> tempStr;
                TimTheoImei(Q_PB, tempStr);
                break;
            case 8:
                TimLoTheoHang(Q_DT);
                break;
            case 9:
                SapXepNgayGiamDan(Q_PB);
                cout << "\n=== DANH SACH PHIEU SAU KHI SAP XEP GIAM DAN THEO NGAY ===\n";
                XuatPhieuBanHang(Q_PB); // In lại danh sách sau khi sắp xếp
                break;
            case 10:
                TongDoanhThu(Q_DT);
                break;
            case 11:
                cout << "Nhap IMEI thiet bi tiep nhan bao hanh: ";
                cin >> tempStr;
                TiepNhanBaoHanh(Q_PB, tempStr);
                break;
            case 0:
                cout << "\nDa Thoat chuong trinh. Cam on ban!\n";
                break;
            default:
                cout << "\nLua chon khong hop le! Vui long chon lai tu 0 den 10.\n";
                break;
        }
    } while (chon != 0);

    return 0;
}
