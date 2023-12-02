/* Дано:
 * Круглая мишень, центр 0,0.
 * Разбита на сектора [0, 1), [1, 2), [2, 3), [3, 4), [4, 5) - 5шт.
 * Балл за центральный = 5, За каждый следующий сектор от центра бал на единицу меньше. Вне мишени балл = 0.
 * Пользователь делает 5 выстрелов: {(xi, yi)}, где i=[1,5]. За каждое попадание начисляются баллы.
 * На выходе: Sum of points (сумма балов) и сообщение "лузер", если суммарное значение баллов < 10.
 * !!! Два условных оператора и одни побитовый.
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {

    double x, y, distance;
    int hitSector;
    int maxSectorNum = 5;
    int maxShotCount = 5;
    int scoreToWin = 10;
    int scoreCount = 0;

    srand(static_cast <unsigned> (time(0)));

    for(int curShotCount = 0; curShotCount != maxShotCount; curShotCount++){
        printf("[*] Attempt %i\n", curShotCount+1);
        printf("# Enter X and Y coords:");
        scanf("%lf %lf", &x, &y);

        x = x + (static_cast<double>(rand()) / RAND_MAX * (maxSectorNum - (-maxSectorNum)) - maxSectorNum);
        y = y + (static_cast<double>(rand()) / RAND_MAX * (maxSectorNum - (-maxSectorNum)) - maxSectorNum);

        distance = sqrt(pow(x, 2) + pow(y, 2));
        hitSector = min(5, static_cast<int>(distance) << 0);
        scoreCount += 5 - hitSector;
        printf("Point of impact: X = %.1f & Y = %.1f | + %i score(s)\n\n", x, y, 5 - hitSector);
    }

    printf("[*] Sum of points is %i\n", scoreCount);
    if(scoreCount < scoreToWin){
        printf("[-] Unfortunately, you're a loser :)");
    } else {
        printf("[+] Unfortunately, you're a NOT loser. Good job!");
    }

    return 0;
}
