#include <iostream>

using namespace std;

char a[100][100], jucator1, calc1;
int i, j, scor_O, scor_X, jucatorCurent, playerCurent, optiune, numar, selectare_jucator, cine_incepe;

void Start_JOC();

void Calc_Joc();

void afisare() {
    cout << "     |     |     " << endl;
    cout << "  " << a[1][1] << "  |  " << a[1][2] << "  |  " << a[1][3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << a[2][1] << "  |  " << a[2][2] << "  |  " << a[2][3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << a[3][1] << "  |  " << a[3][2] << "  |  " << a[3][3] << endl;
    cout << "     |     |     " << endl;
}

void valoare_curenta(int b, int c, char x) {
    if (a[b][c] != 'X' && a[b][c] != 'O')
        a[b][c] = x;
    else {
        cout << "Aceasta casuta a fost deja selectata!!" << endl;
        cout << "Alegeti alta casuta!" << endl;
    }
}

void transformare(int nr, int &b, int &c) {
    if (nr == 1) {
        b = 1;
        c = 1;
    } else if (nr == 2) {
        b = 1;
        c = 2;
    } else if (nr == 3) {
        b = 1;
        c = 3;
    } else if (nr == 4) {
        b = 2;
        c = 1;
    } else if (nr == 5) {
        b = 2;
        c = 2;
    } else if (nr == 6) {
        b = 2;
        c = 3;
    } else if (nr == 7) {
        b = 3;
        c = 1;
    } else if (nr == 8) {
        b = 3;
        c = 2;
    } else if (nr == 9) {
        b = 3;
        c = 3;
    }
}

int validare_X() {
    bool ok;
    for (i = 1; i <= 3; i++) {
        ok = true;
        for (j = 1; j <= 3 && ok; j++)
            if (a[i][j] != 'X')
                ok = false;
        if (ok)
            return 2;
    }
    for (i = 1; i <= 3; i++) {
        ok = true;
        for (j = 1; j <= 3 && ok; j++)
            if (a[j][i] != 'X')
                ok = false;
        if (ok)
            return 2;
    }
    if ((a[1][1] == 'X' && a[2][2] == 'X' && a[3][3] == 'X') || (a[1][3] == 'X' && a[2][2] == 'X' && a[3][1] == 'X'))
        return 2;
    return 1;
}

int validare_O() {
    bool ok;
    for (i = 1; i <= 3; i++) {
        ok = true;
        for (j = 1; j <= 3 && ok; j++)
            if (a[i][j] != 'O')
                ok = false;
        if (ok)
            return 1;
    }
    for (i = 1; i <= 3; i++) {
        ok = true;
        for (j = 1; j <= 3 && ok; j++)
            if (a[j][i] != 'O')
                ok = false;
        if (ok)
            return 1;
    }
    if ((a[1][1] == 'O' && a[2][2] == 'O' && a[3][3] == 'O') || (a[1][3] == 'O' && a[2][2] == 'O' && a[3][1] == 'O'))
        return 1;
    return 2;
}

bool remiza() {
    for (i = 1; i <= 3; i++)
        for (j = 1; j <= 3; j++)
            if (a[i][j] != 'X' && a[i][j] != 'O')
                return false;
    return true;
}

void regulament() {
    cout
            << "X si O (engleza tic-tac-toe) este un joc pentru doi jucatori, \"X\" respectiv \"0\", care marcheaza pe rand cate o casuta \n dintr-un tabel cu 3 linii si 3 coloane.";
    cout << endl;
    cout << "1.Se alege numarul corspunzator casuteti(de la stanga la dreapte de sus in jos se numeroteaza crescator)"
         << endl;
    cout << "     |     |     " << endl;
    cout << "  " << "1" << "  |  " << "2" << "  |  " << "3" << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << "4" << "  |  " << "5" << "  |  " << "6" << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << "7" << "  |  " << "8" << "  |  " << "9" << endl;
    cout << "     |     |     " << endl;
    cout << "2.Se apasa tasta enter dupa ce a fost aleasa casuta corespunzatoare";
}

void resetare() {
    // char p;
    //  p = '1';
    for (i = 1; i <= 3; i++)
        for (j = 1; j <= 3; j++) {
            a[i][j] = 0;
            //   p++;
        }
}

void meniu() {
    a1:
    int joc_nou = 1;
    cout << "Selectati optiunea dorita: " << endl;
    cout << "1.Regulament" << endl;
    cout << "2.Afisati scorul" << endl;
    cout << "3.Resetati scorul" << endl;
    cout << "4.Incepeti un joc nou" << endl;
    cout << "5.Incepeti un joc nou contra calculatoruli" << endl;
    cout << "6.Stop" << endl;
    cout << "Optiune: ";
    cin >> optiune;
    cout << endl;
    switch (optiune) {
        case 1:
            regulament();
            goto a1;
        case 2:
            cout << "Scor X: " << scor_X << endl;
            cout << "Scor O: " << scor_O << endl;
            goto a1;
        case 3:
            scor_X = 0;
            scor_O = 0;
            goto a1;
        case 4:
            joc_nou = 0;
            goto JOC_NOU;
        case 5:
            Calc_Joc();
            break;
        case 6:
            break;
        default:
            do {
                cout << "Introduceti o valoare de la 1 la 6: ";
                cin >> optiune;
                if (1 <= optiune && optiune <= 6)
                    goto a1;
            } while (optiune < 1 || optiune > 6);
            break;
    }
    JOC_NOU:
    if (joc_nou % 2 == 0)
        Start_JOC();
}

void Start_JOC() {
    resetare();
    cout << "Alege cine v-a incepe primul:" << endl;
    cout << "1.O" << endl << "2.X" << endl;
    cout << "--> ";
    do {
        cin >> playerCurent;
        cout << endl;
        if (playerCurent < 1 || playerCurent > 2)
            cout << "Alegeti 1/2!!!" << endl;
        if (playerCurent == 1)
            jucatorCurent = 1;
        else if (playerCurent == 2)
            jucatorCurent = 0;
    } while (playerCurent != 1 && playerCurent != 2);
    afisare();
    while (true) {
        cout << "Alegeti casuta unde doriti sa puneti: ";
        cin >> numar;
        cout << endl;
        i = j = 0;
        transformare(numar, i, j);
        if (jucatorCurent % 2 == 0)
            valoare_curenta(i, j, 'X');
        else
            valoare_curenta(i, j, 'O');
        if (jucatorCurent >= 3) {
            if (validare_X() == 2) {
                scor_X++;
                cout << "Jucatorul X a castigat!!" << endl;
                meniu();
                break;
            } else if (validare_O() == 1) {
                scor_O++;
                cout << "Jucatorul O a castigat!!" << endl;
                meniu();
                break;
            }
        }
        if (jucatorCurent >= 8)
            if (remiza()) {
                cout << "Remiza!!" << endl;
                meniu();
                break;
            }
        jucatorCurent++;
        afisare();
    }
}

void calculator(char jucator, char calc, int jucator_curent) {
    int mutare = 1;
    if (jucator_curent % 2 == 0) {
        for (i = 1; i <= 3 && mutare; i++)
            for (j = 1; j <= 3 && mutare; j++)
                if (i == 1 && j == 3 && a[i][j] == 0) {
                    a[i][j] = calc;
                    mutare--;
                } else if (((i == 1 && j == 2 && a[i][j] == jucator) || (i == 2 && j == 3 && a[i][j] == jucator)) &&
                           a[2][2] == 0) {
                    a[2][2] = calc;
                    mutare--;
                } else if (i == 1 && j == 2 && a[i][j] == jucator && a[2][2] == calc && a[3][1] != jucator) {
                    if (a[3][1] != jucator && a[3][1] != calc) {
                        a[3][1] = calc;
                        mutare--;
                    } else if (a[1][2] == 0) {
                        a[1][2] = calc;
                        mutare--;
                    } else if (a[2][3] == 0) {
                        a[2][3] = calc;
                        mutare--;
                    } else if (a[2][1] == 0) {
                        a[2][1] = calc;
                        mutare--;
                    } else if (a[3][3] == 0) {
                        a[3][3] = calc;
                        mutare--;
                    }
                } else if (i == 2 && j == 3 && a[i][j] == jucator && a[2][2] == calc) {
                    if (a[3][1] != jucator && a[3][1] != calc) {
                        a[3][1] = calc;
                        mutare--;
                    } else if (a[1][2] == 0 && a[3][3] != calc) {
                        a[1][2] = calc;
                        mutare--;
                    } else if (a[1][1] == 0) {
                        a[1][1] = calc;
                        mutare--;
                    } else if (a[3][2] == 0 && a[3][3] != calc) {
                        a[3][2] = calc;
                        mutare--;
                    }
                } else if (a[2][2] == jucator && i == 2 && j == i && a[3][1] == 0) {
                    if (a[2][3] == 0) {
                        a[2][3] = calc;
                        mutare--;
                    } else if (a[3][3] == 0) {
                        a[3][3] = calc;
                        mutare--;
                    } else if (a[1][1] == 0) {
                        a[1][1] = calc;
                        mutare--;
                    } else if (a[1][2] == 0) {
                        a[1][2] = calc;
                        mutare--;
                    } else if (a[3][2] == 0) {
                        a[3][2] = calc;
                        mutare--;
                    } else if (a[2][1] == jucator) {
                        a[3][1] = calc;
                        mutare--;
                    } else if (a[3][1] == jucator) {
                        a[2][1] = calc;
                        mutare--;
                    }
                } else if (a[1][1] == jucator && i == j && i == 1 && a[2][2] != calc && a[3][1] != jucator) {
                    if (a[3][1] == 0) {
                        a[3][1] = calc;
                        mutare--;
                    } else if (a[2][2] == 0) {
                        a[2][2] = calc;
                        mutare--;
                    } else if (a[3][3] == 0) {
                        a[3][3] = calc;
                        mutare--;
                    } else if (a[2][3] == 0) {
                        a[2][3] = calc;
                        mutare--;
                    } else if (a[3][2] == 0) {
                        a[3][2] = calc;
                        mutare--;
                    }
                } else if (a[3][3] == jucator && i == j && i == 3 && a[2][2] != calc) {
                    if (a[3][1] == 0) {
                        a[3][1] = calc;
                        mutare--;
                    } else if (a[2][2] == 0) {
                        a[2][2] = calc;
                        mutare--;
                    } else if (a[1][1] == 0) {
                        a[1][1] = calc;
                        mutare--;
                    } else if (a[1][2] == 0) {
                        a[1][2] = calc;
                        mutare--;
                    } else if (a[2][1] == 0) {
                        a[2][1] = calc;
                        mutare--;
                    }
                } else if (a[3][1] == jucator && i == 3 && j == 1) {
                    if (a[3][3] == 0) {
                        a[3][3] = calc;
                        mutare--;
                    } else if (a[2][3] == 0) {
                        a[2][3] = calc;
                        mutare--;
                    } else if (a[2][2] == 0) {
                        a[2][2] = calc;
                        mutare--;
                    } else if (a[1][1] == 0) {
                        a[1][1] = calc;
                        mutare--;
                    } else if (a[2][1] == 0) {
                        a[2][1] = calc;
                        mutare--;
                    } else if (a[1][2] == 0) {
                        a[1][2] = calc;
                        mutare--;
                    } else if (a[3][2] == 0) {
                        a[3][2] = calc;
                        mutare--;
                    }
                } else if (a[2][1] == jucator && i == 2 && j == 1) {
                    if (a[2][2] == 0) {
                        a[2][2] = calc;
                        mutare--;
                    } else if (a[3][1] == 0) {
                        a[3][1] = calc;
                        mutare--;
                    } else if (a[1][1] == 0) {
                        a[1][1] = calc;
                        mutare--;
                    } else if (a[1][2] == 0) {
                        a[1][2] = calc;
                        mutare--;
                    } else if (a[3][3] == 0) {
                        a[3][3] = calc;
                        mutare--;
                    }
                } else if (a[3][2] == jucator && i == 3 && j == 2) {
                    if (a[2][2] == 0) {
                        a[2][2] = calc;
                        mutare--;
                    } else if (a[3][1] == 0) {
                        a[3][1] = calc;
                        mutare--;
                    } else if (a[3][3] == 0) {
                        a[3][3] = calc;
                        mutare--;
                    } else if (a[1][1] == 0) {
                        a[1][1] = calc;
                        mutare--;
                    } else if (a[2][3] == 0) {
                        a[2][3] = calc;
                        mutare--;
                    }
                }
    } else {

    }
}

void Calc_Joc() {
    resetare();
    cout << "Alegeti-va jucatorul" << endl;
    cout << "1.Player-O" << endl << "2.Player-X" << endl;
    cout << "--> ";
    do {
        cin >> selectare_jucator;
        cout << endl;
        if (selectare_jucator < 1 || selectare_jucator > 2)
            cout << "Alegeti 1/2!!!" << endl;
        if (selectare_jucator == 1) {
            jucator1 = 'O';
            calc1 = 'X';
        } else if (selectare_jucator == 2) {
            jucator1 = 'X';
            calc1 = 'O';
        }
    } while (selectare_jucator != 1 && selectare_jucator != 2);
    cout << "Alege cine v-a incepe primul:" << endl;
    cout << "1.O" << endl << "2.X" << endl;
    cout << "--> ";
    do {
        cin >> playerCurent;
        cout << endl;
        if (playerCurent < 1 || playerCurent > 2)
            cout << "Alegeti 1/2!!!" << endl;
        if ((playerCurent == 1 && jucator1 == 'O'))
            jucatorCurent = 1;
        else if (playerCurent == 2)
            jucatorCurent = 0;
    } while (playerCurent != 1 && playerCurent != 2);
    if (jucatorCurent % 2 == 0)
        cine_incepe = 0;
    else
        cine_incepe = 1;
    while (true) {
        if (cine_incepe % 2 == 0) {
            if (jucatorCurent % 2 == 0)
                calculator(jucator1, calc1, jucatorCurent);
            else {
                cout << "Alegeti casuta unde doriti sa puneti: ";
                cin >> numar;
                cout << endl;
                i = j = 0;
                transformare(numar, i, j);
                valoare_curenta(i, j, jucator1);
            }
        }
        else {
            if (jucatorCurent % 2 != 0)
                calculator(jucator1, calc1, jucatorCurent);
            else {
                cout << "Alegeti casuta unde doriti sa puneti: ";
                cin >> numar;
                cout << endl;
                i = j = 0;
                transformare(numar, i, j);
                valoare_curenta(i, j, jucator1);
            }
        }
        if (jucatorCurent >= 3) {
            if (validare_X() == 2) {
                scor_X++;
                afisare();
                cout << "Jucatorul X a castigat!!" << endl;
                meniu();
                break;
            } else if (validare_O() == 1) {
                scor_O++;
                afisare();
                cout << "Jucatorul O a castigat!!" << endl;
                meniu();
                break;
            }
        }
        if (remiza()) {
            afisare();
            cout << "Remiza!!" << endl;
            meniu();
            break;
        }
        afisare();
        jucatorCurent++;
        //afisare();
    }

}

void credits() {
    cout << "Developed by Ovyzzz";
}

int main() {
    meniu();
    credits();
    return 0;
}
