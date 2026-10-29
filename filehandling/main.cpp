#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;



vector<string> bacaFilekeVector(const string& namaFile){
    vector<string> daftarData;
    ifstream file(namaFile);
    string baris;

    if(file.is_open()){
        while (getline(file,baris)){
            daftarData.push_back(baris);
        }
        file.close();
    }else{
        cout<<"File tidak ada";
    }
    return daftarData;
}

void simpanVectorkeFile(const string& namaFile,const vector<string>& daftarData){
    ofstream file(namaFile);
    if(file.is_open()){
        for (const string& baris : daftarData){
            file<<baris<<"\n";
        }
        file.close();
        cout<<"Data berhasil disimpan ke file"<<endl;
    }else{
        cout<<"Data gagal disimpan ke file"<<endl;
    }
}
    


int main(){
string namaFile= "data.txt";


vector<string> data = bacaFilekeVector(namaFile);
data.push_back("Data baru");

if(!data.empty()){
    data[0]="Baris data pertama sudah di ubah\n";
}

cout<<"Isi datavector"<<endl;
for (int i=0;i<data.size();i++){
    cout<<i+1<<". "<<data[i]<<endl;
}

simpanVectorkeFile(namaFile,data);

cout<<"Hasil";

return 0;
}


