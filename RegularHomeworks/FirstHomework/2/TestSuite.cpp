#include "TestSuite.hpp"

TestSuite::TestSuite(std::string name)
{
	this->name = name;
}

void TestSuite::add(const TestCase& other)
{
	this->testCases.push_back(other);
}

std::vector<TestCase> TestSuite::filterPassing() const
{
	vector<TestCase> passing;
	for (size_t i = 0; i < this->testCases.size(); i++)
	{
		if (testCases[i].isPassing()) {
			passing.push_back(testCases[i]);
		}
	}
	return passing;
}

std::vector<TestCase> TestSuite::filterFailing() const
{
	vector<TestCase> failing;
	for (size_t i = 0; i < this->testCases.size(); i++)
	{
		if (!testCases[i].isPassing()) {
			failing.push_back(testCases[i]);
		}
	}
	return failing;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType errorType) const
{
	vector<TestCase> groupedByErrorType;
	for (size_t i = 0; i < this->testCases.size(); i++)
	{
		if (testCases[i].getErrorType()==errorType) {
			groupedByErrorType.push_back(testCases[i]);
		}
	}
	return groupedByErrorType;
}

void TestSuite::removeByErrorType(ErrorType errorType)
{
	for (size_t i = 0; i < this->testCases.size(); i++)
	{
		if (testCases[i].getErrorType() == errorType) {
			this->testCases.erase(testCases.begin()+i);
		}
	}
}

std::string TestSuite::getName() const
{
	return this->name;
}

void TestSuite::setName(const std::string& newName)
{
	this->name = newName;
}
