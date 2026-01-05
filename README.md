# CPP Module 04 - Subtype Polymorphism, Abstract Classes and Interfaces

**42 School Project** | C++98 | Object-Oriented Programming

---

## 🎯 Overview

Implementation of polymorphic systems in C++98, progressing from basic virtual functions to complete interface-based architecture. Focused on runtime polymorphism, abstract class design, and memory-safe deep copy with dynamic allocation.

**Tech Stack**: C++98 | Virtual Functions | Pure Virtual | Orthodox Canonical Form | Zero Memory Leaks

---

## 📐 Class Hierarchy

### Exercise 03 - Complete System Architecture

```
Interfaces (Pure Abstract)          Concrete Implementations
─────────────────────────           ────────────────────────

   IMateriaSource                        MateriaSource
        │                                      │
        │ learnMateria()                      │ stores AMateria*[4]
        │ createMateria()                     │ clone() pattern
        └──────────────────────────────────────┘


   ICharacter                            Character
        │                                      │
        │ equip()                             │ inventory: AMateria*[4]
        │ unequip()                           │ deep copy w/ clone()
        │ use()                               │ manual cleanup on unequip
        └──────────────────────────────────────┘


   AMateria (Abstract)
        │
        ├─── Ice                         clone() → new Ice(*this)
        │                                use() → "shoots ice bolt"
        │
        └─── Cure                        clone() → new Cure(*this)
                                         use() → "heals wounds"
```

---

## 📋 Exercises Summary

| Exercise | Focus | Key Components | Challenge |
|----------|-------|----------------|-----------|
| **ex00** | Basic Polymorphism | `Animal`, `Dog`, `Cat` with virtual methods | Virtual destructor necessity |
| **ex01** | Deep Copy + Dynamic Memory | `Brain*` in derived classes | Deep copy via `clone()` pattern |
| **ex02** | Abstract Classes | `Animal` as pure abstract base | Pure virtual `makeSound() = 0` |
| **ex03** | Interface Design | `IMateriaSource`, `ICharacter` | Dangling pointer management in `unequip()` |

---

## 🔧 Technical Implementation

### Virtual Destructor Chain
Every polymorphic base class implements virtual destructor to ensure proper cleanup when deleting through base pointers.

```cpp
class Animal {
    virtual ~Animal();  // Ensures ~Dog() → ~Animal() chain
};
```

### Deep Copy Strategy
All classes with dynamic members implement deep copy using the prototype pattern:

```cpp
AMateria* Ice::clone() const { return new Ice(*this); }
```

Character's copy constructor uses `clone()` to duplicate entire inventory independently.

### Unequip Pattern (ex03)
Critical design decision: `unequip()` removes from inventory **without deletion**, preventing double-free. Caller must manage cleanup:

```cpp
AMateria* temp = character->getMateria(idx);
character->unequip(idx);  // Removes pointer, doesn't delete
delete temp;              // Manual cleanup
```

This pattern prevents accidental deletion of materias that might be stored elsewhere.

---

## ⚙️ Compilation & Testing

### Build
```bash
make                    # Compile
make clean             # Remove objects
make fclean            # Remove objects + executable
make re                # Rebuild
```

**Flags**: `-Wall -Wextra -Werror -std=c++98`

### Memory Validation
```bash
valgrind --leak-check=full ./program
```

**Result**: 0 bytes in use at exit | 0 errors | All heap blocks freed

---

## 📊 Results

- ✅ **53 allocations, 53 frees** (ex03 comprehensive test)
- ✅ **Zero memory leaks** across all exercises
- ✅ **Proper polymorphic behavior** verified through base class pointers
- ✅ **Deep copy validated** - independent object lifetimes
- ✅ **Abstract enforcement** - compilation fails on invalid instantiation

---

## 🎓 Key Learnings

**Polymorphism Mechanics**
- Dynamic dispatch via vtable
- Virtual vs pure virtual distinction
- Static binding pitfalls (WrongAnimal demonstration)

**Memory Safety**
- Virtual destructors in base classes
- Deep copy with `clone()` pattern
- Ownership transfer on `unequip()`

**Interface Design**
- Pure abstract interfaces (`ICharacter`, `IMateriaSource`)
- Separation of interface and implementation
- Forward declaration to break circular dependencies

---

## 📁 Project Structure

```
cpp04/
├── ex00/          # Polymorphism basics
├── ex01/          # Deep copy with Brain*
├── ex02/          # Abstract Animal class
└── ex03/          # Complete interface system
    ├── AMateria.{hpp,cpp}
    ├── Ice.{hpp,cpp}
    ├── Cure.{hpp,cpp}
    ├── ICharacter.hpp
    ├── Character.{hpp,cpp}
    ├── IMateriaSource.hpp
    ├── MateriaSource.{hpp,cpp}
    └── main.cpp
```

---

**Standard**: C++98 | **Year**: 2026