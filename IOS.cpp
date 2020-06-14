/*
	cout，ostream对象，不会将'\n'从缓冲区中读走
	cin，istream对象

	cerr：标准出错，直接输出错误到屏幕
	clog：和cerr不同在于clog有缓冲区，当缓冲区满或者刷新时候才输出到屏幕

重定向
	 freopen("*.txt", w/r, stdout/stdin);将标准输出/输入重定向到指定的文件
	 重定向cout的时候不影响cerr的输出，cerr依然可以将错误信息输出到屏幕

	istream& getline(char *buff, int size, char deim),读入size-1个字符到buff缓冲区，或者遇到deim为止，读入的字符串
	末尾加'\0',并且从缓冲区中读走'\n',deim。

	bool eof()

	int peek();返回下一个输入流的字符，并不从缓冲区中读走

	istream & putback(char c);将字符c放回输入流

	istream & ignore(int nCount = 1, int delim = EOF);冲输入流中删除nCount个字符


流操作算子
	hex：十六进制，cout<<hex<<x...;
	dec：十进制
	otc：八进制

	precision:
	setprecision:	cout<<setprecision()<<x<<...;
		以定点形式输出
	cout<<setiosflags(ios::fixed)<<setprecision(6)<<x<<....<<resetiosflags(ios::fixed)<<;


	域宽设置：
		cout<<setw(4):流操作算子，或者cout.width(4)，设置每次输入和输出的字符宽度
		宽度设置的有效性是一次性的，再次调用输入输出时需要再次设置宽度

	用户自定义流操作算子
		ostream & name(ostream & output)
		{
			return output<<"\t";
		}

		使用函数指针实现
		ostream & opertor<<(ostream &(*p)(ostream &));


文件
						ios
					 ↙	    ↘
				istream		ostream
			  ↙	  ↘	↙	  ↘
		ifstream	  iostream		ofstream
						 ↓
					  fstream
		
	ofstream outFile("*.dat", ios::out|ios::binary);

	ios::out 存在则覆盖
	ios::app 在末尾添加
	ios::binary 二进制形式
	ios::ate 读的方式打开

	location = tellp()返回文件指针的位置
	seekp(location, ios::beg\ios::cur\ios::end);文件指针移动到从开始\当前\末尾开始数location个字节处




*/