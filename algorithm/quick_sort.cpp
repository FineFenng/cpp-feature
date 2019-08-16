#include <vector>

int lomuto_partition(std::vector<int>& array, int head, int tail) 
{
    const int pivot_val = array[head]; 
    int insert_idx = head;

    for (int i = head + 1; i <= tail; ++i) {
        if (array[i] < pivot_val) {
            std::swap(array[i], array[++insert_idx]);
        }
    }

    std::swap(array[head], array[insert_idx]);
    return insert_idx;
}

void quick_sort(std::vector<int>& array, int head, int tail) {
    if (array.size() == 0) {
        return;
    }

    const int sorted_idx = lomuto_partition(array, head, tail);

    quick_sort(array, head, sorted_idx - 1);
    quick_sort(array, sorted_idx + 1, tail);
}


