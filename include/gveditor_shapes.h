#ifndef GVEDITOR_SHAPES_H_
#define GVEDITOR_SHAPES_H_

#include "gveditor_basefncl.h"
#include "gveditor_iobj.h"
#include <iostream>
#include <memory>
#include <vector>

namespace gvedt
{

class point : public gvedt::iobj
{
public:
    virtual gvedt::obj_types get_type() const override;
    point();
    virtual ~point() override;
    virtual void create(std::vector<long> &shape_data) override;

protected:
    void send(std::ostream &out) const override; // you should define private functions send() and
    void load(std::istream &in) override;        // load() for each class derived from gvedt::iobj
};

class vector : public gvedt::iobj
{
public:
    virtual gvedt::obj_types get_type() const override;
    vector();
    virtual ~vector() override;
    virtual void create(std::vector<long> &shape_data) override;

protected:
    void send(std::ostream &out) const override; // you should define private functions send() and
    void load(std::istream &in) override;        // load() for each class derived from gvedt::iobj
};

class polyline : public gvedt::iobj
{
public:
    virtual gvedt::obj_types get_type() const override;
    polyline();
    virtual ~polyline() override;
    virtual void create(std::vector<long> &shape_data) override;

protected:
    void send(std::ostream &out) const override; // you should define private functions send() and
    void load(std::istream &in) override;        // load() for each class derived from gvedt::iobj
};

class circle : public gvedt::iobj
{
public:
    virtual gvedt::obj_types get_type() const override;
    circle();
    virtual ~circle() override;
    virtual void create(std::vector<long> &shape_data) override;

protected:
    void send(std::ostream &out) const override; // you should define private functions send() and
    void load(std::istream &in) override;        // load() for each class derived from gvedt::iobj
};

std::shared_ptr<iobj> shape_factory(gvedt::obj_types obj_type);


} // namespace gvedt

#endif /* GVEDITOR_SHAPES_H_ */
