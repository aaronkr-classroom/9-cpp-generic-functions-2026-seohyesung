// my_algo_T.h
#pragma once

#ifdef GUARD_my_algo_T_h
#define GUARD_my_algo_T_h

#include <cctype>
#include <algorithm>
#include (string)

// 최대값
template <class T>
T max(const T& left, const T& right)
{
	return left > right ? left : right;
}

// 최소값
template <class T>
T min(const T& left, const T& right)
{
	return left < right ? left : right;
}

// 같은 값
template <class T>
bool equal(const T& left, const T& right)
{
	return left == right ? true : false;
}

// 같지 않은 0값
template <class T>
bool not_equal(const T& left, const T& right)
{
	return !equal(left, right);
}

// 알 수 없는 자료형의 벡터에 있는 요소(값)을 찾기
template <class In, class X>
In find(In begin, In end, const X& x)
{
	// 끝까지 안가서 값도 찾지 못해서
	while (begin != end && *begin != x)
	{
		
	}
	return end;
}

// 사본 만들기
template <class In, class Out>
Out copy(In begin, In end, Out result)
{ // 첫요소부터 끝까지 모든 
//begin 반복자의 있는 요소를 
//dest 반복자로 복사하기
	while (begin != end)
	{
		*dest++ = *begin++;
	}
	return dest;
}

// 덮어쓰기
template <class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{	while (beg != end)
	{
		if (*beg == x) {
		*beg = y;
		}
		++beg;
	}
}

// 역방향으로 재저장하기
template <class Bi>
void reverse(Bi begin, Bi end)
{
	while (begin != end)
	{
		--end;
		if (begin != end) {
			swap(*begin++, *end);
		}
	}
}

// 이진법 탐색
template <class Oct, class X>
Oct binary_search(Oct begin, Oct end, const X& x)
{
	while (begin < end)
	{
		// 범위의 중간지점 찾기
		Oct mid = begin + (end - begin) / 2;

		// 중간지점을 기준으로 어느 부분이 x를
		// 포함하는지 확인하기 해당 부분에만
		// 탐색을 계속  진행
		if (x < *mid) {
			end = mid;
		}
		else if (*mid > x) begin = mid + 1;
		else return true; // 찾음
	}
	return false; // 못찾음
}

// 인수가 공백일 때는 true, 그렇지 않을때는 false
bool space(char c)
{
	return isspace(c); // #include <cctype> 필요
}

// 인수가 공백일 때는 false, 그렇지 않을 때는 true
bool not_space(char c)
{
	return !isspace(c); // #include <cctype> 필요
}

// 문자열 나누기
template <class Out>
void split(const string& str, Out os)
{
	typedef string::const_iterator iter;

	iter i = str.begin();

	while (i != str.end())
	{
		// 공백이 아닌 부분의 시작점 찾기
		i = find_if(i, str.end(), not_space);
		// 공백이 아닌 부분의 끝점 찾기
		iter j = find_if(i, str.end(), space);
		// [first, last) 범위의 문자열을 result에 추가
		if (i != str.end()) {
			*os++ = string(i, j);
		}
		i = j;
	}
}

#endif
