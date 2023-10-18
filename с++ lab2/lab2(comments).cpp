#include <stdlib.h>
#include <iostream>

; // This program was designed to show you how the stack works.
  // You shouldn't dereference pointers which are no longer in scope.
  // Never do that, it's undefined behavior (anything can happen).

// Note that this program may break if you use optimizations.
// Also, I have only tried it on Zig C++ (Clang) on Windows.

// Also note, that this produces a warning on Zig C++ (Clang), which is expected.

// See the excel file for a visualization of the stack.

//  Создаем функцию стэкмемори 1 которая будет возвращать указатель интежер там внутри создаем переменную а приравниваем ее одному и возвращаем указатель на а
int *stackMemory1()
{
    int a = 1;
    return &a;
}
// Тоже самое но уже с б
int *stackMemory2()
{
    int b = 2;
    return &b;
}

// Возвращаются именно такие значения из-за того что обе функции имеют свои локальные переменные и возвращают поинтеры на них в первом случае стекмемори создает
// локальную переменную а со значением 1 и возвращает указатель на эту переменную сама переменная после завершения функции остается в памяти стека
// Во втором случае а1 получает значение на которое указывает б, то есть 1
// В третьем случае с вызывает вторую функцию и возвращает указатель на нее новая переменная инициализируется со значением 2  В четвертом случае а2 получает значение
// на которое указывает с, а с в свою очередь указывает на новую созданную переменную и мы видим два
// В пятом случае а3 будет равна двум потому что б уже указывает на новую переменную из второй функции и она равна двум(потому что мы вызвали функцию выше); и
// именно поэтому указатели указывают на одно и ту же область памяти
// ОТЛИЧИЕ ПЕРЕМЕННОЙ ИЗ СТЭК1СПП ОТ ПЕРЕМЕННОЙ В СТЭК2СПП: в стэк1спп переменная и функция не возвращает указатель на нее из-за этого всегда выводится 0
// в отличии от второго случая.
int main()
{
    int *b = stackMemory1();
    int a1 = *b; // 1
    int *c = stackMemory2();
    int a2 = *c; // 2
    int a3 = *b; // 2

    std::cout << a1 << std::endl;                                // prints 1
    std::cout << a2 << std::endl;                                // prints 2
    std::cout << a3 << std::endl;                                // prints 2
    std::cout << ((std::byte *)b - (std::byte *)c) << std::endl; // prints 0, pointers are equal

    return 0;
}