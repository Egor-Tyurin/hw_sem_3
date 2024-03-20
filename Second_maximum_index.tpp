template <typename T>
int findSecondMaxIndex(T* array, int size) {
    if (size < 2) {
        return -1; // Недостаточно элементов для поиска второго максимума
    }

    T max1 = array[0];
    T max2 = array[0];
    int index1 = 0;
    int index2 = 0;

    for (int i = 1; i < size; ++i) {
        if (array[i] > max1) {
            max2 = max1;
            index2 = index1;
            max1 = array[i];
            index1 = i;
        } else if (array[i] > max2 && array[i] != max1) {
            max2 = array[i];
            index2 = i;
        }
    }

    return index2;
}