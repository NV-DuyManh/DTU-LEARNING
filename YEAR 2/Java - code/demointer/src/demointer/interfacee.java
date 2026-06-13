package demointer;
import java.io.*;
interface IAREA{
	final float PI = (float) 3.14;
	static int a =20;
	
	
	float calArea();
		static void display() {
			System.out.println("Hello world");
		}
	
}
class area implements IAREA{
	public float calArea() {
		int r =10;
		return r*r*PI;
	}
}


public class interfacee {

	public static void main(String[] args) {
area qq = new area();
int b;
b=IAREA.a+10;
System.out.println("Dien tich: "+qq.calArea());
IAREA.display();
System.out.println("B= "+b);
		
	}

}
