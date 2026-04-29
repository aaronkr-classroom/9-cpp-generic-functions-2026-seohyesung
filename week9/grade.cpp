// grade.cpp
#include <algorithm>
#include <list>
#include <vector>
#include <stdexcept>

#include "grade.h"
#include "median.h"
#include "Student_info.h"

// �л��� ���� ���θ� �����ϴ� ���� �Լ�
bool fgrade(const Student_info& s) {
    return grade(s) < 60;
}

bool pgrade(const Student_info& s) {
    return !fgrade(s);
}

// �߰����� ����, �⸻���� ����, ���� ���� ��������
// �л��� ���� ������ ����
double grade(double mt, double ft, double hw) {
    return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}

// �߰����� ����, �⸻���� ����, ���� ������ ���ͷ�
// �л��� ���� ������ ����.
// �� �Լ��� �μ��� �����ϱ� �ʰ� median �Լ��� �ش� �۾��� ����.
double grade(double mt, double ft, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("No homework!");

    return grade(mt, ft, median(hw));
}

// �� ��° ����:
// �ε��� ��� �ݺ��ڸ� ��������� ������
// ���� ���ϰ� �����
list<Student_info> extract_fails(list<Student_info>& students) {
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter); // ������ = �ݺ����� ��
            iter = students.erase(iter); // �ݺ����� �޸� ��ġ ����
        }
        else {
            ++iter;
        }
    }
    return fail;
}
