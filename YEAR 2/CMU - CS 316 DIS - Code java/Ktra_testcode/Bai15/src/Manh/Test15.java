package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.Advance5;

class Test15 {

	@Test
	void testPalindromeTrue() {
	    Advance5 adv = new Advance5();
	    assertTrue(adv.kiemTraDoiXung(12121)); // Số đối xứng.
	}

	@Test
	void testPalindromeFalse() {
	    Advance5 adv = new Advance5();
	    assertFalse(adv.kiemTraDoiXung(112)); // Số không đối xứng.
	}


}
