#include <clocale>
#include <iostream>
#include <string>

// Задание 1. Методы

double fraction(double x) {
    return x - static_cast<int>(x);
}

int charToNum(char x) {
    return x - '0';
}

bool is2Digits(int x) {
    const int absX = x < 0 ? -x : x;
    return absX >= 10 && absX <= 99;
}

bool isInRange(int a, int b, int num) {
    const int minVal = a < b ? a : b;
    const int maxVal = a > b ? a : b;
    return num >= minVal && num <= maxVal;
}

bool isEqual(int a, int b, int c) {
    return a == b && b == c;
}

// Задание 2. Условия

int abs(int x) {
    return x < 0 ? -x : x;
}

bool is35(int x) {
    const bool div3 = (x % 3 == 0);
    const bool div5 = (x % 5 == 0);
    return div3 != div5;
}

int max3(int x, int y, int z) {
    int max_val = x;
    if (y > max_val) max_val = y;
    if (z > max_val) max_val = z;
    return max_val;
}

int sum2(int x, int y) {
    const int sum = x + y;
    return (sum >= 10 && sum <= 19) ? 20 : sum;
}

std::string day(int x) {
    switch (x) {
    case 1: return "Понедельник";
    case 2: return "Вторник";
    case 3: return "Среда";
    case 4: return "Четверг";
    case 5: return "Пятница";
    case 6: return "Суббота";
    case 7: return "Воскресенье";
    default: return "это не день недели";
    }
}

// Задание 3. Циклы

std::string listNums(int x) {
    std::string result;
    for (int i = 0; i <= x; ++i) {
        result += std::to_string(i);
        if (i != x) result += ' ';
    }
    return result;
}

std::string chet(int x) {
    std::string result;
    for (int i = 0; i <= x; i += 2) {
        result += std::to_string(i);
        if (i + 2 <= x) result += ' ';
    }
    return result;
}

int numLen(long x) {
    if (x == 0) return 1;
    int count = 0;
    while (x != 0) {
        x /= 10;
        ++count;
    }
    return count;
}

void square(int x) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

void rightTriangle(int x) {
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < x - i; ++j) {
            std::cout << ' ';
        }
        for (int j = 0; j < i; ++j) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

// Задание 4. Массивы 

