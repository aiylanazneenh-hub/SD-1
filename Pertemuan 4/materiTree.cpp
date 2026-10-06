#include <iostream>
using namespace std;

struct node{
    int data;
    node* kiri;
    node* kanan;
};

node* akar = NULL;

void addnote (node** akar, int isi){
    if (*akar == NULL){
        node* baru = new node;
        baru->data = isi;
        baru->kanan = NULL;
        baru->kiri = NULL;
        *akar = baru;
    }
}

void preorder (node* akar){
    if (akar != NULL){
        cout << akar->data << " ";
        preorder (akar->kiri);
        preorder (akar->kanan);
    }
}

void inorder (node* akar){
    if (akar != NULL){
        inorder (akar->kiri);
        cout << akar->data << " ";
        inorder (akar->kanan);
    }
}

void postorder (node* akar){
    if (akar != NULL){
        postorder (akar->kiri);
        postorder (akar->kanan);
        cout << akar->data << " ";
    }
}

int main(){
    cout << "\n\n\tPosisi awal tree : \n\n";
    cout<<"\t       15\n";
    cout<<"\t       /\\\n";
    cout<<"\t      27 30\n";
    cout<<"\t      /\\\n";
    cout<<"\t     25 29\n\n";

    //membentuk trer;
    addnote(&akar, 15);
    addnote(&akar->kiri, 27);
    addnote(&akar->kanan, 30);
    addnote(&akar->kiri->kiri, 25);
    addnote(&akar->kiri->kanan, 29);

    //traversal
    cout<<"Tampilkan pre-order : ";
    preorder(akar);
    cout<<"\nTampilkan in-order : ";
    inorder(akar);
    cout<<"\nTampilkan post-order : ";
    postorder(akar);

    return 0;
}