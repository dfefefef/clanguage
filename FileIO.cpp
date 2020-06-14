/*

	标准输入输出流stdin，stdout
		标准输入输出流的重定向"<",">"

数据组织形式

	文本文件
		以ASCII编码方式存储文件，以行为单位，以文本结束符为结尾

	二进制文件
		按照内存原本的数据存储文件，与文本文件本质上是编码的区别，不需要ASCII编码的转换，读写速度快
		而在表示二进制文件的信息的时候，需要指定的编码方式

	文件指针
		FILE *;指向一个磁盘文件，

	FILE *fopen(文件名, 模式);打开文件返回指针，打开失败返回NULL
		模式：
	文本文件
		r	只读	文件必须存在
		w	只写	不管文件存在不存在都建立该文件，覆盖存在的原文件
		a	只写	在文件末尾追加，文件必须存在
		r+	读写	可以读写
		w+	读写	可以读
		a+	读写	可以读

	二进制文件
		rb
		wb
		ab
		rb+
		wb+
		ab+


	int fclose(FILE *fp);关闭fp指向的文件
		把遗留在缓冲区的文件写入磁盘，执行操作系统级的文件关闭操作；
		释放文件控制块FCB，便于后面使用
		
		返回值为非零时关闭文件失败，可能是文件空间不够



	fscanf(stdin,,)等价于scanf()
	fprintf(stdout,,)等价于printf()

	fputs(const char * s,FILE *fp)
	puts(const char *s);在输出完的末尾添加换行符，而fputs不会添加

	char *fgets(char *s,int c, FILE *fp);最多读入n-1个字符，都会在字符串尾加上'\0'，读入失败或者遇到文件尾时候都返回NULL
		保留\n
	char *gets(char *s);往缓冲区输入，不关心缓冲区大小，容易产生溢出，不保留\n
	
	fputc(int c,stdout); putchar()
	putc(int c,stdout);	

	fgetc(stdin)	getchar()	//文件读取错误也返回EOF
	getc(stdin)							#define getchar(c) getc(stdin)

	读到文件末尾的时候，返回EOF（ASCII码值为-1）
	输入：读入一个字符，文件指针指向下一个字符
	输出：写入一个字符到指针指向的位置，写入成功返回c，写入失败返回EOF

	feof(FILE *p)，到达文件尾时候返回非零值，文件结束符读走以后，文件指针指向文件结束符后面的的时候，文件真的为空的时候才返回非零值


	ferror(FILE *p)，出错返非零，否则返回零。

	按块读写文件，参数表参数依次是缓冲区，读写块的大小，读写块的数量，文件指针，返回实际读写块的数量
	size_t fread(void *buffer, size_t size, size_t count, FILE *fp)
	size_t fwrite(void *buffer, size_t size, size_t count, FILE *fp)


	long ftell(FILE *p);返回当前文件指针的字节偏移量
	int fseek(FILE *fp; long offset, int fromwhere);改变文件位置指针，实现随机读写文件
		offset：字节偏移量
		fromwhere：起始地址
			SEEK_SET 0 文件开始
			SEEK_CUR 1 当前位置
			SEEK_END 2 文件末尾
	void fwind(FILE *fp);文件位置指针回到起始位置


	输入输出缓冲区（操作系统级）
		1.内存和磁盘读写速度不匹配，需要缓冲区来协调，
		2.缓冲区满或关闭（文件）输入输出流的时候写入磁盘
		3.或者主动清洗缓冲区	fflush(fp);

	内存《=》输入/输出缓冲区《=》磁盘

	每打开一个文件，为每个文件设置缓冲区；
*/