
template <class T>
Ship<T>::Ship(std::string name) : name(name), size(0), person_num(0) {}

template <class T> Ship<T>::Ship() : size(0), person_num(0) {}

// 成员函数实现
template <class T> int Ship<T>::get_size() const { return size; }

template <class T> int Ship<T>::get_person_num() const { return person_num; }

template <class T> void Ship<T>::set_person_num(int num) { person_num = num; }
template <class T> int Ship<T>::cal() { return size * person_num; }