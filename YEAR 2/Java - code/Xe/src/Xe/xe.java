package Xe;

import java.util.*;
import java.io.*;

abstract class Vehicle {
	public int numberOfWheels;
	public int speed;
	public String color;
	public double distance;

	public Vehicle() {
	}

	public Vehicle(int numberOfWheels, int speed, String color, double distance) {
		this.numberOfWheels = numberOfWheels;
		this.speed = speed;
		this.color = color;
		this.distance = distance;
	}

	public abstract void display(BufferedWriter bw) throws IOException;

	public double timeToMove() {
		return distance / speed;
	}
}

class Car extends Vehicle {
	public double gasVolume;

	public Car() {
	}

	public Car(int numberOfWheels, int speed, String color, double distance, double gasVolume) {
		super(numberOfWheels, speed, color, distance);
		this.gasVolume = gasVolume;
	}

	public void display(BufferedWriter bw) throws IOException {
		bw.write("This car has: " + numberOfWheels + " wheels, color: " + color + ", takes " + timeToMove()
				+ " hours to move the distance: " + distance + " km, with speed " + speed + " km/h and gas volume is "
				+ gasVolume + "\n");
	}
}

class Bicycle extends Vehicle {
	public boolean electrical;

	public Bicycle() {
	}

	public Bicycle(int numberOfWheels, int speed, String color, double distance, boolean electrical) {
		super(numberOfWheels, speed, color, distance);
		this.electrical = electrical;
	}

	public void display(BufferedWriter bw) throws IOException {
		String rechargeStatus = needToRecharge();
		bw.write("This " + (electrical ? "electrical " : "") + "bicycle has: " + numberOfWheels + " wheels, color: "
				+ color + ", takes " + timeToMove() + " hours to move the distance: " + distance + " km and "
				+ rechargeStatus + "\n");
	}

	public String needToRecharge() {
		if (electrical && this.distance > 60) {
			return "Recharge batteries";
		} else {
			return "Don't need";
		}
	}
}

class VehicleList {
	Vehicle[] a = new Vehicle[100];
	int n = 0;
	File f = new File("vehicles.txt");

	void input() throws IOException {
		Scanner q = new Scanner(System.in);
		for (int i = 0; i < a.length; i++) {
			System.out.println("Car or Bicycle (1/2)?");
			int choice = q.nextInt();
			q.nextLine();

			if (choice == 1) {
				System.out.print("Enter number of wheels: ");
				int wheels = q.nextInt();
				System.out.print("Enter speed: ");
				int speed = q.nextInt();
				q.nextLine();
				System.out.print("Enter color: ");
				String color = q.nextLine();
				System.out.print("Enter distance: ");
				double distance = q.nextDouble();
				System.out.print("Enter gas volume: ");
				double gasVolume = q.nextDouble();
				a[i] = new Car(wheels, speed, color, distance, gasVolume);
				n++;
			} else if (choice == 2) {
				System.out.print("Enter number of wheels: ");
				int wheels = q.nextInt();
				System.out.print("Enter speed: ");
				int speed = q.nextInt();
				q.nextLine();
				System.out.print("Enter color: ");
				String color = q.nextLine();
				System.out.print("Enter distance: ");
				double distance = q.nextDouble();
				System.out.print("Is it electrical (true/false): ");
				boolean electrical = q.nextBoolean();
				a[i] = new Bicycle(wheels, speed, color, distance, electrical);
				n++;
			} else {
				break;
			}

		}
	}

	Vehicle fastestVehicle() {

		Vehicle fastest = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i].timeToMove() < fastest.timeToMove()) {
				fastest = a[i];
			}
		}
		return fastest;
	}

	void output() throws IOException {
	    File file = new File("D:\\cmutpm2.txt");
	    BufferedWriter bw = new BufferedWriter(new FileWriter(file));
	    bw.write("All vehicles:\n");
	    for (int i = 0; i < n; i++) {
	        a[i].display(bw);
	    }

	    Vehicle fastest = fastestVehicle();
	    if (fastest != null) {
	        bw.write("\nThe fastest vehicle is:\n");
	        fastest.display(bw);
	    } else {
	        bw.write("\nNo vehicles available.\n");
	    }

	    bw.close();
	}

	void displayFile() throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(f));
		String line;
		while ((line = br.readLine()) != null) {
			System.out.println(line);
		}
		br.close();
	}
}

public class xe {
	public static void main(String[] args) throws IOException {
		VehicleList q = new VehicleList();
		q.input();
		q.output();
		q.displayFile();
	}
}
