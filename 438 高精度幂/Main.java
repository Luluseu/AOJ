import java.math.*;
import java.util.Scanner;

public class Main
{
	public static String proc(String a)
	{
		int i,j,k;
		String R=new String();
		
		if(a.indexOf('E')!=-1)
		{
			
		}
		
		for(i=0;i<a.length();++i)
		{
			if(a.charAt(i)=='.')
			{
				break;
			}
		}
		if(i==a.length()) a=a+'.';
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
		for(k=i;k<j;++k)
		{
			R=R+a.charAt(k);
		}
		if(a.charAt(j)!='.') R=R+a.charAt(k);
		if(R.length()==0) R="0";
		return R;
	}
	public static void main(String []agrs)
	{
		Scanner sc=new Scanner(System.in);
		String a;
		int n,i;
		while(sc.hasNext())
		{
			a=sc.next();
			n=sc.nextInt();
			BigDecimal Big_a=new BigDecimal(a);
			BigDecimal Big_R=new BigDecimal("1");
			for(i=0;i<n;++i)
			{
				Big_R=Big_R.multiply(Big_a);
			}
		//	System.out.println(Big_R.toPlainString());
			System.out.println(proc(Big_R.toPlainString()));
		}
		
	}
}