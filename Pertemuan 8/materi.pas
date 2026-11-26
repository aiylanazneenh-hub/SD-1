GRAF
- representasi jaringan (titik & garis)
- titik = objek
- garis = hubungan antar objek

komponen GRAF
- vertex - simpul
- edge - garis

jenis graf berdasarkan arah sisi
- tak berarah = sisi2nya ga pny arah (timbal balik)
- berarah = pny arah tertentu (hny 1 arah, busur)

jenis graf berdasarkan bobot sisi
- berbobot = sisinya gpny nilai numerik, yg penting cuma ada koneksi atau ga
- tak berbobot = sisi pny nilai numerik (biaya/cost)

ADJACENCY MATRIX
cara menyimpan/menggambarkan hubungan antar simpul dalam graf pake tabel angka 0 (gd hubungan) & 1 (ada hubungan)

minimum spanning tree -> algoritma utk nyari semua garis yang menghubungi sebuah graf (edge) tanpa membentuk siklus dgn total bobot yg paling kecil

3 algoritma mst : 
reverse-delete = mulai dari graf penuh -> ngapus ngapus edge yang besar tanpa mutus graf
kruskal = mulai dari graf kosong -> tambahkan edge kecil satu per satu
prim = mulai dari vertex 0 -> numbuhin node satu per satu cari yang terkecil

shortest path = pencarian rute terpendek

2 algoritma utama shortest path : 
1. djikstra = 
2. bellman - ford = 