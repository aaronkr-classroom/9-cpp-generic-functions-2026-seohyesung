// Student_info.h
#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student_info {
public: // ������ �� �ִ� �Լ�
    // ## ������ ���� ############
    Student_info(); // �� Student_info ��ü�� ����
    Student_info(istream&); // ��Ʈ���� �о� Student_info ��ü�� ����
    // read_hw()�Լ��� ����� 

    // ## ��� �Լ� ���� #########
    string getName() const { return name; }
    void setName(string n) { name = n; } // �� ������ ����

    bool valid() const { return !homework.empty(); }

    // 9.2.1/254p���� ������ read �Լ�
    istream& read(istream&);

    // 9.2.1/254p���� ������ �Ͱ� ����
    double grade() const;

private: // ����� ���� ����
    string name;
    double midterm, final;
    vector<double> homework;
}; // �����ݷ��� ���� �ʵ��� ����

bool compare(const Student_info&, const Student_info&);

#endif
