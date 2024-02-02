#pragma once

class Counter {

private:
	
public:
	int initial;
	unsigned int step;
	Counter();
	Counter(int initial);
	Counter(int initial, unsigned int step);
	void increment();
	int getTotal() const;
	unsigned int getStep() const;
};
