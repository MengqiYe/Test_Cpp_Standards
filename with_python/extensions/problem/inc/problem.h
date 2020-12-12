//
// Created by mqye on 2020/11/12.
//

#ifndef TEST_CPP_STANDARDS_PROBLEM_H
#define TEST_CPP_STANDARDS_PROBLEM_H
class Pet {
public:
  Pet(const std::string &name, const std::string &species)
    : m_name(name), m_species(species) {}

  std::string name() const { return m_name; }

  std::string species() const { return m_species; }

private:
  std::string m_name;
  std::string m_species;
};

class Pet_Decoder {
public:
  Pet_Decoder(const Pet &_pet) : m_pet(_pet) {};
  Pet pet() const { return m_pet; }

  int decode();

private:
  Pet m_pet;
};

int Pet_Decoder::decode() {
  std::cout << &m_pet << std::endl;
  return 100;
}

#endif //TEST_CPP_STANDARDS_PROBLEM_H
