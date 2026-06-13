package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.Advance1;

class Test11 {

	@Test
	void testUSCLN() {
	    Advance1 adv = new Advance1();
	    assertEquals(6, adv.USCLN(12, 18)); // USCLN của 12 và 18 là 6.
	}

	@Test
	void testBSCNN() {
	    Advance1 adv = new Advance1();
	    assertEquals(36, adv.BSCNN(12, 18)); // BSCNN của 12 và 18 là 36.
	}


}
