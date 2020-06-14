/*

函数模板
	template<class T>//可以有多个类型template<class T, class T1, ...>
	void swap(T & a, T & b)
	{
		T temp = a;
		a = b;
		b = temp;
	}
	在具体调用过程中，编译器根据使用参数类型自动生成函数,如void swap(int & a, int & b){}
	也可以不通过参数实例化函数模板，如：swap<double>(n)

	模板函数也可以重载，只要他们的形参表或类型参数表不同即可<class T, class T2>

	模板函数和普通函数同名时，编译器处理顺序为，先查看是否有符合条件的普通函数→再查看模板函数→最后查看类型转换过后
	的普通函数，都没有则报错。（匹配普通函数的时候，编译器会自动转换类型，匹配模板函数的时候编译器不会自动转换类型，转换类型存在歧义）


类模板
	当一些类当中所有操作都一样，只是操作的元素类型不同的时候，可以使用模板进行操作。
	模板类之间不兼容，模板类的成员函数也可以是模板函数。
	template<class T1, class T2, ... , int size>	类模板的参数列表中可以有非类型参数
	class A
	{}
	函数模板成员函数体外定义的时候需要添加模板声明


模板类的派生
	类模板从类模板派生： 
	template<class T2, class T1>
	class B：A<T1,T2>{}

	类模板从模板类派生
	template<class T1, class T2>
	class B:A<int, double>{}

	类模板从普通类派生
	template<class T1, class T2>
	class B:A{}

	普通类从模板类派生
	class B:A<int, int>{}


类模板和静态成员
	类模板实例化的所有模板类都包含同样的静态成员(不同的类的静态成员存放位置不同)
	类模板的静态成员，在实例化类的时候需要去声明和初始化静态成员
		template<> int A<int>::count = 0;


*/