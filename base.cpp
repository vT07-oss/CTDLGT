#include <iostream>
using namespace std;
struct DienThoai
{
    string sMaDT, sTenDT, sThuongHieu;
    int iSoLuongTon;
    float fDonGia;
};
struct NhanVien
{
    string sMaNV, sTenNV, sEmail, sSDT;
};
struct KhachHang
{
    string sMaKH, sTenKH, sSDT;
};
struct DongHD
{
    string sMaDT;
    int iSoLuong;
    float fDonGia, fThanhTien;
};
struct HoaDon
{
    string sMaHD, sMaKH, sMaNV, sNgayLap;
    int iSoDong, iTongSL;
    float fTongTien, fGiamGia, fTongTienPhaiTra;
    DongHD dsDong[10];
};

// Cấu trúc liên kết đơn

// Dienthoai
struct NodeDT
{
    DienThoai info;
    NodeDT *next;
};
struct QLDT
{
    NodeDT *head;
    NodeDT *tail;
};

void init(QLDT &Q)
{
    Q.head = NULL;
    Q.tail = NULL;
}

// Nhan vien
struct NodeNV
{
    NhanVien info;
    NodeNV *next;
};
struct QLNV
{
    NodeNV *head;
    NodeNV *tail;
};

void init(QLNV &Q)
{
    Q.head = NULL;
    Q.tail = NULL;
}
// Khách hàng
struct NodeKH
{
    KhachHang info;
    NodeKH *next;
};
struct QLKH
{
    NodeKH *head;
    NodeKH *tail;
};
void init(QLKH &Q)
{
    Q.head = NULL;
    Q.tail = NULL;
}

// Hóa đơn
struct NodeHD
{
    HoaDon info;
    NodeHD *next;
};
struct QLHD
{
    NodeHD *head;
    NodeHD *tail;
};

void init(QLHD &Q)
{
    Q.head = NULL;
    Q.tail = NULL;
}
// cấp phát nút

NodeDT *get_Node(DienThoai x)
{
    NodeDT *p = new NodeDT;
    if (p == NULL)
    {
        cout << "Cap phat khong thanh cong";
        exit(1);
    }
    p->info = x;
    p->next = NULL;
    return p;
}

// khách hàng
NodeKH *get_Node(KhachHang x)
{
    NodeKH *p = new NodeKH;
    if (p == NULL)
    {
        cout << "Cap phat khong thanh cong";
        exit(1);
    }
    p->info = x;
    p->next = NULL;
    return p;
}
// nhân viên
NodeNV *get_Node(NhanVien x)
{
    NodeNV *p = new NodeNV;
    if (p == NULL)
    {
        cout << "Cap phat khong thanh cong";
        exit(1);
    }
    p->info = x;
    p->next = NULL;
    return p;
}
// hóa đơn
NodeHD *get_Node(HoaDon x)
{
    NodeHD *p = new NodeHD;
    if (p == NULL)
    {
        cout << "Cap phat khong thanh cong";
        exit(1);
    }
    p->info = x;
    p->next = NULL;
    return p;
}

// Hàm thêm nút
void addLast(QLDT &Q, DienThoai x)
{
    NodeDT *p = get_Node(x);
    if (Q.head == NULL)
        Q.head = Q.tail = p;
    else
    {
        Q.tail->next = p;
        Q.tail = p;
    }
}

void addLast(QLKH &Q, KhachHang x)
{
    NodeKH *p = get_Node(x);
    if (Q.head == NULL)
        Q.head = Q.tail = p;
    else
    {
        Q.tail->next = p;
        Q.tail = p;
    }
}

void addLast(QLNV &Q, NhanVien x)
{
    NodeNV *p = get_Node(x);
    if (Q.head == NULL)
        Q.head = Q.tail = p;
    else
    {
        Q.tail->next = p;
        Q.tail = p;
    }
}

void addLast(QLHD &Q, HoaDon x)
{
    NodeHD *p = get_Node(x);
    if (Q.head == NULL)
        Q.head = Q.tail = p;
    else
    {
        Q.tail->next = p;
        Q.tail = p;
    }
}

