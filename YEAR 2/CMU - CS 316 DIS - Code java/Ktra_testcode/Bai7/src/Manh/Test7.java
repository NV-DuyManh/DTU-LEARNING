package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.MaxNumber2;

class Test7 {

	@Test
	void testFirstNumberIsMax() {
	    MaxNumber2 max = new MaxNumber2();
	    max.number1 = 10;
	    max.number2 = 5;
	    assertEquals(10, max.max2()); // Kiểm tra số đầu tiên là lớn nhất.
	}

	@Test
	void testSecondNumberIsMax() {
	    MaxNumber2 max = new MaxNumber2();
	    max.number1 = 5;
	    max.number2 = 10;
	    assertEquals(10, max.max2()); // Kiểm tra số thứ hai là lớn nhất.
	}


}
