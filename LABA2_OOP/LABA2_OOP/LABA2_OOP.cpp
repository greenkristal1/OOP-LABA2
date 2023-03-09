// LABA2_OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <stdio.h>
using namespace std;
//Part 1

class Line {//класс Line, содержащий одно приватное свойство length и публичное свойство length
private:
    int length;

public:
    int brush_size;

    Line() : length(0), brush_size(1) {//конструктор по-умолчанию
        printf_s("Line()\n");

    }
    Line(int length) : length(length), brush_size(1) {//конструктор с одним параметром
        printf_s("Line(int length)\n");

    }
    Line(int length, int br) : length(length), brush_size(br) {//конструктор с двумя параметрами
        printf_s("Line(int length, int br)\n");

    }
    Line(const Line& l) : length(l.length), brush_size(l.brush_size) {//конструктор копирования
        printf_s("Line(const Line& l)\n");

    }
    ~Line() {//деструктор
        printf_s("~Line()\n");
        printf_s("Length = %d, Brush Size = %d\n", length, brush_size);
    }
    void pull_out() {//метод, который выводмт значения свойств length и sharpness
        printf_s("Line::void pull_out()\n");
        printf_s("Length = %d, Brush Size = %d\n", length, brush_size);
    }
    void set_length(int dl);//объявление метода без реализации внутри класса



};
void Line::set_length(int dl) {//реализация метода вне класса, изменяющее длину линии
    printf_s("Line::void set_length(int dl)\n");
    if (dl > 4) {
        length = dl;
    }
    printf_s("Length = %d\n", length);
}
//part 2 --------------------------------------------------------------------------------------------------
class Car {//класса Car, имеющее одно приватное поле max_speed, одно протектед поле price
private:
    int max_speed;
protected:
    int price;
public:
    Car() { //конструктор по-умолчанию
        printf("Car()\n");
        max_speed = 50;
        price = 100'000;

    }
    Car(int max_speed) {//конструктор с одним параметром
        printf("Car(int max_speed)\n");
        this->max_speed = max_speed;
        this->price = 50000;
    }
    Car(int max_speed, int price) : Car(max_speed) {//конструктор с двумя параметрами
        printf("Car(int max_speed, int price)\n");
        this->price = price;
    }
    Car(const Car& c) {//конструктор копирования
        printf("Car(const Car& c)\n");
        max_speed = c.max_speed;
        price = c.price;
    }
    void demonstrate() {//метод, выыводящий поля max_speed, price
        printf("Car::void demonstrate()\n");
        printf("Maximum speed: %d, price: %d\n", max_speed, price);

    }
    ~Car() {
        printf("~Car()\n");
        printf("Maximum speed: %d, price: %d\n", max_speed, price);
    }

};




class Truck : public Car {//класс, имеющий приватное поле power_traction
private:
    int power_traction;
public:
    Truck() : Car() {//консрукор по умолчанию, вызывающий конструктор по-умолчанию предка Car
        printf("Truck()\n");
        power_traction = 1;
    }
    Truck(int speed, int price, int power_traction) : Car(speed) {//конструктор с параметрами, вызывающий конструктор предка Car
        printf("Truck(int speed, int price, int power_traction)\n");
        //this->speed = speed - Ошибка. Дочерний класс не может использовать свойства private. Поэтому делегируем в конструктор с параметром базового класса
        this->price = price;
        this->power_traction = power_traction;
    }
    Truck(const Truck& t) :Car(t) {//конструктор копирования, вызывающий конструктор копирования Car
        printf("Car(const Truck& t)\n");
        this->power_traction = t.power_traction;
    }
    ~Truck() {//деструктор
        printf("~Truck()\n");
        printf("Power Traction is %d\n", power_traction);
    }
    void demonstrate() {//метод, выводящий поле power_traction
        printf("Truck::void demonstrate()\n");
        Car::demonstrate();
        printf("Power Traction is %d\n", power_traction);
    };
};

//part 3
class Spoon {//класс, имеющий одно протектед поле length, используется для реализации композиции
protected:
    int length;
public:
    Spoon() {//конструкор по умолчанию
        printf_s("Spoon()\n");
        length = 10;
    }
    Spoon(int l) {//конструктор с параметрами
        printf_s("Spoon(int l)\n");
        length = l;
    }
    Spoon(const Spoon& s) {//конструктор копирования
        printf_s("Spoon(const Spoon& s)\n");
        length = s.length;
    }
    ~Spoon() {//деструктор
        printf_s("~Spoon()\n");
        printf_s("Length: %d\n", length);
    }
    void show_spoon_length() {//метод, выводящий свойтство length
        printf_s("void show_spoon_length()\n");
        printf_s("Length of spoon is %d\n", length);
    }

};

