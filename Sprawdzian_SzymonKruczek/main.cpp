#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

const int N = 48;

int Generator()
{
    return
    100+rand()%899;
}

void zliczPodz(int tablica[N])
{
    int wystopila=0;
    for(int i=0;i<N;i++)
    {
        if(tablica[i]%7==0) wystopila++;
    }
    cout<<"\nLiczba podzielna prze 7 wystopila: "<<wystopila<<" razy";
}

void zapis(int tablica[])
{
    fstream zapis;
    zapis.open("liczby_Szymon.txt",ios::out);
    if(zapis.good()==true)
    {
        for(int i=0;i<N;i++)
        {
            zapis<<tablica[i]<<"\n";
        }
    }
    zapis.close();

    cout<<"\nZapis udany"<<endl;
}

void wiersze(int tablica[N])
{
    for(int i=0;i<N;i++)
    {
        if(i%6==0) cout<<endl;
        cout<<tablica[i]<<" ";
    }
    cout<<endl;
}

void sumaP(int tablica[N])
{
    int sumaL=0;
    for(int i=0;i<N;i++)
    {
        if(tablica[i]%2==0) sumaL=sumaL+tablica[i];
    }
    cout<<"\nSuma liczb parzystych to: "<<sumaL;
}
int main()
{
    srand(time(NULL));

    int a,b,c,d;
    int tablica[N];

    for(int i=0;i<N-4;i++)
    {
        tablica[i] = Generator();
    }
    cout << "Podaj cztery liczby trzycyfrowe:" << endl;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;

    tablica[N-4]=a;
    tablica[N-3]=b;
    tablica[N-2]=c;
    tablica[N-1]=d;

    zliczPodz(tablica);
    zapis(tablica);
    wiersze(tablica);
    sumaP(tablica);

}
