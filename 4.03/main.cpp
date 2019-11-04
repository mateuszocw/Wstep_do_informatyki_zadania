#include <iostream>
using namespace std;
const int MAX=10;
int x=MAX*MAX-2;
int kolumna=MAX/2;
int wiersz=MAX/2;
int t[MAX][MAX];
bool parzystosc[MAX][MAX];
bool parzystosc_wiersza[MAX];

void spirala()                                                //wypelnienie tablic - metoda spirali
{
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
    if(MAX%2==1)                                              //metoda spirali - dopelnienie ostatniej kolumny (dla nieparzystego MAX)
    {
        for(int i=0; i<MAX; i++)
        {    wiersz--;
            t[wiersz][kolumna] = x;
            x--;}
    }
}
void standard() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)                                 //wypelnienie tablicy - metoda standardowa
        {
            t[i][j] = i * MAX + j;
        }
    }
}                                           //wypelnienie tablic - metoda standardowa


int main() {

    t[MAX/2][MAX/2]=MAX*MAX-1;


    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++) {
            parzystosc[i][j] = false;
        }
    }
    for(int i=0; i<MAX; i++)
    {
        parzystosc_wiersza[i]=true;
    }


    spirala();
for(int i=0; i<MAX; i++) {
    for (int j = 0; j < MAX; j++) {
    if(t[i][j]==0) parzystosc[i][j]=true;
        for (int k = 1; t[i][j]/k > 0; k *= 10) {
            if ((t[i][j] / k) % 2 == 0) {
                parzystosc[i][j] = true;
            }
        }
    }
}
for(int i=0; i<MAX; i++)
{
    for(int j=0; j<MAX; j++)
    {
        if(!parzystosc[i][j])
        {
            parzystosc_wiersza[i]=false;
        }

    }

}


    for(int x=0; x<MAX; x++)
    {
        for(int y=0; y<MAX; y++)
        {
            if(t[x][y]/10==0)
            {
                cout<<" ";
            }
            cout<<t[x][y]<<" ";

        }
        if(!parzystosc_wiersza[x])
        {cout<<"<- ten nie ma";
        }
        else cout<<"<- a ten ma :)";
        cout<<endl;
    }
    for(int i=0; i<MAX; i++)
    {
        if(!parzystosc_wiersza[i])
        {
            cout<<"Nie wszystkie liczby w kazdym wierszu skladaja sie z conajmniej jednej cyfry parzystej"<<endl;
            break;
        }
    }


    return 0;
}