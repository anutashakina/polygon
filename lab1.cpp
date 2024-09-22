#include <iostream>
#include <unordered_set>
#include <fstream>

using namespace std;

// Задача:
// Удалить дублирующиеся значения из входного массива

// Асимптотическая сложность этого алгоритма O(N), где N - размер массива
// Алгоритм проходит один раз по всему массиву, а также используется хеш таблица, где каждый insert в среднем работает за O(1).

// По памяти O(8*K+16*2*K)=(40K), учитывая хеш таблицу с элементами long long по 8 байт, где K - количество уникальных элементов
// Для хеш таблицы учитываются примерные значения, так как реальное количество памяти сильно зависит от компилятора и системы

int main(int argc, char* argv[]) {  // В функцию main передается количество аргументов и сами аргументы командной строки в виде массива указателей
    ifstream file(argv[1]);  // Открываем файл

    int size;
    file >> size;  // Ввод размера массива

    unordered_set<long long> ans;  // Хеш таблица, которая отсекает дублирующиеся варианты

    for (int i = 0; i < size; i++) {
        long long elem;
        file >> elem;  // Ввод очередного элемента массива

        ans.insert(elem);  // Добавление в хеш таблицу (Вычисляется хеш значение элемента и добавляется в соответствующую ячейку)
    }
    
    for (long long elem : ans) {
        cout << elem << ' ';  // Вывод элементов
    } cout << '\n';

    file.close();  // Закрываем файл
    return 0;
}
