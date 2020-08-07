#include "gveditor_shapes.h"

#include "gveditor_basefncl.h"
#include "gveditor_iobj.h"
#include <iostream>
#include <memory>
#include <vector>

//////////////////// point /////////////////////

gvedt::obj_types gvedt::point::get_type() const
{
    return obj_types::POINT;
}

gvedt::point::point()
{
std::cerr << " type " << static_cast<long>(this->get_type()) << std::endl ;
}

gvedt::point::~point()
{

}
void gvedt::point::create(std::vector<long>& shape_data) 
{
(void)shape_data;
}

void gvedt::point::send(std::ostream &out) const
{
(void)out;
}

void gvedt::point::load(std::istream &in)
{
(void)in;
}

//////////////////// vector /////////////////////

gvedt::obj_types gvedt::vector::get_type() const
{
    return obj_types::VECTOR;
}

gvedt::vector::vector()
{

}

gvedt::vector::~vector()
{

}
void gvedt::vector::create(std::vector<long>& shape_data) 
{
(void)shape_data;
}

void gvedt::vector::send(std::ostream &out) const
{
(void)out;
}

void gvedt::vector::load(std::istream &in)
{
(void)in;
}

//////////////////// polyline /////////////////////

gvedt::obj_types gvedt::polyline::get_type() const
{
    return obj_types::POLYLINE;
}

gvedt::polyline::polyline()
{

}

gvedt::polyline::~polyline()
{

}
void gvedt::polyline::create(std::vector<long>& shape_data) 
{
(void)shape_data;
}

void gvedt::polyline::send(std::ostream &out) const
{
(void)out;
}

void gvedt::polyline::load(std::istream &in)
{
(void)in;
}

//////////////////// circle /////////////////////

gvedt::obj_types gvedt::circle::get_type() const
{
    return obj_types::CIRCLE;
}

gvedt::circle::circle()
{

}

gvedt::circle::~circle()
{

}
void gvedt::circle::create(std::vector<long>& shape_data) 
{
(void)shape_data;
}

void gvedt::circle::send(std::ostream &out) const
{
(void)out;
}

void gvedt::circle::load(std::istream &in)
{
(void)in;
}

//////////////////////////// shape_factory()  /////////////////////////////

std::shared_ptr<gvedt::iobj> gvedt::shape_factory(gvedt::obj_types obj_type)
{
    std::shared_ptr<iobj> temp_sp;
    switch (obj_type)
    {
    case gvedt::obj_types::POINT:
        temp_sp = slvr::lib::factory<gvedt::point>();
        break;
    case gvedt::obj_types::VECTOR:
        temp_sp = slvr::lib::factory<gvedt::vector>();
        break;
    case gvedt::obj_types::POLYLINE:
        temp_sp = slvr::lib::factory<gvedt::polyline>();
        break;
    case gvedt::obj_types::CIRCLE:
        temp_sp = slvr::lib::factory<gvedt::circle>();
        break;
    default:
        break;
    }
    return temp_sp;
}

