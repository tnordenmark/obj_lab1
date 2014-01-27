// lab1_upg1.cpp
// Program för att utföra ett antal operationer på en array med hjälp av
// pekare
// Thomas Nordenmark 2013-01-27
// Ver 0.1
//------------------------------------------------------------------------------
#include <iostream> // cout, cin
#include <random> // default_random_engine
#include <functional> // bind
using namespace std;

// =========================
// Deklaration av konstanter
// =========================
// Intervall för slumpgeneratorn
const int LOW = -5000;
const int HIGH = 5000;

// ============
// Huvudprogram
// ============
int main()
{
    // Initiera slumpdistributörsobjektet generator
    default_random_engine generator(static_cast<signed>(time(0)));
    uniform_int_distribution<int> random(LOW, HIGH); // Slumpa i intervallet -5000 - 5000
    // Slå ihop slumpgeneratorn till en funktion för enklare användning
    auto randNum = bind(random, generator);

    size_t size;

    cout << "Ange antalet platser i arrayen: ";
    cin >> size;
    cin.get(); // Läs bort returtecknet

    // Allokera minne för en array av storleken "size"
    int *arr = new int[size];
    // Pekare till arrayens sista element
    int *p_end = arr + size;

    // Slumpa tal till arrayen
    for(int *p = arr; p != p_end; ++p)
        *p = randNum();

    // Räknare för modus och radutskrift
    int num = 0;

    // Skriv ut arrayen med hjälp av pekare som iteratorer
    for(int *p = arr; p != p_end; ++p)
    {
        // Index är inte exakt index utan index+1 som ett löpnummer för att
        // det är mer lättläst för användaren
        cout << "Index " << num +1 << " = " << *p << endl;
        num++;

        // Pausa var 200:e element
        if(num % 200 == 0)
        {
            cout << "Tryck enterför att fortsätta...";
            cin.get();
        }
    }

    // Pekare och variabler för summa, min och max-värde. En annan metod vore att deklarera
    // en max-variabel till ett mindre värde än -5000 och sen sätta *p_max = &max
    //int max = -9999;
    //int *p_max = &max;
    int sum = 0;
    int min = 9999; // Ett värde större än det största möjliga värdet i arrayen
    int *p_max = arr;
    int *p_min = &min;
    int *p_sum = &sum;

    // Stega igenom arrayen med pekare
    for(int *p = arr; p != p_end; ++p)
    {
        // Om *p_max är mindre än aktuellt index i arrayen
        if(*p_max < *p)
            // Sätt *p_pax till att peka på det aktuella värdet
            *p_max = *p;
        // Och vice versa för *p_min
        if(*p_min > *p)
            *p_min = *p;
        // Addera arrayens summa och peka på värdet
        *p_sum += *p;

    }

    // Skriv ut resultatet av beräkningarna
    cout << endl;
    cout << "Minsta tal är: " << *p_min << endl;
    cout << "Största tal är: " << *p_max << endl;
    cout << "Summan är: " << *p_sum << endl;

    return 0;
}
