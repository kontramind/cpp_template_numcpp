# cpp_template_numcpp
Starter project template using NumCpp

1. Inspired by:
    https://github.com/lefticus/cpp_starter_project
2. Use (to fetch NumCpp): 
    git submodule update --init -recursive
3. edit conan profile to start using clang
    [settings]
    ...
    compiler=clang
    compiler.version=9.0.1
    compiler.libcxx=libstdc++11
    ...
    [env]
    ...
    CC=/usr/bin/clang
    CXX=/usr/bin/clang++
    ...


