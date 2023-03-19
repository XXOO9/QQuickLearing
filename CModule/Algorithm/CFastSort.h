#ifndef CFASTSORT_H
#define CFASTSORT_H

#include<QDebug>

class CFastSort
{
public:
    CFastSort();

    void fastSort(QVector<int> &src);

    void guluguluSort();

    QVector< int > generate(const int size);
};

#endif // CFASTSORT_H
