#include <iostream>
using namespace std;

struct node {
    int data;
    node* kiri;
    node* kanan;
};
void addnode(node** akar, int isi) {
    if (*akar == NULL) {
        node* baru = new node;
        baru->data = isi;
        baru->kiri = NULL;
        baru->kanan = NULL;
        *akar = baru;
    } else if (isi < (*akar)->data) {
        addnode(&((*akar)->kiri), isi);  // Lebih kecil -> masuk ke kiri
    } else if (isi > (*akar)->data) {
        addnode(&((*akar)->kanan), isi); // Lebih besar -> masuk ke kanan
    }
}

void preorder(node* akar) {
    if (akar != NULL) {
        cout << akar->data << " ";
        preorder(akar->kiri);
        preorder(akar->kanan);
    }
}

void inorder(node* akar) {
    if (akar != NULL) {
        inorder(akar->kiri);
        cout << akar->data << " ";
        inorder(akar->kanan);
    }
}

void postorder(node* akar) {
    if (akar != NULL) {
        postorder(akar->kiri);
        postorder(akar->kanan);
        cout << akar->data << " ";
    }
}

int main() {
    node* akar = NULL;
    int angka;

    cout << "Masukkan angka sebagai root (masukkan 0 untuk batal): ";
    cin >> angka;

    if (angka != 0) {
        addnode(&akar, angka); // Membentuk root pertama

        while (true) {
            cout << "Masukkan angka selanjutnya (0 untuk selesai): ";
            cin >> angka;

            if (angka == 0) {
                break; // Berhenti jika pengguna memasukkan 0
            }

            addnode(&akar, angka);
        }
    }

    // Traversal
    cout << "\nTampilkan pre-order  : ";
    preorder(akar);
    cout << "\nTampilkan in-order   : ";
    inorder(akar);
    cout << "\nTampilkan post-order : ";
    postorder(akar);
    cout << endl;

    return 0;
}