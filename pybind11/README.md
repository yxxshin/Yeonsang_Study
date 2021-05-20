# Learning Pybind11
### (feat. Creating Palisade-Python)

- First, make a `build` file and do `cmake`
  - `cmake ..`

- You could compile this file by the following code:
  - `c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) {FILENAME} -o {MODULENAME}$(python3-config --extension-suffix)`
  
  - ex: `c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) myfile.cpp -o mymodule$(python3-config --extension-suffix)`

- Then, you could test your python module by importing from python3
  - `import mymodule`

- When you want to erase errors from the IDE (ex. VSCode): build it!
  - Don't forget to add `pybind11_add_module({MODULENAME} {FILENAME})` at `CmakeLists.txt`

---
- Environment: Ubuntu 20.04
- Prerequisites: `python3-dev`, `cmake`, `pybind11`
