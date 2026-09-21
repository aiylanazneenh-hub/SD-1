#include <iostream>
using namespace std;

struct node {
    int value;
    node *next;
};

int angka, after;
char pil;

node *head = NULL;
node *tail = NULL;

void printList() {
    node *temp = head;
    cout << "Isi dari linked list : ";
    while(temp != NULL) {
        cout << temp -> value << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

void insertFirst(int n) {
    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL;

    if (head == NULL){
        head = newnode;
        tail = head;
    }
    else {
        newnode -> next = head;
        head = newnode;
    }

    printList();
}

void insertLast(int n) {
    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL;

    if (head == NULL){
        head = newnode;
        tail = head;
    }
    else {
        tail -> next = newnode;
        tail = newnode;
    }

    printList();
}

void insertAfter(int n, int check) {
    if (head == NULL){
        cout<<"list kosong silahkan insert ";
        return;
    }

    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL;

    node *p = head;
    while (p != NULL && p->value != check){
        p = p->next;
    }

    if (p == NULL){
        cout<<"node dengan nilai "<<check<<" tidak ketemu"<<endl;
        delete newnode;
    }
    else {
        newnode -> next = p -> next;
        p -> next = newnode;

        if (p == tail){
            tail = newnode;
        }
    }

    printList();
}

void deleteFirst() {
    if (head==NULL){
        cout<<"list kosong\n";
        return;
    }
    
    node *temp = head;
    head = head->next;

    if (head==NULL) tail = NULL;
        delete temp;

    printList();
}

void deleteLast() {
    if (head==NULL){
        cout<<"list kosong\n";
        return;
    }

    if (head == tail){
        delete head;
        head = tail = NULL;
        return;
    }

    node *p = head;
    while (p->next != tail){
        p = p->next;
    }

    delete tail;
    tail = p;
    tail->next = NULL;

    printList();
}

void deleteMiddle(int value) {
    if (head==NULL){
        cout<<"list kosong\n";
        return;
    }

    if (head->value==value){
        deleteFirst();
        return;
    }

    if (tail->value==value){
        deleteLast();
        return;
    }

    node *p = head;
    while (p->next!=NULL && p->next->value != value){
        p = p->next;
    }

    if (p->next==NULL){
        cout<<"node dengan nilai "<<value<<" tidak ketemu.";
    }
    else{
        node *temp = p -> next;
        p->next = temp -> next;
        if (temp==tail) tail = p;
        delete temp;
    }

    printList();
}

int main () {
    do{
        cout<<"=== MENU SINGLE LINKED LIST ==="<<endl;
        cout<<"1. Tambah di awal"<<endl;
        cout<<"2. Tambah di akhir"<<endl;
        cout<<"3. Tambah setelahl nilai tertentu"<<endl;
        cout<<"4. Hapus berdasarkan nilai"<<endl;
        cout<<"5. Tampilkan linked list"<<endl;
        cout<<"6. Keluar"<<endl;
        cout<<"pilih menu (1-6): ";
        cin>>pil;

        if (pil == '1') {
            cout<<"Masukkan nilai : ";
            cin>>angka;
            insertFirst(angka);
        }

        else if (pil == '2'){
            cout<<"Masukkan nilai : ";
            cin >> angka;
            insertLast(angka);
        }

        else if (pil == '3'){
            cout<<"asukkan nilai : ";
            cin >> angka;
            cout<<"Masukkan nilai yang ingin dicari : ";
            cin>>after;
            insertAfter(angka, after);
        }

        else if (pil == '4'){
            cout<<"Masukkan nilai yang ingin dihapus : ";
            cin >> angka;
            deleteMiddle(angka);
        }

        else if (pil == '5'){
            printList();
        }

        else if (pil == '6') {
            cout<<"Terimakasih, program selesai";
        }

        else {
            cout<<"Nomor pilihan tidak ada di menu";
        }
    }

    while (pil != '6');
}
