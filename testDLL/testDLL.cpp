// testDLL.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "testDLL.h"
#include <iostream>
#include <stdio.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "qpOASES.hpp"
#include <unsupported/Eigen/KroneckerProduct>

using namespace std;
using namespace Eigen;
// 这是导出变量的一个示例
TESTDLL_API int ntestDLL=0;

// 这是导出函数的一个示例。
TESTDLL_API int fntestDLL(void)
{
    return 0;
}

// 这是已导出类的构造函数。
CtestDLL::CtestDLL()
{
    return;
}

TESTDLL_API int add(int a, int b)
{
    int value = a + b;
    cout << "DLL add copy = " <<value<< endl;
    cout <<u8"DLL add 赵超 = " << value << endl;
    printf("%d", value);
    return  value;
}
TESTDLL_API int test_matrix(double a, double b)
{
    MatrixXd m(1,2);
    m(0, 0) = a;
    m(0, 1) = b;
    cout << m(0, 0) << m(0, 1) << endl;
    cout <<u8"矩阵可以使用" << endl;
    return 1;
}

TESTDLL_API void test_qpOASES()
{
	USING_NAMESPACE_QPOASES

		/* Setup data of first QP. */
		real_t H[2 * 2] = { 1.0, 0.0, 0.0, 0.5 };
	real_t A[1 * 2] = { 1.0, 1.0 };
	real_t g[2] = { 1.5, 1.0 };
	real_t lb[2] = { 0.5, -2.0 };
	real_t ub[2] = { 5.0, 2.0 };
	real_t lbA[1] = { -1.0 };
	real_t ubA[1] = { 2.0 };

	/* Setup data of second QP. */
	real_t g_new[2] = { 1.0, 1.5 };
	real_t lb_new[2] = { 0.0, -1.0 };
	real_t ub_new[2] = { 5.0, -0.5 };
	real_t lbA_new[1] = { -2.0 };
	real_t ubA_new[1] = { 1.0 };


	/* Setting up QProblem object. */
	QProblem example(2, 1);

	Options options;
	example.setOptions(options);

	/* Solve first QP. */
	int_t nWSR = 10;
	example.init(H, g, A, lb, ub, lbA, ubA, nWSR);

	/* Get and print solution of first QP. */
	real_t xOpt[2];
	real_t yOpt[2 + 1];
	example.getPrimalSolution(xOpt);
	example.getDualSolution(yOpt);
	printf("\nxOpt = [ %e, %e ];  yOpt = [ %e, %e, %e ];  objVal = %e\n\n",
		xOpt[0], xOpt[1], yOpt[0], yOpt[1], yOpt[2], example.getObjVal());

	/* Solve second QP. */
	nWSR = 10;
	example.hotstart(g_new, lb_new, ub_new, lbA_new, ubA_new, nWSR);

	/* Get and print solution of second QP. */
	example.getPrimalSolution(xOpt);
	example.getDualSolution(yOpt);
	printf("\nxOpt = [ %e, %e ];  yOpt = [ %e, %e, %e ];  objVal = %e\n\n",
		xOpt[0], xOpt[1], yOpt[0], yOpt[1], yOpt[2], example.getObjVal());

	example.printOptions();
	/*example.printProperties();*/

	/*getGlobalMessageHandler()->listAllMessages();*/
}