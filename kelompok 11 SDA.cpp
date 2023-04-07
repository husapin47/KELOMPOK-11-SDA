#include <iostream>
#include <stack>
using namespace std;

const int MAX = 100; // ukuran array
int belanja[MAX]; // array untuk menyimpan daftar belanja
int n; // jumlah item belanja
int totalBelanja; // total belanjaan
int totalPembayaran; // total pembayaran
stack<int> s; // stack untuk menyimpan harga belanja

// Prosedur untuk menginput daftar belanja
void inputBelanja() {
    cout << "Masukkan jumlah item belanja: ";
    cin >> n;
    cout << "Masukkan harga belanja:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item ke-" << i+1 << ": ";
        cin >> belanja[i];
    }
}

// Fungsi untuk menghitung total belanja
int hitungTotalBelanja() {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += belanja[i];
    }
    return total;
}

// Prosedur untuk menampilkan daftar belanja dan total belanja
void tampilkanBelanja() {
    cout << "Daftar Belanja:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item ke-" << i+1 << ": " << belanja[i] << endl;
    }
    totalBelanja = hitungTotalBelanja();
    cout << "Total belanja: " << totalBelanja << endl;
}

// Prosedur untuk menginput pembayaran dan menghitung total pembayaran
void inputPembayaran() {
    int bayar, kembalian;
    while (true) {
        cout << "Masukkan pembayaran: ";
        cin >> bayar;
        s.push(bayar);
        totalPembayaran += bayar;
        if (totalPembayaran >= totalBelanja) {
            kembalian = totalPembayaran - totalBelanja;
            break;
        }
        else {
            cout << "Total pembayaran: " << totalPembayaran << endl;
        }
    }
    cout << "Total pembayaran: " << totalPembayaran << endl;
    cout << "Kembalian: " << kembalian << endl;
}

int main() {
    inputBelanja();
    tampilkanBelanja();
    inputPembayaran();
    return 0;
}


