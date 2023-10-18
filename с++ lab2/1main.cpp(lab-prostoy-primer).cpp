#include <iostream>

int hello(int input);

int hello(int input)
{
    return input;
};

int main()
{
    int result = hello(43);
    std::cout << result;
    return 0;
};

// (если бы фукнция была бы без тела была бы ошибка, потом просто добавляем функции любое валидное тело и все работает) без тела было бы так:
//  #include <iostream>

//  int hello(int input);

// int main()
// {
//      int result = hello(43);
//      std::cout << result;
//      return 0;
//  };
// и ниче бы не работало.