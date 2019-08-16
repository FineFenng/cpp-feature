#include <vector>

void merge(std::vector<int>& array, int head, int mid, int tail, std::vector<int>& tmp) {
    int i = head;
    int j = mid;

    int m = mid + 1;
    int n = tail;

    int k = i;

    while (i <= j && m <= n) {
        if (array[i] < array[m]) {
            tmp[k++] = array[i++];
        } else {
            tmp[k++] = array[m++];
        }
    }

    while (i <= j) {
        tmp[k++] == array[i++];
    }
   
    while (m <= n) {
        tmp[k++] == array[m++];
    }

    while (head <= tail) {
        array[head++] = tmp[head++];
    }
}

void _merge_sort(std::vector<int>& array, int head, int tail, std::vector<int>& tmp) {

    int mid = (tail - head) / 2 + head;
    _merge_sort(array, head, mid, tmp);
    _merge_sort(array, mid + 1, tail, tmp);
    merge(array, head, mid, tail, tmp);
}

void merge_sort(std::vector<int>& array) {
    if (array.size() == 0) {
        return;
    }

    std::vector<int> tmp;
    tmp.resize(array.size());
    int head = 0;
    int tail = array.size() - 1;
    _merge_sort(array, head, tail, tmp);
}





