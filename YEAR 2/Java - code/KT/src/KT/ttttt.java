package KT;
import java.util.*;



public class ttttt {
	final static int MAX=1000;
public static void input(int a[]) {
	Scanner ii = new Scanner(System.in);
	for(int i=0;i<a.length;i++) {
		System.out.println("a["+i+"]=");
		a[i]=ii.nextInt();
	}
}
public static void output(int a[]) {
	System.out.println("Dãy số đã nhập là: ");
	for(int i=0;i<a.length;i++) {
		System.out.println(" "+a[i]);
	}
}

public static void max(int a[]) {
	int max=a[0];
	for(int i=0;i<a.length;i++) {
		if(a[i]>max) {
			max=a[i];
		}
	}System.out.println("sln là: "+max);
}
	

public static void min(int a[]) {
	int min=a[0];
	for(int i=0;i<a.length;i++) {
		if(a[i]<min) {
			min=a[i];
		}
	}System.out.println("snn là: "+min);
}




public static int ktsnt(int a) {
	if(a<=1) {
		return 0;
	}
	for(int i=2;i<=Math.sqrt(a);i++) {
		if(a%i==0) {
			return 0;
		}
	}return 1;
}
public static void snt(int a[]) {
	int snt[]=new int[MAX];
	int k=0;
	for(int i=0;i<a.length;i++) {
		if(ktsnt(a[i])==1) {
			snt[k++]=a[i];
		}
	}
	System.out.println("Dãy số nt là: ");
	for(int i=0;i<k;i++) {
		System.out.println(" "+snt[i]);
	}if(k==a.length) {
		System.out.println("tất cả là snt");
	}else {
		System.out.println(" k pk tất cả đều là snt");
	}
	
	
}

public static int ktscp(int a) {
	
	int n = (int)Math.sqrt(a);
	if(n*n==a) {
		return 1;
	}else {
		return 0;
	}
		
	
}
public static void scp(int a[]) {
	int scp[]=new int[MAX];
	int k=0;
	for(int i=1;i<a.length;i++) {
		if(ktscp(a[i])==1) {
			scp[k++]=a[i];
		}
	}
	System.out.println("Dãy số cp là: ");
	for(int i=0;i<k;i++) {
		System.out.println(" "+scp[i]);
	}
	
	
}
public static int ktshh(int a) {
	int n=0;
	for(int i=1;i<a;i++) {
		if(a%i==0) {
			n+=i;
		}
	}if(n==a) {
		return 1;
	}else{
		return 0;
	}
}
	
public static void tach(int a[],int shh[],int khh[]) {
	
	int k=0,s=0;
	for(int i=0;i<a.length;i++) {
		if(ktshh(a[i])==1) {
			shh[k++]=a[i];
		}else {
			khh[s++]=a[i];
		}
	}
	System.out.println("Dãy số hh là: ");
	for(int i=0;i<k;i++) {
		System.out.println(" "+shh[i]);
	}System.out.println("Dãy k pk số hh là: ");
	for(int i=0;i<s;i++) {
		System.out.println(" "+khh[i]);
	}
	
}
public static int[] ghep(int a[],int al,int b[],int bl) {
	int hop[]=new int[al+bl];
	int k=0;
	for(int i=0;i<al;i++) {
	hop[k++]=a[i];
}
	for(int i=0;i<bl;i++) {
		hop[k++]=b[i];
	}
	return hop;
}

public static void daomang(int a[]) {
	int dau=0;
	int cuoi=a.length-1;
	while(dau<cuoi) {
		int tam=a[dau];
		a[dau]=a[cuoi];
		a[cuoi]=tam;
		dau++;
		cuoi--;
	}
}
public static void sapxep(int a[]) {
	for(int i=0;i<a.length-1;i++) {
		for(int j=i+1;j<a.length;j++) {
			if(a[i]>a[j]) {
				int tam=a[i];
				a[i]=a[j];
				a[j]=tam;
			}
		}
	}System.out.println("Day sau khi sap xep");
	for(int i=0;i<a.length;i++) {
		System.out.println(" "+a[i]);
	}
}
public static int[]chen(int a[]){
Scanner hh = new Scanner(System.in) ;
	int dau,cuoi;
	System.out.println("Nhập số đầu: ");
	dau=hh.nextInt();
	System.out.println("Nhập số cuoi: ");
	cuoi=hh.nextInt();
	int []tam=new int[a.length+2];
	tam[0]=dau;
	tam[tam.length-1]= cuoi;
	for(int i=1;i<tam.length-1;i++) {
		tam[i]=a[i-1];
	}
	return tam;
}

public static int[]xoa(int  a[]){
	int []tam=new int[a.length-2];
	for(int i=0;i<tam.length;i++) {
		tam[i]=a[i+1];
	}
	return tam;
}
	public static void main(String[] args) {
		int a[]=new int[5];
		int shh[]=new int[MAX];
		int  khh[]=new int[MAX];
		input(a);
		output(a);
		max(a);
		min(a);
		snt(a);
		scp(a);
		tach(a,shh,khh);
		int k=0,s=0;
		for(int i=0;i<a.length;i++) {
			if(ktshh(a[i])==1) {
				k++;
			}else {
				s++;
			}
		}	
		int hopmang[]=ghep(shh,k,khh,s);
		System.out.println("Mảng sau khi ghép: " );
		for (int i = 0; i < hopmang.length; i++) {
			System.out.print(" " + hopmang[i]);
		}
		daomang(a);
		System.out.println("Màng sau khi dao nguoc: ");
		output(a);
		sapxep(a);
		a=chen(a);
		System.out.println("dãy số sau khi chèn: ");
		output(a);
		a=xoa(a);
		System.out.println("dãy số sau khi xoa: ");
		output(a);
	
	}
}
