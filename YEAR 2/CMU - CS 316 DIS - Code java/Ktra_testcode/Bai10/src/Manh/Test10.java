package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.Triangle;

class Test10 {

	@Test
	void testFirstNumberIsMax() {
	    Triangle triangle = new Triangle();
	    triangle.setNumber1(10);
	    triangle.setNumber2(5);
	    triangle.setNumber3(3);
	    assertEquals(10, triangle.maxLength()); // Cạnh thứ nhất lớn nhất.
	}

	@Test
	void testSecondNumberIsMax() {
	    Triangle triangle = new Triangle();
	    triangle.setNumber1(5);
	    triangle.setNumber2(10);
	    triangle.setNumber3(3);
	    assertEquals(10, triangle.maxLength()); // Cạnh thứ hai lớn nhất.
	}

	@Test
	void testThirdNumberIsMax() {
	    Triangle triangle = new Triangle();
	    triangle.setNumber1(5);
	    triangle.setNumber2(3);
	    triangle.setNumber3(10);
	    assertEquals(10, triangle.maxLength()); // Cạnh thứ ba lớn nhất.
	}


}
