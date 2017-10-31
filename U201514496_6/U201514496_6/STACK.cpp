#include"STACK.h"
#include<iostream>

using namespace std;

STACK::STACK(int m) :m_iElems(new int[m]), m_iMax(m), m_iPos(0) {		//初始化构造函数
	if (m_iElems == nullptr) {
		cout << "NO enough memory for a new stack" << endl;
		m_bError_exist = true;
		return;
	}
	m_bError_exist = false;
}

STACK::STACK(const STACK& s) :m_iElems(new int[s.m_iMax]), m_iMax(s.m_iMax), m_iPos(s.m_iPos) {			//拷贝构造函数
	if (m_iElems == nullptr) {
		cout << "NO enough memory for a new stack" << endl;
		m_bError_exist = true;
		return;
	}
	int num_tran = 0;
	for (; num_tran < s.m_iPos; num_tran++) {
		m_iElems[num_tran] = s.m_iElems[num_tran];
	}
	m_bError_exist = false;
}

int STACK::size() const {			//	返回最大元素个数值
	return m_iMax;
}

STACK::operator int()const {			//	返回目前的元素个数
	return m_iPos;
}

int STACK::operator[](int x) const {
	int get_elem;
	get_elem = m_iElems[x];
	return get_elem;
}

STACK& STACK::operator<<(int e) {			//将元素e入栈
	m_iElems[m_iPos] = e;
	m_iPos++;
	return *this;
}

STACK& STACK::operator >> (int &e) {			//将元素e出栈
	e = m_iElems[m_iPos];
	m_iPos--;
	return *this;
}

STACK& STACK::operator=(const STACK& s) {
	delete[] m_iElems;
	int**p_m_iElems = (int**)&m_iElems;
	int* p_m_iMax = (int*)&m_iMax;
	*p_m_iElems = new int[s.m_iMax];
	if (*p_m_iElems == nullptr) {
		m_bError_exist = true;
		return *this;
	}
	*p_m_iMax = s.m_iMax;
	m_iPos = s.m_iPos;
	m_bError_exist = false;
	int cnt_assi = 0;
	for (; cnt_assi < m_iPos; cnt_assi++) {
		(*p_m_iElems)[cnt_assi] = s.m_iElems[cnt_assi];
	}
	return *this;
}

void STACK::print(FILE *fp)const
{
	const int *p = &m_iPos;
	const int *q = m_iElems;
	for (int cnt_pri = 0; cnt_pri < *p; cnt_pri++) {
		fprintf(fp, "%d  ", q[cnt_pri]);
	}
}

STACK::~STACK() {
	if (m_iElems != nullptr) {
		delete[]m_iElems;
	}
	m_iPos = 0;
	m_bError_exist = false;
}
