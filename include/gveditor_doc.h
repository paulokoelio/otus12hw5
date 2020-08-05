#ifndef GVEDITOR_DOC_H_
#define GVEDITOR_DOC_H_

#include "gveditor_iobj.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>

namespace gvedt
{

class doc
{
    friend inline std::ostream &operator<<(std::ostream &out, const gvedt::doc &document);
    friend inline std::istream &operator>>(std::istream &in, gvedt::doc &document);

private:
    std::string name;
    std::map<int, std::shared_ptr<iobj>> shapes;
    int index{1};
protected:
    void send(std::ostream &out) const;
    void load(std::istream &in);

public:
    doc() {std::cerr << "Created document " << std::endl ;};
    doc(const doc &x) = delete;
    doc(doc &&x) = delete;
    ~doc() {std::cerr << "  _Destroyed document " << std::endl ;};
    doc &operator=(const doc &x) = delete;
    doc &operator=(doc &&x) = delete;

    void add_shape(std::shared_ptr<gvedt::iobj> sp_new_obj);
    std::shared_ptr<gvedt::iobj> get_shape(int id);
    void delete_shape(int id);
};

inline std::ostream &operator<<(std::ostream &out, const gvedt::doc &document)
{
    // Здесь должна быть сериализация всего документа в поток
    // Перед каждой фигурой записывается ее тип, полученный методом get_type()
    /* например, так:         */
    
    document.send(out);
    return out;

    /* */
}

inline std::istream &operator>>(std::istream &in, gvedt::doc &document)
{
    // Здесь должна быть загрузка документа из потока с восстановлением всем фигур 
    // определением максимального используемого индекса 
    /* например, так:         */
    
    document.load(in);
    return in;

    /* */
}


} // namespace gvedt


#endif /* GVEDITOR_DOC_H_ */
