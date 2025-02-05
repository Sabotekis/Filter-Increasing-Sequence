/*************************
Pāvels Petrovs, pp23055
G3. Uzrakstīt funkciju, kas  izmet no saraksta tos elementus, kuri mazāki par iepriekšējo (iepriekšējais elements ir tas, kurš norāda uz nākošo pirms izmešanas).
//Pakomentēšu G3. Var neprogrammēt patvaļīga elementa ievadīšanu. Var aizpildīt sarakstu ar nejaušiem skaitļiem, intervālā no 1 līdz 10. Lietotājs ievada tikai saraksta garumu. 
Programma izveidota: 2024/03/27
*******************************/

#include <iostream>
using namespace std;

class elem {
public:
    int num; 
    elem* next; 
};

void add_front(elem*& first, int num) {
    elem* t = new elem{};
    t->num = num;
    t->next = first;
    first = t;
}

void print_list(elem* first) {
    for (elem* t = first; t != 0; t = t->next){
        cout << t->num << " ";
    }
}

void remove_smaller(elem*& first) {
    elem* current = first->next; //Šeit mēs deklarējam rādītāju current un inicializējam to, lai tas norādītu uz saistītā saraksta otro elementu (first->next). Mēs sākam no otrā elementa, jo mēs salīdzinām katru elementu ar iepriekšējo.
    elem* prev = first; //Šī rindiņa inicializē vēl vienu rādītāju prev, kas norāda uz saistītā saraksta pirmo elementu. prev tiek izmantots, lai iterējot sarakstu, saglabātu informāciju par iepriekšējo elementu.

    while (current != nullptr) {
        if (current->num < prev->num) { //Šis if paziņojums pārbauda, vai pašreizējā elementa num vērtība ir mazāka par iepriekšējā elementa num vērtību.
            prev->next = current->next; //Ja pašreizējā elementa num vērtība ir mazāka par iepriekšējā elementa num vērtību, mēs atjauninām iepriekšējā elementa nākamo rādītāju, lai izlaistu pašreizējo elementu, tādējādi faktiski dzēšot to no saraksta.
            delete current; //Pēc pašreizējā elementa izņemšanas no saraksta mēs izdalām ar to saistīto atmiņu.
            current = prev->next; //Mēs atjauninām pašreizējo rādītāju, lai norādītu uz nākamo elementu pēc tikko dzēstā elementa.
        } else { //Ja pašreizējā elementa numurs nav mazāks par iepriekšējā elementa numuru, mēs atjauninām gan prev, gan current rādītājus, lai pārietu uz nākamo elementu pāri saistītajā sarakstā.
            prev = current;
            current = current->next;
        }
    }
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
    elem* first = nullptr; 

    int* numbers = new int[length]; //Šī virkne dinamiski piešķir masīvu, kurā tiek saglabāti lietotāja ievadītie skaitļi.
    cout << "Enter " << length << " numbers:\n";
    for (int i = 0; i < length; ++i) {
        cin >> numbers[i];
    }

    for (int i = length - 1; i >= 0; --i) { //Šī virkne iterē skaitļu masīvu apgrieztā secībā, pievienojot tos saistītā saraksta priekšā.
        add_front(first, numbers[i]);
    }

    delete[] numbers; 
    cout << "Original list: ";
    print_list(first);
    remove_smaller(first);
    cout << "List after removal: ";
    print_list(first);

    elem* temp;
    while (first != nullptr) {
        temp = first;
        first = first->next;
        delete temp;
    }

    return 0;
}






