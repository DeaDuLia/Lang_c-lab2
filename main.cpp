#include <iostream>
#include "domain/Particle.h"
#include "domain/Atom.h"
#include "domain/Molecule.h"
using namespace std;

/**
 * Для каждой задачи необходимо реализовать объектную модель.
 * В реализации задач должны присутствовать наследование, агрегация и др. взаимодействия классов.
 * Общение с пользователем осуществляется через консоль путем вызова наиболее значимых методов классов,
 * позволяющих увидеть основную функциональность задачи.
 * Для моделирования  динамики процессов можно использовать повторяющиеся вызовы пользователем.
 *======================================================================================================================
 * Задача №11
 * 11.	Молекула вещества.
 * Молекула,  атомы,  нуклоны (протон, нейтрон), электроны.
 * Между атомами существуют связи различных энергий,
 * связь реализуется посредством взаимодействия электронных оболочек атомов.
 * Реализовать операции:
 * определение суммарной энергии взаимодействия атомов,
 * массы молекулы,
 * суммарной массы нуклонов и электронов,
 * числа атомов одного типа в молекуле.
 */


int main() {
    system("chcp 1251");
    const int sz1 = 20, sz2 = 20;
    int atomCount=0, moleculesCount=0, count = 0;
    int choice2 = 0, choice3 = 0, choice4 = 0, choice5 = 0;
    Atom **atoms = new Atom*[sz1];
    Molecule **molecules = new Molecule*[sz2];
    while (1) {
        cout << "1. create atom\n" << "2. create molecule \n" <<"3. functions\n4. exit\n";
        int choice = 0;
        cin >> choice;
        string name = "";
        switch (choice) {
            case 1:
                int protonCount, neyutronCount, electronCount;

                cout << "enter protons count:";
                cin >> protonCount;
                cout << "enter neutrons count:";
                cin >> neyutronCount;
                cout << "enter electrons count:";
                cin >> electronCount;
                cout << "enter atom name:";
                cin >> name;
                atoms[atomCount] = new Atom(protonCount, neyutronCount, electronCount, name);
                atomCount++;
                break;
            case 2:
                if (atomCount < 1) {
                    cout << "is nothing here...";
                } else {
                    int sz3 = 10, atmCount = 0;
                    int tmp = 1;
                    Atom **atms = new Atom*[sz3];
                    while (tmp) {
                        cout << "select atom:\n";
                        for (int i = 0; i < atomCount; i++) {
                            cout << (i + 1) << ")" << atoms[i]->getName() << ":\nelectr:" << atoms[i]->getElectronCount()
                                 << " prot:" << atoms[i]->getProtonCount()
                                 << " neutr:" << atoms[i]->getNeutronCount() << "\n";
                        }
                        cin >> choice2;
                        if (choice2 > atomCount || choice2 < 1) {
                            cout << "Error...";
                            break;
                        } else {
                            atms[atmCount] = atoms[choice2-1];
                            atmCount++;
                            cout << "Add atoms ??\n1) Yes\n2) No\n";
                            cin >> choice4;
                            if (choice4 == 2) {
                                tmp =0;
                            }
                        }
                    }
                    // Проверка на расширение массива
                    molecules[moleculesCount] = new Molecule(atmCount, atms);
                    moleculesCount++;
                    delete(atms);
                }
                break;
            case 3:
                if (moleculesCount < 1) {
                    cout << "Is nothing here...\n";
                } else {
                    cout << "select molecule:\n";
                    for (int i = 0; i < moleculesCount; i++) {
                        cout << (i+1) << ") " << molecules[i]->name << "\n";
                    }
                    cin >> choice3;
                    if (choice3 > moleculesCount || choice3 < 1) {
                        cout << "Error...";
                        break;
                    } else {
                        cout << "choice function:\n1)getWeight\n2)getAtomCount\n3)getCharge\n4)exit";
                        cin >> choice5;
                        switch (choice5) {
                            case 1:
                                cout << "weight:" << molecules[choice3-1]->getWeight() << " a.m.u.\n";
                                break;
                            case 2:
                                cout << "atoms:" <<  molecules[choice3-1]->atomsCount << "\n";
                                break;
                            case 3:
                                cout << "charge:" <<  molecules[choice3-1]->getCharge() << "\n";
                                break;
                            default:
                                break;
                        }
                    }
                }
                break;
            case 4:
                for (int i = 0; i < moleculesCount; i++) {
                    delete(molecules[i]);
                }
                delete[](molecules);
                for (int i = 0; i < atomCount; i++) {
                    delete(atoms[i]);
                }
                delete[](atoms);
                return 0;
            default:
                break;
        }
    }
}
