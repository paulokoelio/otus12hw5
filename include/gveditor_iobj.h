#ifndef GVEDITOR_IOBJ_H_
#define GVEDITOR_IOBJ_H_

#include <vector>
#include <iostream>

namespace gvedt
{

enum class obj_types : int
{
    POINT = 1,
    VECTOR = 2,
    POLYLINE = 3,
    CIRCLE = 4
};

class iobj
{
    inline friend std::ostream &operator<<(std::ostream &out, const iobj &obj);
    inline friend std::istream &operator>>(std::istream &in, iobj &obj);

public:
    virtual gvedt::obj_types get_type() const = 0;
    int get_id() const { return id; }
    void set_id(int new_id) { id = new_id; }
    iobj() : id(-1) { std::cerr << "Created object type " << std::endl ; }
    virtual ~iobj() {std::cerr << "Destoyed object id " << static_cast<long>(this->get_id()) << std::endl ;};
    virtual void create(std::vector<long>& shape_data) = 0;
    const std::vector<long> & get_data() {return data; } 

protected:
    int id;
    std::vector<long> data;
    virtual void send(std::ostream &out) const = 0; // you should define private functions send() and
    virtual void load(std::istream &in) = 0; // load() for each class derived from gvedt::iobj
};

inline std::ostream &operator<<(std::ostream &out, const gvedt::iobj &obj);
inline std::istream &operator>>(std::istream &in, gvedt::iobj &obj);

} // namespace gvedt




#endif /* GVEDITOR_IOBJ_H_ */
