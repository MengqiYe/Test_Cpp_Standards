//
// Created by mqye on 2020/10/4.
//

#include <iostream>
#include <string>

class Entity
{
private:
  int m_X, m_Y;
  mutable int var;
public:
  int GetX() const
  {
    var = 2;
    return m_X;
  }

  void SetX(int x)
  {
    m_X = x;
  }

  int GetY() const
  {
    return m_Y;
  }
};

class EntityConst
{
private:
  int* m_X, m_Y;
public:
  const int* const GetX() const
  {
    return m_X;
  }

  void SetX(int x) const
  {
//    m_X = x;
  }

  int GetY() const
  {
    return m_Y;
  }
};

void PrintEntity(const Entity& e)
{
  std::cout << e.GetX() << std::endl;
}

int main(){
  Entity e;
  const int MAX_AGE = 90;
  const int* const a = new int;

}