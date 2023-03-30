#include <iostream>

using namespace std;

class Stack
{
private:
    int top;
    int size;
    int* veriler;

public:
    Stack(int size) {
        this->size = size;
        this->top = -1;
        this->veriler = new int[size];
    }

    void push(int data) {                                           //stack'e sayı ekleme metodu
        if (StackDoluMu()) {
            cout << "Stack dolu" << endl;
        }
        else {
            this->top++;
            veriler[this->top] = data;
        }
    }

    bool StackDoluMu() {
        if (this->top == this->size - 1) {
            return true;
        }
        else {
            return false;
        }
    }


    bool pop(int data) {                                            //kullanıcıdan alınan sayıyı stack'ten cıkarma metodu
        if (top == -1) {
            cout << "Yigin bos!" << endl;   
            return false;
        }

        int aramaDegiskeni = -1;            //kullanıcıdan alınan sayı ile stack içerisindeki sayilardan biri eşleşiyorsa -for döngüsüyle stack'i geziyorum- değişkene indisini atıyorum.
        for (int i = 0; i <= top; i++) {
            if (veriler[i] == data) {
                aramaDegiskeni = i;
                break;
            }
        }

        if (aramaDegiskeni == -1) {
            cout << data << " stack'te bulunamadi!" << endl;
            return false;
        }

        for (int i = aramaDegiskeni; i < top; i++) {                //belirli indisten itibaren tüm elemanlar birer öne alınarak istenen eleman stackten çıkarılıyor
            veriler[i] = veriler[i + 1];
        }

        top--;
        return true;
    }

    void ilkVeSonElemanıDegistir() {
        if (top < 1) {
            cout << "Stack en az iki eleman olmali. " << endl;
            return;
        }

        int temp = veriler[0];
        veriler[0] = veriler[top];  
        veriler[top] = temp;
    }


    void yazdir() {
        if (top == -1) {
            cout << "Stack bos!" << endl;
            return;
        }
        cout <<endl<< "Stack =  " << endl;
        for (int i = top; i >= 0; i--) {
            cout << veriler[i] << endl;
        }
    }
};

int main() {
    int boyut;
    cout << "Stack boyutunu girin: ";
    cin >> boyut;

    Stack stackOrnegi(boyut);

    for (int i = 0; i < boyut; i++) {
        int eleman;
        cout << i + 1 << ". elemani girin: ";
        cin >> eleman;
        stackOrnegi.push(eleman);
    }

    stackOrnegi.yazdir();

    int cikarilacakSayi;
    cout <<endl<< "Cikarilacak sayiyi girin: ";
    cin >> cikarilacakSayi;

    bool sayiCikarildiMi = stackOrnegi.pop(cikarilacakSayi);    //pop degeri true dönüyorsa bool degiskenimiz de true olacak ve alttaki if'te kullanılacak

    if (sayiCikarildiMi) {                                          //eger sayı çıkarıldıysa burada belirtilecek
        cout << cikarilacakSayi << " stack'ten cikarildi." << endl;
        stackOrnegi.yazdir();
    }
    stackOrnegi.ilkVeSonElemanıDegistir();

    cout << "Stack'in ilk ve son elemanlari yer degistirildi =  " << endl;
    stackOrnegi.yazdir();

    return 0;
}

