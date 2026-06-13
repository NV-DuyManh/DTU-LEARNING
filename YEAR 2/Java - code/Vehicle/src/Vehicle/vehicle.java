package Vehicle;

import java.util.*;

abstract class Xe {
	int speed;
	String color;

	Xe() {
	}

	Xe(int speed, String color) {
		this.speed = speed;
		this.color = color;

	}

	public abstract void go();

	public void changeColor(String newColor) {
		this.color = newColor;
	}
}

class Bicycle extends Xe {
	int numberOfwheels;

	public Bicycle() {
	}

	public Bicycle(int numberOfwheels, int speed, String corlor) {
		super(speed, corlor);
		this.numberOfwheels = numberOfwheels;
	}

	public void go() {
		System.out.println(
				"The" + color + " bicycle with " + numberOfwheels + " wheels, go with speed = " + speed + " km/h");
	}
}

class Car extends Xe {
	int sizeofEngine;
	int numberOfDoors;

	public Car() {
	}

	public Car(int sizeofEngine, int numberOfDoors, int speed, String corlor) {
		super(speed, corlor);
		this.sizeofEngine = sizeofEngine;
		this.numberOfDoors = numberOfDoors;
	}

	public void go() {
		System.out.println("The " + color + " Car with: " + numberOfDoors + "  doors and engine:" + sizeofEngine
				+ "  go with speed = " + speed + " km/h");
	}
}

class Vehiclelist {
	int n;
	Xe[] arrVeb;

	public Vehiclelist() {
	}

	public void input() {
		Scanner scan = new Scanner(System.in);
		System.out.println("How many vehicle in the list? ");
		n = scan.nextInt();
		arrVeb = new Xe[n];
		for (int i = 0; i < arrVeb.length; i++) {
			System.out.println("choose vehicle type:\n1.Car:\n2.Bicycle:");
			int choose = scan.nextInt();
			if (choose == 1) {
				System.out.println("enter size of engine, number of doors, speed and color respectively: ");
				arrVeb[i] = new Car(scan.nextInt(), scan.nextInt(), scan.nextInt(), scan.next());
			} else {
				System.out.println("enter number of wheels, speed and color respectively: ");
				arrVeb[i] = new Bicycle(scan.nextInt(), scan.nextInt(), scan.next());
			}
		}
	}

	public void output() {
		for (int i = 0; i < arrVeb.length; i++) {
			arrVeb[i].go();
		}
	}

	public void safetyVehicle() {
		Xe safety = arrVeb[0];
		for (int i = 1; i < arrVeb.length; i++) {
			if (arrVeb[i].speed < safety.speed) {
				safety = arrVeb[i];
			}
		}
		safety.go();
	}
}

public class vehicle {

	public static void main(String[] args) {
		Vehiclelist list = new Vehiclelist();
		list.input();
		list.output();
		list.safetyVehicle();

	}

}