// tim kiem
NodeDT *timDienThoai(QLDT &Q, string sMaDT)
{
    NodeDT *p = Q.head;
    while (p != NULL)
    {
        if (p->info.sMaDT == sMaDT)
            return p;
        p = p->next;
    }
    return NULL;
}

float tinhGiamGiaTheoBac(float fTongTien)
{
    if (fTongTien >= 5000.0f)
        return fTongTien * 0.05f;
    if (fTongTien >= 2000.0f)
        return fTongTien * 0.03f;
    if (fTongTien >= 1000.0f)
        return fTongTien * 0.01f;
    return 0.0f;
}

void tinhToanHoaDon(HoaDon &hd)
{
    hd.iTongSL = 0;
    hd.fTongTien = 0.0f;
    for (int i = 0; i < hd.iSoDong; i++)
    {
        hd.dsDong[i].fThanhTien = (float)hd.dsDong[i].iSoLuong * hd.dsDong[i].fDonGia;
        hd.iTongSL += hd.dsDong[i].iSoLuong;
        hd.fTongTien += hd.dsDong[i].fThanhTien;
    }
    hd.fGiamGia = tinhGiamGiaTheoBac(hd.fTongTien);
    hd.fTongTienPhaiTra = hd.fTongTien - hd.fGiamGia;
}

// hàm nhập
void nhapDT(QLDT &Q)
{
    while (true)
    {
        DienThoai dt;
        cout << "\n--- NHAP DIEN THOAI MOI --- \n";
        cout << "Ma dien thoai(* de dung)  \n";
        cin >> dt.sMaDT;
        cin.ignore();
        if (dt.sMaDT == "*")
        {
            break;
        }
        cout << "Ten dien thoai:";
        getline(cin, dt.sTenDT);
        cout << "Thuong hieu:";
        getline(cin, dt.sThuongHieu);
        cout << "So luong ton`:";
        cin >> dt.iSoLuongTon;
        cout << "Don gia ban: ";
        cin >> dt.fDonGia;

        addLast(Q, dt);
        cout << "Da them dien thoai thanh cong!\n";
    }
}
void nhapKH(QLKH &Q)
{
    while (true)
    {
        KhachHang kh;
        cout << "\n--- NHAP DIEN THOAI MOI ---";
        cout << "Mã khach hang(* de dung): ";
        cin >> kh.sMaKH;
        cin.ignore();
        if (kh.sMaKH == "*")
        {
            break;
        }
        cout << "Ten Khach Hang ";
        getline(cin, kh.sTenKH);
        cout << "So dien thoai";
        cin >> kh.sSDT;
        addLast(Q, kh);
        cout << " Da them dien thoai thanh cong!\n";
    }
}
void nhapNhanVien(QLNV &Q)
{
    while (true)
    {
        NhanVien nv;
        cout << "\n--- Nhap nhan vien moi ---\n";
        cout << "Ma nhan vien ";
        cin >> nv.sMaNV;
        cin.ignore();
        if (nv.sMaNV == "*")
        {
            break;
        }
        cout << "Ten nhan vien";
        getline(cin, nv.sTenNV);
        cout << "Email ";
        cin >> nv.sEmail;
        cout << "So dien thoai: ";
        cin >> nv.sSDT;

        addLast(Q, nv);
        cout << "Da them nhan vien thanh cong!\n";
    }
}
void lapHoaDon(QLHD &QHD, QLDT &QDT)
{
    while (true)
    {
        HoaDon hd;
        cout << "\n================= LAP HOA DON MOI =================\n";
        cout << "Ma hoa don \n";
        cin >> hd.sMaHD;
        if (hd.sMaHD == "*")
            break;
        cout << "Ma khach hang \n";
        cin >> hd.sMaKH;
        cout << "Ma nhan vien lap \n";
        cin >> hd.sMaNV;
        cout << "Ngay lap (dd/mm/yyyy): \n";
        cin >> hd.sNgayLap;

        do
        {
            cout << "Nhap so dong san pham(1-10): \n ";
            cin >> hd.iSoDong;
        } while (hd.iSoDong < 1 || hd.iSoDong > 10);

        for (int i = 0; i < hd.iSoDong; i++)
        {
            cout << "\n-- Dong " << i + 1 << " --\n";
            string sMaDT;
            NodeDT *pDT = NULL;

            while (true)
            {
                cout << "Ma dien thoai ban ";
                cin >> sMaDT;
                pDT = timDienThoai(QDT, sMaDT);

                if (pDT == NULL)
                {
                    cout << "Khong tim thay ma DT! Nhập lại.\n";
                }
                else if (pDT->info.iSoLuongTon <= 0)
                {
                    cout << "San pham da het hang! Chon ma khac.\n";
                }
                else
                {
                    break;
                }
            }

            int slBan = 0;
            while (true)
            {
                cout << "So luong ban (ton: " << pDT->info.iSoLuongTon << "): ";
                cin >> slBan;
                if (slBan > 0 && slBan <= pDT->info.iSoLuongTon)
                    break;
                cout << "So luong khong hop le\n";
            }

            hd.dsDong[i].sMaDT = sMaDT;
            hd.dsDong[i].iSoLuong = slBan;
            hd.dsDong[i].fDonGia = pDT->info.fDonGia;

            pDT->info.iSoLuongTon -= slBan; // Trừ kho
        }
        tinhToanHoaDon(hd);
        addLast(QHD, hd);
        cout << "\n=> Da lap thanh cong\n";
    }
}

