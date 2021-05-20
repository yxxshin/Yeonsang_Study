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

class Pet2 {
    // has a private std::string name
    public:
        Pet2(const std::string &name) : name(name) { }
        void setName(const std::string &name_) { name = name_; }
        const std::string &getName() const {
            return name;
        }

    private:
        std::string name;
};

PYBIND11_MODULE(example2_1, m) {
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())   // Constructor
        .def("setName", &Pet::setName)          // Setter
        .def("getName", &Pet::getName)          // Getter
        
        // Lambda function for a human-readable `print(p)`
        .def("__repr__",
            [](const Pet &a) {
                return "<example2.Pet named '" + a.name + "'>";
            }
        )
        // By `def_readwrite`, you could expose a field.
        // In other words(in this example), you could get/set values directly by objects, such as `p.name = "new_name"`
        // You could use `def_readonly` for const fields.
        .def_readwrite("name", &Pet::name);

    py::class_<Pet2>(m, "Pet2")
        .def(py::init<const std::string &>())

        // By `def_property`, you could expose a private field.
        // You could use `def_property_readonly` for read-only data.
        .def_property("name", &Pet2::getName, &Pet2::setName);
}