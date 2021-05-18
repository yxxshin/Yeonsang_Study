#include <pybind11/pybind11.h>

namespace py = pybind11;

/* First Steps */
/* Source: https://pybind11.readthedocs.io/en/stable/basics.html */

int add(int i, int j) {
    return i + j;
}

int add_with_default_arguments(int i = 2, int j = 1) {
    return i + j;
}


PYBIND11_MODULE(example1, m) {
    // optional module docstring
    m.doc() = "pybind11 example plugin";    

    // Binding for a simple function
    m.def("add", &add, "A function which adds two numbers", py::arg("a"), py::arg("b"));

    // Can also be notated like this (shorthand notation)
    using namespace pybind11::literals;
    m.def("add2", &add, "i"_a, "j"_a);

    // With Default arguments
    m.def("add3", &add_with_default_arguments, py::arg("i") = 2, py::arg("j") = 3);

    // Shorthand notation
    m.def("add4", &add, "i"_a = 1, "j"_a=3);

    // Exporting Variables
    m.attr("int_value") = 42;
    py::object world = py::cast("World");
    m.attr("string_value") = world;
}



/* Notes */
/*
    You could compile this file by the following code:
    c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) {FILENAME} -o {MODULENAME}$(python3-config --extension-suffix)
    ex) c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) example.cpp -o example$(python3-config --extension-suffix)

    You could check your module by importing it from python3
    ex) import example / example.add(1,2)

    You could see the module explaination (`m.doc() part`) and keyword names by the following code:
    help(example)
*/