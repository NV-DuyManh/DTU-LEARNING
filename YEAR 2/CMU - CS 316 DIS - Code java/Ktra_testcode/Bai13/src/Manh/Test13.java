package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.Advance3;

class Test13 {

	@Test
	void testFibonacciNegativeInput() {
	    Advance3 adv = new Advance3();
	    assertEquals(-1, adv.fibonacci(-5)); // Trường hợp n < 0.
	}

	@Test
	void testFibonacciBaseCaseZero() {
	    Advance3 adv = new Advance3();
	    assertEquals(0, adv.fibonacci(0)); // Trường hợp n = 0.
	}

	@Test
	void testFibonacciBaseCaseOne() {
	    Advance3 adv = new Advance3();
	    assertEquals(1, adv.fibonacci(1)); // Trường hợp n = 1.
	}

	@Test
	void testFibonacciPositiveInput() {
	    Advance3 adv = new Advance3();
	    assertEquals(21, adv.fibonacci(8)); // Fibonacci(8) = 21.
	}


}
