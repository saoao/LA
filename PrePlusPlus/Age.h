#pragma once
#include <QDebug>

class Age
{
public:
	Age():m_data(0)
	{

	}

	//Ç°ÖÃ++
	Age& operator++()
	{
		++m_data;
		return *this;
	}

	//ºóÖÃ++
	const Age operator++(int)
	{
		Age tmp = *this;
		++(*this);
		return tmp;
	}

	//¸³Öµ
	Age& operator=(int data)
	{
		this->m_data = data;
		return *this;
	}

	friend QDebug operator<<(QDebug de, const Age& age)
	{
		de << age.m_data;
		return de;
	}

private:
	int m_data;
};