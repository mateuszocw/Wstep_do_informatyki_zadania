#include <iostream>
using namespace std;
const int MAX=8;
int x=MAX*MAX-2;
int kolumna=MAX/2;
int wiersz=MAX/2;
int t[MAX][MAX];
bool nieparzystosc[MAX];
bool wynik;
int main() {
    t[MAX/2][MAX/2]=MAX*MAX-1;
    for(int i=0; i<MAX; i++)
    {
        nieparzystosc[i]=0;
    }


    for (int i = 1; i < MAX; i+=2) {                             //caly cykl gora->lewo->dol->prawo, i+=2 bo o tyle komorek powieksza sie slimak za kazdym cyklem
        for (int j = 1; j <=i;
             j++)
        {
            wiersz--;
            t[wiersz][kolumna] = x;
            x--;
        }
        for (int k = 1; k <= i; k++) {
            kolumna--;
            t[wiersz][kolumna] = x;
            x--;
        }

        for (int l = 1; l <=i+1; l++)
        {
            wiersz++;
            t[wiersz][kolumna] = x;
            x--;
        }
        for (int m = 1; m <= i+1; m++) {
            kolumna++;
            t[wiersz][kolumna] = x;
            x--;
        }

    }
    if(MAX%2==1)
    {
        for(int i=0; i<MAX; i++)
        {    wiersz--;
            t[wiersz][kolumna] = x;
            x--;}
    }
/*
int x=0;
for(int i=0; i<MAX; i++)
{
    for(int j=0; j<MAX; j++)
    {
        t[i][j]=x;
        x++;

    }
}

*/
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            if(t[i][j]%2==1)
            {
                if((t[i][j]/10)%2!=0 || (t[i][j]-t[i][j]%10)/10==0) {
                    nieparzystosc[i] = 1;

                }
            }
        }

    }

    for(int j=0; j<MAX; j++)
    {
        if(nieparzystosc[j]){
            wynik=true;
        }
        else {
            wynik = false;
            break;
        }
    }
    if(wynik)
    {
        cout<<"Kazdy wiersz zawiera liczbe zlozona z samych nieparzystych cyfr"<<endl;
    }
    else
    {
        cout<<"Nie kazdy wiersz zawiera liczbe zlozona z samych nieparzystych cyfr"<<endl;
    }

    for(int x=0; x<MAX; x++)
    {
        for(int y=0; y<MAX; y++)
        {
            cout<<t[x][y]<<" ";
        }
        if(!nieparzystosc[x]) {
            cout << "<----- ten wiersz";
        }
        cout<<endl;
    }

    return 0;
}
