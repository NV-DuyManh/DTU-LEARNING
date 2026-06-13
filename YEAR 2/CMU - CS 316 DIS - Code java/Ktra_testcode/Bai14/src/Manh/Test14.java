package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.Advance4;

class Test14 {

	@Test
	void testIsPrimeLessThanTwo() {
	    Advance4 adv = new Advance4();
	    assertFalse(adv.isPrimeNumber(1)); // Trường hợp n < 2.
	}

	@Test
	void testIsPrimeTrue() {
	    Advance4 adv = new Advance4();
	    assertTrue(adv.isPrimeNumber(7)); // Trường hợp n là số nguyên tố.
	}

	@Test
	void testIsPrimeFalse() {
	    Advance4 adv = new Advance4();
	    assertFalse(adv.isPrimeNumber(10)); // Trường hợp n không phải số nguyên tố.
	}


}
