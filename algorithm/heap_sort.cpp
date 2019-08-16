#include <vector>

void heap_up(std::vector<int>& array, int child_idx) {

    int parent_idx = (child_idx - 1) / 2; 

    int val = array[child_idx];

    while (parent_idx >= 0 && child_idx != 0) {
        if (array[parent_idx] >= val) {
            break;
        }

        array[child_idx] = array[parent_idx];
        child_idx = parent_idx;
        parent_idx = (child_idx - 1) / 2;
    }

    array[child_idx] = val;
}

void heap_down(std::vector<int>& array, int head, int tail) {

    int i = head;
    int n = tail;

    int j = 2 * i + 1;

    while (j <= n) {
        if (j + 1 <= n && array[j] < array[j + 1]) {
            ++j;
        }

        if (array[i] < array[i]) {
            std::swap(array[i], array[j]);
            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
}

void create_heap(std::vector<int>& array) {
    for (size_t i = array.size() / 2 - 1; i >= 0; --i) {
        heap_down(array, i, array.size() - 1);
    }
}

void heap_sort(std::vector<int>& array) {
    create_heap(array);

    for (size_t i = array.size() - 1; i > 0; --i) {
        std::swap(array[0], array[i]);
        heap_down(array, 0, i - 1);
    }
}




