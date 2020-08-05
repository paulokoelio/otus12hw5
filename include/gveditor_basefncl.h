/**
\file
\brief Заголовочный файл с основными константами приложения

Заголовочный файл содержит основные константы и переменные приложения, а также
объявления небольших вспомогательных функций. 
*/
#ifndef GVEDITOR_BASEFNCL_H_
#define GVEDITOR_BASEFNCL_H_

#include <gveditor_coord2d.h>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

#define UNUSED(variable) (void)variable

namespace gvedt
{

const slvr::lib::coord2d MAIN_WINDOW_SIZE{600, 100};
const slvr::lib::coord2d DOC_WINDOW_SIZE{600, 480};
const std::string MAIN_WINDOW_NAME{"gveditor"};

} // namespace gvedt

namespace slvr
{

namespace lib
{
/**
Внутренняя шаблонная функция для создания объектов типа Т
в динамической памяти, используя конструктор Т(args...). 
Возвращает shared_pointer на созданный объект.
\param[in] T тип создаваемого объекта
\param[in] args... аргументы, которые передаются в конструктор
*/
template <class T, class... Args>
std::shared_ptr<T> factory(Args &&... args) { return std::make_shared<T>(std::forward<Args>(args)...); }



} // namespace lib

} // namespace slvr

#endif /* GVEDITOR_BASEFNCL_H_ */

