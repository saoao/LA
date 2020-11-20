#include <QtCore/QCoreApplication>
#include "fftw3.h"
#include <iostream>

//ʵ�����鲿
#define REAL 0
#define IMAG 1

using namespace std;

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	/*
	*fftw_complex ��FFTW�Զ���ĸ�����
	*����<complex>���ʹ��STL�ĸ�����
	*/
	fftw_complex x[5];
	fftw_complex y[5];

	for (int i = 0; i < 5; i++) {
		x[i][REAL] = i;
		x[i][IMAG] = 0;
	}

	//����plan���������г��ȡ��������С�������С��任���򡢱任ģʽ
	fftw_plan plan = fftw_plan_dft_1d(5, x, y, FFTW_FORWARD, FFTW_ESTIMATE);

	//����ÿ��plan��Ӧ��"һ�ζ��� ���ʹ��"��ͬһplan�������ٶȼ���
	fftw_execute(plan);

	for (int i = 0; i < 5; i++) {
		cout << y[i][REAL] << "  " << y[i][IMAG] << endl;
	}

	//����plan
	fftw_destroy_plan(plan);

	cout << "\nPress Enter to exit..." << endl;

	return a.exec();
}
