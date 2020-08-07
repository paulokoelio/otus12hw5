/**
\file
\brief Реализация интерфейсного класса igui

Класс igui определяет минимум public функций, которые должна предоставлять конкретная
библиотека GUI. 
*/
#ifndef GVEDITOR_IGUI_H_
#define GVEDITOR_IGUI_H_

#include "gveditor_coord2d.h"
#include "gveditor_iobj.h"
#include <memory>
#include <string>
#include <tuple>
#include <vector>
#include "gveditor_controller.h"

namespace gvedt
{

struct cl_window
{
    void *handle;
    slvr::lib::coord2d size;
    std::string name{};
    
};

class igui
{
public:
    virtual ~igui(){};
    virtual std::shared_ptr<cl_window> new_mainwindow(slvr::lib::coord2d size, std::string name) = 0;
    virtual std::shared_ptr<cl_window> new_window(slvr::lib::coord2d size, std::string name) = 0;
    virtual void close(void *handle) = 0;
    virtual void process() = 0;
    virtual void show(std::shared_ptr<gvedt::iobj> obj) = 0;
    virtual std::vector<long> build_shape(std::shared_ptr<gvedt::iobj> obj) = 0;
    virtual void get_filename(std::string & full_filename, const std::string & hint) = 0;

};

} // namespace gvedt

#endif /* GVEDITOR_IGUI_H_ */
