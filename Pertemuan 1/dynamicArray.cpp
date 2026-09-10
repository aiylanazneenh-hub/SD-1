#include <iostream>
using namespace std;
int main(){
    int n; //n ngasi tau program brp slot nya

    cout<<"Masukkan jumlah elemen array : ";
    cin >> n;

    //memori membuat lokasi baru utk array dgn ukuran khusus yg user mau (arr)
    int* arr = new int[n]; //new akan selalu berpasangan dengan delete

    cout <<"Masukkan "<< n << " Angka : \n";
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }

    cout<<"Isi array : ";
    for (int i=0; i<n; i++){
        cout<<arr[i]<< " ";
    }

    delete[] arr;
    return 0;
}