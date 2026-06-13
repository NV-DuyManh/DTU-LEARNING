package Manh;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import Nguyen.Sort1;

class Test8 {

	@Test
	void testNumber1GreaterThanNumber2() {
	    Sort1.number1 = 10;
	    Sort1.number2 = 5;
	    Sort1.sortAsc();
	    assertTrue(Sort1.number1 < Sort1.number2); // Kiểm tra sau khi sắp xếp.
	}

	@Test
	void testNumber1LessThanNumber2() {
	    Sort1.number1 = 3;
	    Sort1.number2 = 8;
	    Sort1.sortAsc();
	    assertTrue(Sort1.number1 < Sort1.number2); // Kiểm tra sau khi sắp xếp.
	}


}
