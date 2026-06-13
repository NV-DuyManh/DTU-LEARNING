package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.MaxNumber1;

class Test6 {

	@Test
	void testFirstNumberIsMax() {
	    MaxNumber1 max = new MaxNumber1(10, 5, 3);
	    assertEquals(10, max.max3()); // Kiểm tra số đầu tiên là lớn nhất.
	}

	@Test
	void testSecondNumberIsMax() {
	    MaxNumber1 max = new MaxNumber1(5, 10, 3);
	    assertEquals(10, max.max3()); // Kiểm tra số thứ hai là lớn nhất.
	}

	@Test
	void testThirdNumberIsMax() {
	    MaxNumber1 max = new MaxNumber1(5, 3, 10);
	    assertEquals(10, max.max3()); // Kiểm tra số thứ ba là lớn nhất.
	}


}
