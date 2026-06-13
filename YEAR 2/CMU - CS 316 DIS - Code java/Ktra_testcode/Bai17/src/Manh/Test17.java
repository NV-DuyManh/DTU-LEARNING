package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.Advance7;

class Test17 {

	@Test
	void testValidDayOfWeek() {
	    Advance7 adv = new Advance7();
	    assertEquals(1, adv.tinhThu(5, 4, 2020)); // 05/04/2020 là Chủ nhật (1).
	}

	@Test
	void testInvalidDayOfWeek() {
	    Advance7 adv = new Advance7();
	    assertEquals(0, adv.tinhThu(31, 2, 2020)); // Ngày tháng không hợp lệ.
	}


}
