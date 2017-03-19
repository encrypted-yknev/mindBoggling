import java.io.*;
import java.util.*;

class Sieve {
    public static Vector<Integer> prime=new Vector<Integer>();
    public static int N=100;
    public static Boolean[] isPrime=new Boolean[N+1];
    public static int[] spf = new int[100000];
    
	public static void main (String[] args) {
	    initPrime(N);
		manipulatedSieve(N);
		
		for(int x:prime)
		    System.out.print(x+" ");
	}
	
	public static void initPrime(int N)  {
	    isPrime[0]=isPrime[1]=false;
	    for(int i=2;i<=N;i++)
	        isPrime[i]=true;
	}
	public static void manipulatedSieve(int N)  {
	    
	    for(int i=2;i<N;i++)   {
	        
	        if(isPrime[i])  {
	            prime.addElement(i);
	            spf[i]=i;
	        }
	    
	        for(int j=0; j < (int)prime.size() &&
	                     i*prime.elementAt(j) < N && 
        	             prime.elementAt(j) <= spf[i]; j++)  {
	                
	            isPrime[i*prime.elementAt(j)]=false;
	            spf[i*prime.elementAt(j)]=prime.elementAt(j);
	        }
	    }
	}
}
