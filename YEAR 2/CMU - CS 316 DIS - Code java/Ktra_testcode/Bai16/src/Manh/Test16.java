package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.Advance6;

class Test16 {

	@Test
	void testValidAge() {
	    Advance6 adv = new Advance6();
	    assertEquals(26, adv.tinhTuoi(12, 4, 1999)); // Ngày sinh: 12/04/1999, tuổi hiện tại: 26.
	}

	@Test
	void testInvalidAge() {
	    Advance6 adv = new Advance6();
	    assertEquals(-1, adv.tinhTuoi(31, 2, 2020)); // Ngày tháng không hợp lệ.
	}


}
