#include <iostream>

using namespace std;

// Fungsi untuk registrasi pengguna
void registerUser(string &username, string &password) {
    cout << "=== Registrasi Pengguna ===" << endl;
    cout << "Masukkan Nama: ";
    cin >> username;
    cout << "Masukkan NIM: ";
    cin >> password;
    cout << "Registrasi berhasil!" << endl;
}

// Fungsi untuk login
bool loginUser(const string &username, const string &password) {
    string input_username, input_password;
    cout << "=== Login ===" << endl;
    cout << "Masukkan Nama: ";
    cin >> input_username;
    cout << "Masukkan NIM: ";
    cin >> input_password;

    if (input_username == username && input_password == password) {
        cout << "Login berhasil!" << endl;
        return true;
    } else {
        cout << "Username atau password salah." << endl;
        return false;
        
    }
}

// Fungsi untuk konversi km/jam ke cm/detik
double kmperjamkecentidetik(double kmperjam) {
    return kmperjam * 100000 / 3600; 
}

// Fungsi untuk konversi km/jam ke m/detik
double kmperjamkemdetik(double kmperjam) {
    return kmperjam * 1000 / 3600; 
}

// Fungsi untuk konversi km/jam ke mil/jam
double kmperjamkemiljam(double kmperjam) {
    return kmperjam / 1.60934; 
}

// Fungsi untuk konversi cm/detik ke km/jam
double cm_per_detik_ke_km_per_jam(double cmperdetik) {
    return cmperdetik * 0.036;
}

// Fungsi untuk konversi cm/detik ke m/detik
double cm_per_detik_ke_m_per_detik(double cmperdetik) {
    return cmperdetik * 0.01;
}

// Fungsi untuk konversi cm/detik ke mil/jam
double cm_per_detik_ke_mil_per_jam(double cmperdetik) {
    return cmperdetik * 0.0223694;
}

// Fungsi untuk konversi m/detik ke km/jam
double m_per_detik_ke_km_per_jam(double mperdetik) {
    return mperdetik * 3.6;
}

// Fungsi untuk konversi m/detik ke cm/detik
double m_per_detik_ke_cm_per_detik(double mperdetik) {
    return mperdetik * 100;
}

// Fungsi untuk konversi m/detik ke mil/jam
double m_per_detik_ke_mil_per_jam(double mperdetik) {
    return mperdetik * 2.23694;
}

// fungsi untuk konversi Mil/jam ke km/jam
double mil_per_jam_ke_km_per_jam(double milperjam) {
    return milperjam * 1.60934;
}

// fungsi untuk konversi Mil/jam ke cm/detik
double mil_per_jam_ke_cm_per_detik(double milperjam) {
    return milperjam * 44.704;
}

// fungsi untuk konversi Mil/jam ke m/detik
double mil_per_jam_ke_m_per_detik(double milperjam) {
    return milperjam * 0.44704;
}

int main() {
    string username, password;
    char pilihan;
    int bataslogin = 0;
    bool login = false;

    do {
        cout << "==============" << endl;
        cout << "=    Menu    =" << endl;
        cout << "==============" << endl;
        cout << "1. Registrasi" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                registerUser(username, password);
                break;
            case '2':
                if (!username.empty() && !password.empty()) {
                    if (loginUser(username, password)) {
                        login = true; 
                        bataslogin = 0; 
                    } else {
                        bataslogin++;
                        if (bataslogin >= 3) {
                            cout << "Anda telah melebihi batas percobaan. Program berhenti." << endl;
                            return 0;
                        }
                    }
                } else {
                    cout << "Silakan registrasi terlebih dahulu." << endl;
                }
                break;
            case '3':
                cout << "Program berhenti. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
        }

        // Setelah berhasil login, tampilkan menu konversi kecepatan
        if (login && pilihan == '2') {
            // Tampilkan menu konversi kecepatan
            char opsikonversi;
            do {
                cout << "\n===========================" << endl;
                cout << "= Menu Konversi Kecepatan =" << endl;
                cout << "===========================" << endl;
                cout << "1. Konversi Kilometer/jam " << endl;
                cout << "2. Konversi Centimeter/detik " << endl;
                cout << "3. Konversi Meter/detik " << endl;
                cout << "4. Konversi Mil/jam " << endl;
                cout << "5. Kembali ke menu awal untuk berhenti" << endl;
                cout << "Pilih opsi : ";
                cin >> opsikonversi;

                // Memilih opsi konversi berdasarkan input pengguna
                switch (opsikonversi) {
                    // Implementasikan fungsi konversi seperti yang telah diberikan sebelumnya
                    // Anda dapat memanggil fungsi-fungsi konversi di sini
                    case '1':
                        double kmperjam;

                        cout << "\nMasukkan kecepatan dalam Kilometer/jam: ";
                        cin >> kmperjam;
                        cout << "==============================" << endl;
                        cout << kmperjam << " Kilometer/jam sama dengan:" << endl;
                        cout << "==============================" << endl;
                        cout << kmperjamkecentidetik(kmperjam) << " Centimeter/detik" << endl;
                        cout << kmperjamkemdetik(kmperjam) << " Meter/detik" << endl;
                        cout << kmperjamkemiljam(kmperjam) << " Mil/jam" << endl;
                        cout << "==============================" << endl;
                        break;
                    case '2':
                        double cmperdetik;

                        cout << "\nMasukkan kecepatan dalam Centimeter/detik: ";
                        cin >> cmperdetik;
                        cout << "==============================" << endl;
                        cout << cmperdetik << " Centimeter/detik sama dengan:" << endl;
                        cout << "==============================" << endl;
                        cout << cm_per_detik_ke_km_per_jam(cmperdetik) << " Kilometer/jam" << endl;
                        cout << cm_per_detik_ke_m_per_detik(cmperdetik) << " Meter/detik" << endl;
                        cout << cm_per_detik_ke_mil_per_jam(cmperdetik) << " Mil/jam" << endl;
                        cout << "==============================" << endl;
                        break;
                    case '3':
                        double mperdetik;

                        cout << "\nMasukkan kecepatan dalam Meter/detik: ";
                        cin >> mperdetik;
                        cout << "==============================" << endl;
                        cout << mperdetik << " Meter/detik sama dengan:" << endl;
                        cout << "==============================" << endl;
                        cout << m_per_detik_ke_km_per_jam(mperdetik) << " Kilometer/jam" << endl;
                        cout << m_per_detik_ke_cm_per_detik(mperdetik) << " Centimeter/detik" << endl;
                        cout << m_per_detik_ke_mil_per_jam(mperdetik) << " Mil/jam" << endl;
                        cout << "==============================" << endl;
                        break;
                    case '4':
                        double milperjam;

                        cout << "\nMasukkan kecepatan dalam Mil/jam: ";
                        cin >> milperjam;
                        cout << "==============================" << endl;
                        cout << milperjam << " Mil/jam sama dengan:" << endl;
                        cout << "==============================" << endl;
                        cout << mil_per_jam_ke_km_per_jam(milperjam) << " Kilometer/jam" << endl;
                        cout << mil_per_jam_ke_cm_per_detik(milperjam) << " centimeter/detik" << endl;
                        cout << mil_per_jam_ke_m_per_detik(milperjam) << " Meter/detik" << endl;
                        cout << "==============================" << endl;
                        break;
                    case '5':
                        // Kembali ke menu utama
                        break;
                    default:
                        cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
                }
            } while (opsikonversi != '5');
        }
    } while (pilihan != '3');

    return 0;
}