// ĐỌC FILE VÀ GHI FILE
void ghiTepDT(QLDT Q, string filename = "dienthoai.txt")
{
    ofstream fout(filename);
    if (!fout.is_open())
        return;
    NodeDT *p = Q.head;
    while (p != NULL)
    {
        fout << p->info.sMaDT << "\n"
             << p->info.sTenDT << "\n"
             << p->info.sThuongHieu << "\n"
             << p->info.iSoLuongTon << " "
             << p->info.fDonGia << "\n";
        p = p->next;
    }
    fout.close();
    cout << " Luu file thanh cong " << filename << "\n";
}

void docTepDT(QLDT &Q, string filename = "dienthoai.txt")
{
    ifstream fin(filename);
    if (!fin.is_open())
        return;
    init(Q);
    DienThoai dt;
    while (fin >> dt.sMaDT)
    {
        fin.ignore();
        getline(fin, dt.sTenDT);
        getline(fin, dt.sThuongHieu);
        fin >> dt.iSoLuongTon >> dt.fDonGia;
        addLast(Q, dt);
    }
    fin.close();
    cout << "Doc file thanh cong " << filename << "\n";
}

// 2. Tệp Khách hàng (khachhang.txt)
void ghiTepKH(QLKH Q, string filename = "khachhang.txt")
{
    ofstream fout(filename);
    if (!fout.is_open())
        return;
    NodeKH *p = Q.head;
    while (p != NULL)
    {
        fout << p->info.sMaKH << "\n"
             << p->info.sTenKH << "\n"
             << p->info.sSDT << "\n";
        p = p->next;
    }
    fout.close();
    cout << "Luu file thanh cong " << filename << "\n";
}

void docTepKH(QLKH &Q, string filename = "khachhang.txt")
{
    ifstream fin(filename);
    if (!fin.is_open())
        return;
    init(Q);
    KhachHang kh;
    while (fin >> kh.sMaKH)
    {
        fin.ignore();
        getline(fin, kh.sTenKH);
        fin >> kh.sSDT;
        addLast(Q, kh);
    }
    fin.close();
    cout << "Doc file thanh cong " << filename << "\n";
}

