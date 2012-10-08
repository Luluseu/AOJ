import java.math.*;
import java.util.Scanner.*;
import java.util.*;

public class bigint
{
	public static String pro(String a)
	{
		String r=new String("");
		int i,count=0;
		for(i=a.length()-1;i>=0;--i)
		{
			count++;
			r=a.charAt(i)+r;
			if(count==3 && i!=0)
			{
				r=','+r;
				count=0;
			}
		}
		return r;
	}
	public static void main(String []args)
	{
		Scanner sc=new Scanner(System.in);
		String s;
	//	System.out.println("dingyaguang!!");
		
		while(sc.hasNext())
		{
			s=sc.next();
			if(s.charAt(0)=='*') break;
			if(s.charAt(0)<='9' && s.charAt(0)>='0')
			{
				BigInteger a=new BigInteger(s);
				String re=new String("");
				while(!a.equals(BigInteger.ZERO))
				{
					if(a.equals(BigInteger.valueOf(26)))
					{
						re='z'+re;
						break;
					}
					int t=a.mod(BigInteger.valueOf(26)).intValue();
					char c;
					if(t!=0)
						c=(char)('a'+t-1);
					else
					{
						c='z';
						a=a.add(BigInteger.valueOf(-26));
					}
						
					re=c+re;
					a=a.divide(BigInteger.valueOf(26));
				}
				//System.out.println(re);
				System.out.printf("%-22s",re);
				System.out.println(pro(s));
			}else
			{
				//System.out.println(s);
				System.out.printf("%-22s",s);
				BigInteger re=new BigInteger("0");
				BigInteger base=new BigInteger("1");
				int i;
				for(i=s.length()-1;i>=0;--i)
				{
					re=re.add(base.multiply(BigInteger.valueOf(s.charAt(i)-'a'+1)));
					base=base.multiply(BigInteger.valueOf(26));
				}
				System.out.println(pro(re.toString()));
			}
		}
	}
}