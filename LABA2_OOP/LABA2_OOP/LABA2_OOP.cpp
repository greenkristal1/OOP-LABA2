// LABA2_OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <stdio.h>
using namespace std;
//Part 1

class Line {
private:
    int length;

public:
    int brush_size;

    Line() : length(0), brush_size(1) {
        printf_s("Line()\n");

    }
    Line(int length) : length(length), brush_size(1) {
        printf_s("Line(int length)\n");

    }
    Line(int length, int br) : length(length), brush_size(br) {
        printf_s("Line(int length, int br)\n");

    }
    Line(const Line& l) : length(l.length), brush_size(l.brush_size) {
        printf_s("Line(const Line& l)\n");

    }
    ~Line() {
        printf_s("~Line()\n");
        printf_s("Length = %d, Brush Size = %d\n", length, brush_size);
    }
    void pull_out() {
        printf_s("Line::void pull_out()\n");
        printf_s("Length = %d, Brush Size = %d\n", length, brush_size);
    }
    void set_length(int dl);



};
void Line::set_length(int dl) {
    printf_s("Line::void set_length(int dl)\n");
    length = dl;
    printf_s("Length = %d\n", length);
}
int main()
{
    //part 1--------------------------------------------------------------------------------------------------------------------
    printf_s("Static objects: \n");
    {
        Line ls1;
        Line ls2(32);
        Line ls3(21, 4);
        Line ls4(ls3);
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
    Line* ld1 = new Line;
    Line* ld2 = new Line(6);
    Line* ld3 = new Line(17, 4);
    Line* ld4 = new Line(*ld3);
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

    printf_s("-----------------------------------------------------------------------------------");
}


