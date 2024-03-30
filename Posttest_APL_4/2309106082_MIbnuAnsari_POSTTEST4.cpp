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
    cout << "|5. Keluar                   |" << endl;
    cout << "+----------------------------+" << endl;
}

bool tambahdata(Mahasiswa mahasiswa[], int &data) {
    if (data < MAX_MAHASISWA) {
        cout << "Masukkan Nama Mahasiswa : ";
        getline(cin, mahasiswa[data].nama);
        cout << "Masukkan NIM Mahasiswa : ";
        getline(cin, mahasiswa[data].nim);
        cout << "Masukkan Kelas Mahasiswa : ";
        getline(cin, mahasiswa[data].kelas);
        data++;
        cout << "Data telah ditambahkan" << endl;
        return true;
    } else {
        cout << "Batas maksimum jumlah mahasiswa telah tercapai." << endl;
        return false;
    }
}

void tampilkandata(const Mahasiswa mahasiswa[], int jumlahData) {
    cout << "+-------------------------------+" << endl;
    cout << "|         Data Mahasiswa        |" << endl;
    cout << "+-------------------------------+" << endl;
    for (int i = 0; i < jumlahData; i++) {
        cout << "ID     : " << i + 1 << endl;
        cout << "Nama   : " << mahasiswa[i].nama << endl;
        cout << "NIM    : " << mahasiswa[i].nim << endl;
        cout << "Kelas  : " << mahasiswa[i].kelas << endl;
        cout << "---------------------------------" << endl;
    }
}

void ubahdata(Mahasiswa mahasiswa[], int &data) {
    int update;
    cout << "Masukkan ID Mahasiswa yang ingin diupdate : ";
    if (!(cin >> update)) {
        cout << "Input harus berupa angka." << endl;
        cin.clear();
        cin.ignore();
        cin.ignore();
        return;
    }
    cin.ignore();

    if (update >= 1 && update <= data) {
        cout << "Masukkan nama mahasiswa baru : ";
        getline(cin, mahasiswa[update - 1].nama);
        cout << "Masukkan NIM mahasiswa baru : ";
        getline(cin, mahasiswa[update - 1].nim);
        cout << "Masukkan kelas mahasiswa baru : ";
        getline(cin, mahasiswa[update - 1].kelas);
        cout << "Data mahasiswa berhasil diupdate" << endl;
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}

void hapusdata(Mahasiswa mahasiswa[], int& data) {
    int temp;
    cout << "Masukkan ID Mahasiswa yang ingin dihapus : ";
    if (!(cin >> temp)) {
        cout << "Input harus berupa angka." << endl;
        cin.clear();
        cin.ignore();
        cin.ignore();
        return;
    }

    if (temp >= 1 && temp <= data) {
        for (int i = temp - 1; i < data - 1; i++) {
            mahasiswa[i] = mahasiswa[i + 1];
        }
        data--;
        cout << "Data mahasiswa berhasil dihapus" << endl;
    } else {
        cout << "Indeks tidak valid." << endl;
    }
}


int main() {
    int salah = 0;
    string menu, nama, nim;
    Mahasiswa mahasiswa[MAX_MAHASISWA];
    int data = 0;

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

                if (menu == "1") {
                    cin.ignore();
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
                    tampilkandata(mahasiswa, data);
                    ubahdata(mahasiswa, data);
                    cin.ignore();
                } else if (menu == "4") {
                    system("cls");
                    tampilkandata(mahasiswa, data);
                    hapusdata(mahasiswa, data);
                    cin.ignore();
                    cin.ignore();
                } else if (menu == "5") {
                    system("cls");
                    cout << "Program berhenti. Terima kasih!" << endl;
                    return 0;
                }
            }
        } else {
            cout << "Nama atau NIM anda salah, coba lagi." << endl;
            salah++; 
        }
    }

    if (salah == 3) {
        cout << "Anda sudah gagal login sebanyak 3 kali. Program berhenti." << endl;
        return 0;
    }

    cout << "Terima kasih telah menggunakan program" << endl;

    return 0;
}
