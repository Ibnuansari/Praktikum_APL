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
    cout << "|5. Urutkan data mahasiswa   |" << endl;
    cout << "|6. Cari data mahasiswa      |" << endl;
    cout << "|7. Keluar                   |" << endl;
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
    tampilkandata(mahasiswa, data);
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
    tampilkandata(mahasiswa, data);
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

void urutkandatanamadesc(Mahasiswa mahasiswa[], int jumlahData) {
    cout << "+-------------------------------+" << endl;
    cout << "|         Data Mahasiswa        |" << endl;
    cout << "+-------------------------------+" << endl;
    cout << "|     Urutan nama descending    |" << endl;
    cout << "+-------------------------------+" << endl;

    string array[MAX_MAHASISWA];
    for (int i = 0; i < jumlahData; i++) {
        array[i] = mahasiswa[i].nama;
    }

    string swap;
    for (int i = 0; i < jumlahData; i++) {
        for (int j = 0; j < (jumlahData - i - 1); j++) {
            if(array[j] < array[j+1]) { 
                swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap;
            }
        }
    }
        
    for (int i = 0; i < jumlahData; i++) {
        for (int j = 0; j < jumlahData; j++) {
            if (array[i] == mahasiswa[j].nama) {
                cout << "ID     : " << j + 1 << endl;
                cout << "Nama   : " << mahasiswa[j].nama << endl;
                cout << "NIM    : " << mahasiswa[j].nim << endl;
                cout << "Kelas  : " << mahasiswa[j].kelas << endl;
                cout << "---------------------------------" << endl;
                break;
            }
        }
    }
}

void urutkandataasc(Mahasiswa mahasiswa[], int jumlahData) {
    cout << "+-------------------------------+" << endl;
    cout << "|         Data Mahasiswa        |" << endl;
    cout << "+-------------------------------+" << endl;
    cout << "|     Urutan nim ascending      |" << endl;
    cout << "+-------------------------------+" << endl;

    string array[MAX_MAHASISWA];
    for (int i = 0; i < jumlahData; i++) {
        array[i] = mahasiswa[i].nim;
    }

    for (int i = 0; i < jumlahData - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < jumlahData; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        string temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }

    for (int i = 0; i < jumlahData; i++) {
        for (int j = 0; j < jumlahData; j++) {
            if (array[i] == mahasiswa[j].nim) {
                cout << "ID     : " << j + 1 << endl;
                cout << "Nama   : " << mahasiswa[j].nama << endl;
                cout << "NIM    : " << mahasiswa[j].nim << endl;
                cout << "Kelas  : " << mahasiswa[j].kelas << endl;
                cout << "---------------------------------" << endl;
                break;
            }
        }
    }
}

void urutkandatanimdesc(Mahasiswa mahasiswa[], int jumlahData) {
    cout << "+-------------------------------+" << endl;
    cout << "|         Data Mahasiswa        |" << endl;
    cout << "+-------------------------------+" << endl;
    cout << "|     Urutan nim descending     |" << endl;
    cout << "+-------------------------------+" << endl;

    int array[MAX_MAHASISWA];
    for (int i = 0; i < jumlahData; i++) {
        array[i] = stoi(mahasiswa[i].nim);
    }

    int swap;
    for (int i = 1; i < jumlahData; i++) {
        swap = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] < swap) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = swap;
    }

    for (int i = 0; i < jumlahData; i++) {
        for (int j = 0; j < jumlahData; j++) {
            if (array[i] == stoi(mahasiswa[j].nim)) {
                cout << "ID     : " << j + 1 << endl;
                cout << "Nama   : " << mahasiswa[j].nama << endl;
                cout << "NIM    : " << mahasiswa[j].nim << endl;
                cout << "Kelas  : " << mahasiswa[j].kelas << endl;
                cout << "---------------------------------" << endl;
                break;
            }
        }
    }
}