class Knife {////класс, имеющий 2 протектед поля length и sharpness, используется для реализации композиции
protected:
    double sharpness;
    int length;
public:
    Knife() {//конструктор по-умолчанию
        printf("Knife()\n");
        sharpness = 1;
        length = 10;
    }
    Knife(double sharp, int length) {//конструктор с параметрами
        printf("Knife(int sharp, int length)\n");
        if (sharp <= 1 && sharp > 0) {
            sharpness = sharp;
        }
        else {//если sharpness в пределах от 0 до 1, идет присваивание
            printf("Incoreect sharpness. Set to 1 by default\n");
            sharpness = 1;
        }
        this->length = length;
    }
    Knife(const Knife& k) {//конструктор копирования
        printf("Knife(const Knife& k)\n");
        sharpness = k.sharpness;
        length = k.length;
    }
    ~Knife() {//деструктор
        printf("~Knife()\n");
        printf("Length: %d, Sharpness: %f\n", length, sharpness);
    }
    void show_sharpness() {//метод, выводящий sharpness
        printf("void show_sharpness()\n");
        printf("Sharpness is %f\n", this->sharpness);
    }
    double get_length() {//метод, возращающй length
        printf("int get_length()\n");
        return length;
    }
};

class Utensils {
public:
    Spoon* s;//реалиация композиции
    Knife* k;


    Utensils() {//конструктор по-умолчанию 
        printf("Utensils()\n");
        s = new Spoon();
        k = new Knife();
    }
    Utensils(int spoon_length, int knife_length, double sharpness) {//конструктор с параметрами
        printf("Utensils(int spoon_length, int knife_length, double sharpness)\n");
        s = new Spoon(spoon_length);
        k = new Knife(sharpness, knife_length);
    }
    Utensils(const Utensils& u) {//конструктор копирования
        printf("Utensils(const Utensils& u)\n");
        s = new Spoon(*(u.s));
        k = new Knife(*(u.k));
    }
    ~Utensils() {//деструктор, удаляет объекты композиции

        delete s;
        delete k;
        printf("~Utensils()\n");
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    //part 1--------------------------------------------------------------------------------------------------------------------
    printf_s("Static objects: \n");
    {//создание статических объектов
        Line ls1;//создание без параметров
        Line ls2(32);//создание с парамиетрами
        Line ls3(21, 4);//создание с парамиетрами
        Line ls4(ls3);//создание с помощью конструктора копирования
        //ls2.length = 77 - Ошибка. Нелья обратиться к length напрямую , так как это поле не public
        ls4.set_length(77);
        ls2.brush_size = 13;
        int ls1_br = ls1.brush_size;
        int ls2_br = ls2.brush_size;
        int ls3_br = ls3.brush_size;
        int ls4_br = ls4.brush_size;

        printf_s("Brush sizes variables from ls1_br to ls4_br: %d, %d, %d, %d\n", ls1_br, ls2_br, ls3_br, ls4_br);
        printf_s("\n Method calls:\n");
        ls1.pull_out();
        ls2.pull_out();
        ls3.pull_out();
        ls4.pull_out();
    }

    printf_s("\n\n\nDynamic objects:\n");
    //динамическое создание
    Line* ld1 = new Line;//создание без параметров
    Line* ld2 = new Line(6);//создание с парамиетрами
    Line* ld3 = new Line(17, 4);//создание с парамиетрами
    Line* ld4 = new Line(*ld3);//создание с помощью конструктора копирования
    //ld3->length = 43 - Ошибка. Нелья обратиться к length напрямую , так как это поле не public
    ld3->set_length(43);
    ld1->brush_size = 6;
    int ld1_br = ld1->brush_size;
    int ld2_br = ld2->brush_size;
    int ld3_br = ld3->brush_size;
    int ld4_br = ld4->brush_size;

    printf_s("Brush sizes variables from ls1_br to ls4_br: %d, %d, %d, %d\n", ld1_br, ld2_br, ld3_br, ld4_br);
    printf_s("\n Method calls:\n");
    ld1->pull_out();
    ld2->pull_out();
    ld3->pull_out();
    ld4->pull_out();
    delete ld1;
    delete ld2;
    delete ld3;
    delete ld4;

    printf_s("-----------------------------------------------------------------------------------\n");
    printf_s("Часть вторая");

    Truck* t1 = new Truck;
    t1->demonstrate();
    Car* t2 = new Truck(100, 100'000, 56);
    t2->demonstrate();
    delete t1;
    delete t2;

    printf("-------------------------------------------------------------------------------------------------\n");
    //part 3
    
    Utensils* u = new Utensils(8, 12, 0.7);
    
   
    u->k->show_sharpness();
    int l = u->k->get_length();
    printf_s("The length of knife is %d", l);
    u->s->show_spoon_length();
    
    delete u;
    

}


