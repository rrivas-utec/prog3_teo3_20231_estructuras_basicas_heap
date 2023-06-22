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
            return get_left(parent_index) <= cnt.size();
        }
        bool has_right_child(index_t parent_index) {
            return get_right(parent_index) <= cnt.size();
        }
        index_t get_selected_index(index_t parent_index) {
            auto left_index = get_left(parent_index);
            if (has_right_child(parent_index)) {
                auto right_index = get_right(parent_index);
                return cnt[left_index] > cnt[right_index]?
                    left_index: right_index;
            }
            return left_index;
        }

        void percolate_up(index_t index) {
            // Condiciones bases
            if (is_root(index)) return;
            auto parent_index = get_parent(index);
            if (cnt[index] < cnt[parent_index]) return;
            // Condiciones recursivas
            swap(cnt[index], cnt[parent_index]);
            percolate_up(parent_index);
        }

        void percolate_down(index_t index) {
            // Condiciones bases
            if (!has_children(index)) return;
            auto index_child = get_selected_index(index);
            if (cnt[index_child] < cnt[index]) return;
            // Condiciones recursivas
            swap(cnt[index], cnt[index_child]);
            percolate_down(index_child);
        }

        void heapify(index_t index) {
            auto index_parent = get_parent(index);
            while (index_parent >= 1) {
                percolate_down(index_parent);
                --index_parent;
            }
        }


    public:
        priority_queue(): cnt(1) {}
        explicit priority_queue(const Container& input): cnt(1+input.size()) {
            copy(begin(input), end(input), next(begin(cnt))); // O(n)
            heapify(cnt.size()); // O(n)
        }
        void push(T value) {
            cnt.push_back(value);
            percolate_up(cnt.size());
        }
        template<typename ...Params>
        void emplace(Params ... params) {
            cnt.emplace_back(params...);
            percolate_up(cnt.size());
        }
        void pop() {
            swap (cnt[1], cnt[cnt.size()]);
            cnt.pop_back();
            percolate_down(1);
        }
        T top() { return cnt[1]; }
        size_t size() { return cnt.size() - 1; }
        bool empty() { return size() == 0; }
    };
}

#endif //PROG3_TEO3_20231_ESTRUCTURAS_BASICAS_HEAP_COLA_PRIORITARIA_H
