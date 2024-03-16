#include <iostream>

using namespace std;

const int MAX_MAHASISWA = 30;

// Fungsi untuk menampilkan menu
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

// Fungsi untuk menambahkan data mahasiswa
bool tambahdata(string mahasiswa[], int &data) {
    if (data < MAX_MAHASISWA) {
        cout << "Masukkan nama Mahasiswa : ";
        getline(cin, mahasiswa[data]);
        data++;
        cout << "Data telah ditambahkan" << endl;
        return true;
    } else {
        cout << "Batas maksimum jumlah mahasiswa telah tercapai." << endl;
        return false;
    }
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkandata(const string mahasiswa[], int jumlahData) {
    cout << "+-------------------------------+" << endl;
    cout << "|        Data Mahasiswa         |" << endl;
    cout << "+-------------------------------+" << endl;
    cout << "|   NIM    |        Nama        |" << endl;
    cout << "+----------+--------------------+" << endl;
    for (int i = 0; i < jumlahData; i++) {
        cout << "|23091060" << i + 1 << " | " << mahasiswa[i] << endl;
        cout << "+----------+--------------------+" << endl;
    }
}

// Fungsi untuk mengubah data mahasiswa
bool ubahdata(string mahasiswa[], int &data) {
    int update;
    cout << "Masukkan angka indeks terakhir dari nama yang ingin diupdate : ";
    cin >> update;
    cin.ignore(); 
    if (update >= 1 && update <= data) {
        cout << "Masukkan nama mahasiswa baru : ";
        getline(cin, mahasiswa[update - 1]);
        cout << "Data mahasiswa berhasil diupdate" << endl;
        cin.ignore();
        return true;
    } else {
        cout << "Indeks tidak valid." << endl;
        return false;
    }
}

// Fungsi rekursif untuk menghapus data mahasiswa
void hapusdata(string mahasiswa[], int& data) {
    int temp;
    cout << "Masukkan angka indeks terakhir dari nama yang ingin dihapus : ";
    cin >> temp;

    if (temp >= 1 && temp <= data) {
        for (int i = temp - 1; i < data - 1; i++) {
            mahasiswa[i] = mahasiswa[i + 1];
        }
        data--;
        cout << "Data mahasiswa berhasil dihapus" << endl;
        cin.ignore();
        cin.ignore();
    } else {
        cout << "Indeks tidak valid." << endl;
        cin.ignore();
        hapusdata(mahasiswa, data); 
    }
}

int main() {
    int salah = 0;
    string menu, nama, nim;
    string mahasiswa[MAX_MAHASISWA];
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
                } 
                
                else if (menu == "2") {
                    system("cls");
                    tampilkandata(mahasiswa, data);
                    cin.ignore();
                    cin.ignore();
                } 
                
                else if (menu == "3") {
                    system("cls");
                    tampilkandata(mahasiswa, data);
                    ubahdata(mahasiswa, data);
                } 
                
                else if (menu == "4") {
                    system("cls");
                    tampilkandata(mahasiswa, data);
                    hapusdata(mahasiswa,data);
                }
                
                else if (menu == "5") {
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
