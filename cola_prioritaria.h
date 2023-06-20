//
// Created by rrivas on 20/06/2023.
//

#ifndef PROG3_TEO3_20231_ESTRUCTURAS_BASICAS_HEAP_COLA_PRIORITARIA_H
#define PROG3_TEO3_20231_ESTRUCTURAS_BASICAS_HEAP_COLA_PRIORITARIA_H

#include <vector>
#include <functional>
using namespace std;

namespace utec {
    using index_t = size_t;
    template <typename T, typename Container=vector<T>, typename Compare=less<T>>
    class priority_queue {
        Container cnt;
        index_t get_left(index_t parent_index) { return parent_index * 2; }
        index_t get_right(index_t parent_index) { return parent_index * 2 + 1; }
        index_t get_parent(index_t child_index) { return child_index / 2; }
        bool is_root(index_t index) { return index == 1; }
        bool has_children(index_t parent_index) {
            return get_left(parent_index) <= size(cnt);
        }
        bool has_right_child(index_t parent_index) {
            return get_right(parent_index) <= size(cnt);
        }

        void percolate_up(index_t index) {
            // Condiciones bases
            if (is_root(index)) return;
            auto parent_index = get_parent(index);
            if (cnt[index] > cnt[parent_index]) return;
            // Condiciones recursivas
            swap(cnt[index], cnt[parent_index]);
            percolate_up(parent_index);
        }
    };
}

#endif //PROG3_TEO3_20231_ESTRUCTURAS_BASICAS_HEAP_COLA_PRIORITARIA_H
