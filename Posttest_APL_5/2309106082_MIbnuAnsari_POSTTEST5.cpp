#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_MAHASISWA = 30;

struct Mahasiswa {
    string nim, nama, kelas;
};

void tampilanmenu() {
    cout << "+----------------------------+" << endl;
    cout << "|    List Data Mahasiswa     |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|        MENU UTAMA          |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|1. Tambah data Mahasiswa    |" << endl;
    cout << "|2. Tampilkan data mahasiswa |" << endl;
    cout << "|3. Ubah data mahasiswa      |" << endl;
    cout << "|4. Hapus data mahasiswa     |" << endl;
    cout << "|5. Lihat Detail Mahasiswa   |" << endl;  
    cout << "|6. Keluar                   |" << endl;
    cout << "+----------------------------+" << endl;
}

bool tambahdata(Mahasiswa* mahasiswa[], int& data) {
    if (data < MAX_MAHASISWA) {
        mahasiswa[data] = new Mahasiswa;
        
        cout << "Masukkan Nama Mahasiswa : ";
        getline(cin, mahasiswa[data]->nama);
        cout << "Masukkan NIM Mahasiswa : ";
        getline(cin, mahasiswa[data]->nim);
        cout << "Masukkan Kelas Mahasiswa : ";
        getline(cin, mahasiswa[data]->kelas);
        
        data++;
        cout << "Data telah ditambahkan" << endl;
        return true;
    } else {
        cout << "Batas maksimum jumlah mahasiswa telah tercapai." << endl;
        return false;
    }
}

void tampilkandata(Mahasiswa* mahasiswa[], int jumlahData) {
    cout << "+-------------------------------+" << endl;
    cout << "|         Data Mahasiswa        |" << endl;
    cout << "+-------------------------------+" << endl;
    for (int i = 0; i < jumlahData; i++) {
        cout << "ID     : " << i + 1 << endl;
        cout << "Nama   : " << mahasiswa[i]->nama << endl;
        cout << "NIM    : " << mahasiswa[i]->nim << endl;
        cout << "Kelas  : " << mahasiswa[i]->kelas << endl;
        cout << "---------------------------------" << endl;
    }
}

void ubahdata(Mahasiswa* mahasiswa[], int& data) {
    int update;
    tampilkandata(mahasiswa, data);
    cout << "Masukkan ID Mahasiswa yang ingin diupdate : ";
    if (!(cin >> update)) {
        cout << "Input harus berupa angka." << endl;
        cin.clear();
        cin.ignore();
        return;
    }
    cin.ignore();

    if (update >= 1 && update <= data) {
        cout << "Masukkan nama mahasiswa baru : ";
        getline(cin, mahasiswa[update - 1]->nama);
        cout << "Masukkan NIM mahasiswa baru : ";
        getline(cin, mahasiswa[update - 1]->nim);
        cout << "Masukkan kelas mahasiswa baru : ";
        getline(cin, mahasiswa[update - 1]->kelas);
        cout << "Data mahasiswa berhasil diupdate" << endl;
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}

void hapusdata(Mahasiswa* mahasiswa[], int& data) {
    int temp;
    tampilkandata(mahasiswa, data);
    cout << "Masukkan ID Mahasiswa yang ingin dihapus : ";
    if (!(cin >> temp)) {
        cout << "Input harus berupa angka." << endl;
        cin.clear();
        cin.ignore();
        return;
    }

    if (temp >= 1 && temp <= data) {
        delete mahasiswa[temp - 1];
        
        for (int i = temp - 1; i < data - 1; i++) {
            mahasiswa[i] = mahasiswa[i + 1];
        }
        data--;
        cout << "Data mahasiswa berhasil dihapus" << endl;
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}

void lihatDetailMahasiswa(Mahasiswa* mahasiswa[], int jumlahData) {
    int id;
    cout << "Masukkan ID Mahasiswa : ";
    if (!(cin >> id)) {
        cout << "Input harus berupa angka." << endl;
        cin.clear();
        cin.ignore();
        return;
    }

    if (id >= 1 && id <= jumlahData) {
        cout << "+--------------------------------+" << endl;
        cout << "|        Detail Mahasiswa         |" << endl;
        cout << "+--------------------------------+" << endl;
        cout << "Alamat : " << mahasiswa[id - 1] << endl;
        cout << "Nama   : " << mahasiswa[id - 1]->nama << endl;
        cout << "NIM    : " << mahasiswa[id - 1]->nim << endl;
        cout << "Kelas  : " << mahasiswa[id - 1]->kelas << endl;
        cout << "+--------------------------------+" << endl;
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}

void lihatdetail(Mahasiswa* mahasiswa[], int jumlahData) {
    system("cls");
    tampilkandata(mahasiswa, jumlahData);
    lihatDetailMahasiswa(mahasiswa, jumlahData);
    cin.ignore();
    cin.ignore();
}
int main() {
    int salah = 0;
    string menu, nama, nim;
    Mahasiswa* mahasiswa[MAX_MAHASISWA];
    int data = 0;

    for (int i = 0; i < MAX_MAHASISWA; i++) {
        mahasiswa[i] = nullptr;
    }

    while (salah < 3) {
        cout << "+-------------------------+" << endl;
        cout << "|     Selamat Datang,     |" << endl;
        cout << "|    Login untuk masuk    |" << endl;
        cout << "+-------------------------+" << endl;
        cout << "\nMasukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);
        cin.ignore();
        
        if (nama == "M Ibnu Ansari" && nim == "2309106082") {
            cout << "Login berhasil!" << endl;
            cin.ignore();
            
            
            while (true) {
                system("cls");
                tampilanmenu();
                cout << "Pilih menu: ";
                cin >> menu;

                cin.ignore(); 

                if (menu == "1") {
                    system("cls");
                    tambahdata(mahasiswa, data);
                    cin.ignore();
                } else if (menu == "2") {
                    system("cls");
                    tampilkandata(mahasiswa, data);
                    cin.ignore();
                    cin.ignore();
                } else if (menu == "3") {
                    system("cls");
                    ubahdata(mahasiswa, data);
                    cin.ignore();
                } else if (menu == "4") {
                    system("cls");
                    hapusdata(mahasiswa, data);
                    cin.ignore();
                    cin.ignore();
                } else if (menu == "5") {
                    system("cls");
                    lihatdetail(mahasiswa, data);  
                } else if (menu == "6") {
                    system("cls");
                    cout << "Program berhenti. Terima kasih!" << endl;
                    return 0;
                    for (int i = 0; i < data; i++) {
                        delete mahasiswa[i];
                    }
                } 
            }
        } else {
            cout << "Nama atau NIM anda salah, coba lagi." << endl;
            salah++;
        }
    }

    if (salah == 3) {
        cout << "Anda sudah gagal login sebanyak 3 kali. Program berhenti." << endl;
        
        for (int i = 0; i < data; i++) {
            delete mahasiswa[i];
        }
    }

    cout << "Terima kasih telah menggunakan program" << endl;

    return 0;
}
