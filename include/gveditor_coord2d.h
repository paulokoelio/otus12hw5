/**
\file
\brief Реализация класса coord2d

Класс coord2d позволяет задавать необходимые координаты в виде
{x, y} с приведением значений к единому типу long и возвращать 
координаты в виде пары std::pair. 
*/
#ifndef GVEDITOR_COORD2D_H_
#define GVEDITOR_COORD2D_H_

#include <initializer_list>
#include <utility>

namespace slvr
{

namespace lib
{
class coord2d
{
private:
    long x;
    long y;

public:
    coord2d() : x(0), y(0) {}

    template <class T1, class T2>
    coord2d(T1 new_x, T2 new_y)
    {
        x = static_cast<long>(new_x);
        y = static_cast<long>(new_y);
    }

    coord2d(const coord2d &new_coord)
    {
        x = new_coord.x;
        y = new_coord.y;
    }
    coord2d(coord2d &&new_coord) = default;

    coord2d &operator=(const coord2d &new_coord)
    {
        if (this == &new_coord) return *this;
        x = new_coord.x;
        y = new_coord.y;
        return *this;
    }

    template <class T>
    coord2d &operator=(std::initializer_list<T> new_coord) 
    {
        static_assert(new_coord.size() != 2, "coord2d initializer_list in operator= must have 2 elements");
        auto coord = coord2d(new_coord);
        return coord;
    }

    ~coord2d() = default;

    long getx() const { return x; }
    long gety() const { return y; }
    std::pair<long, long> get() const { return std::make_pair(x, y); }
};

} // namespace lib
} // namespace slvr

#endif /* GVEDITOR_COORD2D_H_ */
