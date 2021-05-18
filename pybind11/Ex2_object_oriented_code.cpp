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

PYBIND11_MODULE(example2, m) {
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName);
}