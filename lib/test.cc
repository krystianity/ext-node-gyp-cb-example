#include "test.h"

Test::Test(double value) : value_(value) {}

Test::~Test() {}

double Test::get(double val) {
	return (double)val * this->value_;
}