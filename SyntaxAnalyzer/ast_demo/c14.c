

int a = 33, b, c = 44;
int bb = "12345";
int bb = 3;
str aaa = "12345", bbb;
int array3[10];
int array2[10] = {10,9,8,7};
str _print_sep = "  ";

str f()
{
	str b = "aaa" + "ddd";
	str c = "ccc" + "bb";
	print c;
	return c;
}

int func(int para1, str para2, int para3, int para4, str para5)
{
	int bb = 456;
	str kkk = "a string";
	str ggg;
	{
		int bb = 123;
		str kkk = "another string";
		bb = bb + 10;
		bb = bb + c * a * 1000;
		print bb, kkk;

		int t = bb < a;

		ggg = aaa;
		ggg[1] = '3';
	}
	while( bb > 10)
	{
		bb = bb - 1;
	}
	return bb;
}

int func1(int fir, int sec)
{
	int b = fir*sec + 3000;
	int a = 10;
	while(a > 0)
	{
		str k = "\t" + a + "\n" ;
		a = a -1;
	}
	print "func1 done" + "\n" ;
	return b;
}

void test1()
{
	int aa = 13;
	str bb = "para2";
	int cc = 10+aa;
	int dd = func1(5, aa);

	str ee = f();
	scan cc;
	print cc;

	int ff = func(aa, bb, 3, 100*5+cc, "ccc" + "dadda");

	dd = "zzzzz" < "dddd";
	print "zzz" + 5 + "\n";
	ee = 5 * "abc" + "\n";
	print ee;
	ee = ee + "\n";
	print ee;

	scan ee;
	print aa, bb, cc, dd, ee*3, ff;
}

void multable()
{
	int i = 1;
	while(i < 10)
	{
		int j = 1;
		while(j < 10)
		{
			print "\t" + i*j;
			j = j + 1;
		}
		print "\n";
		i = i +1;
	}
}

int fn(int n)
{
	if(n == 1)
		return 1;
	else
	{
		int r = n* fn(n-1);
		print r;
		return r;
	}
}

void arrayTest()
{
	int b = 100;
	int array1[b] = {10,9,8,7,6,5};

	int a0 = array1[0];
	int a1 = array1[1];
	int a2 = array1[2];
	int a3 = array1[3];

	b = -(a1+a2*a3);
	array1[4] = b;

	print "\nfinal: ", a0, a1, a2, a3, b, array1[4], "\n";

	int i = 0;
	while(i < 10)
	{
		print array1[i];
		i = i+1;
	}
	print "\n";

	i = -80;
	while( i > -101 )
	{
		if( i % 2 == 0)
			print i, array1[i], "\n";
		else
			print -i, array1[i], "\n";
		i = i- 1;
	}

	print "\nindex test\n";
	print array1[-102];
	print array1[102];
}

void assignTest()
{
	int k = 10;
	print "k += 20", k += 20, "\n";
	print "k -= 20", k -= 20, "\n";
	print "k *= 10", k *= 10, "\n";
	print "k /= 10", k /= 10, "\n";
	print "k %= 7", k %= 7, "\n";
}

void strArrayTest()
{
	str array[10] = {"13", "abc", "333"};
	str k = array[0] + array[1];
	print k, "\n";

	array[7] = k;

	array[3] = array[0] + array[1];
	array[4] = array[1] + array[2];
	array[5] = array[2] + array[3];
	array[6] = array[5] * 5;

	int i = 0;
	while( i < 10 )
	{
		print i, array[i], "\n";
		i += 1;
	}
	print;

}

int main()
{
	multable();
	print fn(8);
	arrayTest();
	assignTest();
	strArrayTest();

	return 0;
}
