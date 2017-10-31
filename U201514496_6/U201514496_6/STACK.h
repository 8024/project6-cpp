#include<stdio.h>
class STACK {
public:
	STACK(int m);
	STACK(const STACK& s);
	virtual int size() const;
	virtual operator int() const;
	virtual int operator[] (int x) const;
	virtual STACK& operator<<(int e);
	virtual STACK& operator >> (int &e);
	virtual STACK& operator=(const STACK& s);
	virtual void print(FILE *fp) const;
	virtual ~STACK();
public:
	int *const m_iElems;
	const int m_iMax;
	int m_iPos;
	bool m_bError_exist;
};

