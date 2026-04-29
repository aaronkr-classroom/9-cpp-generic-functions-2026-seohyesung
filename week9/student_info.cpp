// Student_info.cpp
#include <iostream>

#include "grade.h"
#include "Student_info.h"

using namespace std;

// �� ������ 
Student_info::Student_info() : midterm(0), final(0) {}

// cin�� �о� Student_info�� �ʱ�ȭ
Student_info::Student_info(istream& is) { read(is); }

bool compare(const Student_info& x, const Student_info& y) {
    return x.getName() < y.getName(); // T / F (A-Z)
}

double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}

// �Է� ��Ʈ������ ���� ������ �о vector<double>�� ����.
istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // ���� ������ ����
        hw.clear();

        // �Է��� ���� ����
        double x; // cin���� ����ϱ� 

        // �Һ���: ���ݱ��� count�� ������ �Է¹޾�����
        // �Է¹��� ������ ���� sum
        while (in >> x) {
            hw.push_back(x);
        }

        // ���� �л��� ���� �Է� �۾��� ������ ��Ʈ���� ����
        in.clear();
    }
    return in;
}

istream& Student_info::read(istream& in) {
    // �л��� �̸�, �߰����� ����, �⸻���� ���� �о� ����
    in >> name >> midterm >> final;
    // ���� ������ ����
    read_hw(in, homework);
    return in;
}
