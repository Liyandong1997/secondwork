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
		//ֻ��
	case ReadOnly:

		ifile.open(m_fileName);
		cout << "Reading from the file" << endl;
		ifile >> data;
		cout << data << endl;//����Ļ�����

		ifile.close();

		//ֻд
	case WriteOnly:
	
		ofile.open(m_fileName);
		cout << "write to the file" << endl;
		cout << "Enter your data";
		cin.getline(data, 100);
		//���ļ�д�����������
		ofile << data << endl;

		ofile.close();

		//��д
	case ReadWrite:
	
		rwfile.open(m_fileName, ios::out | ios::in);

		//׷��
	case Append:

		appfile.open(m_fileName, ios::out | ios::app);

		//�ض�
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
	printf("�������ļ�·����");
	cin >> *a;
	const char *m_fileName = a;
    
}

int CFile::readBuffer(char *buf, int maxsize)//�����ݣ�����ֵ�Ƕ�����ֽ�����maxsize��ʾ�������ֽ��������������ݱ����� buf
{
	ifstream ifile;
	ofstream ofile;

	char data[100];
	ifile.open(m_fileName);

	ifile >>data ;
	buf = data; //���������ݱ����� buf

	cout << *buf << endl;//����Ļ�����buf����

	maxsize = sizeof(ifile);

	return maxsize;

}

int CFile::write(char *data)//д���ݣ�����ֵд����ֽ���
{

	bool open(Append);

	fstream appfile;

	appfile.getline(data,100);
	//���ļ�д�����������
	appfile << data << endl;

	appfile.close();


	//����д����ֽ���
	int size = 0;
	size = sizeof(data);
	return size;      
}