// status : yes
#include <iostream>
#include <vector>
using namespace std;
/*
                Вывести маршрут максимальной стоимости

    Нужно найти максимальную стоимость пути из 
    верхнего левого угла в нижний правый угол.
    Двигаться можно вправо и вниз.
    
    Вводятся два числа N x M. Затем идет N строк по M чисел в каждой.
    Выведите максимальную стоимость пути и путь, символами R D;
*/
int main() {
    int n, m;
    cin >> n >> m;
    int data[n][m] = {0};
    vector<char> moves;
    // инициализвация матрицы
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < m ; j++)
            cin >> data[i][j];

    // устанавливаю начальные стоимости пути по строкам 1 - n
    for(int i = 1 ; i < n ; i++)
        data[i][0] += data[i-1][0];

    // устанавливаю начальные стоимости пути по колонкам 1 - m
    for(int j = 1 ; j < m ; j++)
        data[0][j] += data[0][j-1];
    
    // устанавливаю максимвльные стоимости пути
    // в каждую клетку
    for(int i = 1 ; i < n ; i++)
        for(int j = 1 ; j < m ; j++) {
            int data1 = data[i - 1][j];
            int data2 = data[i][j - 1];
            data[i][j] += max(data1, data2);
        }

    // нахожу путь
    int i = n - 1, j = m - 1;
    while(data[i][j] != data[0][0]) {
        if (i - 1 >= 0 && j - 1 >= 0 && (data[i - 1][j] > data[i][j - 1])) {
            i = i - 1;
            moves.push_back('D');
        }
        else if (i - 1 >= 0 && j - 1 >= 0 && (data[i - 1][j] < data[i][j - 1])){
            j = j - 1;
            moves.push_back('R');
        }
        else if (i - 1 < 0) {
            j = j - 1;
            moves.push_back('R');
        }
        else if (j - 1 < 0) {
            i = i - 1;
            moves.push_back('D');
        }
    }

    // вывод максимальной стоимости
    // и пути
    cout << data[n-1][m-1] << endl;
    for(int i = moves.size() - 1 ; i >= 0 ; i--)
        cout << moves[i] << ' ';

    return 0;
}