​	**Шаблони**

 Шаблоните са част от така нареченото "generic"(родствено) програмиране. Чрез тях може да пишем независим от тип на данните код, което е много силен инструмент. Много контейнери и алгоритми в библиотеките на езика са "generic".



**Шаблони в С++** 

 Чрез шаблоните в С++ можем да създаваме шаблонни функции и шаблонни класове(структури). В случаят синтаксисът е следният: преди декларацията на функцията/класа записваме 

template <typename typeParameter>

template <class typeParameter>

като template  е запазена дума за шаблон, typeParameter е типов параметър, който ще използваме като тип на данните, описани след шаблона(по принцип се използва T, защото е кратко и общо прието), a typename и class са 2 запазени думи, които правят едно и също. typename е по-използвано.



Пример за шаблонна функция:
template <typename T>

T findMax(T number1, T number2)

{

​	return a > b ?  a : b;

}



template <typename T, typename U>

void printNumbers(T number1, U number2)

{

cout << number1 <<  " " << number2 << ''\n';

}



Извикване в main:

int a = 10, b = 100;

cout << findMax<int>(a, b);

long c = 10000;

printNumbers<int, long>(a, c);



Пример за шаблонен клас:

template <typename T>

class myContainer 

{

private:

​	T element;

public:

​	myContainer(T element) { this->element = element;}

​	void increase()  {element = element + 1;}

}



По-подробно, но на английски  : http://www.cplusplus.com/doc/oldtutorial/templates/ - тук пише и за template specialization за по-любопитните









