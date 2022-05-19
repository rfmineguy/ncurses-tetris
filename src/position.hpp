template <typename T>
class Position {
    public:
        Position();
        Position(T _x);
        Position(T _x, T _y);
        Position(const Position& p);
        ~Position();
        Position operator=(const Position& p);
        bool operator==(const Position& p);
        bool operator>(const Position& p);
        bool operator>=(const Position& p);
        bool operator<(const Position& p);
        bool operator<=(const Position& p);
        
    private:
        T *x, *y;
};

//
//  IMPLEMENTATION DETAILS
//

template<typename T>
Position<T>::Position() 
:Position(0, 0){}

template <typename T>
Position<T>::Position(T _x)
:Position(_x, 0){}

template <typename T>
Position<T>::Position(T _x, T _y)
:x(new T(_x)), y(new T(_y)) {}

template <typename T>
Position<T>::Position(const Position& p) 
    :x(new T(*p.x)), y(new T(*p.y)) {}

template <typename T>
Position<T>::~Position() {
    delete x;
    x = nullptr;
    delete y;
    y = nullptr;
}

template <typename T>
Position<T> Position<T>::operator=(const Position<T>& p) {
    if (this != &p) {
        delete x;           //free memory that won't be valid anymore
        delete y;
        x = new T(*p.x);
        y = new T(*p.y);
    }
    return *this;
}

template <typename T>
bool Position<T>::operator==(const Position<T>& p) {
    bool xEquals = *x == *p.x;
    bool yEquals = *y == *p.y;
    return xEquals && yEquals;
}

template <typename T>
bool Position<T>::operator<(const Position<T>& p) {
    bool xLess = *x < *p.x;
    bool yLess = *y < *p.y;
    return xLess && yLess;
}

template <typename T>
bool Position<T>::operator<=(const Position<T>& p) {
    return operator<(p) || operator==(p);
}

template <typename T>
bool Position<T>::operator>(const Position<T>& p) {
    return !operator<=(p);
}

template <typename T>
bool Position<T>::operator>=(const Position<T>& p) {
    return operator>(p) || operator==(p);
}
