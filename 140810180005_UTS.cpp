/*
Nama Program    : 140810180005_UTS
Nama            : Fauzan Akmal Hariz
NPM             : 140810180005
Kelas           : A
Tanggal buat    : 23 April 2019
Deskripsi       : UTS Praktikum Struktur Data 2019
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct sepakBola{
    int noDaftar;
    char namaTim[30];
    char asalDaerah[40];
    int gol;
    sepakBola* next;
};

typedef sepakBola* pointer;
typedef pointer List;

void createList(List& First)
{
    First=NULL;
}

void createElmt(pointer& pBaru)
{
    pBaru=new sepakBola;
    cout<<"Masukan Nomor Daftar\t: "; cin>>pBaru->noDaftar;
    cout<<"Masukan Nama Tim\t: "; cin.ignore(); cin.getline(pBaru->namaTim, 30);
    cout<<"Masukan Asal Daerah\t: "; cin.getline(pBaru->asalDaerah, 40);
    cout<<"Masukan Gol\t\t: "; cin>>pBaru->gol;
    pBaru->next=NULL;
}

void insertLast(List& First, pointer pBaru)
{
    pointer Last;

    if(First==NULL)
    {
        First=pBaru;
    }
    else
    {
        Last=First;
        while(Last->next!=NULL)
        {
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}

void traversal(List First)
{
    pointer pBantu;
    pBantu=First;

    cout<<"Nomor Daftar\tNama Tim\tGol\t" <<endl;
    cout<<"=======================================================" <<endl;
    do
    {
        cout<<pBantu->noDaftar <<"\t\t" <<pBantu->namaTim <<"\t\t" <<pBantu->gol <<endl;
        pBantu=pBantu->next;
    }
    while(pBantu!=NULL);
}

void sortDescending(List& First)
{
    int count=0, i;
    pointer start, curr, trail, temp;
    start=First;
    curr=NULL;
    trail=NULL;
    temp=NULL;

    while(start!=NULL)
    {
        count++;
        start=start->next;
    }

    for(i=0; i<count; i++)
    {
        curr=trail=First;
        while (curr->next!=NULL)
        {
            if (curr->gol<curr->next->gol)
            {
                temp=curr->next;
                curr->next=curr->next->next;
                temp->next=curr;

                if(curr==First)
                {
                    First=trail=temp;
                }
                else
                {
                    trail->next = temp;
                }
                curr=temp;
            }
            trail=curr;
            curr=curr->next;
        }
    }
}

int main()
{
    pointer p;
    List First;
    int pilih;

    createList(First);

    do
    {
        system("cls");
        cout<<"================================================" <<endl;
        cout<<"Program untuk Menampilkan Data Peserta Sepakbola" <<endl;
        cout<<"================================================" <<endl <<endl;

        cout<<"Pilihan Menu" <<endl;
        cout<<"1. Masukan Data" <<endl;
        cout<<"2. Tampilkan Data" <<endl;
        cout<<"3. Keluar" <<endl;
        cout<<"========================="<<endl;

        cout<<"Silahkan Masukan Pilihan : "; cin>>pilih; cout<<endl;

        switch(pilih)
        {
            case 1:
                createElmt(p);
                insertLast(First, p);
                break;
            case 2:
                sortDescending(First);
                traversal(First);
                break;
            case 3:
                cout<<"Terima Kasih Telah Menggunakan Program Ini" <<endl;
                return 0;
                break;
            default:
                cout<<"Maaf Pilihan Anda Tidak Tersedia" <<endl;
                break;
        }
        system("pause");
    } while(pilih!=3);
    return 0;
}