// 3. Tệp Nhân viên (nhanvien.txt)
void ghiTepNV(QLNV Q, string filename = "nhanvien.txt")
{
    ofstream fout(filename);
    if (!fout.is_open())
        return;
    NodeNV *p = Q.head;
    while (p != NULL)
    {
        fout << p->info.sMaNV << "\n"
             << p->info.sTenNV << "\n"
             << p->info.sEmail << "\n"
             << p->info.sSDT << "\n";
        p = p->next;
    }
    fout.close();
    cout << "Luu file thanh cong " << filename << "\n";
}

void docTepNV(QLNV &Q, string filename = "nhanvien.txt")
{
    ifstream fin(filename);
    if (!fin.is_open())
        return;
    init(Q);
    NhanVien nv;
    while (fin >> nv.sMaNV)
    {
        fin.ignore();
        getline(fin, nv.sTenNV);
        fin >> nv.sEmail >> nv.sSDT;
        addLast(Q, nv);
    }
    fin.close();
    cout << "Doc file thanh cong" << filename << "\n";
}

// ================= OUTPUT =================
void inDanhSachDT(QLDT Q)
{
    if (Q.head == NULL)
    {
        cout << "\n[!] Danh sach dien thoai dang trong!\n";
        return;
    }
    cout << "\n================================ DANH SACH DIEN THOAI ================================\n";
    cout << left << setw(10) << "Ma DT"
         << setw(25) << "Ten Dien Thoai"
         << setw(18) << "Thuong Hieu"
         << setw(12) << "So Luong"
         << setw(15) << "Don Gia (VND)" << endl;
    cout << string(80, '-') << endl;

    NodeDT *p = Q.head;
    while (p != NULL)
    {
        cout << left << setw(10) << p->info.sMaDT
             << setw(25) << p->info.sTenDT
             << setw(18) << p->info.sThuongHieu
             << setw(12) << p->info.iSoLuongTon
             << setw(15) << (long long)p->info.fDonGia << endl;
        p = p->next;
    }
}

void inDanhSachKH(QLKH Q)
{
    if (Q.head == NULL)
    {
        cout << "\n[!] Danh sach khach hang dang trong!\n";
        return;
    }
    cout << "\n======================== DANH SACH KHACH HANG ========================\n";
    cout << left << setw(12) << "Ma KH"
         << setw(25) << "Ten Khach Hang"
         << setw(15) << "So Dien Thoai" << endl;
    cout << string(52, '-') << endl;

    NodeKH *p = Q.head;
    while (p != NULL)
    {
        cout << left << setw(12) << p->info.sMaKH
             << setw(25) << p->info.sTenKH
             << setw(15) << p->info.sSDT << endl;
        p = p->next;
    }
}

void inDanhSachNV(QLNV Q)
{
    if (Q.head == NULL)
    {
        cout << "\n[!] Danh sach nhan vien dang trong!\n";
        return;
    }
    cout << "\n================================ DANH SACH NHAN VIEN ================================\n";
    cout << left << setw(10) << "Ma NV"
         << setw(22) << "Ten Nhan Vien"
         << setw(25) << "Email"
         << setw(15) << "So Dien Thoai" << endl;
    cout << string(72, '-') << endl;

    NodeNV *p = Q.head;
    while (p != NULL)
    {
        cout << left << setw(10) << p->info.sMaNV
             << setw(22) << p->info.sTenNV
             << setw(25) << p->info.sEmail
             << setw(15) << p->info.sSDT << endl;
        p = p->next;
    }
}

