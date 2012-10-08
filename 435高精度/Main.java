import java.math.*;
import java.util.Scanner;

public class Main
{
	public static String proc(String a)
	{
		int i,j,k;
		String R=new String();

		for(i=0;i<a.length();++i)
		{
			if(a.charAt(i)=='.')
			{
				break;
			}
		}
		if(i==a.length()) 
		{
			a=a+".0";
			return a;
		}
		for(i=0;i<a.length();++i)
		{
			if(a.charAt(i)=='0') continue;
			else /*if(a.charAt(i)=='.') */break;
		}
		for(j=a.length()-1;j>0;--j)
		{
			if(a.charAt(j)=='0') continue;
			else /*if(a.charAt(i)=='.') */break;
		}
		for(k=i;k<=j;++k)
		{
			R=R+a.charAt(k);
		}
		if(a.charAt(i)=='.') R="0"+R;
		if(a.charAt(j)=='.') R=R+"0";
		
		return R;
	}
	public static void main(String []agrs)
	{
		Scanner sc=new Scanner(System.in);
		String a,b;
		int n,i;
		while(sc.hasNext())
		{
			a=sc.next();
			b=sc.next();
			BigDecimal Big_a=new BigDecimal(a);
			BigDecimal Big_b=new BigDecimal(b);
			BigDecimal Big_R=Big_a.add(Big_b);
		
			System.out.println(proc(Big_R.toPlainString()));
		}
		
	}
}