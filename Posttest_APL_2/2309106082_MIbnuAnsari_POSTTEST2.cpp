#include <iostream>


using namespace std;

// Fungsi untuk menampilkan data mahasiswa
void tampilkanMahasiswa(const string mahasiswa[], int jumlahData) {
    cout << "==================" << endl;
    cout << "= Data Mahasiswa =" << endl;
    cout << "==================" << endl;
    cout << "=  NIM  =  Nama   =" << endl;
    cout << "==================" << endl;
    for (int i = 0; i < jumlahData; i++) {
        cout << "[23091060" << i + 1 << "]-" << mahasiswa[i] << endl;
    }
}

int main() {
    int salah = 0;
    string menu, nama, nim;
    string mahasiswa[30];
    int data = 0;

    while (salah < 3) {
        
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);
        cin.ignore();


        if (nama == "M Ibnu Ansari" && nim == "2309106082") {
            cout << "Login berhasil!" << endl;
            cin.ignore();
            while (true) {
                system("cls");
                cout << "===========================" << endl;
                cout << "=== List Data Mahasiswa ===" << endl;
                cout << "===========================" << endl;
                cout << "=      MENU UTAMA         =" << endl;
                cout << "\n1. Tambah data Mahasiswa" << endl;
                cout << "2. Tampilkan data mahasiswa" << endl;
                cout << "3. Ubah data mahasiswa" << endl;
                cout << "4. Hapus data mahasiswa" << endl;
                cout << "5. Keluar" << endl;
                cout << "Pilih menu: ";
                cin >> menu;

                if (menu == "1") {
                    cin.ignore();
                    cout << "Masukkan nama Mahasiswa : ";
                    getline(cin, mahasiswa[data]);
                    data++;
                    cout << "Data telah ditambahkan" << endl;
                    cin.ignore();
                } 
                
                else if (menu == "2") {
                    system("cls");
                    tampilkanMahasiswa(mahasiswa, data);
                    cin.ignore();
                    cin.ignore();
                } 
                
                else if (menu == "3") {
                    system("cls");
                    tampilkanMahasiswa(mahasiswa, data);
                    int update;
                    cout << "Masukkan angka indeks terakhir dari nama yang ingin di update : ";
                    cin >> update;
                    if (update >= 1 && update <= data) {
                        cout << "Masukkan nama mahasiswa baru : ";
                        cin >> mahasiswa[update - 1];
                        cout << "Data mahasiswa berhasil diupdate" << endl;
                        cin.ignore();
                        cin.ignore();
                    } else {
                        cout << "Indeks tidak valid." << endl;
                        cin.ignore();
                    }
                } 
                
                else if (menu == "4") {
                    system("cls");
                    tampilkanMahasiswa(mahasiswa, data);
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
                    } else {
                        cout << "Indeks tidak valid." << endl;
                        cin.ignore();
                    }
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