void inDanhSachHD(QLHD Q)
{
    if (Q.head == NULL)
    {
        cout << "\n[!] Danh sach hoa don dang trong!\n";
        return;
    }
    cout << "\n================================ DANH SACH HOA DON ================================\n";
    NodeHD *p = Q.head;
    int stt = 1;
    while (p != NULL)
    {
        cout << "\n[ HOA DON " << stt++ << " ]" << endl;
        cout << "Ma HD: " << p->info.sMaHD
             << " | Ngay lap: " << p->info.sNgayLap
             << " | Ma KH: " << p->info.sMaKH
             << " | Ma NV lap: " << p->info.sMaNV << endl;
        cout << "Chi tiet mat hang:\n";
        cout << "   " << left << setw(10) << "Ma DT"
             << setw(12) << "So Luong"
             << setw(18) << "Don Gia"
             << setw(18) << "Thanh Tien" << endl;
        for (int i = 0; i < p->info.iSoDong; i++)
        {
            cout << "   " << left << setw(10) << p->info.dsDong[i].sMaDT
                 << setw(12) << p->info.dsDong[i].iSoLuong
                 << setw(18) << (long long)p->info.dsDong[i].fDonGia
                 << setw(18) << (long long)p->info.dsDong[i].fThanhTien << endl;
        }
        cout << "-> Tong SL: " << p->info.iTongSL
             << " | Tong Tien: " << (long long)p->info.fTongTien << " VND"
             << " | Giam Gia: " << (long long)p->info.fGiamGia << " VND"
             << " | Phai Tra: " << (long long)p->info.fTongTienPhaiTra << " VND\n";
        cout << string(68, '-') << endl;
        p = p->next;
    }
}

// Tìm kiếm
void Theo_Ma_DT(QLDT &Q)
{
    if (Q.head == NULL)
    {
        cout << " danh muc trong \n";
        return;
    }
    string sMa;
    cout << "Nhap ma can tim: \n";
    cin >> sMa;
    NodeDT *p = timDienThoai(Q, sMa);
    if (p == NULL)
    {
        cout << "Khong co ma dien thoai can tim \n";
    }
    else
    {
        cout << " Ma:" << p->info.sMaDT;
        cout << "Ten:" << p->info.sTenDT;
        cout << "Thuong hieu:" << p->info.sThuongHieu;
        cout << "So luong ton:" << p->info.iSoLuongTon;
        cout << "Don gia:" << p->info.fDonGia;
    }
}
void TimTheoMaHD(QLHD &Q, QLDT QDT, QLKH QKH)
{
    NodeHD *p = Q.head;
    bool timThay = false;
    if (Q.head == NULL)
    {
        cout << "Khong co hoa don ton tai \n";
        return;
    }
    string sMa;
    cout << "Nhap ma hoa don cam tim: \n";
    cin >> sMa;
    while (p != NULL)
    {
        if (p == NULL)
            break;
        if (sMa == p->info.sMaHD)
        {
            cout << "Da tim thay ma \n";
            cout << "Ma hoa don: " << p->info.sMaHD << endl;
            cout << "Ngay lap : " << p->info.sNgayLap << endl;
            cout << "Ma KH : " << p->info.sMaKH << endl;
            cout << "Ma NV : " << p->info.sMaNV << endl;

            cout << "STT\tMã ĐT\tSố lượng\tĐơn giá\t\tThành tiền" << endl;
            for (int i = 0; i < p->info.iSoDong; i++)
            {
                cout << (i + 1) << "\t"
                     << p->info.dsDong[i].sMaDT << "\t"
                     << p->info.dsDong[i].iSoLuong << "\t\t"
                     << (long long)p->info.dsDong[i].fDonGia << "\t\t"
                     << (long long)p->info.dsDong[i].fThanhTien << endl;
            }
            cout << "----------------------------------------------------" << endl;
            cout << "Tong so luong: " << p->info.iTongSL << endl;
            cout << "Tong tien: " << p->info.fTongTien << endl;
            cout << "So tiem giam: " << p->info.fGiamGia << endl;
            cout << "Tong tien phai tra: " << p->info.fTongTienPhaiTra << endl;
            timThay = true;
            break;
        }
        p = p->next;
    }
    if (!timThay)
    {
        cout << "Khong co hoa don" << endl;
    }
}
// chuyển về thường
/*
string toLowerStr(string s) {
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}
void Tim_Gan_Dung(QLDT &Q){
nodeDT *p=Q.head};
string tim;
cout<<"Nhap tu khoa"<<endl();
cin>>tim;
string khoa=toLowerStr(tim);
bool timThay=false;
while(p !=NULL){
    string tenThuong = toLowerStr(p->info.sTenDT);
    string thThuong = toLowerStr(p->info.sThuongHieu);
    if()
}
*/

