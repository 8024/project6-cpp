#include"QUEUE.h"
#include<iostream>
#include<stdio.h>

using namespace std;

QUEUE::QUEUE(int m) :m_sS2(QUEUE::STACK(m)),QUEUE::STACK(m) {
	if ((true == m_bError_exist) || (true == m_sS2.m_bError_exist)) {
		cout << "can not make a new queue" << endl;
		m_bWrong = true;
		return;
	}
	m_bWrong = false;
}
QUEUE::QUEUE(const QUEUE& s):m_sS2(s.m_sS2),QUEUE::STACK(s) {
	if ((true == m_bError_exist) || (true == m_sS2.m_bError_exist)) {
		cout << "can not copy a new queue" << endl;
		m_bWrong = true;
		return;
	}
	m_bWrong = false;


}
QUEUE::~QUEUE(){}
QUEUE::operator int() const {		//	����ʵ�ʸ���
	int pos_queue;
	pos_queue = m_sS2.m_iPos + m_iPos;
	return pos_queue;
}


int QUEUE::full()const {		//�ж϶����Ƿ��Ѿ���
	if ((m_iMax == m_iPos) && (m_sS2.m_iPos)) {
		return true;
	}
	return false;
}
int QUEUE::operator[](int x) const{
	if (x <= (m_sS2.m_iPos - 1)) {		//	Ԫ����s2��
		return m_sS2.m_iElems[m_sS2.m_iPos - x - 1];
	}
	else if ((x >= m_sS2.m_iPos) && (x < (m_iPos + m_sS2.m_iPos))) {		//	Ԫ����s1��
		return m_iElems[x - m_sS2.m_iPos];
	}
}

QUEUE& QUEUE::operator<<(int e) {
	if (true == QUEUE::full()) {
		m_bWrong = true;
		return *this;
	}
	if ((m_iMax == m_iPos) && (0 == m_sS2.m_iPos)) {		//	��s1����s2Ϊ��ʱ����s1�е�Ԫ���㵹��s2��
		m_sS2.m_iPos = m_iPos;
		int cnt_tran = 0;
		for (; cnt_tran < m_iPos; cnt_tran++) {
			m_sS2.m_iElems[cnt_tran] = m_iElems[m_iPos - cnt_tran - 1];
		}
		m_iPos = 0;
	}
	QUEUE::STACK::operator<<(e);
	m_bWrong = false;
	return *this;
}
QUEUE& QUEUE::operator >> (int &e) {
	if (0 == m_sS2.m_iPos) {
		if (0 == m_iPos) {		//	����Ϊ��ʱ�����ش�����Ϣ
			m_bWrong = true;
			return *this;
		}
		else {			//	s2Ϊ�գ���s1��Ϊ��ʱ����s1�е�Ԫ���㵹��s2��
			m_sS2.m_iPos = m_iPos;
			int cnt_tran = 0;
			for (; cnt_tran < m_iPos; cnt_tran++) {
				m_sS2.m_iElems[cnt_tran] = m_iElems[m_iPos - cnt_tran - 1];
			}
			m_iPos = 0;
			m_sS2.operator >> (e);
			m_bWrong = false;
			return *this;
		}
	}
	else {		//	s2��Ϊ�գ�ֱ�ӳ�ջ
		m_sS2.operator >> (e);
		m_bWrong = false;
		return *this;
	}

}
QUEUE& QUEUE::operator=(const QUEUE& s) {
	QUEUE::STACK::operator=(s);
	m_sS2.operator=(s.m_sS2);
	if ((true == m_bError_exist) || (true == m_sS2.m_bError_exist)) {
		cout << "errors" << endl;
		m_bWrong = true;
		return *this;
	}
	m_bWrong = false;
	return *this;
}

void QUEUE::print(FILE *fp)const
{
	const int *p = &m_sS2.m_iPos;
	const int *q = m_sS2.m_iElems;
	for (int cnt_pri = *p - 1; cnt_pri >= 0; cnt_pri--) {
		fprintf(fp, "%d  ", q[cnt_pri]);
	}
	QUEUE::STACK::print(fp);
}
