// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 CWRAPPER_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// CWRAPPER_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef _WIN64
#   define DLL_EXPORT __declspec(dllexport)
#else
#   define DLL_EXPORT
#endif
#include "Myclass.h"
// 此类是从 dll 导出的
extern "C" DLL_EXPORT MyClass *MyClass_ctor(int nb);
MyClass* MyClass_ctor(int nb)
{
    return new MyClass(nb);
}

extern "C" DLL_EXPORT int MyClass_getValue(const MyClass * self)
{
    return self->getValue();
}

extern "C" DLL_EXPORT void MyClass_increment(MyClass * self)
{
    self->increment();
}

