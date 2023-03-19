#include<iostream>
#include<fstream>
using std::cout;
using std::cin;


int main()
{
    std::ifstream odpowiedzi("rozw4_4.txt");
    std::ifstream wyniki("wyniki4_4.txt");

    int * poprawne = new int[20];
    int * wynik = new int[20];
    while(odpowiedzi >> poprawne[0]){
        wyniki >> wynik[0];
        for(int i = 1; i<20; i++){
            odpowiedzi >> poprawne[i];
            wyniki >>wynik[i];
        }
        for(int i = 0; i<20; i++){
            if(poprawne[i]!=wynik[i]){
                cout <<" ŹLE:\n";
            }
        }

        
    }

    odpowiedzi.close();
    wyniki.close();
    delete poprawne;
    delete wynik;
    return 0;
}