// median.cpp
#include <algorithm>
#include <stdexcept>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using std::vector;
using std::domain_error;
using std::sort;

// vector<double>�� �߾Ӱ��� ����.
// �Լ��� ȣ���ϸ� �μ��� ������ ���͸� ��°�� ����
double median(vector<double> vec) {
    // ���� ������ �Է� ������ Ȯ��
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("Median of empty vector");
    }

    // ������ ����
    sort(vec.begin(), vec.end());

    // ���� ������ �߾Ӱ��� ����
    vec_sz mid = size / 2;
    return size % 2 == 0
        ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}
