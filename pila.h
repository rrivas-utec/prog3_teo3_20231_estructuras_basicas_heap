//
// Created by rrivas on 20/06/2023.
//

#ifndef PROG3_TEO3_20231_ESTRUCTURAS_BASICAS_HEAP_PILA_H
#define PROG3_TEO3_20231_ESTRUCTURAS_BASICAS_HEAP_PILA_H

#include <deque>

namespace utec {
    template <typename T, typename Container = std::deque<T>>
    class stack {
        Container cnt;
    public:
        using const_ref = const T&;
        stack() = default;
        explicit stack(const Container& other): cnt(other) {}
        // evitar utilizar la asignacion
        // stack s1;
        // stack s2 = s1; <-- Evita esto
        size_t size() { return cnt.size(); }
        bool empty() { return size(cnt) == 0; }
        void push(T value) { cnt.push_back(value); }
        template <typename ...Param>
        void emplace(Param ...param) { cnt.emplace_back(param...); }
        void pop() { cnt.pop_back(); }
        const_ref top() { return cnt.back(); }
        // En caso de queue se reemplaza el top() por front() y back()
    };

}

#endif //PROG3_TEO3_20231_ESTRUCTURAS_BASICAS_HEAP_PILA_H