void KhoangGia(QLDT &Q)
{
    float min, max;
    cout << "Nhap gia tri toi thieu: \n";
    cin >> min;
    cout << "Nhap gia tri toi da: \n";
    cin >> max;
    NodeDT *p = Q.head;
    bool timthay = true;
    DienThoai ds[100];
    int count = 0;
    while (p != NULL)
    {
        if (p->info.fDonGia > min && p->info.fDonGia < max)
        {
            ds[count] = p->info;
            count++;
        }
        p = p->next;
    }
    if (count == 0)
    {
        cout << "Khong co dien thoai trong khoang gia" << endl;
    }
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (ds[i].fDonGia > ds[j].fDonGia)
            {
                swap(ds[i], ds[j]);
            }
        }
    }
    cout << "\n--- KET QUA TIM KIEM KHOANG GIA (GIA TANG DAN) ---\n";
    for (int i = 0; i < count; i++)
    {
        cout << "Ma: " << ds[i].sMaDT
             << " | Ten: " << ds[i].sTenDT
             << " | TH: " << ds[i].sThuongHieu
             << " | Ton: " << ds[i].iSoLuongTon
             << " | Gia: " << (long long)ds[i].fDonGia << " VND\n";
    }
}

// liên kết khách hàng với hóa đơn
void KhaithacLK(QLHD &QHD, QLDT &QDT)
{
    if (QHD.head == NULL)
    {
        cout << "Danh sach hoa don trong!\n";
        return;
    }

    string sMaKH;
    cout << "Nhap ma khach hang can khai thac: ";
    cin >> sMaKH;

    NodeHD *p = QHD.head;
    string dsTH[50];
    int slTH[50] = {0};
    int nTH = 0;
    bool timThay = false;
    float tongChiTieu = 0;
    float tongGiamGia = 0;
    while (p != NULL)
    {
        if (p->info.sMaKH == sMaKH)
        {
            timThay = true;
            cout << "\nMa HD: " << p->info.sMaHD << " | Ngay lap: " << p->info.sNgayLap << "\n";
            for (int i = 0; i < p->info.iSoDong; i++)
            {
                string maDT = p->info.dsDong[i].sMaDT;
                int sl = p->info.dsDong[i].iSoLuong;
                float donGia = p->info.dsDong[i].fDonGia;
                string th = "N/A";
                NodeDT *pDT = QDT.head;
                while (pDT != NULL)
                {
                    if (pDT->info.sMaDT == maDT)
                    {
                        th = pDT->info.sThuongHieu;
                        break;
                    }
                    pDT = pDT->next;
                }
                int pos = -1;
                for (int k = 0; k < nTH; k++)
                {
                    if (dsTH[k] == th)
                    {
                        pos = k;
                        break;
                    }
                }
                if (pos != -1)
                {
                    slTH[pos] += sl;
                }
                else
                {
                    dsTH[nTH] = th;
                    slTH[nTH] = sl;
                    nTH++;
                }
                cout << "  - Ma DT: " << maDT
                     << " | TH: " << th
                     << " | SL: " << sl
                     << " | Don gia: " << (long long)donGia << " VND\n";
            }
            tongChiTieu += p->info.fTongTienPhaiTra;
            tongGiamGia += p->info.fGiamGia;
        }
        p = p->next;
    }
    if (!timThay)
    {
        cout << "Khach hang chua mua hoa don nao";
        return;
    }
    string thHayChon = "N/A";
    int maxSL = 0;
    for (int i = 0; i < nTH; i++)
    {
        if (slTH[i] > maxSL)
        {
            maxSL = slTH[i];
            thHayChon = dsTH[i];
        }

        cout << "\n---------------- TONG KET KHACH HANG ----------------\n";
        cout << "Tong chi tieu cong don : " << (long long)tongChiTieu << " VND\n";
        cout << "Tong tien da duoc giam : " << (long long)tongGiamGia << " VND\n";
        cout << "Thuong hieu hay chon   : " << thHayChon << " (Da mua: " << maxSL << " may)\n";
    }
}

