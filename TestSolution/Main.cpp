#include <iostream>

using namespace std;

template <typename T, typename K>
T cin_checker(T& cinNumber, K min, K max) {
    cin >> cinNumber;
    while (1 == 1) {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Помилка введення: некоректне значення! \nВведiть правильно: ";
            cin >> cinNumber;
        }

        else if (cinNumber < min) {
            cin.ignore(32767, '\n');
            cout << "Помилка введення: значення менше мiнiмуму! \nВведiть правильно: ";
            cin >> cinNumber;
        }
        else if (cinNumber > max) {
            cin.ignore(32767, '\n');
            cout << "Помилка введення: значення бiльше максимуму! \nВведiть правильно: ";
            cin >> cinNumber;
        }

        else {
            cin.ignore(32767, '\n');
            break;
        }
    }
    return cinNumber;
}


int main() {
    setlocale(LC_ALL, "");
    int questionX, guessX;
    srand(time(NULL));
    questionX = rand() % 50 + 1;

    cout << "Вгадайте число от 1 до 50: " << endl;

    for (int counter = 1; counter <= 7; counter++) {
        cin_checker(guessX, 1, 50);
        if (guessX == questionX) {
            cout << "Перемога!" << endl;
            break;
        }
        else if (counter == 7) cout << "Ви програли. Комп'ютер загадав число " << questionX << "." << endl;
        else cout << "Ви не вгадали. Це була ваша " << counter << " спроба, спробуйте знову." << endl;
    }
    return 0;
}