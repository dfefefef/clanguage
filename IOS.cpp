/*
	cout��ostream���󣬲��Ὣ'\n'�ӻ������ж���
	cin��istream����

	cerr����׼����ֱ�����������Ļ
	clog����cerr��ͬ����clog�л���������������������ˢ��ʱ����������Ļ

�ض���
	 freopen("*.txt", w/r, stdout/stdin);����׼���/�����ض���ָ�����ļ�
	 �ض���cout��ʱ��Ӱ��cerr�������cerr��Ȼ���Խ�������Ϣ�������Ļ

	istream& getline(char *buff, int size, char deim),����size-1���ַ���buff����������������deimΪֹ��������ַ���
	ĩβ��'\0',���Ҵӻ������ж���'\n',deim��

	bool eof()

	int peek();������һ�����������ַ��������ӻ������ж���

	istream & putback(char c);���ַ�c�Ż�������

	istream & ignore(int nCount = 1, int delim = EOF);����������ɾ��nCount���ַ�


����������
	hex��ʮ�����ƣ�cout<<hex<<x...;
	dec��ʮ����
	otc���˽���

	precision:
	setprecision:	cout<<setprecision()<<x<<...;
		�Զ�����ʽ���
	cout<<setiosflags(ios::fixed)<<setprecision(6)<<x<<....<<resetiosflags(ios::fixed)<<;


	������ã�
		cout<<setw(4):���������ӣ�����cout.width(4)������ÿ�������������ַ����
		������õ���Ч����һ���Եģ��ٴε����������ʱ��Ҫ�ٴ����ÿ��

	�û��Զ�������������
		ostream & name(ostream & output)
		{
			return output<<"\t";
		}

		ʹ�ú���ָ��ʵ��
		ostream & opertor<<(ostream &(*p)(ostream &));


�ļ�
						ios
					 �L	    �K
				istream		ostream
			  �L	  �K	�L	  �K
		ifstream	  iostream		ofstream
						 ��
					  fstream
		
	ofstream outFile("*.dat", ios::out|ios::binary);

	ios::out �����򸲸�
	ios::app ��ĩβ���
	ios::binary ��������ʽ
	ios::ate ���ķ�ʽ��

	location = tellp()�����ļ�ָ���λ��
	seekp(location, ios::beg\ios::cur\ios::end);�ļ�ָ���ƶ����ӿ�ʼ\��ǰ\ĩβ��ʼ��location���ֽڴ�




*/