#include "gveditor_iobj.h"
#include <iostream>

namespace gvedt
{

inline std::ostream &operator<<(std::ostream &out, const gvedt::iobj &obj)
{
    obj.send(out);
    return out;
}

inline std::istream &operator>>(std::istream &in, gvedt::iobj &obj)
{
    obj.load(in);
    return in;
}

} // namespace gvedt
