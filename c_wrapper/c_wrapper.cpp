// c_wrapper.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "c_wrapper.h"
#include "Myclass.h"

MyClass::MyClass(int nb)
    : m_nb(nb)
{
}

int MyClass::getValue() const
{
    return m_nb;
}

void MyClass::increment()
{
    m_nb++;
}

