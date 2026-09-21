#include <iostream>
using namespace std;

// Deklarasi sebuah struktur node
struct node {
    int value;
    node *next;
};

node *head = NULL; //buat linklistnya masih kosong
node *tail = NULL;

// TODO : Insert di Depan
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
}

// TODO : Insert di belakang
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
}

// TODO : Insert setelah nilai tertentu
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
}

// Cetak linked list
void printList() {
    node *temp = head;
    cout << "Isi dari linked list : ";
    while(temp != NULL) {
        cout << temp -> value << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

int main () {
    insertFirst(10); //memasukkan dari depan
    insertLast(20); //memasukkan dari belakang
    insertLast(30);
    insertAfter(25, 20); //"masukkan angka 25 setelah 20"
    insertFirst(5);

    printList();
    return 0;
}