void menusorting(Mahasiswa mahasiswa[], int &data){
    cout << "+-----------------------------------+" << endl;
    cout << "|          Menu Sorting             |" << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "| 1. Urutkan nama secara descending |" << endl;
    cout << "| 2. Urutkan nim secara ascending   |" << endl;
    cout << "| 3. Urutkan nim secara descending  |" << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "Pilih menu : ";
    string menusort;
    cin >> menusort;

    if (menusort == "1"){
        system("cls");
        urutkandatanamadesc(mahasiswa, data);
        cin.ignore();
    } else if (menusort == "2"){
        system("cls");
        urutkandataasc(mahasiswa, data);
        cin.ignore();
    } else if (menusort == "3"){
        system("cls");
        urutkandatanimdesc(mahasiswa, data);
        cin.ignore();
    } else {
        cout << "Pilihan tidak valid";
    }
}

void carinamaasc(Mahasiswa mahasiswa[], int jumlahData) {
    string array[MAX_MAHASISWA];
    for (int i = 0; i < jumlahData; i++) {
        array[i] = mahasiswa[i].nama;
    }

    string key;
    cout << "Masukkan nama yang ingin dicari: ";
    cin >> key;

    bool cari = false;
    for (int i = 0; i < jumlahData; i++) {
        if (array[i] == key) {
            cout << "Data ditemukan pada ID " << i + 1 << endl;
            cout << "Nama   : " << mahasiswa[i].nama << endl;
            cout << "NIM    : " << mahasiswa[i].nim << endl;
            cout << "Kelas  : " << mahasiswa[i].kelas << endl;
            cari = true;
            break;
        }
    }

    if (!cari) {
        cout << "Data tidak ditemukan." << endl;
    }
}

void carinimdesc(Mahasiswa mahasiswa[], int jumlahData) {
    string array[MAX_MAHASISWA];
    for (int i = 0; i < jumlahData; i++) {
        array[i] = mahasiswa[i].nim;
    }

    string key;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> key;

    bool cari = false;
    for (int i = 0; i < jumlahData; i++) {
        if (array[i] == key) {
            cout << "Data ditemukan pada ID " << i + 1 << endl;
            cout << "Nama   : " << mahasiswa[i].nama << endl;
            cout << "NIM    : " << mahasiswa[i].nim << endl;
            cout << "Kelas  : " << mahasiswa[i].kelas << endl;
            cari = true;
            break;
        }
    }

    if (!cari) {
        cout << "Data tidak ditemukan." << endl;
    }
}

void menucaridata(Mahasiswa mahasiswa[], int &data){
    cout << "+------------------------------+" << endl;
    cout << "|        Menu Searching        |" << endl;
    cout << "+------------------------------+" << endl;
    cout << "| 1. Cari nama (ascending)     |" << endl;
    cout << "| 2. Cari nim (descending)     |" << endl;
    cout << "+------------------------------+" << endl;
    cout << "Pilih menu : ";
    string menucari;
    cin >> menucari;

    if (menucari == "1"){
        system("cls");
        urutkandataasc(mahasiswa, data);
        carinamaasc(mahasiswa, data);
        cin.ignore();
    } else if (menucari == "2"){
        system("cls");
        urutkandatanimdesc(mahasiswa, data);
        carinimdesc(mahasiswa, data);
        cin.ignore();
    } else {
        cout << "Pilihan tidak valid";
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

        if (nama == "ibnu" && nim == "82") {
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
                    ubahdata(mahasiswa, data);
                    cin.ignore();
                } else if (menu == "4") {
                    system("cls");
                    hapusdata(mahasiswa, data);
                    cin.ignore();
                    cin.ignore();
                } else if (menu == "5") {
                    system("cls");
                    menusorting(mahasiswa, data);
                    cin.ignore();
                    cin.ignore();
                } else if (menu == "6") {
                    system("cls");
                    menucaridata(mahasiswa, data);
                    cin.ignore();
                } else if (menu == "7") {
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