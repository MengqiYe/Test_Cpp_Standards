# Test C++ Standards 🧪

C++ 标准特性测试项目，涵盖 C++11/14/17/20 的新特性示例。

## 🎯 项目简介

本项目用于测试和学习 C++ 各版本标准的新特性，帮助理解现代 C++ 编程。

## 📂 项目结构

```
Test_Cpp_Standards/
├── CMakeLists.txt       # CMake 构建配置
├── with_cpp11/          # C++11 特性测试
├── with_cpp14/          # C++14 特性测试
├── with_cpp17/          # C++17 特性测试
├── with_cpp20/          # C++20 特性测试
├── with_python/         # Python 绑定测试
└── cmake/               # CMake 模块
```

## 🔧 各版本特性

### C++11
- **auto 关键字**: 自动类型推导
- **lambda 表达式**: 匿名函数
- **智能指针**: unique_ptr, shared_ptr
- **移动语义**: 右值引用
- **范围 for 循环**

### C++14
- **泛型 lambda**: auto 参数
- **返回类型推导**
- **二进制字面量**: 0b 前缀
- **数字分隔符**: 1'000'000

### C++17
- **结构化绑定**: auto [x, y] = tuple
- **if constexpr**: 编译时条件
- **std::optional**: 可选值
- **std::variant**: 类型安全的联合体
- **文件系统库**: std::filesystem

### C++20
- **Concepts**: 概念约束
- **Ranges**: 范围库
- **Coroutines**: 协程
- **Modules**: 模块系统
- **std::span**: 视图类型

## 🛠️ 环境要求

- GCC 10+ / Clang 11+ / MSVC 19.28+
- CMake 3.16+

## 🚀 快速开始

```bash
# 克隆仓库
git clone https://github.com/MengqiYe/Test_Cpp_Standards.git

# 构建
mkdir build && cd build
cmake ..
make

# 运行测试
./cpp11_tests
./cpp17_tests
./cpp20_tests
```

## 📖 学习资源

- [C++ Reference](https://en.cppreference.com/)
- [Compiler Support](https://en.cppreference.com/w/cpp/compiler_support)

## 👤 作者

MengqiYe

## 📄 许可证

MIT License
