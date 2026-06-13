package dichchuyen2so;
import java.util.*;
public class aa {

	public static int[] input(int n) {
		Scanner a = new Scanner(System.in);
		int [] arr = new int [n];
		System.out.println("Nhập "+n+" số: ");
		for(int i=0;i<n;i++) {
			System.out.println("Nhập số thứ "+(i+1)+ " là: ");
			arr[i]=a.nextInt();
		}
		return arr;
	}
	public static void sort(int []arr) {
		Arrays.sort(arr);
		System.out.println("Mảng sau khi sắp xếp là: " +Arrays.toString(arr));
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
Scanner c = new Scanner(System.in);
do {
	System.out.println("Nhập số phần tử cần nhập: ");
	int n=c.nextInt();
	if(n==0) {
		System.out.println("Kết thúc chương trình");
		break;
	}else if(n>0){
		int []arr = input(n);
		sort(arr);
	}
}while(true);
	}

}
