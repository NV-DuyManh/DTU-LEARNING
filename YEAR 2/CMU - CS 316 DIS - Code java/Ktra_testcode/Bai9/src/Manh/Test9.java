package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.Sort2;

class Test9 {

	@Test
	void testNumber1GreaterThanNumber2() {
	    Sort2 sort = new Sort2();
	    sort.number1 = 10;
	    sort.number2 = 5;
	    sort.sortDesc();
	    assertTrue(sort.number1 > sort.number2); // Kiểm tra sau khi sắp xếp.
	}

	@Test
	void testNumber1LessThanNumber2() {
	    Sort2 sort = new Sort2();
	    sort.number1 = 3;
	    sort.number2 = 8;
	    sort.sortDesc();
	    assertTrue(sort.number1 > sort.number2); // Kiểm tra sau khi sắp xếp.
	}


}