int findFirst(int arr[], int x) {
    for (int i = 0; arr[i] != 0; ++i) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int maxAbs(int arr[]) {
    int best = arr[0];
    for (int i = 1; arr[i] != 0; ++i) {
        const int abs_i = arr[i] < 0 ? -arr[i] : arr[i];
        const int abs_best = best < 0 ? -best : best;
        if (abs_i > abs_best) {
            best = arr[i];
        }
    }
    return best;
}

// Меню

void printMenu() {
    std::cout << std::endl << "=== Меню ===" << std::endl
        << "--- Задание 1 ---" << std::endl
        << " 1 - Fraction (дробная часть)" << std::endl
        << " 3 - CharToNum (цифра в число)" << std::endl
        << " 5 - Is2Digits (двузначное?)" << std::endl
        << " 7 - IsInRange (в диапазоне?)" << std::endl
        << " 9 - IsEqual (все равны?)" << std::endl
        << "--- Задание 2 ---" << std::endl
        << "11 - Abs (модуль)" << std::endl
        << "13 - Is35 (делится на 3 или 5, но не на оба)" << std::endl
        << "15 - Max3 (максимум из трёх)" << std::endl
        << "17 - Sum2 (сумма с 20 в [10, 19])" << std::endl
        << "19 - Day (день недели)" << std::endl
        << "--- Задание 3 ---" << std::endl
        << "21 - ListNums (числа от 0 до x)" << std::endl
        << "23 - Chet (чётные числа)" << std::endl
        << "25 - NumLen (длина числа)" << std::endl
        << "27 - Square (квадрат)" << std::endl
        << "29 - RightTriangle (треугольник)" << std::endl
        << "--- Задание 4 ---" << std::endl
        << "31 - FindFirst (первое вхождение)" << std::endl
        << "33 - MaxAbs (максимум по модулю)" << std::endl
        << " 0 - Выход" << std::endl
        << "Выбор: ";
}

int main() {
    std::setlocale(LC_ALL, "Russian");

    int choice = -1;
    while (choice != 0) {
        printMenu();

        // Ввод выбора меню с проверкой
        while (true) {
            if (std::cin >> choice) {
                break;
            }
            std::cout << "Ошибка: введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Выбор: ";
        }

        switch (choice) {
            // Задание 1 
        case 1: {
            double x;
            while (true) {
                std::cout << "Введите x: ";
                if (std::cin >> x) break;
                std::cout << "Ошибка: введите число." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout << "Результат: " << fraction(x) << std::endl;
            break;
        }
        case 3: {
            char c;
            while (true) {
                std::cout << "Введите цифру: ";
                if (std::cin >> c && c >= '0' && c <= '9') break;
                std::cout << "Ошибка: введите цифру от '0' до '9'." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout << "Результат: " << charToNum(c) << std::endl;
            break;
        }
        case 5: {
            int x;
            while (true) {
                std::cout << "Введите x: ";
                if (std::cin >> x) break;
                std::cout << "Ошибка: введите число." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout << "Результат: " << (is2Digits(x) ? "true" : "false")
                << std::endl;
            break;
        }
        case 7: {
            int a, b, num;
            while (true) {
                std::cout << "Введите a, b, num: ";
                if (std::cin >> a >> b >> num) break;
                std::cout << "Ошибка: введите три числа." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout << "Результат: " << (isInRange(a, b, num) ? "true" : "false")
                << std::endl;
            break;
        }
        case 9: {
            int a, b, c;
            while (true) {
                std::cout << "Введите a, b, c: ";
                if (std::cin >> a >> b >> c) break;
                std::cout << "Ошибка: введите три числа." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout << "Результат: " << (isEqual(a, b, c) ? "true" : "false")
                << std::endl;
            break;
        }

              //  Задание 2
        case 11: {
            int x;
            while (true) {
                std::cout << "Введите x: ";
                if (std::cin >> x) break;
                std::cout << "Ошибка: введите число." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout << "Результат: " << abs(x) << std::endl;
            break;
        }
        case 13: {
            int x;
            while (true) {
                std::cout << "Введите x: ";
                if (std::cin >> x) break;
                std::cout << "Ошибка: введите число." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout << "Результат: " << (is35(x) ? "true" : "false")
                << std::endl;
            break;
        }
        case 15: {
            int x, y, z;
            while (true) {
                std::cout << "Введите x, y, z: ";
                if (std::cin >> x >> y >> z) break;
                std::cout << "Ошибка: введите три числа." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout << "Результат: " << max3(x, y, z) << std::endl;
            break;
        }
        case 17: {
            int x, y;
            while (true) {
                std::cout << "Введите x, y: ";
                if (std::cin >> x >> y) break;
                std::cout << "Ошибка: введите два числа." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout << "Результат: " << sum2(x, y) << std::endl;
            break;
        }
        case 19: {
            int x;
            while (true) {
                std::cout << "Введите день недели (1-7): ";
                if (std::cin >> x && x >= 1 && x <= 7) break;
                std::cout << "Ошибка: введите число от 1 до 7." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout << "Результат: " << day(x) << std::endl;
            break;
        }

        // Задание 3 
        case 21: {
            int x;
            while (true) {
                std::cout << "Введите x: ";
                if (std::cin >> x && x >= 0) break;
                std::cout << "Ошибка: введите число от 0 до 100." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout << "Результат: " << listNums(x) << std::endl;
            break;
        }
        case 23: {
            int x;
            while (true) {
                std::cout << "Введите x: ";
                if (std::cin >> x && x >= 0) break;
                std::cout << "Ошибка: введите число от 0 до 100." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout << "Результат: " << chet(x) << std::endl;
            break;
        }
        case 25: {
            long x;
            while (true) {
                std::cout << "Введите число: ";
                if (std::cin >> x) break;
                std::cout << "Ошибка: введите число." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            std::cout << "Результат: " << numLen(x) << std::endl;
            break;
        }
        case 27: {
            int x;
            while (true) {
                std::cout << "Введите сторону квадрата: ";
                if (std::cin >> x && x >= 1) break;
                std::cout << "Ошибка: введите число от 1 до 20." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            square(x);
            break;
        }
        case 29: {
            int x;
            while (true) {
                std::cout << "Введите высоту: ";
                if (std::cin >> x && x >= 1) break;
                std::cout << "Ошибка: введите число от 1 до 20." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            rightTriangle(x);
            break;
        }

        // Задание 4
        case 31: {
            int n;
            std::cout << "Сколько чисел? ";
            while (!(std::cin >> n) || n < 0 || n > 99) {
                std::cout << "Ошибка: введите число от 0 до 99." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }

            int arr[100];
            std::cout << "Введите " << n << " чисел: ";
            for (int i = 0; i < n; ++i) {
                while (!(std::cin >> arr[i])) {
                    std::cout << "Ошибка: введите число." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                }
            }
            arr[n] = 0;

            int x;
            std::cout << "Что искать? ";
            while (!(std::cin >> x)) {
                std::cout << "Ошибка: введите число." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }

            std::cout << "Индекс: " << findFirst(arr, x) << std::endl;
            break;
        }
        case 33: {
            int n;
            std::cout << "Сколько чисел? ";
            while (!(std::cin >> n) || n < 1 || n > 99) {
                std::cout << "Ошибка: введите число от 1 до 99." << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }

            int arr[100];
            std::cout << "Введите " << n << " чисел: ";
            for (int i = 0; i < n; ++i) {
                while (!(std::cin >> arr[i])) {
                    std::cout << "Ошибка: введите число." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                }
            }
            arr[n] = 0;

            std::cout << "Результат: " << maxAbs(arr) << std::endl;
            break;
        }

        case 0:
            std::cout << "Выход." << std::endl;
            break;

        default:
            std::cout << "Неверный пункт меню." << std::endl;
            break;
        }
    }

    return 0;
}