#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct lesson {
    int start;
    int end;
};

void swap(int& lha, int& rha) {
    int tmp = lha;
    lha = rha;
    rha = tmp;
}


































/*
int pr(lesson array[], int lb, int rb) {
    int pivot = array[rb].start;
    int tr = lb;
    for (int i = lb; i < rb; i++) {
        if (array[i].start <= pivot) {
            swap(array[i].start, array[tr].start);
            swap(array[i].end, array[tr].end);
            tr++;
        }
    }

    swap(array[tr].start, array[rb].start);
    swap(array[tr].end, array[rb].end);
    return tr;
}

void qsort(lesson array[], int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = pr(array, start, end);
    qsort(array, start, pivot - 1);
    qsort(array, pivot + 1, end);
}

int pr2(lesson array[], int lb, int rb) {
    int pivot = array[rb].end;
    int tr = lb;
    for (int i = lb; i < rb; i++)
    {
        if (array[i].end <= pivot)
        {
            swap(array[i].start, array[tr].start);
            swap(array[i].end, array[tr].end);
            tr++;
        }
    }

    swap(array[tr].start, array[rb].start);
    swap(array[tr].end, array[rb].end);
    return tr;
}

void qsort2(lesson array[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = pr2(array, start, end);
    qsort2(array, start, pivot - 1);
    qsort2(array, pivot + 1, end);
}

int main()
{
    int num = 0;
    cin >> num;
    lesson d[num];
    for (int i = 0; i < num; i++) {
        cin >> d[i].start >> d[i].end;
    }

    qsort2(d, 0, num - 1);
    qsort(d, 0, num - 1);

    int hm = 0, currents = 0, currente = 0;
    for (int i = 0; i < num; i++)
    {
        if (d[i].start != currents and currente <= d[i].start)
        {
            currents = d[i].start;
            currente = d[i].end;
            hm++;
        }
    }
    cout << hm << endl;
    return 0;
}
*/