// YÊU CẦU tìm kiếm
void DT_Theo_Gia(QLDT &Q)
{

    if (Q.head == NULL || Q.head->next == NULL)
    {
        cout << "Khong co dien thoai duoc nhap" << endl;
    }
    for (NodeDT *p = Q.head; Q.head != NULL; p = p->next)
    {
        for (NodeDT *q; p != NULL; q = q->next)
        {
            if (p->info.fDonGia < q->info.fDonGia)
            {
                swap(p->info, q->info);
            }
        }
    }
    cout << "Sap xep thanh cong" << endl;
    inDanhSachDT(Q);
}

void DT_Theo_SoLuong(QLDT &Q)
{
    if (Q.head == NULL || Q.head->next == NULL)
    {
        cout << "Khong co dien thoai duoc nhap" << endl;
    }
    for (NodeDT *p = Q.head; Q.head != NULL; p = p->next)
    {
        for (NodeDT *q; p != NULL; q = q->next)
        {
            if (p->info.iSoLuongTon < q->info.iSoLuongTon)
            {
                swap(p->info, q->info);
            }
        }
    }
    cout << "Sap xep thanh cong" << endl;
    inDanhSachDT(Q);
}

void HD_Theo_NgayLap(QLHD &Q)
{
    if (Q.head == NULL || Q.head->next == NULL)
    {
        cout << "Khong co hoa don nao duoc lap" << endl;
    }
    for (NodeHD *p = Q.head; Q.head != NULL; p = p->next)
    {
        for (NodeHD *q; p != NULL; q = q->next)
        {
            if (p->info.sNgayLap > q->info.sNgayLap)
            {
                swap(p->info, q->info);
            }
        }
    }
}
void HD_Theo_ThuongHieu_va_Gia(QLDT &Q)
{
    if (Q.head == NULL || Q.head->next == NULL)
    {
        cout << "[!] Danh sach trong hoac chi co 1 phan tu!\n";
        return;
    }
    for (NodeDT *p = Q.head; p->next != NULL; p = p->next)
    {
        for (NodeDT *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.sThuongHieu > q->info.sThuongHieu ||
                (p->info.sThuongHieu == q->info.sThuongHieu && p->info.fDonGia < q->info.fDonGia))
            {
                swap(p->info, q->info);
            }
        }
    }
    cout << "\n>> Da sap xep dien thoai theo Thuong Hieu (TANG DAN) va Don Gia (GIAM DAN) thanh cong!\n";
}

// thống kê vào báo cáo
void Doanh_thu(QLHD &QHD, QLDT &QDT)
{
    long long tong_doanh_thu = 0, tong_giam_gia = 0, tong_ton = 0;
    int tong_sl = 0;

    NodeHD *pHD = QHD.head;
    while (pHD != NULL)
    {
        tong_doanh_thu += pHD->info.fTongTienPhaiTra;
        tong_sl += pHD->info.iTongSL;
        tong_giam_Gia += pHD->info.fGiamGia;
        pHD = pHD->next;
    }
    NodeDT *pDT = QDT.head;
    while (pDT != NULL)
    {
        tong_ton += pDT->info.iSoLuongTon * pDT->info.fDonGia;
        pDT = pDT->next;
    }
    split(20, x)
            cout
        << "Thong ke cua hang" << end;
    split(20, '-');
    cout << "Tong doanh thu cua hang:" << tong_doanh_thu << endl;
    cout << "Tong so luong dien thoai da ban:" << tong_sl << endl;
    cout << "Tong tien giam gia da cap:" << tong_giam_gia << endl;
    cout << "Tong tien ton:" << tong_ton << endl;
}

