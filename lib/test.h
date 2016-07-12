#ifndef TEST_H
#define TEST_H

class Test {
public:
	Test(double value = 0);
	~Test();
	double get(double val);

private:
	double value_;
};

#endif