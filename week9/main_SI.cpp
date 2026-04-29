// main_SI.cpp
#include <algorithm>
#include <iomanip>
#include <ios>

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "student_info.h"
#include "median_T.h"

using namespace std;

int main(void)
{
	vector<student_info> students;
	student_info record;
	string::size_type maxlen = 0;
	while (record.read(cin))
	{
		maxlen = max(maxlen, record.getName().size());
		students.push_back(record);
	}

	//학생 기록 정렬하기
	sort(students.begin(), students.end(), compare);

	// 이름과 점수를 쓰기
	for (vector<student_info>::size_type i = 0;
		i != students.size(); ++i)
	{
		cout << students[i].getName() 
			<< string(maxlen + 1 
				- students[i].getName().size(), ' ');
		try {
			double final_grade = students[i].grade();

			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade 
				<< setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
		
	}
	return 0;
}

// 필요한파일:
// student_info.cpp
// median.h
// median.cpp
// grade.cpp
// grade.h
