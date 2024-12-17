#ifndef SHIP_H
#define SHIP_H

#include <string>

// 模板类 Ship
template <class T> class Ship {
public:
  // 构造函数
  Ship(std::string name);
  Ship();

  // 成员函数
  int get_size() const;
  int get_person_num() const;
  void set_person_num(int num);

private:
  std::string name;
  int size;
  int person_num;
  int cal();
};

class wood {
public:
  bool burn = true;
};

class iron {
public:
  bool burn = false;
};

#include "class.cpp" // 模板实现分离到 tpp 文件
#endif               // SHIP_H