package birthday;

import java.util.*;

public class Birthday {
	public int day, month, year;

	public Birthday() {

	}

	public Birthday(int day, int month, int year) {
		this.day = day;
		this.month = month;
		this.year = year;
	}

	void input() {
		Scanner qq = new Scanner(System.in);
		int iday, imonth, iyear;
		do {
			System.out.println("Enter year: ");
			iyear = qq.nextInt();
			if (iyear < 1900 || iyear > 2999) {
				System.out.println("Try again!");
			} else {
				do {
					System.out.println("Enter month: ");
					imonth = qq.nextInt();
					if (imonth <= 0 || imonth > 12) {
						System.out.println("Try again!");
					} else {
						boolean checkDay = false;
						do {
							System.out.println("Enter day: ");
							iday = qq.nextInt();
							if (iday <= 0 || iday > 31) {
								System.out.println("Try again!");
							} else if ((imonth == 2 && iday > 29)
									|| ((imonth == 4 || imonth == 6 || imonth == 9 || imonth == 1) && iday > 30)) {
								System.out.println("Try again!");
							} else {
								checkDay = true;
								day = iday;
								month = imonth;
								year = iyear;
							}
						} while (!checkDay);
					}
				} while (imonth <= 0 || imonth > 12);
			}
		} while (iyear < 1900 || iyear > 2999);
	}

	double calYearOld() {
		return (Calendar.getInstance().get(Calendar.YEAR) - year);
	}

	void display() {
		System.out.println("Your birthday: " + day + "/" + month + "/" + year);
		System.out.println("You " + calYearOld() + " year old");
	}

	public static void main(String[] args) {
		Birthday a = new Birthday();
		a.input();
		a.display();
	}

}
