#include<stdio.h>
#include<stdbool.h>
#include <string>
#include"file.h"
#include<iostream>
#include<fstream>


using namespace std;


CFile::CFile()
{

}

CFile::CFile(const char *file_name)
{

}

CFile::CFile(const CFile&)
{

}

bool CFile::open(OpenMode mode)
{

	int i = 0;
	i = mode;


	char data[100];
	
	ifstream ifile;
	ofstream ofile;
	ofstream rwfile;
	ofstream appfile;
	ofstream outfile;


	switch (i)
	{
		//只读
	case ReadOnly:

		ifile.open(m_fileName);
		cout << "Reading from the file" << endl;
		ifile >> data;
		cout << data << endl;//在屏幕上输出

		ifile.close();

		//只写
	case WriteOnly:
	
		ofile.open(m_fileName);
		cout << "write to the file" << endl;
		cout << "Enter your data";
		cin.getline(data, 100);
		//向文件写入输入的数据
		ofile << data << endl;

		ofile.close();

		//读写
	case ReadWrite:
	
		rwfile.open(m_fileName, ios::out | ios::in);

		//追加
	case Append:

		appfile.open(m_fileName, ios::out | ios::app);

		//截断
	case Truncate:

		outfile.open(m_fileName, ios::out | ios::trunc);


	default:
		break;
	}

	

	return 0;
}


void CFile::setFileName(const char *)
{
	char *a=0;
	printf("请设置文件路径：");
	cin >> *a;
	const char *m_fileName = a;
    
}

int CFile::readBuffer(char *buf, int maxsize)//读数据，返回值是读入的字节数，maxsize表示最多读的字节数，读出的内容保存在 buf
{
	ifstream ifile;
	ofstream ofile;

	char data[100];
	ifile.open(m_fileName);

	ifile >>data ;
	buf = data; //读出的内容保存在 buf

	cout << *buf << endl;//在屏幕上输出buf内容

	maxsize = sizeof(ifile);

	return maxsize;

}

int CFile::write(char *data)//写数据，返回值写入的字节数
{

	bool open(Append);

	fstream appfile;

	appfile.getline(data,100);
	//向文件写入输入的数据
	appfile << data << endl;

	appfile.close();


	//返回写入的字节数
	int size = 0;
	size = sizeof(data);
	return size;      
}