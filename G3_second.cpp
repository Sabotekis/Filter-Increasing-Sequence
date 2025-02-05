/*************************
Pāvels Petrovs, pp23055
G3. Uzrakstīt funkciju, kas  izmet no saraksta tos elementus, kuri mazāki par iepriekšējo (iepriekšējais elements ir tas, kurš norāda uz nākošo pirms izmešanas).
//Pakomentēšu G3. Var neprogrammēt patvaļīga elementa ievadīšanu. Var aizpildīt sarakstu ar nejaušiem skaitļiem, intervālā no 1 līdz 10. Lietotājs ievada tikai saraksta garumu. 
Programma izveidota: 2024/03/27
*******************************/

#include <iostream>
#include <list>
using namespace std;

void removeSmallerSTL(list<int>& myList) { //Ar šo rindu sākas funkcijas removeSmallerSTL definīcija, kuras parametrs ir atsauce uz veselu skaitļu sarakstu (myList).
    auto t = myList.begin(); //Šajā rindā deklarē iteratoru un inicializē to tā, lai tas norādītu uz saraksta sākumu.
    int prev = *t; //Šeit mēs inicializējam veselskaitļa mainīgo prev ar saraksta pirmā elementa vērtību.
    ++t; //Šajā rindā iterators tiek palielināts, lai norādītu uz nākamo saraksta elementu.
    while (t != myList.end()) { //Šī while cilpa iterē cauri sarakstam, līdz iterators sasniedz saraksta beigas.
        if (*t < prev) //Šis if paziņojums pārbauda, vai pašreizējais elements (uz kuru tas norāda) ir mazāks par iepriekšējo elementu.
            t = myList.erase(t);// Ja pašreizējais elements ir mazāks, mēs to dzēšam no saraksta, izmantojot saraksta konteinera dzēšanas metodi. Izdzēšanas metode atgriež iteratoru, kas norāda uz elementu, kurš seko pēdējam noņemtajam elementam, kurš tam tiek piešķirts.
        else { //Ja pašreizējais elements nav mazāks par iepriekšējo, mēs atjauninām prev vērtību, lai tā būtu pašreizējais elements.
            prev = *t; 
            ++t; //Neatkarīgi no tā, vai esam vai neesam izņēmuši elementu, mēs pārvietojam iteratoru uz nākamo elementu sarakstā.
        }
    }
}

void printListSTL(const list<int>& myList) {  //Ar šo rindu sākas printListSTL funkcijas definīcija, kas kā parametru pieņem konstantu atsauci uz veselu skaitļu sarakstu (myList). Šī funkcija izdrukā saraksta elementus.
    for (auto t = myList.begin(); t != myList.end(); ++t) {  //Šī for cilpa iterē sarakstu, izmantojot iteratoru, sākot no sākuma un beidzot saraksta beigās.
        cout << *t << " ";
    }
    cout << endl; 
}

int main() {
    int length;
    cout << "Enter the length of the list: ";
    do {
        cin >> length;
        if (length <= 0){
            cout << "The length can`t be a zero or negative. Please enter again: ";
        }
    } while (length <= 0);

    list<int> myList; 
    cout << "Enter " << length << " elements:\n"; 
    for (int i = 0; i < length; ++i) { 
        int element;
        cin >> element;
        myList.push_back(element);
    }

    cout << "Original list: ";
    printListSTL(myList);
    removeSmallerSTL(myList);
    cout << "List after removal: ";
    printListSTL(myList);
    myList.clear();

    return 0;
}




