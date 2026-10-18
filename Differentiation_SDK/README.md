# Контракт бібліотеки Differentiation (Варіант 1, Студент Б)

## Опис API
Бібліотека надає функції для чисельного диференціювання. Усі функції експортуються за стандартом C-ABI (extern "C").

## Функції:
1. `double forwardDifference(double fx_plus_h, double fx, double h)` - Права (пряма) різниця.
2. `double backwardDifference(double fx, double fx_minus_h, double h)` - Ліва (зворотна) різниця.
3. `double centralDifference(double fx_plus_h, double fx_minus_h, double h)` - Центральна різниця.
4. `double secondDerivative(double fx_plus_h, double fx, double fx_minus_h, double h)` - Друга похідна.

## Параметри:
* `fx_plus_h` - значення функції у точці (x + h)
* `fx` - значення функції у точці x
* `fx_minus_h` - значення функції у точці (x - h)
* `h` - крок диференціювання.

## Обмеження та обробка помилок (Edge Cases):
* Крок `h` не може дорівнювати `0.0`. Якщо користувач передасть `h = 0.0`, функція безпечно поверне `0.0`, щоб уникнути помилки ділення на нуль.