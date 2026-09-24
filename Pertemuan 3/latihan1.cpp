#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// TODO : Menambahkan karakter ke stack
void push(char value) {
    if (top == MAX - 1){
        cout<<"Stack penuh";
    }

    else {
        top++;
        stack[top] = value;
        cout<< value << " ditambahkan dalam stack\n";
    }
}

void display() {
    if (top == -1){
        cout<<"stack kosong\n";
    }

    else{
        cout<<"\nisi dari stack:\n";

        for (int i = top; i>=0; i--){
            cout<<stack[i]<<" ";
        }

        cout<<endl;
    }
}

// TODO : Mengambil karakter paling atas
char pop() {
    if (top == -1){
        cout<<"Stack kosong";
    }

    else {
        cout <<"\n"<<stack[top]<<" dihapus dari stack\n";
        top--;
    }

    return 0;
}

int main() {

    string kata;

    cout << "Masukkan sebuah kata: ";
    getline (cin, kata);

    // TODO : Memasukkan setiap karakter ke stack
    for (int i=0; i<kata.length();i ++){
        push(kata[i]);
    }

    // TODO Mengeluarkan karakter dari stack
    display();
    pop();
    display();
    cout << endl;

    return 0;
}