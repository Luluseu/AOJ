#include <cstdio>


int main()
{
	char c;
	bool f=false;
	int deepdouble=0;
	int deepsigle=0;
	while ((c=getchar())!=EOF)
	{
		if (c=='"')
		{
			if (!f)
			{
				if (deepdouble==0)
				{
					deepdouble++;
					putchar('`');
					putchar('`');
				}else
				if (deepdouble==1)
				{
					deepdouble--;
					putchar('\'');
					putchar('\'');
				}else
				{
					deepdouble--;
					f=true;
					putchar('\'');
					putchar('\'');
				}
			}else
			{
				f=false;
				deepdouble++;
				putchar('`');
				putchar('`');
			}
		}else if(c=='`')
		{
			f=true;
			deepsigle++;
			putchar(c);
		}else if (c=='\'')
		{
			f=false;
			deepsigle--;
			putchar(c);
		}
		else
		{
			putchar(c);
		}
	}
	putchar('\n');
}