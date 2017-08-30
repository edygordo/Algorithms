package Code_chef;

public class Maximallargesubarray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int A[] = { -2,1,-3,4,-1,2,1,-5,4};
		System.out.println(kadane(A));
	}

	public static int kadane(int A[])
	{
		int max_so_far = 0;
		int max_till_here = 0; int si=0,ei=0; boolean flag = true;
		for(int i=0;i<A.length;i++)
		{
			max_till_here +=A[i];
			if(max_till_here < 0)
				{
				max_till_here = 0;
				flag = true;
				}
			if(max_so_far < max_till_here)
				{
				max_so_far = max_till_here;
				if(flag)
				 si = i;
				else
					ei = i;
				flag = false;
				}
		}
		System.out.println(si+" "+ei);
		return max_so_far;
	}
}
