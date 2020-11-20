#include <QtCore/QCoreApplication>
#include "fftw3.h"
#include <iostream>

//实部与虚部
#define REAL 0
#define IMAG 1

using namespace std;

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	/*
	*fftw_complex 是FFTW自定义的复数类
	*引入<complex>则会使用STL的复数类
	*/
	fftw_complex x[5];
	fftw_complex y[5];

	for (int i = 0; i < 5; i++) {
		x[i][REAL] = i;
		x[i][IMAG] = 0;
	}

	//定义plan，包含序列长度、输入序列、输出序列、变换方向、变换模式
	fftw_plan plan = fftw_plan_dft_1d(5, x, y, FFTW_FORWARD, FFTW_ESTIMATE);

	//对于每个plan，应当"一次定义 多次使用"，同一plan的运算速度极快
	fftw_execute(plan);

	for (int i = 0; i < 5; i++) {
		cout << y[i][REAL] << "  " << y[i][IMAG] << endl;
	}

	//销毁plan
	fftw_destroy_plan(plan);

	cout << "\nPress Enter to exit..." << endl;

	return a.exec();
}
