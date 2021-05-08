#include <iostream>

using namespace std;

class MathException
{
protected:
	char m_operationName[20];
	int m_value1;
	int m_value2;

public:
	MathException(const char* operationName, const int value1, const int value2) : m_value1(value1), m_value2(value2)
	{
		strcpy_s(m_operationName, operationName);
	}
	virtual void message() const = 0;
};

class OverflowException : public MathException
{
public:
	OverflowException(const char* operationName, const int value1, const int value2)
		: MathException(operationName, value1, value2)
	{

	}
	void message() const override;
};

void OverflowException::message() const
{
	cerr << "Overflow exception: " << m_operationName << "(" << m_value1 << ", " << m_value2 << ")" << endl;
}

class UnderflowException : public MathException
{
public:
	UnderflowException(const char* operationName, const int value1, const int value2)
		: MathException(operationName, value1, value2)
	{

	}
	void message() const override;
};

void UnderflowException::message() const
{
	cerr << "Underflow exception: " << m_operationName << "(" << m_value1 << ", " << m_value2 << ")" << endl;
}

class ZeroDivideException : public MathException
{
public:
	ZeroDivideException(const char* operationName, const int value1, const int value2)
		: MathException(operationName, value1, value2)
	{

	}
	void message() const override;
};

void ZeroDivideException::message() const
{
	cerr << "Zero divide exception: " << m_operationName << "(" << m_value1 << ", " << m_value2 << ")" << endl;
}

class Math
{
public:
	static int add(int, int);
	static int sub(int, int);
	static int mul(int, int);
	static int div(int, int);
	static int mod(int, int);
};

int Math::add(int a, int b)
{
	if (a > 0 && b > 0 && a > INT_MAX - b)
		throw OverflowException("add", a, b);
	if (a < 0 && b < 0 && a < INT_MIN - b)
		throw UnderflowException("add", a, b);
	return a + b;
}

int Math::sub(int a, int b)
{
	if (a >= 0 && b < 0 && a > INT_MAX + b)
		throw OverflowException("sub", a, b);
	if (a < 0 && b > 0 && a < INT_MIN + b)
		throw UnderflowException("sub", a, b);
	return a - b;
}

int Math::mul(int a, int b)
{
	if (a < 0 && b < 0 && a < INT_MAX / b || a > 0 && b > 0 && a > INT_MAX / b)
		throw OverflowException("mul", a, b);
	if (a < 0 && b > 0 && a < INT_MIN / b || a > 0 && b < 0 && a > INT_MIN / b)
		throw UnderflowException("mul", a, b);
	return a * b;
}

int Math::div(int a, int b)
{
	if (b == 0)
		throw ZeroDivideException("div", a, b);
	return a / b;
}

int Math::mod(int a, int b)
{
	if (b == 0)
		throw ZeroDivideException("mod", a, b);
	return a % b;
}

int main()
{
	try
	{
		Math::add(INT_MIN, -1);
	}
	catch (MathException& exception)
	{
		exception.message();
	}
	try
	{
		Math::sub(1, INT_MIN);
	}
	catch (MathException& exception)
	{
		exception.message();
	}
	try
	{
		Math::mul(2, INT_MIN);
	}
	catch (MathException& exception)
	{
		exception.message();
	}
	try
	{
		Math::div(123, 0);
	}
	catch (MathException& exception)
	{
		exception.message();
	}
	try
	{
		Math::mod(123, 0);
	}
	catch (MathException& exception)
	{
		exception.message();
	}

	system("pause");
	return 0;
}