#pragma once
#include<stdio.h>
#include<stdbool.h>
#include <string>
class CFile
{
public:
	CFile();
	CFile(const char *file_name);
	//拷贝构造
	CFile(const CFile &);

	enum OpenMode
	{
		ReadOnly,  //只读
		WriteOnly, //只写
		ReadWrite, //读写
		Append,	//追加，在原有文件的末尾写入
		Truncate   //截断，打开文件后原有内容全部清空，再读写文件
	};

	bool open(OpenMode mode);
	void setFileName(const char *);

	int readBuffer(char *buf, int maxsize); //读数据，返回值是读入的字节数，maxsize表示最多读的字节数，读出的内容保存在 buf
	int write(char *data);			//写数据，返回值写入的字节数

private:
	FILE *m_fileHandle;
	const char *m_fileName;
};