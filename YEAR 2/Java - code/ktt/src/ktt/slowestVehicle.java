package ktt;

import java.io.IOException;
import java.util.*;

abstract class Vehicle {
	public String color;
	public int speed;

	public Vehicle() {

	}

	public Vehicle(String color, int speed) {
		this.color = color;
		this.speed = speed;
	}

	abstract void go();

	void changeColor(String color) {
		this.color = color;
	}
}

class Bicycle extends Vehicle {
	public int numberOfWheels;

	public Bicycle() {

	}

	public Bicycle(String color, int speed, int numberOfWheels) {
		super(color, speed);
		this.numberOfWheels = numberOfWheels;
	}

	void go() {
		System.out.println("color Bicycle: " + this.color);
		System.out.println("speed Bicycle: " + this.speed);
		System.out.println("numberOfWheels Bicycle: " + this.numberOfWheels);
	};
}

class Car extends Vehicle {
	public int sizeOfEngine;
	public int numberOfDoors;

	public Car() {

	}

	public Car(String color, int speed, int sizeOfEngine, int numberOfDoors) {
		super(color, speed);
		this.sizeOfEngine = sizeOfEngine;
		this.numberOfDoors = numberOfDoors;
	}

	void go() {
		System.out.println("color Car: " + this.color);
		System.out.println("speed Car: " + this.speed);
		System.out.println("sizeOfEngine Car: " + this.sizeOfEngine);
		System.out.println("numberOfDoors Car: " + this.numberOfDoors);
	};
}

class VehicleList {
	Vehicle arrayOfVehicle[] = new Vehicle[100];
	int n;
	char chon, loai;
	Scanner qq = new Scanner(System.in);

	void input() throws IOException {
		do {

			System.out.println("Bicycle or Car(1/2)");
			chon = (char) System.in.read();
			if (chon == '1') {
				arrayOfVehicle[n] = new Bicycle();
			} else {
				arrayOfVehicle[n] = new Car();
			}
			System.in.skip(chon);
			System.out.println("Color");
			arrayOfVehicle[n].color = qq.nextLine();
			System.out.println("speed");
			arrayOfVehicle[n].speed = qq.nextInt();
			qq.nextLine();
			if (chon == '1') {
				System.out.println("numberOfWheels");
				((Bicycle) (arrayOfVehicle[n])).numberOfWheels = qq.nextInt();

			} else {
				System.out.println("sizeOfEngine");
				((Car) (arrayOfVehicle[n])).sizeOfEngine = qq.nextInt();
				System.out.println("numberOfDoors");
				((Car) (arrayOfVehicle[n])).numberOfDoors = qq.nextInt();
			}
			qq.nextLine();
			n++;
			System.out.println("Continues(C/K) ");
			loai = (char) System.in.read();
			System.in.skip(loai);
			if ((n == 100) || (loai == 'k' || loai == 'K')) {
				break;
			}

		} while (true);
	}

	void output() {
		for (int i = 0; i < n; i++) {
			arrayOfVehicle[i].go();
		}
	}

	Vehicle safetyVehicle() {
		Vehicle slow = arrayOfVehicle[0];
		for (int i = 1; i < n; i++) {
			if (arrayOfVehicle[i].speed < slow.speed) {
				slow = arrayOfVehicle[i];
			}
		}
		return slow;
	}

}

public abstract class slowestVehicle {

	public static void main(String[] args) throws IOException {
		VehicleList d = new VehicleList();
		d.input();
		d.output();
		Vehicle slowestVehicle = d.safetyVehicle();
		System.out.println("The slowest vehicle is:");

		slowestVehicle.go();
	}

}