void Trung_Binh(QLHD &QHD, QLDT &QDT)
{
    NodeHD *pHD = QHD.head;
    int so_HD = 0, tong_may;
    long long tb_HD;
    while (pHD != NULL)
    {
        tb_HD += pHD->info.fTongTienPhaiTra / pHD->info.iTongSL;
        tong_may += pHD->info.iTongSL;
        so_HD += 1;
        pHD = pHD->next;
    }
    cout << "Gia tri trung binh cua mot hoa don: \n"
         << tb_HD;
    cout << "So may trung binh tren mot hoa don: \n"
         << so_HD / tong_may;
    string dsThuongHieu[20];
    double tong_gia[20];
    double so_long[20];

    NodeDT *pDT = QDT.head;
    while (pDT != NULL)
    {
        string th = pDT->info.sThuongHieu;
        int pos = -1;
        for (int i = 0; i < nTH; i++)
        {
            if (dsThuongHieu[i] == th)
            {
                pos = i;
                break;
            }
        }
        if (pos != -1)
        {
            tong_gia += pDT->info.fDonGia;
            soLuongMau[pos]++;
        }
    }
}

// Hàm bắt đầu
int main()
{
    QLDT qDT;
    init(qDT);
    QLKH qKH;
    init(qKH);
    QLNV qNV;
    init(qNV);
    QLHD qHD;
    init(qHD);
    int luaChon;
    do
    {
        cout << "\n================ MENU QUAN LY CUA HANG DIEN THOAI ================\n";
        cout << " [1] Nhap danh sach dien thoai \n";
        cout << " [2] Nhap danh sach Khach Hang\n";
        cout << " [3] Nhap danh sach Nhah Vien\n";
        cout << " [4] Lap hoa don moi (Tru kho tu dong)\n";
        cout << "-----------------------------------------------------------------\n";
        cout << " [5] IN danh sach dien thoai\n";
        cout << " [6] IN danh sach khach Hang\n";
        cout << " [7] IN danh sach nhan vien\n";
        cout << " [8] IN danh sach Don\n";
        cout << "-----------------------------------------------------------------\n";
        cout << " [9] Tim dien thoai theo Ma\n";
        cout << " [10] Tim hoa don theo Ma\n";
        cout << " [11] Tim dien thoai theo khoang gia\n";
        cout << " [12] Thong ke chi tieu khach hang\n";
        cout << "-----------------------------------------------------------------\n";
        cout << " [13] Luu  du lieu ra File (.txt)\n";
        cout << " [14] Doc  du lieu tu File (.txt)\n";
        cout << " [0] Thoat chuong trinh\n";
        cout << "=================================================================\n";
        cout << "LUA CHON CUA BAN: ";
        cin >> luaChon;

        switch (luaChon)
        {
        case 1:
            nhapDT(qDT);
            break;
        case 2:
            nhapKH(qKH);
            break;
        case 3:
            nhapNhanVien(qNV);
            break;
        case 4:
            lapHoaDon(qHD, qDT);
            break;
        case 5:
            inDanhSachDT(qDT);
            break;
        case 6:
            inDanhSachKH(qKH);
            break;
        case 7:
            inDanhSachNV(qNV);
            break;
        case 8:
            inDanhSachHD(qHD);
            break;
        case 9:
            Theo_Ma_DT(qDT);
            break;
        case 10:
            TimTheoMaHD(qHD, qDT, qKH);
            break;
        case 11:
            KhoangGia(qDT);
            break;
        case 12:
            KhaithacLK(qHD, qDT);
            break;
        case 13:
            ghiTepDT(qDT);
            ghiTepKH(qKH);
            ghiTepNV(qNV);
            cout << ">> Luu du lieu thanh cong!\n";
            break;
        case 14:
            docTepDT(qDT);
            docTepKH(qKH);
            docTepNV(qNV);
            cout << ">> Da doc toan bo du lieu thanh cong!\n";
            break;
        case 0:
            cout << "Cam on ban da su dung chuong trinh!\n";
            break;
        default:
            cout << "Lua chon khong hop le, vui long nhap lai!\n";
            break;
        }
    } while (luaChon != 0);

    return 0;
}
