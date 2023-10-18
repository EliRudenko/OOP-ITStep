#pragma once
class Foo
{
	int m_data;
public:

	Foo() = default;
	explicit Foo(const int data);

	void Show();

	int GetData() const;
	void SetData(int d);

};

//Foo operator+(const Foo obj1, const Foo obj2);

