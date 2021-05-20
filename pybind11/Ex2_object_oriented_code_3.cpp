#include <pybind11/pybind11.h>

namespace py = pybind11;

/* Object-oriented code */
/* Source: https://pybind11.readthedocs.io/en/stable/classes.html */

struct Pet {
    Pet(const std::string &name, int age) : name(name), age(age) { }

    void set(int age_) { age = age_; }
    void set(const std::string &name_) { name = name_; }

    std::string name;
    int age;
};

struct Widget {
    int foo(int x, float y);
    int foo(int x, float y) const;
};


struct Pet2 {
    // contains an internal enumeration type
    enum Kind {
        Dog = 0,
        Cat
    };
    Pet2(const std::string &name, Kind type) : name(name), type(type) { }

    std::string name;
    Kind type;
};


PYBIND11_MODULE(example2_3, m) {
    /* Overloaded Methods */

    // When there are several overloaded C++ methods with the same name taking different kinds of input arguments:
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &, int>())
        
        .def("set", static_cast<void (Pet::*)(int)>(&Pet::set), "Set the pet's age")
        .def("set", static_cast<void (Pet::*)(const std::string &)>(&Pet::set), "Set the pet's name");
        
    /*
        // Over C++14
        .def("set", py::overload_cast<int>(&Pet::set), "Set the pet's age")
        .def("Set", py::overload_cast<const std::string &>(&Pet::set), "Set the pet's name");
    
    // If the function is overloaded based on constness:
    py::class_<Widget>(m, "Widget")
        .def("foo_mutable", py::overload_cast<int, float>(&Widget::foo))
        .def("foo_const", py::overload_cast<int, float>(&Widget::foo, py::const_));
    */


    /* Enumerations and internal types */
    py::class_<Pet2> pet(m, "Pet2");
    pet.def(py::init<const std::string &, Pet2::Kind>())
        .def_readwrite("name", &Pet2::name)
        .def_readwrite("type", &Pet2::type);
    
    py::enum_<Pet2::Kind>(pet, "Kind")
        .value("Dog", Pet2::Kind::Dog)
        .value("Cat", Pet2::Kind::Cat)
        .export_values();
};