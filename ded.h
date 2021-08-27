#ifndef DED
#define DED

//! @file   ded.h
//! @brief  ded - программа для решения квадратных уравнений

#include <stdio.h>
#include <assert.h>
#include <math.h>

enum ROOTCODE {NO_REAL_ROOTS = 0, ONE_ROOT = 1, TWO_ROOTS = 2, NO_ROOTS = 3, INF_ROOTS = 4};
const double EPS = 1e-6;

//! @brief  Сравнение значений двух переменных, производимое с учетом допустимой погрешности в 1e-6
//!
//! @param  value1  Первая переменная типа double, значение которой подлежит сравнению
//! @param  value2  Вторая переменная типа double, значение которой подлежит сравнению
//!
//! @return Значение типа bool: true, если числа совпадают с указанной точностью; false, если не совпадают
//!
//! @note   Автор любит сырники..

bool cmp (double value1, double value2);

//! @brief  Сравнение значения переменной с нулем, производимое с учетом допустимой погрешности в 1е-6
//!
//! @param  value   Переменная типа double, значение которой подлежит сравнению с нулем
//!
//! @return Значение типа bool: true, если числj равно нулю с указанной точностью; false, если не равно
//!
//! @warning Не забирайте у автора сырники!


bool cmp_0 (double value);

//! @brief  Решение квадратного уравнения с заданными коэффициентами
//!
//! @param  a       Коэффициент при x^2 в приведенном виде квадратного уравнения
//! @param  b       Коэффициент при x в приведенном виде квадратного уравнения
//! @param  c       Свободный коэффициент в приведенном виде квадратного уравнения
//!
//! @param  root1   Ссылка на ячейку памяти, в которую будет записан первый корень квадратного уравнения (при наличии)
//! @param  root1   Ссылка на ячейку памяти, в которую будет записан второй корень квадратного уравнения (при наличии)
//!
//! @return В указанные ячейки при наличии записываются значения корней уравнения, возвращается код выполнения
//!
//! @note   Код выполнения rootcode может принимать значения -1, 0, 1, 2, 3, 4 если, соответственно: функция не изменила код выполнения; у уравнения нет ДЕЙСТВИТЕЛЬНЫХ корней, но есть комплексные; у уравнения есть всего один действительный корень; у уравнения есть два действительных корня; у уравнения в принципе не существует корней; у уравнения бесконечность корней / любое число является решением уравнения.

int get_rootcode_roots (double a, double b, double c, double* root1, double* root2);

//! @brief  Печать результатов решения уравнения
//!
//! @param  rootcode    Код выполнения функции give_rootcode_roots
//! @param  root1       Первый найденный корень уравнения (при наличии)
//! @param  root2       Второй найденный корень уравнения (при наличии)
//!
//! @return Ничего не врзвращает, производит печать

void print_rootcode (int rootcode, double root1, double root2);

#endif