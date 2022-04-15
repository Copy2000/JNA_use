/*
 * @Description: 
 * @Version: 
 * @Autor: copy
 * @Date: 2022-04-10 00:02:59
 * @LastEditors: copy
 * @LastEditTime: 2022-04-10 12:41:33
 */
package com.company;

import com.sun.jna.Library;
import com.sun.jna.Native;


//创建接口继承Library接口：
public interface JnaDLL extends Library {
    JnaDLL jnadll=(JnaDLL) Native.load("com/company/testDLL.dll",JnaDLL.class);
    //声明函数
    int add(int a,int b);
    int test_matrix(double c,double d);
    void test_qpOASES();
}
