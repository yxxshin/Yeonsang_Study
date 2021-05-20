#include <pybind11/pybind11.h>

namespace py = pybind11;

/* Object-oriented code */
/* Source: https://pybind11.readthedocs.io/en/stable/classes.html */

struct Pet {
    Pet(const std::string &name) : name(name) { }
    void setName(const std::string &name_) { name = name_; }
    const std::string &getName() const {
        return name;
    }

    std::string name;
};

struct Dog : Pet {
    Dog(const std::string &name) : Pet(name) { }
    std::string bark() const { 
        return "woof!";
    }
};

struct PolymorphicPet {
    virtual~PolymorphicPet() = default;
};

struct PolymorphicDog : PolymorphicPet {
    std::string bark() const {
        return "woof!";
    }
};


PYBIND11_MODULE(example2_2, m) {
    /* Dynamic Attributes */

    // If you want to enable dynamic attributes, use `dynamic_attr()`
    // ex) now you can do `p.age = 1` even though you didn't define the age attribute
    // `p.name = 'new_name'` is OK (C++ overwriting), but p.name != p.getName()
    py::class_<Pet>(m, "Pet", py::dynamic_attr())
        .def(py::init<const std::string &>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName);

    // You can use `p.__dict__` at Python, just like a native Python class

    /* Inheritance */
    // You could also pass parent class_ object: see Source
    py::class_<Dog, Pet /* <- specify C++ parent type */>(m, "Dog")
        .def(py::init<const std::string &>())
        .def("bark", &Dog::bark);


    /* Automatic Downcasting (Polymorphism) */
    // In C++, a type is only considered polymorphic if it has at least one virtual function,
    // and pybind11 will automatically recognize this:

    py::class_<PolymorphicPet>(m, "PolymorphicPet");
    py::class_<PolymorphicDog, PolymorphicPet>(m, "PolymorphicDog")
        .def(py::init<>())
        .def("bark", &PolymorphicDog::bark);
    
    m.def("pet_store", []() {
        return std::unique_ptr<PolymorphicPet>(new PolymorphicDog);
    });
    // `p = example2_2.pet_store()`
    // `p.bark()` works, and `type(p)` == PolymorphicDog

};