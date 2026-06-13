package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.Calculator1;

class Test1 {

	@Test
	void testResultValue() {
		Calculator1 calc = new Calculator1();
		assertEquals(5, calc.add(2, 3));
	}

	@Test
	void testNumberLargerThanMaxInt() {
		Calculator1 calc = new Calculator1();
		assertThrows(ArithmeticException.class, () -> calc.add(Integer.MAX_VALUE, 1));
	}

	@Test
	void testNumberSmallerThanMinInt() {
		Calculator1 calc = new Calculator1();
		assertThrows(ArithmeticException.class, () -> calc.add(Integer.MIN_VALUE, -1));
	}
}
