#include <iostream>

using namespace std;

//1. Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.

template<class T>
class Pair1 {
private:
    T p1;
    T p2;
public:
    Pair1(const T &a, const T &b) : p1(a), p2(b) {}

    const T &first() const {
        return p1;
    }

    const T &second() const {
        return p2;
    }
};

//2. Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.

template<class T, class U>
class Pair {
private:
    T p1;
    U p2;
public:
    Pair(const T &a, const U &b) : p1(a), p2(b) {}

    const T &first() const {
        return p1;
    }

    const U &second() const {
        return p2;
    }
};

/*3. Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа.
 * Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string,
 * а второй — любого типа данных.*/

template<class T>
class StringValuePair : public Pair<string, T> {
public:
    StringValuePair(string a, const T &b) : Pair<string, T>(a, b) {}
};

/*4. Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer,
 * который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер.
 * Создать класс GenericPlayer, в который добавить поле name - имя игрока. Также добавить 3 метода:
• IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
• IsBoosted() - возвращает bool значение, есть ли у игрока перебор
• Bust() - выводит на экран имя игрока и объявляет, что у него перебор.*/

class GenericPlayer : public Hand {
private:
    string name;
public:
    virtual bool IsHitting() = 0;

    bool IsBoosted() {
        return GetTotal() > 21;
    }

    void Bust() {
        cout << name << " is boosted" << endl;
    }
};

int main() {
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}

// Не очень хорошо понимаю, почему в шаблонах параметры и возвращаемое значение должны быть константными ссылками.
// Если передавать константные ссылки в параметры, чтобы случайно не изменить передаваемые объекты, то какая логика с возвражаемым значением?


